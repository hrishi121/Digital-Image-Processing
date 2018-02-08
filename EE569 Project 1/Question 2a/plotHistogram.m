clc;
clear all;

Array=csvread('transferFunc_plane3.csv');
col1 = Array(:, 1);
col2 = Array(:, 2);
plot(col1, col2, 'b');
title('Transfer of B channel of enhanced image (Method1)')
xlabel('Input Pixel Intensities')
ylabel('Ouput Pixel Intensities')
%ylim([0 600])
grid on;