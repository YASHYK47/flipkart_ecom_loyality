#include "EcomLoyaltySystem.h"
#include <iostream>
#include <iomanip>


void EcomLoyaltySystem::onboardUser(const std::string& user_name) {
    if(user_name.empty()){
        std::cout << "User name cannot be null" << std::endl;
        return;
    }

    if (users.count(user_name)) {
        std::cout << "User already exists." << std::endl;
        return;
    }
    users[user_name] = User(user_name);
    std::cout << user_name << " onboarded successfully." << std::endl;
}


void EcomLoyaltySystem::purchase(const std::string& userName, double amount, double redeemPoints) {
    if (!users.count(userName)) {
        std::cout << "User not found." << std::endl;
        return;
    }
    User& user = users[userName];
    UserLevel level = user.getCurrentLevel();

    double max_redeemable_by_percent = LoyaltyProgram::getMaxRedeemable(level, amount);
    double max_redeemable_by_limit = LoyaltyProgram::getMaxRedemptionLimit(level);
    double allowed_redemption = std::min(max_redeemable_by_percent, max_redeemable_by_limit);

    if (redeemPoints > allowed_redemption || redeemPoints > user.getPoints()) {
        std::cout << "Purchase Failed. Not enough points to redeem." << std::endl;
        return;
    }

    bool redeemed = user.redeemPoints(redeemPoints);
    double remainingAmount = amount - (redeemed ? redeemPoints : 0);

    double discount = LoyaltyProgram::applyDiscount(user, remainingAmount);
    double earnedPoints = LoyaltyProgram::calculateEarnedPoints(level, remainingAmount);

    user.addPoints(earnedPoints);
    user.addSpending(amount);
    user.incrementOrders();

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Purchase successful. Points redeemed: " << (redeemed ? redeemPoints : 0)
              << ". Points added: " << earnedPoints
              << ". Discount applied: \u20B9" << discount
              << ". Total payable amount: " << remainingAmount
              << ". Current points: " << user.getPoints()
              << ". Current level: ";

    switch (user.getCurrentLevel()) {
        case UserLevel::Bronze: std::cout << "Bronze"; break;
        case UserLevel::Silver: std::cout << "Silver"; break;
        case UserLevel::Gold:   std::cout << "Gold"; break;
    }
    std::cout << "\norders count : " << user.getOrderCount() << std::endl;
}


void EcomLoyaltySystem::getUserStats(const std::string& userName) {
    if (!users.count(userName)) {
        std::cout << "User not found." << std::endl;
        return;
    }
    User& user = users[userName];
    std::cout << std::fixed << std::setprecision(1);
    std::cout << user.getName() << " has " << user.getPoints() << " points. Current level: ";
    switch (user.getCurrentLevel()) {
        case UserLevel::Bronze: std::cout << "Bronze"; break;
        case UserLevel::Silver: std::cout << "Silver"; break;
        case UserLevel::Gold:   std::cout << "Gold"; break;
    }
    std::cout << "." << std::endl;
}