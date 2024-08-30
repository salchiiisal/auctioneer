#pragma once
#include "auction.h"

class EnglishAuction : public Auction {
 public:
  Price AddBid(BidPointer bid) override;

 private:
};
