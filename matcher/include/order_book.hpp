#pragma once

#include <vector>
#include "order.hpp"

class OrderBook {
public:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;

    void addOrder(const Order& order);
    void processOrder(Order& order);
};
