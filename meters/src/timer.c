#include "meters.h"
#include <time.h>
#include <stdio.h>

void getCurrentTime(struct Time* time) {
  struct timespec timeSpec;
  clock_gettime(CLOCK_REALTIME, &timeSpec);
  time->sec = (int64_t)timeSpec.tv_sec;
  time->nsec = (int64_t)timeSpec.tv_nsec;
}

enum _TimeUnits {
  _Sec = 0,
  _Msec,
  _Usec,
  _Nsec
};

double getDuration(struct Time* start, struct Time* end, int32_t units) {
  double secFactor;
  double nsecFactor;

  switch (units) {
    default:
    case _Sec: {
      secFactor = 1e0;
      nsecFactor = 1e-9;
      break;
    }
    case _Msec: {
      secFactor = 1e3;
      nsecFactor = 1e-6;
      break;
    }
    case _Usec: {
      secFactor = 1e6;
      nsecFactor = 1e-3;
      break;
    }
    case _Nsec: {
      secFactor = 1e9;
      nsecFactor = 1e0;
      break;
    }
  }

  double sec = secFactor * (double)(end->sec - start->sec);
  double nsec = nsecFactor * (double)(end->nsec - start->nsec);
  return sec + nsec;
}


void printDummyText() {
  printf("[meters] printing dummy text\n");
}
