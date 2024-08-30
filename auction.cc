#include "auction.h"

Auction::Auction(AuctionId auction_id,
                 std::string item,
                 Price starting_price,
                 Price reserve_price)
    : auction_id_{auction_id},
      item_{std::move(item)},
      starting_price_{starting_price},
      reserve_price_{reserve_price} {}

AuctionId Auction::auction_id() const { return auction_id_; }
std::string_view Auction::item() const { return item_; }
Price Auction::starting_price() const { return starting_price_; }
Price Auction::reserve_price() const { return reserve_price_; }
Price Auction::current_highest_bid() const {
  return current_highest_bid_price_;
}
