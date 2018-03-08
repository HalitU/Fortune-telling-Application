/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma once
#ifndef DESK_H
#define DESK_H

#include <stdio.h>
#include <fstream>
#include <time.h>
#include "Temporary.h"
#include "Queue.h"
#include "FileOps.h"

using namespace std;

#define CARDCOUNT 4
#define CARDCOUNTINEACHSET 13
/*
Used for storing the main deck and its sub structures. Details about how they are used is given on report.
*/
typedef struct deck {
	int cardCounts[13];
	char cardTypes[4] = { 'S', 'H', 'D', 'C' };

	Queue *cardQue;
	Queue *fortuneQue;
	Temporary *temp;

	FileOps *fileOps;

	void evaluateDeck();
	void putCard(int);
	bool calculateFortune();
	void initialize();
	void shuffleDeck(int);
	void printDeck();
} Deck;

void deck::evaluateDeck() {
	srand(time(NULL));
	initialize();
	printDeck();
	fileOps->fortuneFile << "Fortune-telling steps:" << endl;
	int i = 1;
	while (cardQue->front) {
		if (i == 14) {
			while (temp->tempHead != NULL) {
				temp->pop();
			}
			i = 1;
		}else if (cardQue->front->number == i) {
			fileOps->fortuneFile << i << ":" << cardQue->front->type << ":" << cardQue->front->number << ":match" << endl;
			while (temp->tempHead) {
				cardQue->enqueue(temp->pop());
			}
			fortuneQue->enqueue(cardQue->dequeue());
			i = 1;
		}else {
			fileOps->fortuneFile << i << ":" << cardQue->front->type << ":" << cardQue->front->number << ":unmatch" << endl;
			temp->push(cardQue->dequeue());
			i++;
		}
	}
	calculateFortune();
}

/*
Function takes number parameter which will be between 0 and 12
for example for number 7
new card number will be 8
new card type will be the the char from cardcount amount which will be between 0 and 3
cardcount indicates the amount of cards used for that number type which 
in our example if cardcount is 3 then 3 7s are already placed
so if 3 7s are used then card type will be 3 (from 0-3) which is 'C'
new cards nextcard will be stated to null
then it is sent to main card queue
after that program increments the cardcount of 7s by one so that if it reaches 4 no more 7s will be added in shuffledeck
*/
void deck::putCard(int number) {
	Card *newCard = new Card;
	newCard->number = number+1;
	newCard->type = cardTypes[cardCounts[number]];
	newCard->nextCard = NULL;
	cardQue->enqueue(newCard);
	cardCounts[number]++;
}

/*
parameters : count
recursive ending condition : when count reaches 52
if cardcount for calculated random number which will be from 0-12 for each card type is not equal to zero
	put that type of card to queue
	call function with increasing count
else
	since program wont add any new cards
	call the function by same count
*/
void deck::shuffleDeck(int count) {
	if (count == 52) {
		return;
	}
	int random = rand() % 13;
	if (cardCounts[random] < 4) {
		putCard(random);
		shuffleDeck(count + 1);
	}
	else {
		shuffleDeck(count);
	}
}

void deck::initialize() {
	fileOps = new FileOps;
	fileOps->createFile();
	cardQue = new Queue;
	fortuneQue = new Queue;
	temp = new Temporary;
	temp->tempHead = NULL;
	for (int i = 0; i < CARDCOUNTINEACHSET; i++)
		cardCounts[i] = 0;
	shuffleDeck(0);
}

void deck::printDeck() {
	fileOps->fortuneFile << "Shuffled deck:" << endl;
	Card *crr = cardQue->front;
	int i = 1;
	while (crr) {
		fileOps->fortuneFile << i << ":" << crr->type << ":" << crr->number << endl;
		crr = crr->nextCard;
		i++;
	}
}

bool deck::calculateFortune() {
	fileOps->fortuneFile << "Fortune Results:" << endl;
	int total = 0;
	Card *crr = fortuneQue->front;
	while (crr) {
		fileOps->fortuneFile << crr->type << ":" << crr->number << endl;
		if (crr->number == QUEEN || crr->number == KING || crr->number == JOKER) {
			total += 10;
		}
		else {
			total += crr->number;
		}
		crr = crr->nextCard;
	}
	fileOps->fortuneFile << "Sum: " << total << endl;
	if (total < 50) {
		fileOps->fortuneFile << "Bad luck!" << endl;
		return false;
	}
	else {
		fileOps->fortuneFile << "Fortune will come true" << endl;
		return true;
	}
}

#endif