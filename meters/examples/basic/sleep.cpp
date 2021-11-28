#include <iostream>
#include <unistd.h>


int main() {
  double elapsed{};

  #pragma meter time elapsed nsec
  {
    usleep(1550000);
  }

#ifdef _CLANG_PRAGMA_METER
  std::cout << "elapsed time: " << elapsed << ", nsec" << std::endl;
#endif

  return 0;
}
