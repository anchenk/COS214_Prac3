/**
 * @file main.cpp
 * @brief Demonstration program for The Heap & Heap Artisanal Bazaar
 *
 * This program demonstrates:
 * - Composite pattern: Building an event tree with multiple levels
 * - Observer pattern: Broadcasting notices and cascading notifications
 * - Original features: Shift changes, medical alerts, multi-language support
 * - Runtime reorganisation: Transferring vendors between areas
 *
 * @author Caleb Jennings - u25173805, Anchen Kruger - u25073703, Chloe Larsen - u25004141
 */

#include "../include/composite/EventGroup.h"
#include "../include/composite/VendorBooth.h"
#include "../include/composite/PerformanceStage.h"
#include "../include/composite/FoodStation.h"
#include "../include/composite/InformationDesk.h"
#include "../include/composite/FirstAidPoint.h"
#include "../include/observer/NotificationHub.h"
#include "../include/observer/Notice.h"

/**
 * @brief Print a separator line for visual clarity.
 *
 * @param title Optional title to display in the separator
 */
void printSeparator(const std::string &title = "")
{
    std::cout << "\n"
              << std::string(60, '=') << std::endl;
    if (!title.empty())
    {
        std::cout << "  " << title << std::endl;
        std::cout << std::string(60, '=') << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Wait for user input to continue the demonstration.
 */
void waitForUser()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void testing()
{
    printSeparator("THE HEAP & HEAP ARTISANAL BAZAAR - EVENT SIMULATION");
    std::cout << "\n Building the event structure...\n"
              << std::endl;
    EventGroup *bazaar = new EventGroup("Heap & Heap Bazaar", false, true, true);

    // Create precincts
    EventGroup *foodQuarter = new EventGroup("Food Quarter", false, true, true);
    EventGroup *artisanRow = new EventGroup("Artisan Row", true, true, true);
    EventGroup *performanceGreen = new EventGroup("Performance Green", true, true, true);

    // Create zones
    EventGroup *hotFoodLane = new EventGroup("Hot Food Lane", true, true, true);
    EventGroup *coffeeCourt = new EventGroup("Coffee Court", false, true, true);
    EventGroup *potteryCorner = new EventGroup("Pottery Corner", true, true, true);
    EventGroup *textileAlley = new EventGroup("Textile Alley", true, true, true);

    // Create leaves
    FoodStation *tacoVendor = new FoodStation("Taco Stand", 50, "Mexican");
    FoodStation *burgerVendor = new FoodStation("Burger Grill", 40, "American");
    FoodStation *coffeeStation = new FoodStation("Artisan Coffee", 30, "Beverages");
    FoodStation *teaHouse = new FoodStation("Tea House", 25, "Tea & Snacks");

    VendorBooth *potteryVendor = new VendorBooth("Pottery Studio", 35, "Ceramics");
    VendorBooth *weavingVendor = new VendorBooth("Weaving Workshop", 30, "Textiles");
    VendorBooth *jewelryVendor = new VendorBooth("Jewelry Craft", 20, "Jewelry");

    PerformanceStage *mainStage = new PerformanceStage("Main Stage", 200);
    InformationDesk *infoDesk = new InformationDesk("Main Info Desk", 15);
    FirstAidPoint *firstAid = new FirstAidPoint("First Aid Station", 10);

    foodQuarter->addChild(hotFoodLane);
    hotFoodLane->addChild(tacoVendor);
    hotFoodLane->addChild(burgerVendor);

    foodQuarter->addChild(coffeeCourt);
    coffeeCourt->addChild(coffeeStation);
    coffeeCourt->addChild(teaHouse);

    artisanRow->addChild(potteryCorner);
    potteryCorner->addChild(potteryVendor);
    potteryCorner->addChild(jewelryVendor);

    artisanRow->addChild(textileAlley);
    textileAlley->addChild(weavingVendor);

    performanceGreen->addChild(mainStage);
    performanceGreen->addChild(infoDesk);
    performanceGreen->addChild(firstAid);

    bazaar->addChild(foodQuarter);
    bazaar->addChild(artisanRow);
    bazaar->addChild(performanceGreen);

    std::cout << "   - Root: " << bazaar->getName() << std::endl;
    std::cout << "   - Event tree built successfully!" << std::endl;

    printSeparator("OPENING THE EVENT");
    bazaar->open();

    printSeparator("OBSERVER REGISTRATION");
    NotificationHub hub;
    hub.attach(bazaar);
    std::cout << "Root registered with hub" << std::endl;

    printSeparator("WEATHER ALERT");
    Notice weatherNotice = Notice::weatherAlert("Severe thunderstorm approaching!");
    hub.broadcastToAll(&weatherNotice);

    printSeparator("SCHEDULE CHANGE");
    Notice shiftNotice = Notice::shiftChange();
    shiftNotice.addDetail("new_staff", "Maria Rodriguez");
    shiftNotice.addDetail("new_chef", "Chef Gordon");
    shiftNotice.addDetail("new_manager", "Sarah Johnson");
    shiftNotice.addDetail("new_desk_staff", "James May");
    shiftNotice.addDetail("new_doctor", "Dr. Chen");
    hub.broadcastToAll(&shiftNotice);

    printSeparator("MEDICAL ALERT - 1 staff and no supplies");
    Notice medicalNotice = Notice::medicalAlert(
        "Cardiac Arrest",
        mainStage,
        Severity::Critical);
    hub.broadcastToAll(&medicalNotice);

    printSeparator("RESTOCK FIRSTAID");
    std::cout << "Reopen" << std::endl;
    bazaar->open();
    std::cout << std::endl;
    firstAid->restockSupplies(50);
    firstAid->changeDoctor("Dr Grey");
    printSeparator("MEDICAL ALERT - 2 staff and 50% supplies");
    medicalNotice = Notice::medicalAlert(
        "Broken leg",
        coffeeCourt,
        Severity::Warning);
    hub.broadcastToAll(&medicalNotice);

    printSeparator("RUNTIME REORGANISATION");
    std::cout << "Reopen" << std::endl;
    bazaar->open();
    std::cout << std::endl;
    std::cout << "\nTransferring 'Taco Stand' from Hot Food Lane to Food Quarter...\n"
              << std::endl;

    EventComponent *transferredVendor = hotFoodLane->removeChild(tacoVendor);
    if (transferredVendor)
    {
        foodQuarter->addChild(transferredVendor);
        std::cout << tacoVendor->getName() << " transferred to Food Quarter" << std::endl;
    }

    printSeparator("EVACUATION");
    Notice evacNotice = Notice::evacuation("Fire detected in Artisan Row");
    hub.broadcastToAll(&evacNotice);

    std::cout << "Reopen" << std::endl;
    bazaar->open();

    printSeparator("MULTI-LANGUAGE SUPPORT");
    std::cout << "Adding languages to Information Desk..." << std::endl;
    infoDesk->addLanguage("French");
    infoDesk->addLanguage("Mandarin");
    infoDesk->addLanguage("Spanish");
    std::cout << std::endl;
    infoDesk->reportStatus();

    printSeparator("REPORT STATUS");
    bazaar->reportStatus();
    
    printSeparator("CLOSE DOWN TIME");
    Notice close = Notice::close("All", "Market is done");
    hub.broadcastToAll(&close);

    delete bazaar;
}

void demo()
{
    printSeparator("THE HEAP & HEAP ARTISANAL BAZAAR - EVENT SIMULATION");
    std::cout << "\n Building the event structure...\n"
              << std::endl;
    EventGroup *bazaar = new EventGroup("Heap & Heap Bazaar", false, true, true);

    // Create precincts
    EventGroup *foodQuarter = new EventGroup("Food Quarter", false, true, true);
    EventGroup *artisanRow = new EventGroup("Artisan Row", true, true, true);
    EventGroup *performanceGreen = new EventGroup("Performance Green", true, true, true);

    // Create zones
    EventGroup *hotFoodLane = new EventGroup("Hot Food Lane", true, true, true);
    EventGroup *coffeeCourt = new EventGroup("Coffee Court", false, true, true);
    EventGroup *potteryCorner = new EventGroup("Pottery Corner", true, true, true);
    EventGroup *textileAlley = new EventGroup("Textile Alley", true, true, true);

    // Create leaves
    FoodStation *tacoVendor = new FoodStation("Taco Stand", 50, "Mexican");
    FoodStation *burgerVendor = new FoodStation("Burger Grill", 40, "American");
    FoodStation *coffeeStation = new FoodStation("Artisan Coffee", 30, "Beverages");
    FoodStation *teaHouse = new FoodStation("Tea House", 25, "Tea & Snacks");

    VendorBooth *potteryVendor = new VendorBooth("Pottery Studio", 35, "Ceramics");
    VendorBooth *weavingVendor = new VendorBooth("Weaving Workshop", 30, "Textiles");
    VendorBooth *jewelryVendor = new VendorBooth("Jewelry Craft", 20, "Jewelry");

    PerformanceStage *mainStage = new PerformanceStage("Main Stage", 200);
    InformationDesk *infoDesk = new InformationDesk("Main Info Desk", 15);
    FirstAidPoint *firstAid = new FirstAidPoint("First Aid Station", 10);

    foodQuarter->addChild(hotFoodLane);
    hotFoodLane->addChild(tacoVendor);
    hotFoodLane->addChild(burgerVendor);

    foodQuarter->addChild(coffeeCourt);
    coffeeCourt->addChild(coffeeStation);
    coffeeCourt->addChild(teaHouse);

    artisanRow->addChild(potteryCorner);
    potteryCorner->addChild(potteryVendor);
    potteryCorner->addChild(jewelryVendor);

    artisanRow->addChild(textileAlley);
    textileAlley->addChild(weavingVendor);

    performanceGreen->addChild(mainStage);
    performanceGreen->addChild(infoDesk);
    performanceGreen->addChild(firstAid);

    bazaar->addChild(foodQuarter);
    bazaar->addChild(artisanRow);
    bazaar->addChild(performanceGreen);

    std::cout << "   - Root: " << bazaar->getName() << std::endl;
    std::cout << "   - Event tree built successfully!" << std::endl;

    printSeparator("OPENING THE EVENT");
    bazaar->open();    
    
    printSeparator("OBSERVER REGISTRATION");
    NotificationHub hub;
    hub.attach(bazaar);
    std::cout << "Root registered with hub" << std::endl;

    waitForUser();

    printSeparator("WEATHER ALERT");
    Notice weatherNotice = Notice::weatherAlert("Severe thunderstorm approaching!");
    hub.broadcastToAll(&weatherNotice);

    waitForUser();

    printSeparator("SCHEDULE CHANGE");
    Notice shiftNotice = Notice::shiftChange();
    shiftNotice.addDetail("new_staff", "Maria Rodriguez");
    shiftNotice.addDetail("new_chef", "Chef Gordon");
    shiftNotice.addDetail("new_manager", "Sarah Johnson");
    shiftNotice.addDetail("new_desk_staff", "James May");
    shiftNotice.addDetail("new_doctor", "Dr. Chen");
    hub.broadcastToAll(&shiftNotice);

    waitForUser();

    printSeparator("MEDICAL ALERT - 1 staff and no supplies");
    Notice medicalNotice = Notice::medicalAlert(
        "Cardiac Arrest",
        mainStage,
        Severity::Critical);
    hub.broadcastToAll(&medicalNotice);

    waitForUser();

    printSeparator("RESTOCK FIRSTAID");
    std::cout << "Reopen" << std::endl;
    bazaar->open();
    std::cout << std::endl;
    firstAid->restockSupplies(50);
    firstAid->changeDoctor("Dr Grey");
    printSeparator("MEDICAL ALERT - 2 staff and 50% supplies");
    medicalNotice = Notice::medicalAlert(
        "Broken leg",
        coffeeCourt,
        Severity::Warning);
    hub.broadcastToAll(&medicalNotice);

    waitForUser();

    printSeparator("RUNTIME REORGANISATION");
    std::cout << "Reopen" << std::endl;
    bazaar->open();
    std::cout << std::endl;
    std::cout << "\nTransferring 'Taco Stand' from Hot Food Lane to Food Quarter...\n"
              << std::endl;

    EventComponent *transferredVendor = hotFoodLane->removeChild(tacoVendor);
    if (transferredVendor)
    {
        foodQuarter->addChild(transferredVendor);
        std::cout << tacoVendor->getName() << " transferred to Food Quarter" << std::endl;
    }

    waitForUser();

    printSeparator("EVACUATION");
    Notice evacNotice = Notice::evacuation("Fire detected in Artisan Row");
    hub.broadcastToAll(&evacNotice);

    waitForUser();

    std::cout << "Reopen" << std::endl;
    bazaar->open();

    printSeparator("MULTI-LANGUAGE SUPPORT");
    std::cout << "Adding languages to Information Desk..." << std::endl;
    infoDesk->addLanguage("French");
    infoDesk->addLanguage("Mandarin");
    infoDesk->addLanguage("Spanish");
    std::cout << std::endl;
    infoDesk->reportStatus();

    waitForUser();

    printSeparator("CLOSE DOWN TIME");
    Notice close = Notice::close("All", "Market is done");
    hub.broadcastToAll(&close);
    delete bazaar;
}

int main()
{
    bool test = true;
    if (test)
        testing();
    else
        demo();
    return 0;
}