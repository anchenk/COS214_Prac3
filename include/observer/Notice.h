#ifndef NOTICE_H
#define NOTICE_H

#include <string>
#include <map>
#include <iostream>

#include "../enums/Severity.h"
#include "../enums/NoticeType.h"

class Notice
{
private:
    std::map<std::string, std::string> details;
    std::string message;
    Severity severity;
    NoticeType type;

public:
    Notice(NoticeType type, std::string message);

    NoticeType getType() const;
    std::string getMessage() const;
    Severity getSeverity() const;
    std::string getDetail(const std::string &key) const;
    const std::map<std::string, std::string> &getDetails() const;

    bool hasDetail(const std::string &key) const;
    void setSeverity(Severity severity);
    void addDetail(const std::string &key, const std::string &value);
    void print() const;

    static Notice open(const std::string &facility);
    static Notice close(const std::string &facility, const std::string &reason);
    static Notice weatherAlert(const std::string &message);
    static Notice evacuation(const std::string &reason);
    static Notice shiftChange();
    static Notice medicalAlert(const std::string &condition, const std::string &location, Severity severity);
};

#endif