#include "engine.h"
#include "orderbook.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>

#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/list.hpp>


void init(){
    OB::OrderBook::get().initialize();
}

void destroy(){
    OB::OrderBook::get().shutdown();
}

t_orderid limit(t_order order){
    /* Process an incoming limit order 
     */
    return OB::OrderBook::get().limit(order);
}

void cancel(t_orderid orderid){
    /* Cancel an outstanding order
     */
    OB::OrderBook::get().cancel(orderid);
}
