#include "order.hpp"

Order::Order(std::string id, int qty, double pr, Side s, OrderType t,
             std::shared_ptr<MatchingStrategy> m)
    : id(std::move(id)), quantity(qty), price(pr), side(s), type(t), matcher(std::move(m)) {}

void Order::match(std::vector<Order>& book) {
    matcher->match(*this, book);
}
