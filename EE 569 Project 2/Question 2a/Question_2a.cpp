//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 9){
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        cout << "program_name input_image.raw fixedthresh.raw randThresh.raw dither.raw new.raw [ImgWidth = 256] [ImgHeight = 256] [Threshold = 127] [order = 8]" << endl;
        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[6]), atoi(argv[7]));

	unsigned char *inputImage = test1.readImage(argv[1], 3);
	cout << "Program running...." << "\n\n";

    test1.FixedThreshold(inputImage, atoi(argv[8]), argv[2]);
    test1.RandomThreshold(inputImage, argv[3]);

    test1.OrderedDither(inputImage, argv[4], atoi(argv[9]));

    test1.FourLevelOrderedDither(inputImage, argv[5], atoi(argv[9]));

    test1.freeMemory(inputImage);
    cout << "Program executed succesfully!!" << endl;

	getchar();

}
