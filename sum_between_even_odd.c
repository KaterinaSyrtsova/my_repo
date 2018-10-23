#include <stdio.h>

int sum_between_even_odd(int *array, int arrayLength) {
  int i;
  int sum_bet = 0;
  for (i=index_first_even(array, arrayLength); i<index_last_odd(array, arrayLength); i++) {
        sum_bet = sum_bet + abs(array[i]);
  }
return sum_bet;
}
