#pragma once
#include <string>

#include "bid.h"
#include "custom_types.h"

// abstract base class for Auctions
class Auction {
 public:
  Auction(AuctionId auction_id,
          std::string item,
          Price starting_price,
          Price reserve_price);

  // functions
  // auction

  // Returns the current highest bid price post bid
  // and adds the bid to list of bids
  virtual Price AddBid(BidPointer bid) = 0;

  // getters & setters
  AuctionId auction_id() const;
  std::string_view item() const;
  Price starting_price() const;
  Price reserve_price() const;
  Price current_highest_bid() const;

 protected:
  // structs
  struct BidEntry {
    BidPointer bid{nullptr};
    BidPointers::iterator location;
  };

  // member variables
  AuctionId auction_id_;
  std::string item_;
  Price starting_price_;
  Price reserve_price_;
  Price current_highest_bid_price_{0.0};

  std::unordered_map<BidId, BidEntry> bids_;
};

using AuctionPointer = std::shared_ptr<Auction>;
