#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include "Date.h"
#include "Task.h"
#include "Project.h"

using namespace std;

void printMenu() {
    cout << "\n========================================\n";
    cout << "   HE THONG QUAN LY CONG VIEC CHRONOS\n";
    cout << "========================================\n";
    cout << "[1]. Quan ly Nhiem vu \n";
    cout << "[2]. Sap xep Du an \n";
    cout << "[3]. Hoan tac / Undo \n";
    cout << "[0]. Thoat\n";
    cout << "========================================\n";
    cout << "Lua chon: ";
}

void showTaskMenu() {
    cout << "\n----------- QUAN LY NHIEM VU -----------\n";
    cout << "[1]. Tao nhiem vu moi\n";
    cout << "[2]. Hien thi danh sach nhiem vu\n";
    cout << "[0]. Quay lai\n";
    cout << "----------------------------------------\n";
    cout << "Lua chon: ";
}

int main() {
    Project myProject("Chronos Project");

    int choice = -1;

    while (choice != 0) {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[LOI] Vui long nhap so hop le!\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            int taskChoice = -1;
            while (taskChoice != 0) {
                showTaskMenu();
                cin >> taskChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n[LOI] Vui long nhap so!\n";
                    continue;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (taskChoice) {
                case 1: {
                    string title;
                    int sd, sm, sy, ed, em, ey, priority;

                    cout << "\nTen nhiem vu: ";
                    getline(cin, title);

                    cout << "Ngay bat dau (dd mm yyyy): ";
                    cin >> sd >> sm >> sy;

                    cout << "Ngay ket thuc (dd mm yyyy): ";
                    cin >> ed >> em >> ey;

                    cout << "Do uu tien (1: Cao nhat): ";
                    cin >> priority;

                    // BỔ SUNG: Chặn lỗi văng chương trình nếu nhập chữ cái vào ngày tháng/ưu tiên
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n[LOI] Ban phai nhap so cho Ngay thang va Do uu tien! Vui long thu lai.\n";
                        break; // Thoát khỏi case 1, quay lại menu phụ
                    }

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    try {
                        Date start(sd, sm, sy);
                        Date end(ed, em, ey);
                        Task task(title, start, end, priority);

                        myProject.addTask(task); 
                        cout << "\n[Dashboard] Them nhiem vu vao du an thanh cong!\n";
                    }
                    catch (const invalid_argument& e) {
                        cout << "\n[LOI NGAY THANG] " << e.what() << endl;
                    }
                    catch (const overflow_error& e) {
                        cout << "\n[LOI BO DEM] " << e.what() << endl;
                    }
                    break;
                }

                case 2:
                    myProject.displayDashboard();
                    break;

                case 0:
                    break;

                default:
                    cout << "\nLua chon khong hop le!\n";
                }
            }
            break;
        }

        case 2:
            myProject.sortTasks();
            cout << "\n[Dashboard] Da sap xep xong nhiem vu! Ban co the chon Xem danh sach de kiem tra.\n";
            break;

        case 3:
            myProject.undo();
            break;

        case 0:
            cout << "\nTam biet!\n";
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
        }
    }

    return 0;
}