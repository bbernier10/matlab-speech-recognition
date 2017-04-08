%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Brandon Bernier           %
% ECE 6214 Final Project    %
% Professor Jerry Wu        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc
close all
clear all
format compact

Fs = 8000;  % Sampling Frequency
directory = 'iPhone';

% Mel Frequency Cepstral Coefficients
for i = 1:15
    one(i,:) = wavread(strcat(directory,'\one\one',int2str(i),'.wav'));
    two(i,:) = wavread(strcat(directory,'\two\two',int2str(i),'.wav'));
    Brandon(i,:) = wavread(strcat(directory,'\Brandon\Brandon',int2str(i),'.wav'));
    ceps_one(:,:,i) = mfcc(one(i,:),16000,100);
    ceps_two(:,:,i) = mfcc(two(i,:),16000,100);
    ceps_Brandon(:,:,i) = mfcc(Brandon(i,:),16000,100);
end

% Combine Feature Vectors for Different Utterances
coeff_one(:,:)  = horzcat(ceps_one(:,:,1),ceps_one(:,:,2),ceps_one(:,:,3),ceps_one(:,:,4),ceps_one(:,:,5));
coeff_one  = transpose(coeff_one);

coeff_two(:,:)  = horzcat(ceps_two(:,:,1),ceps_two(:,:,2),ceps_two(:,:,3),ceps_two(:,:,4),ceps_two(:,:,5));
coeff_two  = transpose(coeff_two);

coeff_Brandon(:,:)  = horzcat(ceps_Brandon(:,:,1),ceps_Brandon(:,:,2),ceps_Brandon(:,:,3),ceps_Brandon(:,:,4),ceps_Brandon(:,:,5));
coeff_Brandon  = transpose(coeff_Brandon);

% Gaussian Mixture Model
gmm_one = gmdistribution.fit(coeff_one, 8, 'Start', 'randSample', 'Replicates', 10, 'CovType', 'diagonal');
gmm_two = gmdistribution.fit(coeff_two, 8, 'Start', 'randSample', 'Replicates', 10, 'CovType', 'diagonal');
gmm_Brandon = gmdistribution.fit(coeff_Brandon, 8, 'Start', 'randSample', 'Replicates', 10, 'CovType', 'diagonal');

while 1
    % Record Samples
    input('Speak Now')
    sample = wavrecord(Fs,Fs);
    wavwrite(sample,'sample.wav');
    sample = wavread('sample.wav');
    coeffs = transpose(mfcc(sample,16000,100));

    [~, log_like(1)] = posterior(gmm_one,coeffs);
    [~, log_like(2)] = posterior(gmm_two,coeffs);
    [~, log_like(3)] = posterior(gmm_Brandon,coeffs);

    [M,I] = min(log_like);

    if(log_like(1)>400 && log_like(2)>400 && log_like(3)>400 || abs(log_like(1)-log_like(2))<150)
        disp('No Match');
    elseif(I==1)
            disp('ONE');
    elseif(I==2)
            disp('TWO');
    elseif(I==3)
            disp('Brandon');
    end
end