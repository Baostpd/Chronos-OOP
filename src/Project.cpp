#include "../include/Project.h"
#include <iostream>
#include <algorithm> // Thư viện bắt buộc để dùng hàm std::sort
#include <stdexcept> // Thư viện chứa std::overflow_error

// Ngưỡng giới hạn bộ đệm để phục vụ kịch bản Stress-test 10.000 tasks
const size_t MAX_TASKS_LIMIT = 5000;

Project::Project(std::string name) : projectName(name) {}

// Thêm nhiệm vụ vào danh sách vector
void Project::addTask(const Task& t, bool saveHistory) {
    // Kiểm tra nếu vượt quá giới hạn an toàn thì ném ngoại lệ ngay lập tức
    if (taskList.size() >= MAX_TASKS_LIMIT) {
        throw std::overflow_error("Buffer Overflow: Danh sach nhiem vu vuot qua gioi han an toan (5000 tasks) cua Chronos!");
    }
    if (saveHistory) {
        // Chụp lại trạng thái của taskList trước khi thêm để làm tính năng Hoàn tác
        undoStack.push(taskList);
    }

    // Thêm nhiệm vụ vào danh sách vector
    taskList.push_back(t);
}

void Project::undo() {
    if (undoStack.empty()) {
        std::cout << "[Undo Warning] Khong co hanh dong nao de hoan tac!\n";
        return;
    }
    
    // Khôi phục lại trạng thái cũ từ đỉnh stack lịch sử
    taskList = undoStack.top();
    
    // Xóa trạng thái đó ra khỏi stack
    undoStack.pop();
    
    std::cout << "[Undo System] Hoan tac thanh cong! Da quay lai trang thai phia truoc.\n";
}

// Sắp xếp tự động sử dụng toán tử < 
void Project::sortTasks() {
    std::sort(taskList.begin(), taskList.end());
}

// Hiển thị dashboard dạng bảng CLI
void Project::displayDashboard() const {
    std::cout << "\n=================== DASHBOARD: " << projectName << " ===================\n";
    if (taskList.empty()) {
        std::cout << "Hien tai chua co nhiem vu nao trong du an.\n";
        return;
    }
    
    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << "[" << i + 1 << "] ";
        const Task& currentTask = taskList[i];
        
        // Gọi hàm hiển thị của Thành viên 1
        currentTask.displayBasicInfo(); 
        
        // Gọi hàm tính điểm khẩn cấp của bạn (Thành viên 2)
        std::cout << "-> Diem khan cap: " << currentTask.calculateUrgencyScore() << "\n";
        std::cout << "------------------------------------------------------------------\n";
    }
    std::cout << "==================================================================\n";
}