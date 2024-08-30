#pragma once
#include <vector>

#include "auction.h"
#include "custom_types.h"

class AuctionHouse {
 public:
  AuctionHouse() = default;

 private:
  // functions

  // create new Auction
  void StartAuction();

  // end existing Auction
  Price EndAuction(AuctionId auction_id);

  // member variables
  std::unordered_map<AuctionId, AuctionPointer> active_auctions_;

  AuctionId next_auction_id_{1};
};
