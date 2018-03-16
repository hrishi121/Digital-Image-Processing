//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1a
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 4){
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        cout << "program_name input_image.raw circle_image.raw square_image.raw [ImgWidth = 256] [ImgHeight = 256]" << endl;
        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[4]), atoi(argv[5]));

	unsigned char *squareImage = test1.readImage(argv[1], 3);
	cout << "Program running...." << "\n\n";

    unsigned char *circleWarp = test1.Square2CircleWarp(squareImage);
    test1.saveImage(circleWarp, argv[2], 3);

    unsigned char *circleImage = test1.readImage(argv[2], 3);
    unsigned char *squareWarp = test1.Circle2SquareWarp(circleWarp);
    test1.saveImage(squareWarp, argv[3], 3);

    test1.freeMemory(squareWarp);
    test1.freeMemory(squareImage);
    test1.freeMemory(circleImage);
    test1.freeMemory(circleWarp);
    cout << "Program executed succesfully!!" << endl;

	getchar();

}
