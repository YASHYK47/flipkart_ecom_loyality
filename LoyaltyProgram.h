#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H

#include "User.h"

class LoyaltyProgram {
    public:
        static double calculateEarnedPoints(UserLevel level, double amountAfterRedemption);
        static double getMaxRedeemable(UserLevel level, double purchaseAmount);
        static double getMaxRedemptionLimit(UserLevel level);
        static double applyDiscount(User& user, double& payableAmount);
};

#endif 