# BLAS matrix operations

### Build and run

```
mkdir build && cd build
cmake .. && make
./matrix
```

### Measurements

Processor info:
- `Intel(R) Core(TM) i5-8250U CPU @ 1.60GHz` (CPU(s): 8)

Iterations: 100000

Matrix (vector) size: 3
- matrix x matrix multiplication: faster in **~ 3 - 7**
- matrix x vector multiplication: faster in **~ 2.5 - 4**

Matrix (vector) size: 4
- matrix x matrix multiplication: faster in **~ 3.5 - 8**
- matrix x vector multiplication: faster in **~ 3 - 4**
