# Big Number Library Rewrite Checklist

## Current Issues
- [ ] Test the addition function for edge cases and optimise
- [ ] Clean up and optimise current memory usage
- [ ] Rework the logic of the sub function to make it simpler and more efficient

## Fixed
- [x] Seperate the chunk converter into its own functiona and put it into func.c/func.h
- [x] Fix the bug where number lengths in multiples of 9 create an extra chunk
- [x] Store data in structs to make it easier to use (added a function that does the set up of a Big int for you)
