#include <iostream>
#include <stdexcept>
#include "Date.h"
#include "Task.h"
#include "Project.h"

using namespace std;

int main() {
    // Ép Terminal xóa bộ đệm và in ra ngay lập tức
    setvbuf(stdout, NULL, _IONBF, 0); 

    cout << "====================================================" << endl;
    cout << "===== TEST THANH VIEN 2: UNDO STACK & STRESS-TEST =====" << endl;
    cout << "====================================================" << endl;

    Project myProject("Chronos Core");
    Date today(24, 6, 2026);
    Task t1("Thiet ke UI", today, today, 1);
    Task t2("Code Core OOP", today, today, 2);

    // ----------------------------------------------------------------------
    // TEST 1: KIỂM THỬ TÍNH NĂNG HOÀN TÁC (UNDO)
    // ----------------------------------------------------------------------
    cout << "\n--- Test 1: Tinh nang Hoan tac qua class Project ---" << endl;

    myProject.addTask(t1);
    cout << "[System] Da add task 1. So luong hien tai: " << myProject.getTaskCount() << endl;

    myProject.addTask(t2);
    cout << "[System] Da add task 2. So luong hien tai: " << myProject.getTaskCount() << endl;

    myProject.undo();
    cout << "-> So luong task sau khi goi undo(): " << myProject.getTaskCount() << endl;

    // ----------------------------------------------------------------------
    // TEST 2: STRESS-TEST 10.000 TASKS & BẮT NGOẠI LỆ OVERFLOW_ERROR
    // ----------------------------------------------------------------------
    cout << "\n--- Test 2: Stress-test 10.000 Tasks & Catch Overflow ---" << endl;
    cout << "[System] Chay vong lap nhet 10.000 tasks vao he thong..." << endl;

    try {
        for (int i = 1; i <= 10000; ++i) {
            // Truyền false để KHÔNG lưu lịch sử Undo trong lúc test tải nặng
            myProject.addTask(t1, false);

            if (i % 1000 == 0) {
                cout << "-> Da chen em xuoi " << i << " tasks..." << endl;
            }
        }
    } 
    catch (const overflow_error& e) {
        cout << "\n>>> [CATCH EXCEPTION SUCCESS] <<<" << endl;
        cout << "-> Tin nhan loi: " << e.what() << endl;
        cout << "-> He thong da ngan chan tran bo dem thanh cong!" << endl;
        cout << "-> So luong nhiem vu dung lai an toan o muc: " << myProject.getTaskCount() << endl;
    }
    catch (const exception& e) {
        cout << "-> Loi khac: " << e.what() << endl;
    }

    cout << "\n==========================================================" << endl;
    return 0;
}