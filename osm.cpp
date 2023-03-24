//
// Created by wmata on 24/03/2023.
//
#include osm.h


void empty_function(){
  return;
}

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){
  if (iterations == 0){
    return -1;
  }
  double sum = 0;
  for(int i=0; i < iterations; i++){
      int t0 = gettimeofday();
      12 + 22;
      int t1 = gettimeofday();
      sum += t1- t0
  }
  return sum / iterations;
}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations){
  if (iterations == 0){
      return -1;
    }
  double sum = 0;
  for(int i=0; i < iterations; i++){
      int t0 = gettimeofday();
      empty_function();
      int t1 = gettimeofday();
      sum += t1- t0
    }
  return sum / iterations;
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
  if (iterations == 0){
      return -1;
    }
  double sum = 0;
  for(int i=0; i < iterations; i++){
      int t0 = gettimeofday();
      OSM_NULLSYSCALL();
      int t1 = gettimeofday();
      sum += t1- t0
    }
  return sum / iterations;
}

