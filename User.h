#ifndef USER_H
#define USER_H

#include<string>

enum class UserLevel {
    Bronze,
    Silver,
    Gold
};

class User {
    private:
        std::string name;
        double points;
        int order_count;
        double totalSpent;
        bool eligibleForDiscount;

    public:
        User();
        User(const std::string& name);

        std::string getName() const;
        double getPoints() const;
        int getOrderCount() const;
        double getTotalSpent() const;
        UserLevel getCurrentLevel() const;
        bool canGetDiscount() const;

        void addPoints(double pts);
        bool redeemPoints(double pts);
        void incrementOrders();
        void addSpending(double amount);
        void resetDiscountEligibility();
};


#endif

