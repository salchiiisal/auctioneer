#include "bid.h"
Bid::Bid(BidId id, UserId user_id, Price price)
    : id_{id}, user_id_{user_id}, price_{price} {}

BidId Bid::id() const { return id_; }
UserId Bid::user_id() const { return user_id_; }
Price Bid::price() const { return price_; }
