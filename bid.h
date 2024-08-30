#pragma once
#include <list>

#include "custom_types.h"

class Bid {
 public:
  Bid(BidId id, UserId user_id, Price price);

  // getters & setters
  BidId id() const;
  UserId user_id() const;
  Price price() const;

 private:
  BidId id_;
  UserId user_id_;
  Price price_;
};

using BidPointer = std::shared_ptr<Bid>;
using BidPointers = std::list<Bid>;
