# Big Number Library Roadmap

## Current Issues
- [X] Fix carry propagation bugs in big_add
- [x] Remove string reversing (performance issue)
- [ ] switch to dynamic memory
- [ ] Replace ASCII storage with integer digits

> Will need a full rewrite for the last 2 in "Current Issues"

## Next Features
- [ ] Implement big multiplication
- [ ] Implement division
- [ ] Turn into library(add header file, etc...)
- [ ] Add benchmarking system
- [ ] Add an option to clean up the output(removing extra 0s, etc...)

## Optimizations
- [ ] Switch to base 10^9 storage / switch to uint_32t or uint_64t
- [ ] Reduce memory copying in format()
- [ ] Avoid repeated strlen calls

## Ideas (not started)
- [ ] Karatsuba multiplication
- [ ] FFT multiplication
- [ ] File-based big integers (disk storage)
