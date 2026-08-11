# Big-Number-Arithmetic-library (WIP)
A C library for performing arithmetic on integers larger than the CPU's native integer types, while maintaining exact precision.

## Development Status

This project is currently a work in progress.

Development was temporarily paused while I worked on a larger application. I am now returning to the project with additional experience and plans to improve its design, add new operations, and continue development.

## Motivation
C's built-in integer types are limited by their fixed sizes. This project explores how arbitrarily large integers can be represented and manipulated in C without relying on the CPU's native integer limits.

This project aims to explore how large numerical values can be used while keeping perfect precision, similar to how libraries like the GNU Multiple Precision Arithmetic library work internally.

## How it works

Numbers are currently represented as a 9 digit chunks.

EX: 1'234'567'895 -> [234567895, 1]

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

## Goals

The long-term goal is to build a functional arbitrary-precision arithmetic library from the ground up in C while gaining a deeper understanding of memory management, dynamic data structures, numerical representation, and low-level arithmetic.
