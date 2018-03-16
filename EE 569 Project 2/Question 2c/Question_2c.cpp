//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2c
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 8){
        printf("Syntax Error - Incorrect Parameter Usage: \n"
               "program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256]\n"
               "[Threshold colour image(for each channel)]\n"
               "[ Option:\n"
                  "1-> Separable Error Diffusion\n"
                  "2-> MBVQ-based Error diffusion\n]");

        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[3]), atoi(argv[4]));

	unsigned char *inputImage = test1.readImage(argv[1], 3);
	cout << "Program running...." << "\n\n";

    unsigned char *threshold = new unsigned char[3];
    threshold[0] = atoi(argv[5]);
    threshold[1] = atoi(argv[7]);
    threshold[2] = atoi(argv[6]);

    switch(atoi(argv[8])) {

        case 1:{
            test1.SeparableErrorDiffusion(inputImage, threshold, argv[2]);
            break;
        }

        case 2:{
            test1.MBVQ_FloydSteinberg(inputImage, argv[2]);
            break;
        }
    }

    test1.freeMemory(threshold);
    test1.freeMemory(inputImage);
    cout << "Program executed succesfully!!....Press Ctrl+C to exit\n" << endl;

	getchar();

}
