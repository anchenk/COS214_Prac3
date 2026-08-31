#include "../../include/observer/Notice.h"

Notice::Notice(NoticeType type, std::string message)
    : type(type), message(std::move(message)), severity(Severity::Info), location(nullptr) {}

NoticeType Notice::getType() const
{
    return type;
}

std::string Notice::getMessage() const
{
    return message;
}

Severity Notice::getSeverity() const
{
    return severity;
}

EventComponent *Notice::getLocation()
{
    return location;
}

void Notice::setLocation(EventComponent *location)
{
    this->location = location;
}

std::string Notice::getDetail(const std::string &key) const
{
    auto it = details.find(key);

    if (it == details.end())
    {
        throw "Notice does not have detail: " + key + "!";
    }

    return it->second;
}

const std::map<std::string, std::string> &Notice::getDetails() const
{
    return details;
}

bool Notice::hasDetail(const std::string &key) const
{
    return details.find(key) != details.end();
}

void Notice::setSeverity(Severity severity)
{
    this->severity = severity;
}

void Notice::addDetail(const std::string &key, const std::string &value)
{
    details[key] = value;
}

void Notice::print() const
{
    std::cout << "[Notice] Message: " << message << std::endl;
    std::cout << "Details:" << std::endl;

    for (const auto &pair : details)
    {
        std::cout << "  - " << pair.first << ": " << pair.second << std::endl;
    }
}

Notice Notice::open(const std::string &facility)
{
    std::string msg = "Facility " + facility + " is now open.";
    Notice notice(NoticeType::Open, msg);
    notice.addDetail("facility", facility);
    notice.setSeverity(Severity::Info);
    return notice;
}

Notice Notice::close(const std::string &facility, const std::string &reason)
{
    std::string msg = "Facility " + facility + " is now closed: " + reason;
    Notice notice(NoticeType::Close, msg);
    notice.addDetail("facility", facility);
    notice.addDetail("reason", reason);
    notice.setSeverity(Severity::Warning);
    return notice;
}

Notice Notice::weatherAlert(const std::string &message)
{
    Notice notice(NoticeType::WeatherAlert, message);
    notice.setSeverity(Severity::Warning);
    return notice;
}

Notice Notice::evacuation(const std::string &reason)
{
    Notice notice(NoticeType::Evacuate, "EVACUATE IMMEDIATELY: " + reason);
    notice.addDetail("reason", reason);
    notice.setSeverity(Severity::Critical);
    return notice;
}

Notice Notice::shiftChange()
{
    std::string msg = "Current shift ended, new shift starting";
    Notice notice(NoticeType::ScheduleChange, msg);
    notice.setSeverity(Severity::Info);
    return notice;
}

Notice Notice::medicalAlert(const std::string &condition, const std::string &location, Severity severity)
{
    std::string msg = "Medical alert (" + condition + ") at " + location;
    Notice notice(NoticeType::MedicalAlert, msg);
    notice.addDetail("condition", condition);
    notice.addDetail("location", location);
    notice.setSeverity(severity);
    return notice;
}