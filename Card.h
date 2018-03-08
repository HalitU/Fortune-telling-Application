/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#pragma once
#ifndef CARD_H
#define CARD_H

#define JOKER 11
#define QUEEN 12
#define KING 13
/*
Struct for cards includes number from 1-13, type from 4 types, and a pointer for next card
*/
typedef struct card {
	int number;
	char type;
	struct card *nextCard;
} Card;

#endif