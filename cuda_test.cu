#include <stdio.h>

// Kernel
__global__ void bit_shift_test()
{
  unsigned long long one = 1;
  for (int i = 0; i <= 64; i++) {
    printf("(%llu << %d) - 1 = %llu\n", one, i, (one << i) - 1);
  }
  unsigned long long max = 18446744073709551615;
  for (int i = 0; i <= 64; i++) {
    printf("%llu >> %d = %llu\n", max, i, max >> i);
  }
}

// Main program
int main()
{
  // Launch kernel
  bit_shift_test<<<1, 1>>>();
  cudaError_t cuErrSync  = cudaGetLastError();
  cudaError_t cuErrAsync = cudaDeviceSynchronize();
  if (cuErrSync != cudaSuccess) { printf("CUDA Error - %s:%d: '%s'\n", __FILE__, __LINE__, cudaGetErrorString(cuErrSync)); exit(0); }
  if (cuErrAsync != cudaSuccess) { printf("CUDA Error - %s:%d: '%s'\n", __FILE__, __LINE__, cudaGetErrorString(cuErrAsync)); exit(0); }

  return 0;
}
