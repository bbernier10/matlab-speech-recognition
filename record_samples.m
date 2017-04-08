clc
close all
clear all
format compact

Fs = 8000;  % Sampling Frequency
num = 'Brandon';

% Record Samples
for i = 1:15
    input('Speak Now')
    sample = wavrecord(Fs,Fs);
    path = strcat('iPhone\',num,'\',num,int2str(i),'.wav');
    wavwrite(sample,path);
end