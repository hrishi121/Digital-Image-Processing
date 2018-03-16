//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1b
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:
	unsigned char *BilinInter(unsigned char ***imgData, double x, double y);
	// Perform Bilinear Interpolation of the coordinates x, y for the original image imgData

	double *HmatrixMultiply1(double x, double y);

	double *HmatrixMultiply2(double x, double y);

	double *HmatrixMultiply3(double x, double y);

	void Stitch(unsigned char *leftImg, unsigned char *middleImg,
				 unsigned char *rightImg, char name[]);

};

#endif /* IMAGEPROCESALGO_H_ */
