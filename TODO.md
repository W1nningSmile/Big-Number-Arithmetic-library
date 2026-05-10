# Big Number Library Roadmap

## Current Issues
- [X] Fix carry propagation bugs in big_add
- [ ] Remove string reversing (performance issue)
- [ ] Replace ASCII storage with integer digits 

## Next Features
- [ ] Implement big multiplication
- [ ] Implement division
- [ ] Add benchmarking system

## Optimizations
- [ ] Switch to base 10^9 storage / switch to uint_32t or uint_64t
- [ ] Reduce memory copying in format()
- [ ] Avoid repeated strlen calls

## Ideas (not started)
- [ ] Karatsuba multiplication
- [ ] FFT multiplication
- [ ] File-based big integers (disk storage)
