 //***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1
// Submission Date: 4th February, 2016
//***********************************************************************

#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:
	void RGB2Gray(unsigned char *imageData, int imageHeight, int imageWidth);

	void RGB2CMYK(unsigned char *imageData, char imageName[],
				 int imageHeight, int imageWidth);

	void separatePlanes(unsigned char *imageData, int imageHeight, int imageWidth);

	vector< vector <unsigned char> > separatePlane(unsigned char *imageData,
	 								int imageHeight, int imageWidth, int planeNum);

	void BilinInter(unsigned char *imgData, int imgHeight, int imgWidth,
								 int newImgHeight, int newImgWidth);

};

#endif /* IMAGEPROCESALGO_H_ */
