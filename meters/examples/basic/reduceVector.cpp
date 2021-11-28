#include <iostream>
#include <vector>


int main() {
  std::vector<float> container{};
  float result{};
  double elapsedTime{};

  #pragma meter time elapsedTime usec
  {
    for (size_t i{0}; i < 1024; ++i) {
      container.push_back(static_cast<float>(i));
    }
    
    for (size_t i{0}; i < container.size(); ++i) {
      result += container[i];
    }

  }

#ifdef _CLANG_PRAGMA_METER
  std::cout << "elapsed time: " << elapsedTime << ", usec" << std::endl;
#endif

  std::cout << "result: " << result << std::endl;
  return result;
}
