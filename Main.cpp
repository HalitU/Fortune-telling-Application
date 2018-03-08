/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Deck.h"

using namespace std;

Deck *newDeck;
/*
Main function creates a new deck and evaluates it
*/
int main() {
	newDeck = new Deck;
	newDeck->evaluateDeck();
}