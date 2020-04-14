#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_OF_DIMS 6
#define NS 10

size_t bresenhamLineArbitrary(int [], int []);

int main(void){
  int from[NUM_OF_DIMS], to[NUM_OF_DIMS];
  size_t totalSteps;

  srand(time(0));
  for(int i=0; i<NUM_OF_DIMS; ++i){
    from[i] = (int)(rand()%(1<<NS)) - (1<<(NS-1));
    to[i] = (int)(rand()%(1<<NS)) - (1<<(NS-1));
    printf("dim_%d: from %d to %d\n", i, from[i], to[i]);
  }
  totalSteps = bresenhamLineArbitrary(from, to);
  printf("Total steps = %d", totalSteps);
  return 0;
}

size_t bresenhamLineArbitrary(int from[], int to[]){
  int current[NUM_OF_DIMS],
      err[NUM_OF_DIMS],
      absDiffx2[NUM_OF_DIMS],
      inc[NUM_OF_DIMS];
  int diff, absDiff;
  size_t steps = 0;

  for(int i=0; i<NUM_OF_DIMS; ++i){
    current[i] = from[i];
    diff = to[i] - from[i];
    inc[i] = (diff>0) - (diff<0);

    absDiff = abs(diff);
    absDiffx2[i] = 2*absDiff;
    if (absDiff > steps){ /* get minimum needed steps  */
      steps = absDiff;
    }
  }

  for(int i=0; i<NUM_OF_DIMS; ++i){
    err[i] = absDiffx2[i] - steps;
  }

  for(int j=0; j<steps; ++j){
    for(int i=0; i<NUM_OF_DIMS; ++i){
      if (err[i] > 0) {
        current[i] += inc[i];
        err[i] -= steps*2;
      }
      err[i] += absDiffx2[i];
      printf("%d  ", current[i]);
    }
    printf("\n");
  }
  return steps;
}
