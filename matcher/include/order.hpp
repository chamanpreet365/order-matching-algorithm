#pragma once

#include <string>
#include <memory>
#include <vector>
#include "matcher.hpp"

enum class Side { BUY, SELL };
enum class OrderType { MARKET, LIMIT, CANCEL };

class Order {
public:
    std::string id;
    int quantity;
    double price;
    Side side;
    OrderType type;
    std::shared_ptr<MatchingStrategy> matcher;

    Order(std::string id, int qty, double pr, Side s, OrderType t,
          std::shared_ptr<MatchingStrategy> m);

    void match(std::vector<Order>& book);
};