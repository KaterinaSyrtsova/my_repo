#include <stdio.h>
#include "index_first_even.h"
#include "index_last_odd.h"
#include "index_first_even.h"
#include "index_last_odd.h"
#define MAX_NUMB 100

int main() {
  int array[MAX_NUMB];
  int i=0;
  int arg=0;
  int exit=0;
      scanf("%d ", &arg);
  while(1) {
      exit=scanf("%d", array+i);
          if (exit == -1) {
          break;
          }
      i++;
  }
    switch (arg) {

    case 0:
			printf ("%d\n", index_first_even(array, i));
    break;
    case 1:
			printf ("%d\n", index_last_odd(array, i));
	break;
    case 2:
		printf ("%d\n", sum_between_even_odd(array, i));
	break;
    case 3:
		printf ("%d\n", sum_before_even_and_after_odd(array, i));
	break;
    default:
    printf ("Данные некорректны\n");
    }
}
