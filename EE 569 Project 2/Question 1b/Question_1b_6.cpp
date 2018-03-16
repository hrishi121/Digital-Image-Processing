//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1b
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 6){
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        cout << "program_name left.raw middle.raw right.raw output.raw [ImgWidth = 256] [ImgHeight = 256]" << endl;
        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[5]), atoi(argv[6]));

	unsigned char *leftImg   = test1.readImage(argv[1], 3);
    unsigned char *middleImg = test1.readImage(argv[2], 3);
    unsigned char *rightImg  = test1.readImage(argv[3], 3);
	cout << "Program running...." << "\n\n";

    test1.Stitch(leftImg, middleImg, rightImg, argv[4]);

    test1.freeMemory(leftImg);
    test1.freeMemory(middleImg);
    test1.freeMemory(rightImg);
    cout << "\nProgram executed succesfully!!.....Press Ctrl+C to exit" << endl;

	getchar();

}
