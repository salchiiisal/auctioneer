#pragma once
#include <string>

#include "auction_type.h"
#include "bid.h"
#include "custom_types.h"

class Auction {
 public:
  Auction(AuctionId auction_id,
          AuctionType auction_type,
          std::string item,
          Price starting_price,
          Price reserve_price,
          Price tick);

  Auction(AuctionId auction_id, std::string item);

  // getters & setters
  AuctionId auction_id() const;
  AuctionType type() const;
  std::string_view item() const;
  Price starting_price() const;
  Price reserve_price() const;
  Price tick() const;
  Price current_highest_bid() const;

 private:
  // member variables
  AuctionId auction_id_;
  AuctionType auction_type_;
  std::string item_{};
  Price starting_price_;
  Price reserve_price_;
  Price tick_;
  Price current_highest_bid_price_{0.0};

  std::vector<Bid> bids_;
};

using AuctionPointer = std::unique_ptr<Auction>;
