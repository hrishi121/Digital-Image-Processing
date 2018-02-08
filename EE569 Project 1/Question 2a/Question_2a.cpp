//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 2a
// Submission Date: 4th February, 2016
//***********************************************************************

#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main() {


	imageProcesAlgo test1;

    test1.setDimensions(400,300);
	unsigned char *testImage1 = test1.readImage("Desk.raw", 3);
	cout << "Program running....." << "\n\n";

    test1.histEq1(testImage1);
    test1.histEq2(testImage1);


    unsigned char *newPlane1 = test1.separatePlanes(testImage1, 1);
	unsigned char *newPlane2 = test1.separatePlanes(testImage1, 2);
	unsigned char *newPlane3 = test1.separatePlanes(testImage1, 3);

    test1.transferFunc(newPlane1, "transferFunc_plane1.csv");
	test1.transferFunc(newPlane2, "transferFunc_plane2.csv");
	test1.transferFunc(newPlane3, "transferFunc_plane3.csv");

	test1.freeMemory(newPlane1);
	test1.freeMemory(newPlane2);
	test1.freeMemory(newPlane3);

    test1.freeMemory(testImage1);
    cout << "And the final flag" << endl;


	getchar();

}
