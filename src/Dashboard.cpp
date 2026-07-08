#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Project.h"
#include "Task.h"
#include "Date.h"

using namespace std;

static bool readDateInput(const string& prompt, int& day, int& month, int& year) {
    string line;

    while (true) {
        cout << prompt;
        getline(cin, line);

        istringstream iss(line);
        string yearToken;

        if (iss >> day >> month >> yearToken && iss.eof()) {
            istringstream yearStream(yearToken);
            if (!(yearStream >> year)) {
                cout << "[Input Error] Nam khong hop le.\n";
                continue;
            }

            if (yearToken.size() == 2) {
                year += 2000;
            } else if (yearToken.size() != 4) {
                cout << "[Input Error] Nam phai co 2 hoac 4 chu so, vi du: 25 hoac 2025.\n";
                continue;
            }

            Date parsedDate(day, month, year);
            if (parsedDate.isValid()) {
                return true;
            }

            cout << "[Input Error] Ngay khong hop le.\n";
        } else {
            cout << "[Input Error] Vui long nhap theo dang: ngay thang nam (VD: 1 6 2026 hoac 1 6 25).\n";
        }
    }
}

void addTaskFromDashboard(Project& project) {
    string title;

    cin.ignore(10000, '\n');

    cout << "\n--- THEM NHIEM VU MOI ---" << endl;
    cout << "Ten nhiem vu: ";
    getline(cin, title);

    int d1, m1, y1, d2, m2, y2, p;
    if (!readDateInput("Nhap Ngay bat dau (ngay thang nam, VD: 1 6 2026): ", d1, m1, y1)) {
        return;
    }

    if (!readDateInput("Nhap Han chot/Deadline (ngay thang nam, VD: 5 6 2026): ", d2, m2, y2)) {
        return;
    }

    cout << "Do uu tien (1: Cao nhat -> 5: Thap nhat): ";
    cin >> p;
    cin.ignore(10000, '\n');

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
        cout << "\n[Warning] Danh sach hien tai dang trong, khong co nhiem vu de gia han!" << endl;
    } else {
        cout << "\n>>> DEMO TOAN TU ++ (Gia han nhiem vu dau tien them 1 ngay) <<<" << endl;
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
                cout << "-> Da chen xuoi lot " << i << " tasks..." << endl;
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