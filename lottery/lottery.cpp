/*
 * lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: kylew
 */
#include "LAB2LOTTERY.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Customer makeCustomer(){
	Customer temp;
	temp.customerID = rand () % 1000 + 1; // random number between 1 and 1000
	temp.numOfTickets = rand () % 20 + 1; // random ticket numbers from 1 - 20
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
	temp.storeID = rand() % 100 + 1; // 1-100
	temp.numOfCustomers = rand() % 10 +1; //1-10
	Customer *customerList;
	customerList = new Customer[temp.numOfCustomers];
	temp.numOfSold = 0;

	temp.customerList=customerList;

	for(int i = 0; i < 	temp.numOfCustomers ;i++){
		temp.customerList[i] = makeCustomer().numOfTickets;
		temp.numOfSold += makeCustomer().numOfTickets;
	}
	//for
	return temp;
}// makeStore

Owner *makeOwner(){
	Owner *temp;

	temp->numOfStores =  rand()%10 + 1; // random num 1-10(including 10)
	Store *Stores;
	Stores=new Store[temp->numOfStores];
	temp->totalSold = 0;

	temp->stores=Stores;

	for (int i = 0 ; i < temp->numOfStores; i++){
		temp->stores[i] = makeStore().numOfCustomers;
		temp->totalSold += makeStore().numOfSold;
	}// for

	return temp;
}

void getWinners (int winners[]){
	int n1 = rand() % 10;
	int n2 = rand() % 10;
	int n3 = rand() % 10;
	winners[0] = n1;
	winners[1] = n2;
	winners[2] = n3;
}

int checkwin(int *nums, int *winners){
	int countwinnum=0;
	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			if (nums[i]==winners[j]){
				countwinnum +=1;
			}
		}
	}
	return countwinnum;

}
void findWinners(Owner *owner, int *ls){
	cout << "Total lottery tickets sold: "<<owner->totalSold<<endl;
	cout << "Winning numbers: "<< ls << endl;
	cout << "\tStores: "<< owner->stores<<endl;
}
