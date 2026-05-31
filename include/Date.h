#ifndef DATE_H
#define DATE_H

#include <string>

struct Date {
    int day;
    int month;
    int year;

    // Constructor mặc định
    Date();

    // Constructor có tham số
    Date(int d, int m, int y);

    // Kiểm tra năm nhuận
    bool isLeapYear() const;

    // Trả về số ngày trong tháng hiện tại
    int daysInMonth() const;

    // Kiểm tra ngày có hợp lệ không
    bool isValid() const;

    // Tăng ngày lên 1 ngày
    void advanceOneDay();

    // Kiểm tra ngày hiện tại có trước ngày other không
    bool isBefore(const Date& other) const;

    // Chuyển ngày thành chuỗi để in ra màn hình
    std::string toString() const;
};

#endif