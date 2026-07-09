#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"

class Task {
private:
    std::string title;
    Date startDate;
    Date endDate;
    int priority;

public:
    // Constructors
    Task();
    Task(const std::string& title, const Date& startDate, const Date& endDate, int priority);

    // Getters
    std::string getTitle() const;
    Date getStartDate() const;
    Date getEndDate() const;
    int getPriority() const;

    // Setters
    void setTitle(const std::string& title);
    void setStartDate(const Date& startDate);
    void setEndDate(const Date& endDate);
    void setPriority(int priority);

    // Các hàm của Thành viên 1
    void validateDates() const;
    void displayBasicInfo() const;

    // Các hàm logic cốt lõi của Thành viên 2
    int calculateUrgencyScore() const;        
    bool operator<(const Task& other) const;  
    Task& operator++(); // Dùng để gia hạn chính task này
};

#endif