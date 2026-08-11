# Big-Number-Arithmetic-library (WIP)
A library that can do arithmetic on integers larger than the CPU's native register size (typically 64-bit), with support for decimal values. 

## Development Status

This project was paused while I worked on a larger application.
I am now returning to it with new experience and plans to improve its design, add features, and continue development.

## Motivation
C data types have a size limit to them and I wish to go past this limitation.
This project aims to explore how large numerical values can be used while keeping perfect precision, similar to how libraries like the GNU Multiple Precision Arithmetic library work internally.

## How it works

Numbers are currently represented as a 9 digit chunks in an array.

Addition is done one chunk at a time with manual carry handling.


## Future implementation
  - [ ] Implementation of subtraction, multiplication, division, exponential and factorial
  - [x] Transitioning form strings to digital arrays representation for efficiency
  - [ ] Optimisation memory usage, speed and performance
  - [ ] Add the option to use floating point numbers

## Challenges
  - Alligning numbers with different lengths and decimal places
  - Balancing memory usage, safety and speed while manipulating big integer
  - Trying to keep the library easy to use for the user while not hindering performance
  - Keeping track of all the necessary variables while keeping the usage of memory relatively low
