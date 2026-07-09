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
    Date future1(25, 6, 2026);
    Date future2(26, 6, 2026);
    Date future3(27, 6, 2026);
    
    // Tạo các task với tên khác nhau
    Task t1("Thiet ke UI", today, future1, 1);
    Task t2("Code Core OOP", today, future2, 2);
    Task t3("Test he thong", today, future3, 3);
    Task t4("Viet tai lieu", today, future1, 1);

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

    // =========================================================================
    // THÊM MỚI: TEST CÁC CHỨC NĂNG GIA HẠN CỦA THÀNH VIÊN 2
    // =========================================================================
    
    // Xóa project cũ và tạo mới để test sạch sẽ
    cout << "\n==========================================================" << endl;
    cout << "===== TEST MOI: GIA HAN NHIEM VU THEO TEN & THU TU =====" << endl;
    cout << "==========================================================" << endl;
    
    Project testProject("Test Project");
    
    // Thêm các task mới
    cout << "\n--- Tao cac nhiem vu mau ---" << endl;
    testProject.addTask(Task("Hoan thanh bao cao", Date(1, 1, 2026), Date(10, 1, 2026), 2));
    testProject.addTask(Task("Thuyet trinh du an", Date(5, 1, 2026), Date(15, 1, 2026), 1));
    testProject.addTask(Task("Gui email khach hang", Date(10, 1, 2026), Date(20, 1, 2026), 3));
    testProject.addTask(Task("Nop tai lieu", Date(1, 1, 2026), Date(12, 1, 2026), 2));
    
    cout << "Da tao 4 nhiem vu mau!" << endl;
    
    // Hiển thị danh sách ban đầu
    cout << "\n--- DANH SACH BAN DAU ---" << endl;
    Task::displayAllTasks();
    
    // ----------------------------------------------------------------------
    // TEST 3: GIA HẠN THEO TÊN
    // ----------------------------------------------------------------------
    cout << "\n--- Test 3: Gia han nhiem vu theo TEN ---" << endl;
    
    // Hiển thị deadline trước khi gia hạn
    cout << "[Truoc khi gia han] Deadline cua 'Thuyet trinh du an': ";
    for (Task* task : testProject.getTaskList()) {
        if (task->getTitle() == "Thuyet trinh du an") {
            cout << task->getEndDate().toString() << endl;
            break;
        }
    }
    
    // Gia hạn theo tên
    cout << "\n-> Goi Task::extendTaskByName(\"Thuyet trinh du an\")" << endl;
    bool result1 = Task::extendTaskByName("Thuyet trinh du an");
    cout << "-> Ket qua: " << (result1 ? "THANH CONG" : "THAT BAI") << endl;
    
    // Hiển thị deadline sau khi gia hạn
    cout << "[Sau khi gia han] Deadline cua 'Thuyet trinh du an': ";
    for (Task* task : testProject.getTaskList()) {
        if (task->getTitle() == "Thuyet trinh du an") {
            cout << task->getEndDate().toString() << endl;
            break;
        }
    }
    
    // Thử gia hạn task không tồn tại
    cout << "\n-> Goi Task::extendTaskByName(\"Task khong ton tai\")" << endl;
    bool result2 = Task::extendTaskByName("Task khong ton tai");
    cout << "-> Ket qua: " << (result2 ? "THANH CONG" : "THAT BAI") << endl;
    
    // ----------------------------------------------------------------------
    // TEST 4: GIA HẠN THEO THỨ TỰ
    // ----------------------------------------------------------------------
    cout << "\n--- Test 4: Gia han nhiem vu theo THU TU ---" << endl;
    
    // Hiển thị danh sách hiện tại
    Task::displayAllTasks();
    
    // Gia hạn task đầu tiên (index 0)
    cout << "\n-> Goi Task::extendTaskByIndex(0) - Gia han task dau tien" << endl;
    cout << "[Truoc khi gia han] Deadline task 1: ";
    if (testProject.getTaskCount() > 0) {
        cout << testProject.getTaskList()[0].getEndDate().toString() << endl;
    }
    
    bool result3 = Task::extendTaskByIndex(0);
    cout << "-> Ket qua: " << (result3 ? "THANH CONG" : "THAT BAI") << endl;
    
    cout << "[Sau khi gia han] Deadline task 1: ";
    if (testProject.getTaskCount() > 0) {
        cout << testProject.getTaskList()[0].getEndDate().toString() << endl;
    }
    
    // Gia hạn task thứ 3 (index 2)
    cout << "\n-> Goi Task::extendTaskByIndex(2) - Gia han task thu 3" << endl;
    cout << "[Truoc khi gia han] Deadline task 3: ";
    if (testProject.getTaskCount() > 2) {
        cout << testProject.getTaskList()[2].getEndDate().toString() << endl;
    }
    
    bool result4 = Task::extendTaskByIndex(2);
    cout << "-> Ket qua: " << (result4 ? "THANH CONG" : "THAT BAI") << endl;
    
    cout << "[Sau khi gia han] Deadline task 3: ";
    if (testProject.getTaskCount() > 2) {
        cout << testProject.getTaskList()[2].getEndDate().toString() << endl;
    }
    
    // Thử gia hạn với index không hợp lệ
    cout << "\n-> Goi Task::extendTaskByIndex(99) - Index khong hop le" << endl;
    bool result5 = Task::extendTaskByIndex(99);
    cout << "-> Ket qua: " << (result5 ? "THANH CONG" : "THAT BAI") << endl;
    
    // ----------------------------------------------------------------------
    // TEST 5: HIỂN THỊ DANH SÁCH SAU KHI GIA HẠN
    // ----------------------------------------------------------------------
    cout << "\n--- Test 5: Hien thi danh sach sau khi gia han ---" << endl;
    Task::displayAllTasks();
    
    // ----------------------------------------------------------------------
    // TEST 6: KIỂM TRA TOÁN TỬ ++ TRÊN TASK CỤ THỂ
    // ----------------------------------------------------------------------
    cout << "\n--- Test 6: Kiem tra toan tu ++ tren task cu the ---" << endl;
    
    // Lấy task đầu tiên và gia hạn bằng toán tử ++
    if (testProject.getTaskCount() > 0) {
        Task& firstTask = testProject.getTaskList()[0];
        cout << "[Truoc khi ++] Deadline: " << firstTask.getEndDate().toString() << endl;
        
        ++firstTask;  // Gọi toán tử ++
        
        cout << "[Sau khi ++] Deadline: " << firstTask.getEndDate().toString() << endl;
        cout << "-> Toan tu ++ da hoat dong thanh cong!" << endl;
    }
    
    // Hiển thị danh sách cuối cùng
    cout << "\n--- DANH SACH CUOI CUNG ---" << endl;
    Task::displayAllTasks();

    cout << "\n==========================================================" << endl;
    cout << "===== KET THUC TEST THANH VIEN 2 =====" << endl;
    cout << "==========================================================" << endl;
    
    return 0;
}