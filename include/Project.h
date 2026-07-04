#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <string>
#include "Task.h" // Nhúng lớp Task để quản lý danh sách nhiệm vụ
#include <stack> 

class Project {
private:
    std::string projectName;
    std::vector<Task> taskList; // Container quản lý tập hợp các đối tượng Task
    std::stack<std::vector<Task>> undoStack; //stack lưu lịch sử hoàn tác

public:
    // Constructor nhận tên dự án
    Project(std::string name);

    // Các phương thức cốt lõi (Thành viên 2)
    void addTask(const Task& t, bool saveHistory = true);        // Hàm thêm nhiệm vụ mới vào vector
    void sortTasks();                  // Hàm sắp xếp tự động dựa trên toán tử <
    void displayDashboard() const;     // Hàm hiển thị dữ liệu dạng bảng CLI
    void undo(); //Hàm hoàn tác
    
    // Các hàm getter hỗ trợ lấy thông tin danh sách (viết inline trực tiếp)
    int getTaskCount() const { 
        return taskList.size(); 
    }
    
    std::vector<Task>& getTaskList() { 
        return taskList; 
    }
};

#endif