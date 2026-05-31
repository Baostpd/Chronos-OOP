#include <iostream>
#include "Date.h"
#include "Task.h"

using namespace std;

int main() {
    cout << "===== TEST THANH VIEN 1: DATE & TASK =====" << endl;

    try {
        cout << "\n--- Test 1: Kiem tra Date hop le ---" << endl;

        Date d1(31, 12, 2026);
        cout << "Ngay ban dau: " << d1.toString() << endl;

        d1.advanceOneDay();
        cout << "Sau khi tang 1 ngay: " << d1.toString() << endl;

        cout << "\n--- Test 2: Tao Task hop le ---" << endl;

        Date start(1, 6, 2026);
        Date end(5, 6, 2026);

        Task task1("Lam module Date va Task", start, end, 3);
        task1.displayBasicInfo();

        cout << "\n--- Test 3: Demo loi Time Paradox ---" << endl;

        Date wrongStart(10, 6, 2026);
        Date wrongEnd(5, 6, 2026);

        Task task2("Task bi loi ngay thang", wrongStart, wrongEnd, 2);
        task2.displayBasicInfo();
    }
    catch (const invalid_argument& e) {
        cout << "\n[CATCH ERROR] " << e.what() << endl;
        cout << "He thong da chan loi ngay thang thanh cong!" << endl;
    }

    return 0;
}