#pragma once
#include "auction.h"

class DutchAuction : public Auction {
 public:
  Price AddBid(BidPointer bid) override;

  // getters & setters
  Price tick_size() const;
  Price decreasing_ticks_per_second() const;

 private:
  Price tick_size_;
  Price decreasing_ticks_per_second_;
};
