#include "Project.h"
#include <iostream>
#include <algorithm> // Thư viện bắt buộc để dùng hàm std::sort

Project::Project(std::string name) : projectName(name) {}

// Thêm nhiệm vụ vào danh sách vector
void Project::addTask(const Task& t) {
    taskList.push_back(t);
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