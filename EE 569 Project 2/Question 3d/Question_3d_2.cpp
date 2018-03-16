//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3d
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 4){
        printf("Syntax Error - Incorrect Parameter Usage: \n"
               "program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256]\n");

        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[3]), atoi(argv[4]));

	unsigned char *inputImage = test1.readImage(argv[1], 3);
	cout << "Program running...." << "\n\n";

    test1.FindUniquePieces(inputImage);

    test1.freeMemory(inputImage);
    cout << "\nProgram executed succesfully!!....Press Ctrl+C to exit" << endl;

	getchar();

}
