//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	void FixedThreshold(unsigned char *imgData, unsigned char threshold, char name[]);

	void RandomThreshold(unsigned char *imgData, char name[]);

	void OrderedDither(unsigned char *imgData, char name[], int order);

	int **BayerIndexMatrix(int order);

	void FourLevelOrderedDither(unsigned char*imgData, char name[], int order);

};

#endif /* IMAGEPROCESALGO_H_ */
