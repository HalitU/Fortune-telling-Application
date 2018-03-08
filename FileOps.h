/*
*@Author
*Student Name: Halit Uyanýk
*Student Id: 150140138
*Date: 19.12.2015
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma once
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;
/*
Used for creating a new file
*/
typedef struct fileOps {
	ofstream fortuneFile;

	void createFile();
} FileOps;

void fileOps::createFile() {
	fortuneFile.open("output.txt");
}

#endif