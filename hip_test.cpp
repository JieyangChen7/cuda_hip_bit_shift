#include <stdio.h>
#include "hip/hip_runtime.h"

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
  hipError_t hipErrSync  = hipGetLastError();
  hipError_t hipErrAsync = hipDeviceSynchronize();
  if (hipErrSync != hipSuccess) { printf("HIP Error - %s:%d: '%s'\n", __FILE__, __LINE__, hipGetErrorString(hipErrSync)); exit(0); }
  if (hipErrAsync != hipSuccess) { printf("HIP Error - %s:%d: '%s'\n", __FILE__, __LINE__, hipGetErrorString(hipErrAsync)); exit(0); }

  return 0;
}
