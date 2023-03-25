
#include <sys/time.h>
#include "osm.h"

static const int MILLION = 1000000;
static const int TO_NANO = 1000;
void empty_func ()
{}

unsigned int round_up (unsigned int iterations)
{
  return ((iterations + 9) / 10) * 10; // rounding iterations to the nearest
}

double osm_operation_time (unsigned int iterations)
{
  if (iterations == 0)
    {
      return -1;
    }
  [[maybe_unused]] unsigned short _;
  timeval starttime, endtime;
  long total_time = 0;
  iterations = round_up (iterations);
  // multiple of 5, as allowed in the ex1 pdf
  for (unsigned int i = 0; i < iterations; i += 10)
    {
      gettimeofday (&starttime, nullptr);
      _ = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11;
      gettimeofday (&endtime, nullptr);
      total_time += (endtime.tv_sec - starttime.tv_sec) * MILLION;
      total_time += endtime.tv_usec - starttime.tv_usec;
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
  iterations = round_up (iterations);
  // multiple of 10, as allowed in the ex1 pdf
  for (unsigned int i = 0; i < iterations; i += 10)
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
      total_time += (endtime.tv_sec - starttime.tv_sec) * MILLION;
      total_time += endtime.tv_usec - starttime.tv_usec;
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
  iterations = round_up (iterations);
  // multiple of 10, as allowed in the ex1 pdf
  for (unsigned int i = 0; i < iterations; i += 10)
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
      total_time += (endtime.tv_sec - starttime.tv_sec) * MILLION;
      total_time += endtime.tv_usec - starttime.tv_usec;
    }
  return (double) TO_NANO * total_time / iterations;
}
