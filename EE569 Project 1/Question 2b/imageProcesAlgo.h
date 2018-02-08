//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th February, 2016
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:
	unsigned char *oilQuantize64(unsigned char *img, int planeNum);
	unsigned char *oilQuantize512(unsigned char *img, int planeNum);

	void oilMaskPart1(unsigned char *img, char name[], int quantize);

	void oilMaskPart2(unsigned char *img, int filterSize, char name[]);

	unsigned char *separatePlanes(unsigned char *img, int planeNum);
	// The plane number can be 1, 2 or 3

	unsigned char **paddedImg(unsigned char *img, int pad);
	// int pad can be 1->3x3 filter;  2->5x5 filer; 3->7x7 filter;	4->9x9 filter;  5->11x11 filter


	unsigned char findFrequentPixel(unsigned char** img, int x, int y, int pad);
	// filter size can be 3, 5, 7, 9, 11

	unsigned int *imgHistDataPartial(unsigned char *plane, int pixelValue, int count,
									char name[], int quantize);
	// quantize can be 4 or 8

};

#endif /* IMAGEPROCESALGO_H_ */
