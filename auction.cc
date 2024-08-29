#include "auction.h"

Auction::Auction(AuctionId auction_id,
                 AuctionType auction_type,
                 std::string item,
                 Price starting_price,
                 Price reserve_price,
                 Price tick)
    : auction_id_{auction_id},
      auction_type_{auction_type},
      item_{std::move(item)},
      starting_price_{starting_price},
      reserve_price_{reserve_price},
      tick_{tick} {}

Auction::Auction(AuctionId auction_id, std::string item)
    : Auction(auction_id, AuctionType::English, item, 0.0, 0.0, 1.0) {}

AuctionId Auction::auction_id() const { return auction_id_; }
AuctionType Auction::type() const { return auction_type_; }
std::string_view Auction::item() const { return item_; }
Price Auction::starting_price() const { return starting_price_; }
Price Auction::reserve_price() const { return reserve_price_; }
Price Auction::tick() const { return tick_; }
Price Auction::current_highest_bid() const {
  return current_highest_bid_price_;
}
