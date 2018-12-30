#pragma once

#include <array>
#include <cstdint>
#include <limits>

#include <boost/serialization/strong_typedef.hpp>


// Prices are just unsigned shorts
// Unsigned because prices could not be negative
typedef unsigned short t_price;

namespace OB {
    constexpr t_price kMaxPrice = std::numeric_limits<t_price>::max();
    constexpr int kMaxNumOrders = 101000;
    constexpr t_price kMinPrice = 1;
    constexpr uint32_t kMaxLiveOrders = std::numeric_limits<t_price>::max();
    constexpr size_t kFieldLength = 4;
}


typedef std::array<char, OB::kFieldLength> Field;
typedef unsigned long t_orderid;

/* Price
   0-65536 interpreted as divided by 100
   eg the range is 000.00-655.36
   eg the price 123.45 = 12345
   eg the price 23.45 = 2345
   eg the price 23.4 = 2340 */

/* Order Size */
typedef unsigned long t_size;

/* Side
   Ask=1, Bid=0 */
typedef int t_side;
inline int is_ask(t_side side) { return side; }

/* Limit Order */
typedef struct {
  Field symbol;
  Field trader;
  t_side side;
  t_price price;
  t_size size;
} t_order;

/* Execution Report
   send one per opposite-sided order
   completely filled */
typedef t_order t_execution;

