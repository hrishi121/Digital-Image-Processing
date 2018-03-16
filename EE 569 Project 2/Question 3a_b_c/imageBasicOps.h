//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3 a,b,c
// Submission Date: 4th March, 2018
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

	unsigned char **separatePlane(unsigned char *img, int planeNum);
	// The plane number can be 1, 2 or 3

	unsigned char *separatePlane(unsigned char *imgData, int planeNum, int dummy);

};
#endif /* IMAGEBASICOPS */
