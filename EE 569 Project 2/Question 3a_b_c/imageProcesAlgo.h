//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3 a,b,c
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	int computeBond(unsigned char **image, int row, int column);

	unsigned char **binaryIntensity(unsigned char *img);

	unsigned char **reverseBinaryIntensity(unsigned char *img);

	unsigned char bitPattern(unsigned char **img, int row, int column);

	unsigned char **padImage(unsigned char **img);

	unsigned char matchConditionalMask(unsigned char inputPattern, int operation);

	unsigned char matchUnconditionalMask(unsigned char inputPattern);

	unsigned char matchUnconditionalMaskSkeleton(unsigned char inputPattern);

	void shrinking(unsigned char *img, char name[]);

	void skeletonizing(unsigned char *img, char name[]);

	void thinning(unsigned char *img, char name[]);
};


#endif /* IMAGEPROCESALGO_H_ */
