#ifndef NOTICE_TYPE_H
#define NOTICE_TYPE_H

/**
 * @brief Types of event notices that can be broadcast through the system.
 *
 * Each notice type triggers different behaviors in observers.
 * Observers use switch statements on this enum to determine their reactions.
 * @author Caleb Jennings - u25173805, Anchen Kruger - u25073703, Chloe Larsen - u25004141
 */
enum class NoticeType
{
    /**
     * @brief Open a facility or area.
     *
     * Causes observers to open/activate.
     * Severity: Info
     * Used by: All EventComponents
     */
    Open,

    /**
     * @brief Close a facility or area.
     *
     * Causes observers to close/deactivate.
     * Severity: Warning
     * Used by: All EventComponents
     */
    Close,

    /**
     * @brief Evacuate the area immediately.
     *
     * Triggers emergency evacuation procedures.
     * Severity: Critical
     * Used by: All EventComponents
     */
    Evacuate,

    /**
     * @brief Schedule or staff change notification.
     *
     * Used for shift changes, staff rotations, and schedule updates.
     * Can carry additional details like "new_staff", "new_chef", "new_manager",
     * or "new_language".
     * Severity: Info
     * Used by: All leaves (VendorBooth, FoodStation, PerformanceStage, etc.)
     */
    ScheduleChange,

    /**
     * @brief Medical emergency alert.
     *
     * Triggers medical response from FirstAidPoint and alerts other units.
     * Carries details: "condition" and "location".
     * Severity: Info, Warning, or Critical
     * Used by: FirstAidPoint (primary), all other units (secondary)
     */
    MedicalAlert,

    /**
     * @brief Weather warning or alert.
     * 
     * Triggers weather-related responses (closing outdoor areas, pausing shows).
     * Severity: Warning
     * Used by: Outdoor EventComponents
     */
    WeatherAlert
};

#endif