//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	unsigned char* FloydSteinberg1(unsigned char *imgData, int threshold);

	unsigned char* FloydSteinberg2(unsigned char *imgData, int threshold);

	unsigned char* JJN(unsigned char *imgData, int threshold);

	unsigned char* Stucki(unsigned char *imgData, int threshold);

};

#endif /* IMAGEPROCESALGO_H_ */
