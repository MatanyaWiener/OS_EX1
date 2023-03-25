
#include <sys/time.h>
#include "osm.h"

#define MILLION 1000000
void empty_func ()
{}

double osm_operation_time (unsigned int iterations)
{
  if (iterations == 0)
  {
    return -1;
  }
  timeval starttime, endtime;
  long total_time = 0;
  iterations =
      ((iterations + 9) / 10) * 10; // rounding iterations to the nearest
  // multiple of 5, as allowed in the ex1 pdf
  for (int i = 0; i < iterations; i += 10)
  {
    gettimeofday (&starttime, nullptr);
    1 + 1;
    2 + 2;
    3 + 3;
    4 + 4;
    5 + 5;
    1 + 1;
    2 + 2;
    3 + 3;
    4 + 4;
    5 + 5;
    gettimeofday (&endtime, nullptr);
    long seconds = endtime.tv_sec - starttime.tv_sec;
    long microseconds = endtime.tv_usec - starttime.tv_usec;
    if (microseconds < 0)
    {
      seconds--;
      microseconds += MILLION;
    }
    total_time += (seconds * MILLION) + microseconds;
  }
  return (double) total_time * TO_NANO / iterations;
}

double osm_function_time (unsigned int iterations)
{
  if (iterations == 0)
  {
    return -1;
  }
  timeval starttime, endtime;
  long total_time = 0;
  iterations =
      ((iterations + 9) / 10) * 10; // rounding iterations to the nearest
  // multiple of 10, as allowed in the ex1 pdf
  for (int i = 0; i < iterations; i += 10)
  {
    gettimeofday (&starttime, nullptr);
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    empty_func ();
    gettimeofday (&endtime, nullptr);
    long seconds = endtime.tv_sec - starttime.tv_sec;
    long microseconds = endtime.tv_usec - starttime.tv_usec;
    if (microseconds < 0)
    {
      seconds--;
      microseconds += MILLION;
    }
    total_time += (seconds * MILLION) + microseconds;
  }
  return (double) total_time * TO_NANO / iterations;
}

double osm_syscall_time (unsigned int iterations)
{
  if (iterations == 0)
  {
    return -1;
  }
  timeval starttime, endtime;
  long total_time = 0;
  iterations =
      ((iterations + 9) / 10) * 10; // rounding iterations to the nearest
  // multiple of 10, as allowed in the ex1 pdf
  for (int i = 0; i < iterations; i += 10)
  {
    gettimeofday (&starttime, nullptr);
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    OSM_NULLSYSCALL;
    gettimeofday (&endtime, nullptr);
    long seconds = endtime.tv_sec - starttime.tv_sec;
    long microseconds = endtime.tv_usec - starttime.tv_usec;
    if (microseconds < 0)
    {
      seconds--;
      microseconds += MILLION;
    }
    total_time += (seconds * MILLION) + microseconds;
  }
  return (double) TO_NANO * total_time / iterations;
}
