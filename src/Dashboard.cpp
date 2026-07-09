#include <iostream>
#include <string>
#include <stdexcept>
#include "Date.h"
#include "Task.h"
#include "Project.h"

using namespace std;

void addTaskFromDashboard(Project& project) {
    string title;
    int d1, m1, y1, d2, m2, y2, p;
    
    cout << "\n--- THEM NHIEM VU MOI ---" << endl;
    cout << "Ten nhiem vu: "; 
    cin.ignore(); 
    getline(cin, title);
    
    cout << "Nhap Ngay bat dau (VD: 1 6 2026): "; 
    cin >> d1 >> m1 >> y1;
    
    cout << "Nhap Han chot/Deadline (VD: 5 6 2026): "; 
    cin >> d2 >> m2 >> y2;
    
    cout << "Do uu tien (1: Cao nhat -> 5: Thap nhat): "; 
    cin >> p;
    
    try {
        Task newTask(title, Date(d1, m1, y1), Date(d2, m2, y2), p);
        project.addTask(newTask);
        cout << "[System] Da them nhiem vu vao he thong thanh cong!" << endl;
    } 
    catch (const invalid_argument& e) {
        cout << "\n[CATCH EXCEPTION: TIME PARADOX]" << endl;
        cout << "-> Chi tiet loi: " << e.what() << endl;
        cout << "-> He thong da ngan chan viec tao nhiem vu loi." << endl;
    }
}

void viewDashboard(Project& project) {
    project.sortTasks();
    project.displayDashboard();
}

void undoLastAction(Project& project) {
    project.undo();
}

// HÀM GIA HẠN TỔNG HỢP (Xử lý theo cả số thứ tự và Tên)
void extendTask(Project& project) {
    if (project.getTaskCount() == 0) {
        cout << "\n[Warning] Danh sach dang trong, khong co nhiem vu de gia han!" << endl;
        return;
    }

    auto& taskList = project.getTaskList();
    int choice;

    cout << "\n>>> GIA HAN NHIEM VU <<<" << endl;
    cout << "1. Gia han theo so thu tu" << endl;
    cout << "2. Gia han theo ten" << endl;
    cout << "Nhap lua chon: ";
    
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        choice = -1;
    }

    if (choice == 1) {
        int index;
        cout << "Nhap so thu tu nhiem vu can gia han (1 - " << project.getTaskCount() << "): ";
        cin >> index;
        if (index > 0 && index <= project.getTaskCount()) {
            // ĐÃ THÊM: Chụp ảnh trạng thái trước khi thay đổi
            project.saveCurrentState(); 
            
            ++taskList[index - 1]; 
            cout << "[Thanh cong] Da gia han nhiem vu: " << taskList[index - 1].getTitle() << endl;
        } else {
            cout << "[Loi] Vi tri khong hop le!" << endl;
        }
    } 
    else if (choice == 2) {
        string name;
        cout << "Nhap ten nhiem vu can gia han: ";
        cin.ignore();
        getline(cin, name);
        
        bool found = false;
        for (auto& task : taskList) {
            if (task.getTitle() == name) {
                // ĐÃ THÊM: Chụp ảnh trạng thái trước khi thay đổi
                project.saveCurrentState(); 
                
                ++task; 
                cout << "[Thanh cong] Da gia han nhiem vu: " << task.getTitle() << endl;
                found = true;
                break; 
            }
        }
        if (!found) {
            cout << "[Loi] Khong tim thay nhiem vu mang ten: " << name << endl;
        }
    }
}

void stressTestDashboard(Project& project) {
    cout << "\n>>> DEMO STRESS-TEST 10.000 TASKS <<<" << endl;
    cout << "[System] Dang nap du lieu toc do cao vao he thong..." << endl;
    try {
        Date today(24, 6, 2026);
        Task dummyTask("Nhiem vu an danh", today, today, 3);
        
        for (int i = 1; i <= 10000; ++i) {
            project.addTask(dummyTask, false); 
            if (i % 1000 == 0) {
                cout << "-> Tien trinh nap du lieu: " << i << "/10000 tasks..." << endl;
            }
        }
    } 
    catch (const overflow_error& e) {
        cout << "\n[CATCH EXCEPTION SUCCESS: OVERFLOW]" << endl;
        cout << "-> Tin nhan loi: " << e.what() << endl;
        cout << "-> He thong da ngan chan tran bo dem an toan!" << endl;
        cout << "-> So luong nhiem vu dung lai an toan o muc: " << project.getTaskCount() << endl;
    }
}