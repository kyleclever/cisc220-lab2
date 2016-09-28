/*
 * LAB2LOTTERY.hpp
 *
 *  Created on: Sep 21, 2016
 *      Author: kylew
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_


	struct Customer {
	int customerID;
	int numOfTickets;
	int *lotterynums;

	};

	struct Store{
	int storeID;
	int numOfCustomers;
	int *customerList;
	int numOfSold;
	int numOfWinners[3]; // number of winners who match 1, 2 or 3 numbers

	};

	struct Owner{
	int *stores;
	int numOfStores;
	int totalSold;
	int totalWinners[3];

	};


	Owner *makeOwner();
	Store makeStore();
	Customer makeCustomer();
	void getWinners (int winners[]);
	void findWinners(Owner *owner, int *ls);
	int checkwin(int *nums, int *winners);

//lottery header


#endif /* LAB2LOTTERY_HPP_ */
