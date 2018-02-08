//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th February, 2016
//***********************************************************************


#ifndef IMAGEBASICOPS_H_
#define IMAGEBASICOPS_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class imageBasicOps {

public:
	int imgHeight;
	int imgWidth;

	void setDimensions(int newImgWidth,int newImgHeight);

	unsigned char *readImage(char imgName[], int bytesPerPixel) ;

	void saveImage(unsigned char *imgData, char imgName[], int bytesPerPixel) ;

	void freeMemory(unsigned char *imgData) { delete [] imgData; }

};
#endif /* IMAGEBASICOPS */
