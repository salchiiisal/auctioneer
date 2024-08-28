#pragma once
#include <string>

#include "auction_type.h"
#include "bid.h"
#include "custom_types.h"

class Auction {
 public:
  explicit Auction(std::string item) : item_{std::move(item)} {}

 private:
  // structs
  struct BidEntry {
    // TODO:
  };

  // member variables
  AuctionId auction_id_;
  std::string item_{};
  AuctionType auction_type_;
  std::unordered_map<BidId, BidEntry> bids_;
};
