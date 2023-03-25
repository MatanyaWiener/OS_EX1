#include <iostream>
#include "osm.h"
#include <sys/time.h>

#define ADDITION_ITERATIONS 1000000
#define FUNCTION_CALL_ITERATIONS 1000000
#define SYSCALL_ITERATIONS 10000
int main ()
{
  std::cout << "The time it takes to make an addition operation: "
            << osm_operation_time (ADDITION_ITERATIONS) << std::endl;
  std::cout << "The time it takes to make a function call: " <<
            osm_function_time (FUNCTION_CALL_ITERATIONS) << std::endl;
  std::cout << "The time it takes to make a system call: " <<
            osm_syscall_time (SYSCALL_ITERATIONS) << std::endl;
  return 0;
}
