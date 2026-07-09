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

    // Các hàm của Thành viên 2 (Chỉ xuất hiện duy nhất 1 lần ở đây)
    int calculateUrgencyScore() const;        
    bool operator<(const Task& other) const;  
    Task& operator++();                       


    // === THÊM MỚI CỦA THÀNH VIÊN 2 ===
    // Đăng ký task
    void registerTask();
    void unregisterTask();
    
    // Gia hạn task theo TÊN
    static bool extendTaskByName(const std::string& taskTitle);
    
    // Gia hạn task theo THỨ TỰ (chỉ số)
    static bool extendTaskByIndex(int index);
    
    // Hiển thị danh sách task (tiện ích)
    static void displayAllTasks();
};

#endif