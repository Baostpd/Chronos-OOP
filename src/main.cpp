#include <iostream>
#include "Date.h"
#include "Task.h"
#include "Project.h"
using namespace std;

int main() {
    cout << "=========================================================" << endl;
    cout << "    HE THONG QUAN LY CONG VIEC CHRONOS - OOP DEMO        " << endl;
    cout << "=========================================================" << endl;

    // 1. Tạo một dự án mẫu
    Project myProject("Do an Co so nganh");

    // 2. Tạo các Task hợp lệ và đưa vào danh sách
    try {
        Date s1(1, 6, 2026), e1(15, 6, 2026);
        Date s2(1, 6, 2026), e2(5, 6, 2026);  // Hạn ngắn hơn -> Khẩn cấp hơn
        Date s3(2, 6, 2026), e3(20, 6, 2026); // Hạn dài nhất

        Task t1("Thanh vien 1: Lam phan Date & Task Base", s1, e1, 2);
        Task t2("Thanh vien 2: Tinh diem khan cap & Sort", s2, e2, 1); // Priority 1 (Cao)
        Task t3("Thanh vien Khac: Code chuc nang phu", s3, e3, 3);

        // PHẢI CÓ CÁC DÒNG NÀY ĐỂ NẠP TASK VÀO PROJECT
        myProject.addTask(t1);
        myProject.addTask(t2);
        myProject.addTask(t3);

        cout << "\n>>> DANH SACH TASK BAN DAU:" << endl;
        myProject.displayDashboard();

        // 3. Gọi tính năng SẮP XẾP TỰ ĐỘNG của Thành viên 2
        myProject.sortTasks();

        cout << "\n>>> DANH SACH TASK SAU KHI SAP XEP (THANH VIEN 2):" << endl;
        cout << "(* He thong tu dong dua Task co han ngan hon va Priority cao hon len truoc)" << endl;
        myProject.displayDashboard();

    } catch (const invalid_argument& e) {
        cout << "\n[LOI HE THONG]: " << e.what() << endl;
    }

    return 0;
}