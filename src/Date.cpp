#include "Date.h"
#include <sstream>
#include <iomanip>

// Constructor mặc định
Date::Date() {
    day = 1;
    month = 1;
    year = 2026;
}

// Constructor có tham số
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

// Kiểm tra năm nhuận
bool Date::isLeapYear() const {
    /*
        Năm nhuận:
        - Chia hết cho 400
        hoặc
        - Chia hết cho 4 nhưng không chia hết cho 100
    */
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Trả về số ngày trong tháng
int Date::daysInMonth() const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            return isLeapYear() ? 29 : 28;

        default:
            return 0; // Tháng không hợp lệ
    }
}

// Kiểm tra ngày hợp lệ
bool Date::isValid() const {
    if (year <= 0) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > daysInMonth()) {
        return false;
    }

    return true;
}

// Tăng ngày lên 1 ngày
void Date::advanceOneDay() {
    day++;

    // Nếu ngày vượt quá số ngày trong tháng
    if (day > daysInMonth()) {
        day = 1;
        month++;

        // Nếu tháng vượt quá 12
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// So sánh ngày hiện tại có trước ngày other không
bool Date::isBefore(const Date& other) const {
    if (year != other.year) {
        return year < other.year;
    }

    if (month != other.month) {
        return month < other.month;
    }

    return day < other.day;
}

// Chuyển ngày thành chuỗi dạng dd/mm/yyyy
std::string Date::toString() const {
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(2) << day << "/"
        << std::setw(2) << month << "/"
        << year;

    return oss.str();
}