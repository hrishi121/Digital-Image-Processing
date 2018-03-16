//***********************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th March, 2018
//***********************************************************************



#ifndef IMAGEPROCESALGO_H_
#define IMAGEPROCESALGO_H_

#include "imageBasicOps.h"

class imageProcesAlgo: public imageBasicOps {
public:

	void MBVQ_FloydSteinberg(unsigned char *imgData, char name[]);

	void SeparableErrorDiffusion(unsigned char *imgData, unsigned char *threshold, char name[]);

	unsigned char *CMYW(float R2, float G2, float B2);
	unsigned char *MYGC(float R2, float G2, float B2);
	unsigned char *RGMY(float R2, float G2, float B2);
	unsigned char *KRGB(float R2, float G2, float B2);
	unsigned char *RGBM(float R2, float G2, float B2);
	unsigned char *CMGB(float R2, float G2, float B2);

	unsigned char *pyramidMBVQ(unsigned char R1, unsigned char G1, unsigned char B1,
							   float R2, float G2, float B2 );
	unsigned char C[3] = {0, 255, 255};
	unsigned char M[3] = {255, 0, 255};
	unsigned char Y[3] = {255, 255, 0};
	unsigned char R[3] = {255, 0, 0};
	unsigned char G[3] = {0, 255, 0};
	unsigned char B[3] = {0, 0, 255};
	unsigned char W[3] = {255, 255, 255};
	unsigned char K[3] = {0, 0, 0};
};

#endif /* IMAGEPROCESALGO_H_ */
 