#ifndef ECOMLOYALTYSYSTEM_H
#define ECOMLOYALTYSYSTEM_H

#include "User.h"
#include "LoyaltyProgram.h"
#include <unordered_map>
#include <string>


class EcomLoyaltySystem {
    private:
        std::unordered_map<std::string, User> users;

    public:
        void onboardUser(const std::string& userName);
        void purchase(const std::string& userName, double amount, double redeemPoints);
        void getUserStats(const std::string& userName);
};

#endif