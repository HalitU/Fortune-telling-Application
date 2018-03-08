/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#pragma once
#ifndef TEMPORARY_H 
#define TEMPORARY_H

#include "Card.h"

using namespace std;
/*
Used for storing stack data types and do stack operations on them
*/
typedef struct temporary {
	Card *tempHead;

	void printStack();
	void push(Card*);
	Card* pop();
} Temporary;

void temporary::printStack() {
	Card *crr = tempHead;
	int i = 1;
	while (crr) {
		cout << i << ":  " << crr->number << "  ";
		crr = crr->nextCard;
		i++;
	}
	cout << endl;
}

void temporary::push(Card *newCard) {
	newCard->nextCard = tempHead;
	tempHead = newCard;
}

Card* temporary::pop() {
	Card *topNode = tempHead;
	tempHead = tempHead->nextCard;
	return topNode;
}

#endif