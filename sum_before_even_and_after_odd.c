#include <stdio.h>

int sum_before_even_and_after_odd(int *array, int arrayLength) {
  int i;
  int sum_bef=0;
  for (i=0; i<index_first_even(array, arrayLength); i++) {
            sum_bef = sum_bef + abs(array[i]);
  }
  for (i=index_last_odd(array, arrayLength); i<arrayLength; i++) {
            sum_bef = sum_bef + abs(array[i]);
  }
  return sum_bef;
}
