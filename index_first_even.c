#include <stdio.h>
#include <index_first_even.h>

int index_first_even(int *array, int arrayLength) {
  int i;
  for (i=0; i<arrayLength; i++) {
       if (array[i] % 2 == 0)
       return i;
  }
}
