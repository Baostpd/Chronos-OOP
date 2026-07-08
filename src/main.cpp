#include <iostream>
#include "Project.h"

using namespace std;

// Khai báo các hàm sẽ được định nghĩa ở file Dashboard.cpp
void addTaskFromDashboard(Project& project);
void viewDashboard(Project& project);
void undoLastAction(Project& project);
void extendFirstTask(Project& project);
void stressTestDashboard(Project& project);

int main() {
    setvbuf(stdout, NULL, _IONBF, 0); 
    
    Project myProject("Chronos Core");
    int choice;

    do {
        cout << "\n======== DASHBOARD CHRONOS ========" << endl;
        cout << "1. Them nhiem vu" << endl;
        cout << "2. Xem danh sach nhiem vu" << endl;
        cout << "3. Hoan tac hanh dong" << endl;
        cout << "4. Gia han nhiem vu dau tien" << endl;
        cout << "5. Stress-test 10.000 tasks" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "====================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: addTaskFromDashboard(myProject); break;
            case 2: viewDashboard(myProject); break;
            case 3: undoLastAction(myProject); break;
            case 4: extendFirstTask(myProject); break;
            case 5: stressTestDashboard(myProject); break;
            case 0: cout << "\nChuong trinh ket thuc. Tam biet!" << endl; break;
            default: cout << "\n[Loi] Lua chon khong hop le, vui long nhap lai tu 0 den 5!" << endl;
        }
    } while (choice != 0);

    return 0;
}