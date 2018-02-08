//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3a
// Submission Date: 4th February, 2016
//***********************************************************************


#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	unsigned char *separatePlanes(unsigned char *img, int planeNum);
	// The plane number can be 1, 2 or 3

	unsigned char **paddedImg(unsigned char *img, int pad);
	// int pad can be 1->3x3 filter;  2->5x5 filer; 3->7x7 filter;	4->9x9 filter;  5->11x11 filter

	unsigned char findMedian(unsigned char **img, int x, int y, int filtSize);

	unsigned char findMax(unsigned char **img, int x, int y, int filtSize);

	unsigned char findMin(unsigned char **img, int x, int y, int filtSize);

	unsigned char *filter(unsigned char *noisyImg, int planeNum, int filtSize, int filtNum, double qValue);
	// filtNum can be 1- median; 2- max; 3- min; 4 - contraHarmonic; 5 - Averaging

	unsigned char contraHarmonic(unsigned char **img, int x, int y, int filtSize, double qValue);

	unsigned char findMean(unsigned char **img, int x, int y, int filtSize);

	double findPSNR(unsigned char *originalImg, unsigned char *filteredImg, int plane);



};

#endif /* IMAGEPROCESALGO_H_ */
