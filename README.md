# CUDA and HIP behave differently on bit shift operations
Tested on CUDA 10.1 and ROCM 3.9.0
* Output from CUDA:
```
(1 << 64) - 1 = 18446744073709551615
18446744073709551615 >> 64 = 0
```
* Output from HIP:
```
(1 << 64) - 1 = 0
18446744073709551615 >> 64 = 18446744073709551615
```
