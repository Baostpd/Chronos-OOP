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
    // Constructor mặc định
    Task();

    // Constructor có tham số
    Task(const std::string& title, const Date& startDate, const Date& endDate, int priority);

    // Getter
    std::string getTitle() const;
    Date getStartDate() const;
    Date getEndDate() const;
    int getPriority() const;

    // Setter
    void setTitle(const std::string& title);
    void setStartDate(const Date& startDate);
    void setEndDate(const Date& endDate);
    void setPriority(int priority);

    // Kiểm tra lỗi ngày kết thúc trước ngày bắt đầu
    void validateDates() const;

    // In thông tin cơ bản của task
    void displayBasicInfo() const;
};

#endif