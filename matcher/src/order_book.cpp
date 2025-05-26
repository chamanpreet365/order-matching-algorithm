#include "order_book.hpp"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY) {
        buyOrders.push_back(order);
    } else {
        sellOrders.push_back(order);
    }
}

void OrderBook::processOrder(Order& order) {
    if (order.side == Side::SELL) {
        order.match(buyOrders); // Match buy order against sell book
    } else {
        order.match(sellOrders);    // Match sell order against buy book
    }
}
