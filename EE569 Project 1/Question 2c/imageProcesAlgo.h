//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th February, 2016
//***********************************************************************

#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	unsigned char *RGB2CMY(unsigned char *img);

	unsigned char *mirror(unsigned char *img);

	unsigned char *histMapping(unsigned char *filmImg, unsigned char *origImg, int h1, int w1 );

	unsigned char *histCopy(unsigned char *filmImg, unsigned char *origImg, int plane,  int h1, int w1);

	map<unsigned char,double> cumulativeHist(unsigned char *plane);

};

#endif /* IMAGEPROCESALGO_H_ */
