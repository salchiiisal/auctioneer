# Auctioneer

_salchiiisal_

Find the best price.

## Supported Auction Types

### English

Open ascending auction.
The buyers will start bidding with a low price, then the bid prices go up until there’s no more price bidding a higher price. The last person to bid, which is also the person who bids the highest price, will get the item. If the seller has a predetermined reserved price, we need to make sure the highest bid excesses the reserved price, or the item will not be sold to anyone.[^1]

### Dutch

Open descending auction.
The seller will initiate a high value and bidders will bid down from this high price. The bid price will go down until a bidder’s willing to take it.[^1]

### Vickrey[^2]

Sealed-bid second-price auction.
Bidders submit written bids without knowing the bids of the other people in the auction. The highest bidder wins but the price paid is the second-highest bid.

### Double

Buyers submit their bids and potential sellers submit their ask prices.
When a buyer’s price and a seller’s asking price match, and the trade proceeds at that price.

## Compilation

```
mkdir ./build
cd ./build
cmake ..; make;
```

[^1]: [Four Common Types of Auctions](https://blogs.cornell.edu/info2040/2021/11/29/four-common-types-of-auctions/)
[^2]: https://en.wikipedia.org/wiki/Vickrey_auction
