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

void extendFirstTask(Project& project) {
    if (project.getTaskCount() == 0) {
        cout << "\n[Warning] Danh sach dang trong, khong co nhiem vu de gia han!" << endl;
    } else {
        cout << "\n>>> DEMO TOAN TU ++ <<<" << endl;
        Task& firstTask = project.getTaskList()[0];
        cout << "[Truoc khi gia han] Deadline la: " << firstTask.getEndDate().toString() << endl;
        
        ++firstTask; 
        
        cout << "[Sau khi gia han] Deadline la:   " << firstTask.getEndDate().toString() << endl;
        cout << "-> Toan tu ++ da hoat dong thanh cong!" << endl;
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
                cout << "-> Da chen xuoi lọt " << i << " tasks..." << endl;
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