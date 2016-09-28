/*
 * lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: kylew
 */
#include "LAB2LOTTERY.hpp"
#include <stdlib.h>
using namespace std;

Customer makeCustomer(){
	Customer temp;
	temp.customerID = rand () % 999 + 1; // random number between 1 and 1000
	temp.numOfTickets = rand () % 19 + 1; // random ticket numbers from 1 - 20
	int ticketArray[temp.numOfTickets][3];

	for(int i = 0; i< temp.numOfTickets;i++){
		do{

		for(int k=0;k<3;k++){
			int lotterynums = rand()% 9+0;
			ticketArray[i][k]=lotterynums;}//for

		}while
			(ticketArray[i][0]==ticketArray[i][1] ||ticketArray[i][0]==ticketArray[i][2] \
					||ticketArray[i][1]==ticketArray[i][2] ); //do while
	}//for

	return temp;
}
Store makeStore(){
	Store temp;
	temp.storeID = rand() % 99 + 1; // 1-100
	temp.numOfCustomers = rand() % 9 +1; //1-10
	temp.customerList[temp.numOfCustomers];
	temp.numOfSold = 0;

	for(int i = 0; i < 	temp.numOfCustomers ;i++){
		temp.customerList[i] = makeCustomer().numOfTickets;
		temp.numOfSold += makeCustomer().numOfTickets;
	}
	//for
	return temp;
}// makeStore


//Owner *makeOwner(){
//	int a = rand() % 10 +1;
//    Store x[];
//
//    Owner totalsold = 0;
//    for (int i = 0; i < Owner (*x)[makeStore()]; i ++){
//           x[i] = makeStore();
//           Store Numsold;
//           totalsold += a * x[Numsold];
//    }//for
//    return x;
//}





