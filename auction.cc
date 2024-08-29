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
