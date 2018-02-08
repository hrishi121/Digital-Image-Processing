//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th February, 2016
//***********************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main() {


	imageProcesAlgo test1,test2;

    test1.setDimensions(256, 256);
    test2.setDimensions(750,1000);
    unsigned char *filmImg = test2.readImage("Film.raw", 3);
	unsigned char *testImage1 = test1.readImage("Girl.raw", 3);
	unsigned char *cmyImg = test1.RGB2CMY(testImage1);
	cout << "Stage 1 successfull !" << "\n\n";

    unsigned char *temp1 = test2.histMapping(filmImg, cmyImg, 256, 256);
    unsigned char *finalImage = test1.mirror(temp1);

    test1.saveImage(finalImage,"final_Girl.raw", 3);

    test1.freeMemory(finalImage);
    test1.freeMemory(temp1);
    test1.freeMemory(cmyImg);
    test1.freeMemory(testImage1);
    test2.freeMemory(filmImg);
    cout << "And the final flag" << endl;

	getchar();

}
