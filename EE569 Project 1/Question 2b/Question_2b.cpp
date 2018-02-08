//************************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th February, 2016
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 7){
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        cout << "program_name input_image.raw Quantized_Image.raw output_image.raw [ImgWidth = 256] [ImgHeight = 256] [FilterSize = 3] [Quantize = 64]" << endl;
        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[4]), atoi(argv[5]));

	unsigned char *testImage1 = test1.readImage(argv[1], 3);
	cout << "Flag 1" << "\n\n";

    test1.oilMaskPart1(testImage1, argv[2], atoi(argv[7]));

    unsigned char *testImage2 = test1.readImage(argv[2], 3);

    test1.oilMaskPart2(testImage2, atoi(argv[6]), argv[3]);

    test1.freeMemory(testImage1);
    test1.freeMemory(testImage2);

    cout << "And the final flag" << endl;

	getchar();

}
