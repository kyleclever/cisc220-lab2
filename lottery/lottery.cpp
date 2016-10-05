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

	temp.lotterynums = new int *[temp.numOfTickets];

	for(int i =0; i<temp.numOfTickets; i++){
		temp.lotterynums[i]= new int[3];
	               }// for

	int a = 0;
	int b = 0;
	int c = 0;

    for(int j =0; j<temp.numOfTickets;j++){
    	do{
    		 a=rand()%9+0;
    		 b=rand()%9+0;
    		 c=rand()%9+0;

    	} while ( a==  b || a==c || b==c); // r1, r2, r3, must be different

    	temp.lotterynums[j][0]=a;
    	temp.lotterynums[j][1]=b;
    	temp.lotterynums[j][2]=c;
    }

    temp.customerID=customerID;
    //temp.lotterynums=*lotteryNums;

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
		cout << "\nstore: "<< owner->stores[i].storeID<<endl;

		owner->stores[i].numOfWinners[0]=0;
		owner->stores[i].numOfWinners[1]=0;
		owner->stores[i].numOfWinners[2]=0;

		for (int j = 0; j < owner->stores[i].numOfCustomers; j++){
			cout <<"\tcustomer: "<< owner->stores[i].customerList[j].customerID << endl;

			for (int k = 0; k < owner->stores[i].customerList[j].numOfTickets; k++){

				//int p = owner->stores[i].customerList[j].lotterynums[k][0];
				int matched = checkwin(owner->stores[i].customerList[j].lotterynums[k], ls);


				if(matched ==1){
					 cout<<"\t\tticket: ";
					 //int *b= &p[k];
				     for (int l =0;l<3;l++){
				    	 cout<< owner->stores[i].customerList[j].lotterynums[k][l];
				    	 //cout << b[l];
				    }//for
				     cout<<" matched "<<matched<<endl;
				     owner->totalWinners[0]+=1;
				     owner->stores[i].numOfWinners[0]+=1;
				 }//if
				 else if (matched == 2){
					 //int *b= &p[k];
					 cout<<"\t\tticket: ";
				     for (int m =0; m<3;m++){
				    	 cout<< owner->stores[i].customerList[j].lotterynums[k][m];
				    	 //cout<< p[m];
				    	// cout << b[m];
				     }//for
				     cout<<" matched "<<matched<<endl;
				     owner->totalWinners[1]+=1;
				     owner->stores[i].numOfWinners[1]+=1;
				 }// else if
	             else if (matched ==3){
	            	// int *b= &p[k];
					 cout<<"\t\tticket: ";
				     for (int n =0;n<3;n++){
				    	 //cout << p[n];
				    	 cout<< owner->stores[i].customerList[j].lotterynums[k][n];
				     }//for
				     cout<<" matched "<<matched<<endl;
				     owner->totalWinners[2]+=1;
				     owner->stores[i].numOfWinners[2]+=1;
	             } // else if

				}// for tickets
			}// for -id

		cout << "Total count for store: " << owner->stores[i].storeID;
		cout << "  won with 1 number: " << owner->stores[i].numOfWinners[0];
		cout << "  won with 2 number: " << owner->stores[i].numOfWinners[1];
		cout << "  won with 3 number: " << owner->stores[i].numOfWinners[2] << endl;


		}// for -stores

		cout << "" << endl;
//		cout<<"total 1 number win: "<<owner->totalWinners[0]<<endl;
//		cout<<"total 2 number win: "<<owner->totalWinners[1]<<endl;
//		cout<<"total 3 number win: "<<owner->totalWinners[2]<<endl;
} //findWinners
