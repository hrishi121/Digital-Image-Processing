//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 1
// Submission Date: 4th February, 2016
//***********************************************************************

#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main() {


	imageProcesAlgo test1;

	unsigned char *testImage1 = test1.readImage("Tiffany.raw", 512, 512, 3);

    test1.RGB2Gray(testImage1,512, 512);
    test1.freeMemory(testImage1);

    unsigned char *testImage2 = test1.readImage("Bear.raw", 854, 480, 3);
    test1.RGB2CMYK(testImage2, "CMYK_Bear.raw", 854, 480);
    test1.freeMemory(testImage2);

	unsigned char *testImage3 = test1.readImage("Dance.raw", 854, 480, 3);
    test1.RGB2CMYK(testImage3, "CMYK_Dance.raw", 854, 480);
    test1.freeMemory(testImage3);

    unsigned char *testImage5 = test1.readImage("Airplane.raw", 512, 512, 3);
    test1.BilinInter(testImage5, 512, 512, 650, 650);
    cout << "\n" << "This is the final flag" << "\n\n";
    test1.freeMemory(testImage5);

	getchar();

}
