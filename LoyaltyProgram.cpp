#include "LoyaltyProgram.h"
#include <cmath>

// Calculate points based on user's level and amount
double LoyaltyProgram::calculateEarnedPoints(UserLevel level, double amount) {
    double rate = 0;
    switch (level) {
        case UserLevel::Bronze: rate = 10; break;
        case UserLevel::Silver: rate = 12.5; break;
        case UserLevel::Gold:   rate = 15; break;
    }
    return floor((amount / 100) * rate * 10) / 10.0;  // round to 1 decimal
}

// Max % of order amount that can be paid with points
double LoyaltyProgram::getMaxRedeemable(UserLevel level, double purchaseAmount) {
    double percent = 0;
    switch (level) {
        case UserLevel::Bronze: percent = 0.05; break;
        case UserLevel::Silver: percent = 0.10; break;
        case UserLevel::Gold:   percent = 0.15; break;
    }
    return purchaseAmount * percent;
}

// Max absolute points that can be redeemed
double LoyaltyProgram::getMaxRedemptionLimit(UserLevel level) {
    switch (level) {
        case UserLevel::Bronze: return 200;
        case UserLevel::Silver: return 500;
        case UserLevel::Gold:   return 1000;
    }
    return 0;
}

// Apply discount based on history
double LoyaltyProgram::applyDiscount(User& user, double& payableAmount) {
    if (!user.canGetDiscount()) return 0;

    double discount = 0;
    if (user.getOrderCount() > 3 && user.getTotalSpent() > 10000)
        discount = 0.12;
    else if (user.getTotalSpent() > 10000)
        discount = 0.10;
    else if (user.getOrderCount() > 3)
        discount = 0.05;

    double discountAmount = payableAmount * discount;
    if (discountAmount > 5000) discountAmount = 5000;

    payableAmount -= discountAmount;
    user.resetDiscountEligibility();
    return discountAmount;
}