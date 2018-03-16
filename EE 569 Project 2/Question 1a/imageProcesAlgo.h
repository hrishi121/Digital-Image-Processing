//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1a
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:
	unsigned char BilinInter(unsigned char **imgData, double x, double y);
	// Perform Bilinear Interpolation of the coordinates x, y for the original image imgData

	unsigned char *Square2CircleWarp(unsigned char *imgData);
	// Warp a square image to a circle

	unsigned char *Circle2SquareWarp(unsigned char *imgData);
	// Warp a circular image to a square

};

#endif /* IMAGEPROCESALGO_H_ */
