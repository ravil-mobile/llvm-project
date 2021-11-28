#ifndef METERS_H_
#define METERS_H_

#include <stdint.h>

#define MANGLE( NAME ) clangmeterslib_##NAME
#define Time MANGLE(Time)
#define TimeUnits MANGLE(TimeUnits)
#define getCurrentTime MANGLE(getCurrentTime)
#define getDuration MANGLE(getDuration)
#define printDummyText MANGLE(printDummyText)


#ifdef __cplusplus
// CPP enum for testing
enum TimeUnits {
  Sec = 0,
  Msec,
  Usec,
  Nsec
};

extern "C" {
#endif

/*
* A wrapper struct for time for a convenient
* code generation for `#pragma time`
* */
struct Time {
  int64_t sec;
  int64_t nsec;
};

void getCurrentTime(struct Time* start);
double getDuration(struct Time* start, struct Time* end, int32_t units);
void printDummyText();

#ifdef __cplusplus
}
#endif

#endif  // METERS_H_
