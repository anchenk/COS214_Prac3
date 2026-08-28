#ifndef NOTICE_H
#define NOTICE_H

#include <string>
#include <map>
#include <iostream>

#include "../enums/Severity.h"
#include "../enums/NoticeType.h"

/**
 * @brief An event that is sent out to event listeners, and contains all necessary details for conditionally handling the event.
 */
class Notice
{
private:
    std::map<std::string, std::string> details;
    std::string message;
    Severity severity;
    NoticeType type;

public:
    /**
     * @brief Create a new Notice object.
     *
     * @param type The type of event.
     * @param message Description of the notice event.
     */
    Notice(NoticeType type, std::string message);

    /**
     * @brief Get the type of event of this Notice.
     *
     * @return the type of event of this Notice.
     */
    NoticeType getType() const;

    /**
     * @brief Get the message describing this Notice.
     *
     * @return the message describing this Notice.
     */
    std::string getMessage() const;

    /**
     * @brief Get the severity of this Notice.
     *
     * The severity describes how important the event is.
     *
     * @return the severity of this Notice.
     */
    Severity getSeverity() const;

    /**
     * @brief Get a particular detail set in this Notice.
     *
     * @param key The key whose corresponding detail value to get.
     * @return the detail associated with the given key.
     * @throw const char* If the key does not exist.
     */
    std::string getDetail(const std::string &key) const;

    /**
     * @brief Get the full map of key-value details attached to this Notice.
     *
     * @return const reference to the internal details map.
     */
    const std::map<std::string, std::string> &getDetails() const;

    /**
     * @brief Check if a specific detail key exists in this Notice.
     *
     * @param key The metadata key to search for.
     * @return true if the key exists, false otherwise.
     */
    bool hasDetail(const std::string &key) const;

    /**
     * @brief Set the severity level of this Notice.
     *
     * @param severity The new severity value to assign.
     */
    void setSeverity(Severity severity);

    /**
     * @brief Add or update a key-value detail entry in this Notice.
     *
     * @param key The detail metadata key.
     * @param value The detail value associated with the key.
     */
    void addDetail(const std::string &key, const std::string &value);

    /**
     * @brief Print the Notice message and attached metadata details to standard output.
     */
    void print() const;

    /**
     * @brief Factory method to create a facility opening notice.
     *
     * @param facility The name of the facility being opened.
     * @return a Notice configured with NoticeType::Open.
     */
    static Notice open(const std::string &facility);

    /**
     * @brief Factory method to create a facility closure notice.
     *
     * @param facility The name of the facility being closed.
     * @param reason The explanation for closing the facility.
     * @return a Notice configured with NoticeType::Close.
     */
    static Notice close(const std::string &facility, const std::string &reason);

    /**
     * @brief Factory method to create a weather alert notice.
     *
     * @param message Description of the severe weather conditions.
     * @return a Notice configured with NoticeType::WeatherAlert.
     */
    static Notice weatherAlert(const std::string &message);

    /**
     * @brief Factory method to create an emergency evacuation notice.
     *
     * @param reason The cause triggering the evacuation order.
     * @return a Notice configured with NoticeType::Evacuate.
     */
    static Notice evacuation(const std::string &reason);

    /**
     * @brief Factory method to create a shift change notification.
     *
     * @return a Notice configured with NoticeType::ShiftChange.
     */
    static Notice shiftChange();

    /**
     * @brief Factory method to create a medical emergency alert notice.
     *
     * @param condition The type or description of medical emergency.
     * @param location The specific site where the medical emergency is occurring.
     * @param severity The urgency/severity level of the medical event.
     * @return a Notice configured with NoticeType::MedicalAlert.
     */
    static Notice medicalAlert(const std::string &condition, const std::string &location, Severity severity);
};

#endif