#pragma once

#include <vector>
#include "order.hpp"

class MatchingStrategy {
public:
    virtual void match(Order& order, std::vector<Order>& book) = 0;
    virtual ~MatchingStrategy() = default;
};


class BuyLimitMatch : public MatchingStrategy {
public:
    void match(Order& order, std::vector<Order>& book) override;
};

class BuyMarketMatch : public MatchingStrategy {
public:
    void match(Order& order, std::vector<Order>& book) override;
};

class SellLimitMatch : public MatchingStrategy {
public:
    void match(Order& order, std::vector<Order>& book) override;
};

class SellMarketMatch : public MatchingStrategy {
public:
    void match(Order& order, std::vector<Order>& book) override;
};
