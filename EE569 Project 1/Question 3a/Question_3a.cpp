//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// Email ID: hippalga@usc.edu
// USC ID: 9573681608
// Tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Question 3a
// Submission Date: 4th February, 2016
//***********************************************************************


#include <iostream>
#include "imageBasicOps.h"
#include "imageProcesAlgo.h"
using namespace std;

int main() {


	imageProcesAlgo test1;

    test1.setDimensions(512, 512);

    unsigned char *originalImage = test1.readImage("Lena.raw", 3);
    unsigned char *noiseImage = test1.readImage("Lena_mixed.raw", 3);
    unsigned char *filterImage = new unsigned char[512*512*3];
    unsigned char *tempImg = new unsigned char[512*512*3];


    unsigned char *filtPlane1, *filtPlane2, *filtPlane3, *temp1, *temp2, *temp3;

    double psnr1, psnr2, psnr3, average;

        // This is the first stage of filtering, change the third parameter to change filter
        // size and 4th parameter to change type of parameter
        temp1 = test1.filter(noiseImage, 1, 3, 1, 0);
        temp2 = test1.filter(noiseImage, 2, 3, 1, 0);
        temp3 = test1.filter(noiseImage, 3, 3, 1, 0);

    for(int i = 0; i<512; i++) {
        for(int j = 0; j<512; j++) {
            tempImg[i*512*3 + j*3] = temp1[i*512 + j];
            tempImg[i*512*3 + j*3 + 1] = temp2[i*512 + j];
            tempImg[i*512*3 + j*3 + 2] = temp3[i*512 + j];
        }
    }

    // This is the second stage of filtering, change the third parameter to change filter
    // size and 4th parameter to change type of parameter
    filtPlane1 = test1.filter(tempImg, 1, 7, 1, 0);
    filtPlane2 = test1.filter(tempImg, 2, 7, 1, 0);
    filtPlane3 = test1.filter(tempImg, 3, 7, 1, 0);

    for(int i = 0; i<512; i++) {
        for(int j = 0; j<512; j++) {
            filterImage[i*512*3 + j*3] = filtPlane1[i*512 + j];
            filterImage[i*512*3 + j*3 + 1] = filtPlane2[i*512 + j];
            filterImage[i*512*3 + j*3 + 2] = filtPlane3[i*512 + j];
        }
    }

    psnr1 = test1.findPSNR(filterImage, originalImage, 1);
    psnr2 = test1.findPSNR(filterImage, originalImage, 2);
    psnr3 = test1.findPSNR(filterImage, originalImage, 3);
    average = (psnr1 + psnr2 + psnr3)/3;

    cout << "PSNR plane1: " << (psnr1) << endl;
    cout << "PSNR plane2: " << (psnr2) << endl;
    cout << "PSNR plane3: " << (psnr3) << endl;
    cout << " Average PSNR: " << average << endl;

    //test1.saveImage(newPlane1, "rPlane_median_filtered.raw", 1);
    //test1.saveImage(newPlane2, "gPlane_median_filtered.raw", 1);
    //test1.saveImage(newPlane3, "bPlane_mean_filtered.raw", 1);
    test1.saveImage(filterImage, "filterImage8.raw", 3);

    test1.freeMemory(filtPlane1);
    test1.freeMemory(filtPlane2);
    test1.freeMemory(filtPlane3);

    test1.freeMemory(temp1);
    test1.freeMemory(temp2);
    test1.freeMemory(temp3);

    test1.freeMemory(filterImage);
    test1.freeMemory(originalImage);
    test1.freeMemory(noiseImage);
    cout << "And the final flag. Press Ctrl + C to exit" << endl;
	getchar();

}
