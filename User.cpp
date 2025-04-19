#include "User.h"
#include <cmath>

User::User() : name(""), points(0), order_count(0), totalSpent(0), eligibleForDiscount(false) {}

User::User(const std::string& name)
    : name(name), points(0), order_count(0), totalSpent(0), eligibleForDiscount(false) {}

std::string User::getName() const {
    return name;
}

double User::getPoints() const {
    return points;
}

int User::getOrderCount() const {
    return order_count;
}

double User::getTotalSpent() const {
    return totalSpent;
}

UserLevel User::getCurrentLevel() const {
    if (points >= 1000) return UserLevel::Gold;
    if (points >= 500) return UserLevel::Silver;
    return UserLevel::Bronze;
}

bool User::canGetDiscount() const {
    return eligibleForDiscount;
}

void User::addPoints(double pts) {
    points += pts;
}

bool User::redeemPoints(double pts) {
    if (points >= pts) {
        points -= pts;
        return true;
    }
    return false;
}

void User::incrementOrders() {
    order_count++;
    if (order_count > 3 || totalSpent > 10000) {
        eligibleForDiscount = true;
    }
}

void User::addSpending(double amount) {
    totalSpent += amount;
}

void User::resetDiscountEligibility() {
    eligibleForDiscount = false;
    // error: need to reset order count and spend amount here
}