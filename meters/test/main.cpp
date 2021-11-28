#include "meters.h"
#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cmath>


int main() {
  Time start, end;
  getCurrentTime(&start);
  usleep(1550000);
  getCurrentTime(&end);

  double elapsedTime = getDuration(&start, &end, TimeUnits::Sec);
  double diff = std::abs(elapsedTime - 1.55);
  std::cout << "elapsed time, " << elapsedTime << ", sec\n"
            << "diff: " << diff << ", sec"
            << std::endl;
  assert(diff < 1e-2);
  return 0;
}
