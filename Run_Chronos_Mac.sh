#!/bin/bash
echo "Dang bien dich du an Chronos... Vui long doi..."

# Bien dich
g++ -I include src/main.cpp src/Dashboard.cpp src/Date.cpp src/Task.cpp src/Project.cpp -o Chronos_App

# Kiem tra loi
if [ $? -ne 0 ]; then
    echo ""
    echo "[LOI] Bien dich that bai! Vui long kiem tra lai code."
    read -p "Nhan Enter de thoat..."
    exit 1
fi

# Xoa man hinh va chay
clear
./Chronos_App