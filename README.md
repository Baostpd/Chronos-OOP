# Chronos-OOP
C++ OOP midterm project - Chronos personal task manager
# Chronos-OOP
C++ OOP midterm project - Chronos personal task manager


# Chronos-OOP

## 1. Giới thiệu đề tài

Chronos là chương trình quản lý nhiệm vụ và thời hạn cá nhân được xây dựng bằng ngôn ngữ C++ theo hướng lập trình hướng đối tượng OOP.

Chương trình chạy trên giao diện dòng lệnh CLI, cho phép người dùng quản lý danh sách nhiệm vụ, deadline, mức độ ưu tiên, điểm khẩn cấp, gia hạn deadline, hoàn tác thao tác và mô phỏng một số tình huống lỗi bằng cơ chế `try-catch`.

Đề tài được thực hiện cho đồ án giữa kỳ môn Lập trình hướng đối tượng C++.

---

## 2. Mục tiêu chương trình

Mục tiêu của hệ thống Chronos là:

* Quản lý các nhiệm vụ cá nhân.
* Lưu ngày bắt đầu và ngày kết thúc của nhiệm vụ.
* Kiểm tra deadline hợp lệ.
* Sắp xếp nhiệm vụ theo deadline và độ ưu tiên.
* Hỗ trợ gia hạn deadline.
* Hỗ trợ hoàn tác thao tác gần nhất.
* Minh họa xử lý ngoại lệ trong C++.
* Thể hiện các tính chất OOP như đóng gói, trừu tượng hóa và nạp chồng toán tử.

---

## 3. Phân công thành viên

### Thành viên 1: Core Data & Logic

Phụ trách:

* Xây dựng `struct Date`.
* Xây dựng `class Task` cơ bản.
* Viết constructor, getter, setter cho Task.
* Kiểm tra ngày hợp lệ.
* Xử lý lỗi Time Paradox bằng `std::invalid_argument`.
* Viết file test riêng `main_test_member1.cpp`.

### Thành viên 2: OOP & Sắp xếp

Phụ trách:

* Xây dựng `class Project`.
* Quản lý danh sách `vector<Task>`.
* Nạp chồng toán tử `<`.
* Nạp chồng toán tử `++`.
* Tính điểm khẩn cấp.
* Sắp xếp nhiệm vụ.

### Thành viên 3: Undo & Stress-test

Phụ trách:

* Xây dựng tính năng Undo bằng `stack<vector<Task>>`.
* Viết stress-test thêm 10.000 nhiệm vụ.
* Mô phỏng lỗi Buffer Overflow bằng `std::overflow_error`.

### Thành viên 4: CLI & Tích hợp

Phụ trách:

* Xây dựng menu CLI.
* Hiển thị dashboard dạng bảng.
* Tích hợp code của các thành viên.
* Chuẩn bị video demo.
