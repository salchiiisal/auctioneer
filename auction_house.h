#pragma once
#include <vector>

#include "custom_types.h"

class AuctionHouse {
 public:
  AuctionHouse() = default;

 private:
  // custom structs

  // functions

  // member variables
  std::unordered_map<AuctionId, AuctionEntry> auctions_;
};
