# Big-Number-Arithmetic-library
A library that can do arithmetic on numbers larger than the CPU's native register size (typically 64-bit), with support for decimal values. 

**Status:** Work in Progress

## Motivation
Standard floating-point types introduce size limitations.
This project aims to explore how large numerical values can be used while keeping perfect precision, similar to how libraries like the GNU Multiple Precision Arithmetic library work internally.

## How it works

Numbers are currently represented as a character array and normalized one at a time before computation:

  - Decimal points are aligned between 2 numbers
  - Numbers are padded with 0s where needed
  - Strings are reversed to allow right to left addition

Addition is done digit-by-digit with manual carry handling, including correct propagation accross the decimal boundary.


## Future implementation
  - Implementation of subtraction, multiplication, division, exponential and factorial
  - Transitioning form strings to digital arrays representation for efficiency
  - Optimisation memory usage, speed and performance

## Challenges
  - Alligning numbers with different lengths and decimal places
  - Avoiding buffer overflow during memory shifts and carry propagation
