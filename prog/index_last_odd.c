#include <stdio.h>

int index_last_odd(int *array, int arrayLength) {
  int odd = arrayLength;
  int i;
  for (i=arrayLength-1; i>-1; i--) {
        if (array[i] % 2 != 0){
            odd=i;
            break;
        }
  }
  return odd;
}
