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
int checkwin(int *nums, int *winners);

Customer makeCustomer(){
	Customer temp;
	int customerID = rand()%1000+1;
	int num_tickets = rand()%20+0;
	temp.numOfTickets = num_tickets;
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

	Customer *customerlist = new Customer[numOfCustomers];

	int numOfSold = 0;

	for(int i = 0; i < 	numOfCustomers ;i++){
		customerlist[i] = makeCustomer();
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

	Store *stores = new Store[NumStores]; // random num 1-10(including 10)
	int totalsold = 0;


	for (int i = 0 ; i < NumStores; i++){
		stores[i]=makeStore();
		totalsold += makeStore().numOfSold;
	}// for

	temp-> stores = stores;
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


	owner->totalWinners[0]=0;
	owner->totalWinners[1]=0;
	owner->totalWinners[2]=0;

	for (int i = 0; i < owner->numOfStores; i++){
		cout << "store: "<< owner->stores[i].storeID<<endl;

		owner->stores[i].numOfWinners[0]=0;
		owner->stores[i].numOfWinners[1]=0;
		owner->stores[i].numOfWinners[2]=0;

		for (int j = 0; j < owner->stores[i].numOfCustomers; j++){
			cout <<"\tcustomer: "<< owner->stores[i].customerList[j].customerID << endl;

			for (int k = 0; k < owner->stores[i].customerList[j].numOfTickets; k++){

				 int matched = checkwin(owner->stores[i].customerList[j].lotterynums[k], ls);

				 if(matched ==1){
					 cout<<"ticket: ";
				     for (int l =0;l<3;l++){
				    	 cout<<owner->stores[i].customerList[j].lotterynums[k][l];
				     }//for
				     cout<<" matched "<<matched<<endl;
				     owner->totalWinners[0]+=1;
				     owner->stores[i].numOfWinners[0]+=1;
				 }//if
				 else if (matched == 2){
					 cout<<"ticket: ";
				     for (int m =0; m<3;m++){
				    	cout<<owner->stores[i].customerList[j].lotterynums[k][m];
				     }//for
				     cout<<" matched "<<matched<<endl;
				     owner->totalWinners[1]+=1;
				     owner->stores[i].numOfWinners[1]+=1;
				 }// else if
	             else if (matched ==3){
					 cout<<"ticket: ";
				     for (int n =0;n<3;n++){
				    	cout<<owner->stores[i].customerList[j].lotterynums[k][n];
				     }//for
				     cout<<" match "<<matched<<endl;
				     owner->totalWinners[2]+=1;
				     owner->stores[i].numOfWinners[2]+=1;
	             } // else if

				}// for tickets
			}// for -id
//		cout<<"Total count for store: "<<owner->stores[i].storeID <<"Winners"<<owner->Stores[j].Customerlist[k]\
//				<<"win nums"<<owner->Stores[j].Customerlist[k].lotterynums[m]<<endl;
//
		}// for -stores

		cout << "" << endl;
//		cout<<"total 1 number win: "<<owner->totalWinners[0]<<endl;
//		cout<<"total 2 number win: "<<owner->totalWinners[1]<<endl;
//		cout<<"total 3 number win: "<<owner->totalWinners[2]<<endl;
} //findWinners
