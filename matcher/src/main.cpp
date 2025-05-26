#include <iostream>
#include "order.hpp"
#include "order_book.hpp"
#include "matcher.hpp"

// Factory to create orders with appropriate matching strategies
class OrderFactory {
public:
    static Order create(const std::string& id, int qty, double pr,
                        Side side, OrderType type) {
        std::shared_ptr<MatchingStrategy> strategy;

        if (side == Side::BUY && type == OrderType::MARKET) {
            strategy = std::make_shared<BuyMarketMatch>();
        } else if (side == Side::BUY && type == OrderType::LIMIT) {
            strategy = std::make_shared<BuyLimitMatch>();
        } else if (side == Side::SELL && type == OrderType::MARKET) {
            strategy = std::make_shared<SellMarketMatch>();
        } else if (side == Side::SELL && type == OrderType::LIMIT) {
            strategy = std::make_shared<SellLimitMatch>();
        } else {
            throw std::invalid_argument("Invalid side or order type");
        }

        return Order(id, qty, pr, side, type, strategy);
    }
};

int main() {
    OrderBook orderBook;
    
    orderBook.addOrder(OrderFactory::create("ORD001", 200, 20.20, Side::BUY, OrderType::LIMIT));
    orderBook.addOrder(OrderFactory::create("ORD002", 100, 20.25, Side::SELL, OrderType::LIMIT));
    orderBook.addOrder(OrderFactory::create("ORD003", 100, 20.30, Side::SELL, OrderType::LIMIT));
    orderBook.addOrder(OrderFactory::create("ORD004", 100, 20.15, Side::BUY, OrderType::LIMIT));
    orderBook.addOrder(OrderFactory::create("ORD005", 200, 20.15, Side::BUY, OrderType::LIMIT));
    orderBook.addOrder(OrderFactory::create("ORD006", 200, 20.30, Side::SELL, OrderType::LIMIT));


    return 0;
}
