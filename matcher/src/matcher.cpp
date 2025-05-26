#include "matcher.hpp"
#include <iostream>

void BuyLimitMatch::match(Order& order, std::vector<Order>& book) {
    std::cout << "Matching Buy Limit Order: " << order.id << std::endl;
    // Matching logic goes here
}

void BuyMarketMatch::match(Order& order, std::vector<Order>& book) {
    std::cout << "Matching Buy Market Order: " << order.id << std::endl;
    // Matching logic goes here
}

void SellLimitMatch::match(Order& order, std::vector<Order>& book) {
    std::cout << "Matching Sell Limit Order: " << order.id << std::endl;
    // Matching logic goes here
}

void SellMarketMatch::match(Order& order, std::vector<Order>& book) {
    std::cout << "Matching Sell Market Order: " << order.id << std::endl;
    // Matching logic goes here
}
