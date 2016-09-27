/*
 * lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: kylew
 */
#include "LAB2LOTTERY.hpp"
#include <stdlib.h>
using namespace std;

Owner *makeOwner(){
	int a = rand() % 10 +1;
    Store x[];

    Owner totalsold = 0;
    for (int i = 0; i < Owner (*x)[makeStore()]; i ++){
           x[i] = makeStore();
           Store Numsold;
           totalsold += a * x[Numsold];
    }//for
    return x;
}

Store makeStore(){
	int Storeid = rand() % 100 + 1;
	int Customernum = rand() % 10 +1;

	Customer x[];
	Store Numsold;

	for(int i = 0; i < Store (*x)[makeCustomer()];i++){
		x[i] = makeCustomer();
	    Customer numtickets;
	    Numsold += Storeid * x[numtickets];
	}//for
	return Numsold;
}// makeStore


//Customer makeCustomer(){
//
//	return;
//}




