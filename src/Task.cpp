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

    // Kiểm tra dữ liệu ngay khi tạo task
    validateDates();
}

// Getter
std::string Task::getTitle() const {
    return title;
}

Date Task::getStartDate() const {
    return startDate;
}

Date Task::getEndDate() const {
    return endDate;
}

int Task::getPriority() const {
    return priority;
}

// Setter
void Task::setTitle(const std::string& title) {
    this->title = title;
}

void Task::setStartDate(const Date& startDate) {
    this->startDate = startDate;
    validateDates();
}

void Task::setEndDate(const Date& endDate) {
    this->endDate = endDate;
    validateDates();
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

// Kiểm tra lỗi Time Paradox
void Task::validateDates() const {
    // Kiểm tra ngày bắt đầu có hợp lệ không
    if (!startDate.isValid()) {
        throw std::invalid_argument("Loi: Ngay bat dau khong hop le!");
    }

    // Kiểm tra ngày kết thúc có hợp lệ không
    if (!endDate.isValid()) {
        throw std::invalid_argument("Loi: Ngay ket thuc khong hop le!");
    }

    // Nếu ngày kết thúc trước ngày bắt đầu
    if (endDate.isBefore(startDate)) {
        throw std::invalid_argument(
            "Time Paradox: Ngay ket thuc khong the truoc ngay bat dau!"
        );
    }
}

// In thông tin cơ bản
void Task::displayBasicInfo() const {
    std::cout << "Ten nhiem vu: " << title << std::endl;
    std::cout << "Ngay bat dau: " << startDate.toString() << std::endl;
    std::cout << "Deadline: " << endDate.toString() << std::endl;
    std::cout << "Do uu tien: " << priority << std::endl;
}

// Tính điểm khẩn cấp
int Task::calculateUrgencyScore() const {
    // Mô hình đơn giản: ưu tiên nhân hệ số 10
    return priority * 10;
}

// So sánh để sắp xếp: muốn sắp xếp theo điểm khẩn cấp giảm dần
bool Task::operator<(const Task& other) const {
    return this->calculateUrgencyScore() > other.calculateUrgencyScore();
}