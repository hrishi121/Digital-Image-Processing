//************************************************************************
// EE569 Homework 2, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2b
// Submission Date: 4th March, 2018
//************************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main(int argc, char *argv[]) {

    // Check for proper syntax
    if (argc < 6){
        printf("Syntax Error - Incorrect Parameter Usage: \n"
               "program_name input_image.raw output.raw [ImgWidth = 256] [ImgHeight = 256] [Threshold = 127]\n"
               "[dithering = 1-> Floyd Steinberg algorithm with normal scanning\n"
               "          \t 2-> Floyd Steinberg algorithm with serpentine scanning\n"
               "          \t 3-> Jarvis, Judice and Ninke algorithm\n"
               "          \t 4-> Stucki algorithm]");

        return 0;
    }

	imageProcesAlgo test1;
    test1.setDimensions(atoi(argv[3]), atoi(argv[4]));

	unsigned char *inputImage = test1.readImage(argv[1], 3);
	cout << "Program running...." << "\n\n";

    switch(atoi(argv[6])) {
        case 1: {
            unsigned char *FloydImage1 = test1.FloydSteinberg1(inputImage, atoi(argv[5]));
            test1.saveImage(FloydImage1, argv[2], 1);
            test1.freeMemory(FloydImage1);
            break;
        }

        case 2: {
            unsigned char *FloydImage2 = test1.FloydSteinberg2(inputImage, atoi(argv[5]));
            test1.saveImage(FloydImage2, argv[2], 1);
            test1.freeMemory(FloydImage2);
            break;
        }

         case 3: {
            unsigned char *JJNimage = test1.JJN(inputImage, atoi(argv[5]));
            test1.saveImage(JJNimage, argv[2], 1);
            test1.freeMemory(JJNimage);
            break;
        }

         case 4: {
            unsigned char *StuckiImage = test1.Stucki(inputImage, atoi(argv[5]));
            test1.saveImage(StuckiImage, argv[2], 1);
            test1.freeMemory(StuckiImage);
            break;
        }
    }

    test1.freeMemory(inputImage);
    cout << "\nProgram executed succesfully!!....Press Enter to continue" << endl;

	getchar();

}
