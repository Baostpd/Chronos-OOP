#include "Task.h"
#include <iostream>
#include <stdexcept>

// Constructor mặc định
Task::Task() {
    title = "Untitled Task";
    startDate = Date(1, 1, 2026);
    endDate = Date(1, 1, 2026);
    priority = 1;
}

// Constructor có tham số
Task::Task(const std::string& title, const Date& startDate, const Date& endDate, int priority) {
    this->title = title;
    this->startDate = startDate;
    this->endDate = endDate;
    this->priority = priority;
    validateDates();
}

// Getter
std::string Task::getTitle() const { return title; }
Date Task::getStartDate() const { return startDate; }
Date Task::getEndDate() const { return endDate; }
int Task::getPriority() const { return priority; }

// Setter
void Task::setTitle(const std::string& title) { this->title = title; }
void Task::setStartDate(const Date& startDate) { this->startDate = startDate; validateDates(); }
void Task::setEndDate(const Date& endDate) { this->endDate = endDate; validateDates(); }
void Task::setPriority(int priority) { this->priority = priority; }

// Kiểm tra lỗi ngày tháng
void Task::validateDates() const {
    if (!startDate.isValid()) throw std::invalid_argument("Loi: Ngay bat dau khong hop le!");
    if (!endDate.isValid()) throw std::invalid_argument("Loi: Ngay ket thuc khong hop le!");
    if (endDate.isBefore(startDate)) {
        throw std::invalid_argument("Time Paradox: Ngay ket thuc khong the truoc ngay bat dau!");
    }
}

// In thông tin cơ bản
void Task::displayBasicInfo() const {
    std::cout << "Ten nhiem vu: " << title << std::endl;
    std::cout << "Ngay bat dau: " << startDate.toString() << std::endl;
    std::cout << "Deadline: " << endDate.toString() << std::endl;
    std::cout << "Do uu tien: " << priority << std::endl;
}

// =========================================================================
// PHẦN LOGIC THỰC THI
// =========================================================================

// 1. Hàm tính điểm "Khẩn cấp"
int Task::calculateUrgencyScore() const {
    int baseScore = (4 - priority) * 10; 
    return baseScore;
}

// 2. Nạp chồng toán tử < để sắp xếp tự động
bool Task::operator<(const Task& other) const {
    if (this->endDate.isBefore(other.endDate)) return true;
    if (other.endDate.isBefore(this->endDate)) return false;
    return this->priority < other.priority; 
}

// 3. Nạp chồng toán tử ++ tiền tố để gia hạn thời hạn thêm đúng 1 ngày
Task& Task::operator++() {
    this->endDate.advanceOneDay(); 
    validateDates(); 
    return *this;
}