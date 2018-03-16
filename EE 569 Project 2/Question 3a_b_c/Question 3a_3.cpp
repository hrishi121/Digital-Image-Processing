//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3 a,b,c
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 5){
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        printf("program_name input_image.raw output_image.raw [ImgWidth = 256] [ImgHeight = 256]\n"
               "[Operation = 1 -> shrinking and counting\n"
               "             2 -> thinning\n"
               "             3 -> skeletonizing\n ]");
        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[3]), atoi(argv[4]));

	unsigned char *inputImage = test1.readImage(argv[1], 1);
	cout << "Program running...." << "\n\n";
    switch(atoi(argv[5])) {
        case 1: {
            test1.shrinking(inputImage, argv[2]);
            break;
        }

        case 2: {
            test1.thinning(inputImage, argv[2]);
            break;
        }

        case 3: {
            test1.skeletonizing(inputImage, argv[2]);
            break;
        }
    }
    
    test1.freeMemory(inputImage);
    cout << "\n\nProgram executed succesfully!!.....Press Ctrl+C to exit" << endl;

	getchar();

}
