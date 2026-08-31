#ifndef SEVERITY_TYPE_H
#define SEVERITY_TYPE_H

/**
 * @brief Severity levels for event notices.
 *
 * Indicates the urgency and importance of a notice.
 * Used by observers to determine the appropriate response level.
 * @author Caleb Jennings - u25173805, Anchen Kruger - u25073703, Chloe Larsen - u25004141
 */
enum class Severity
{
    /**
     * @brief Informational notice - no immediate action required.
     *
     * Used for routine notifications like Open, ScheduleChange.
     * Observers may log these but typically don't change behavior.
     */
    Info,

    /**
     * @brief Warning notice - action may be required.
     *
     * Used for WeatherAlert, Close and some MedicalAlert cases.
     * Observers should be aware and may take preventive actions.
     */
    Warning,

    /**
     * @brief Critical notice - immediate action required.
     *
     * Used for Evacuate and severe MedicalAlert cases.
     * Observers must respond immediately (close, evacuate, dispatch teams).
     */
    Critical
};

#endif