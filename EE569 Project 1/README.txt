//***********************************************************************
// EE569 Homework 1, Prof. Kuo, Spring 2018
// @author: Hrishikesh Hippalgaonkar
// All code tested in GNU GCC Compiler(32 bit)::CodeBlocks 16.01 IDE, Windows 10
// Date: 4th February, 2016
//***********************************************************************


This is the README file for Homework 1

(All the images required for the programs have been placed in the respective folders)

-------------------------------Question 1------------------------------------------
In the Question 1 folder, compile all the files and run the Question_1.cpp file
The images required to be placed in this folder are:
 Tiffany.raw, Bear.raw, Dance.raw, Airplane.raw



------------------------------Question 2a------------------------------------------
In the Question 2a folder, compile all the files and run the Question_2a.cpp file
The images required to be placed in this folder are:
Desk.raw



------------------------------Question 2b-------------------------------------------
The images required to be placed in this folder are:
Trojan.raw, Star_Wars.raw

In the Question 2b folder, compile all the files and run the Question_2b.cpp file with the following arguments:

input_image_name.raw Quantized_Image_name.raw output_image_name.raw [ImgWidth = 256] [ImgHeight = 256] [FilterSize = 3] [Quantize = 64]
 
 where,
 input_image_name.raw --- name of the imput image
 Quantized_Image_name.raw --- name to be assigned to the quantized output image
 output_image_name.raw ---name to be assigned to the final output image
 [ImgWidth = 256] --- Width of the image
 [ImgHeight = 256] --- Height of the image
 [FilterSize = 3] --Size of the filter. Available values are 3, 5, 6, 7, 9, 11
 [Quantize = 64] -- Quantization of the image. Available values are 64 or 512

e.g. Trojan.raw quantized_Trojan.raw oil_Trojan.raw 1800 1200 3 512




------------------------------Question 2c-------------------------------------------
In the Question 2c folder, compile all the files and run the Question_2c.cpp file.
The images required to be placed in this folder are:
Film.raw, Girl.raw




------------------------------Question 3a-------------------------------------------
The images required to be placed in this folder are:
Lena.raw, Lena_mixed.raw

In the Question 3a folder, compile all the files and run the Question_3a.cpp file.

The filter size and type of filter for stage 1 can be changed on line 35, 36, 37
The 3rd argument in the filter function is for the filter size. Available values are 3, 5, 7, 9, 11

The 4th argument in the filter function is for the filter type. Available value are:
1 - Median filter
2 - Max filter
3 - Min filter
4 - Contra harmonic
5 - Averaging

Similarly, the filter size and type of filter for stage 2 can be changes on line 50, 51, 52

---------------------------------------------------------------------------------------


