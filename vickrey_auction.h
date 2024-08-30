#pragma once
#include <chrono>

#include "auction.h"

class VickreyAuction : public Auction {
 public:
  Price AddBid(BidPointer bid) override;

 private:
  std::chrono::system_clock::time_point deadline;
};
