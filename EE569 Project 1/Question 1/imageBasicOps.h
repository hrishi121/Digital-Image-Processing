//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1
// Submission Date: 4th February, 2016
//***********************************************************************

#ifndef IMAGEBASICOPS_H_
#define IMAGEBASICOPS_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class imageBasicOps {

public:
	unsigned char *readImage(char imageName[], int imageHeight,
					int imageWidth, int bytesPerPixel) ;

	void saveImage(unsigned char *imageData, char imageName[], int imageHeight,
					int imageWidth, int bytesPerPixel) ;

	void freeMemory(unsigned char *imageData) { delete [] imageData; }
	int getSize(char imageName[]);

};
#endif /* IMAGEBASICOPS */
