# MATLAB Speech Recognition

Final project for ECE 6214, High-Level VLSI Design Methodology

Coded by [Brandon Bernier](mailto:bbernier@gwu.edu) 

A small MATLAB project using the Auditory Toolbox to accomplish simple speech recognition of the digits "one" through "ten."

## Usage

Open the project.m file in MATLAB to begin using. The file will need to be modified with the correct directories for your specific training set. At least ten recordings of the individual words is ideal. Once the script is run, MATLAB will prompt you to say a word. If MATLAB recognizes the word, it will output the number one through ten in the window, otherwise it will say it is not recognized. It is currently only setup to test for "ONE" or "TWO."