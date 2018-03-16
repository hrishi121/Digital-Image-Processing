//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3d
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

    unsigned char **binaryIntensity(unsigned char *img);

    unsigned char bitPattern(unsigned char **img, int row, int column);

    int **FindTopLeftCorners(unsigned char **img);

    int **FindTopRightCorners(unsigned char **img);

    int **FindBottomLeftCorners(unsigned char **img);

    int **FindBottomRightCorners(unsigned char **img);

	void FindUniquePieces(unsigned char *imgData);

	int ComparePuzzleID(vector<unsigned char> id1,
					 vector<unsigned char> id2, vector<unsigned char> id2_mir);
};

#endif /* IMAGEPROCESALGO_H_ */
