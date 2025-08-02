#include "../include/Utils.h"
#include "../include/transaction.h"
#include "../include/category.h"
#include "../include/financialManagement.h"

int main() {
    financialManagement manager;
    std::string filename = "transactions.csv";

    manager.loadFromFile(filename);

    int choice;
    do {
        std::cout << "\n==== Quan Ly Tai Chinh Ca Nhan ====\n";
        std::cout << "1. Them giao dich moi\n";
        std::cout << "2. Xem danh sach giao dich\n";
        std::cout << "3. Tinh tong so du\n";
        std::cout << "4. Luu vao file\n";
        std::cout << "0. Thoat\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                manager.addTransaction();
                break;
            case 2:
                manager.listTransactions();
                break;
            case 3:
                std::cout << "So du hien tai: " << manager.calculateBalance() << "\n";
                break;
            case 4:
                manager.savetoFile(filename);
                std::cout << "Da luu vao file " << filename << "\n";
                break;
            case 0:
                manager.savetoFile(filename);
                std::cout << "Tam biet!\n";
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
