#include "EcomLoyaltySystem.h"
#include <iostream>
#include <string>

int main() {
    EcomLoyaltySystem system;
    bool running = true;

    while (running) {
        std::cout << "Menu\n";
        std::cout << "1. Onboard User\n";
        std::cout << "2. Make a Purchase\n";
        std::cout << "3. Get User Stats\n";
        std::cout << "4. Exit\n";
        std::cout << "Please choose an option (1-4): ";
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::cout << "Enter the name of the user: ";
                std::string name;
                std::getline(std::cin, name);
                system.onboardUser(name);
                break;
            }
            case 2: {
                std::cin.ignore();
                std::cout << "Enter the name of the user: ";
                std::string userName;
                std::getline(std::cin, userName);

                std::cout << "Enter purchase amount: ";
                double amount;
                std::cin >> amount;

                std::cout << "Enter points to redeem: ";
                double redeemPoints;
                std::cin >> redeemPoints;

                system.purchase(userName, amount, redeemPoints);
                break;
            }
            case 3: {
                std::cin.ignore();
                std::cout << "Enter the name of the user: ";
                std::string userName;
                std::getline(std::cin, userName);

                system.getUserStats(userName);
                break;
            }
            case 4: {
                std::cout << "Exiting the Loyalty Program..." << std::endl;
                running = false;
                break;
            }
            default:
                std::cout << "Invalid option. Please choose between 1 and 4." << std::endl;
        }
    }

    return 0;
}

