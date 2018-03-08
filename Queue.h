/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "Card.h"
/*
Used to store and do operations on queue structures
*/
typedef struct queue {
	Card *back;
	Card *front;
	int eleCount = 0;

	void printQueue();
	bool isEmpty();
	void enqueue(Card*);
	Card* dequeue();
} Queue;

void queue::printQueue() {
	Card *crr = front;
	int i = 1;
	while (crr) {
		if (crr == NULL)
			break;
		cout << i << ": " << crr->number << "  ";
		crr = crr->nextCard;
		i++;
	}
	cout << endl;
}

bool queue::isEmpty() {
	if (eleCount == 0)
		return true;
	return false;
}

void queue::enqueue(Card *newCard) {
	newCard->nextCard = NULL;
	if (isEmpty()) {
		back = newCard;
		front = back;
	}
	else {
		back->nextCard = newCard;
		back = newCard;
	}
	eleCount++;
}

Card * queue::dequeue() {
	Card *tmp = front;
	front = front->nextCard;
	eleCount--;
	return tmp;
}

#endif