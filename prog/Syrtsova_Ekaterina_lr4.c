#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define N 1000
int sort (const void * a, const void * b){
    return ( abs(*(int*)b) - abs(*(int*)a) );
}
int main (){
    int arr[N];
    int* res1;
    clock_t start1;
    clock_t end1;
  
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
  
    start1 = clock();
    qsort (&arr, N, sizeof (int), sort);
    end1 = clock();
    
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n%f", 1.0 * (end1-start1)/ CLOCKS_PER_SEC);
    
  return 0;
} 
