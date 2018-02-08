//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th February, 2016
//***********************************************************************

#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	unsigned char *separatePlanes(unsigned char *img, int planeNum);
	// The plane number can be 1, 2 or 3

	map<unsigned char, int> imgHistData(unsigned char *imageChannel, char name[], int dummy);

	void imgHistData(unsigned char *imageChannel, char name[]);

	void histEq1(unsigned char *img); // Transfer function (CDF) method

	void histEq2(unsigned char *img); // Bucket filling Algorithm

	void transferFunc(unsigned char *imageChannel, char name[]);

};

#endif /* IMAGEPROCESALGO_H_ */
