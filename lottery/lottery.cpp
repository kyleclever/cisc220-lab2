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
	int customerID = rand()%1000+1;
	int numOfTickets = rand()%20+0;
	temp.numOfTickets = numOfTickets;
	int **lotteryNum = new int *[temp.numOfTickets];

	for(int i =0; i<temp.numOfTickets; i++){
		lotteryNum[i]= new int[3];
	               }// for

    for(int i =0; i<temp.numOfTickets;i++){
    	int r1=rand()%9+0;
        int r2=rand()%9+0;
        int r3=rand()%9+0;
        while (r2==r1 || r3==r2 || r3==r1){
            r2=rand()%9+0;
            r3=rand()%9+0;	// r1, r2, r3, must be different
        }
        lotteryNum[i][0]=r1;
        lotteryNum[i][1]=r2;
        lotteryNum[i][2]=r3;
    }
    temp.customerID=customerID;
    temp.lotterynums=*lotteryNum;
	return temp;
}

Store makeStore(){
	Store temp;

	int storeID = rand() % 100 + 1; // 1-100
	int numOfCustomers = rand() % 10 +1; //1-10

	//Customer *customerlist = new Customer[numOfCustomers];
	int customerlist[numOfCustomers];

	int numOfSold = 0;

	for(int i = 0; i < 	numOfCustomers ;i++){
		customerlist[i] = makeCustomer().numOfTickets;
		numOfSold += makeCustomer().numOfTickets;
	}
	//for
	temp.storeID= storeID;
	temp.numOfSold = numOfSold;
	temp.customerList = customerlist;
	temp.numOfCustomers = numOfCustomers;
	return temp;
}// makeStore

Owner *makeOwner(){
	Owner *temp = new Owner();
	int NumStores = rand() % 10 +1;
	//Store *stores = new Store[NumStores]; // random num 1-10(including 10)
	int totalsold = 0;

	int Stores[NumStores];


	for (int i = 0 ; i < NumStores; i++){
		Stores[i] = makeStore().numOfSold;
		totalsold += makeStore().numOfSold;
	}// for

	temp-> stores = Stores;
	temp->totalSold=totalsold;
	temp->numOfStores=NumStores;

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

	cout << "Winning numbers: ";
	for (int j=0;  j<3; j++){
		cout << ls[j];
	}//
	cout << endl;
	cout << "\tStores: "<< owner->numOfStores<<endl;
}
