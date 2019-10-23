/* Даны целые числа 1≤n≤1018 и 2≤m≤105, необходимо найти остаток от деления n-го числа Фибоначчи на m.


Sample Input:

10 2
Sample Output:

1

*/


#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

class Fibonacci final {
 public:
  static int get_remainder(int64_t n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    std::vector <int64_t> remainders = {0, 1};
    int64_t cur = 1, prev = 0;
    for (int64_t i = 1; i < n; i++){
        remainders.push_back((remainders[remainders.size() - 2] + remainders.back()) % m);
        if ((remainders[remainders.size() - 2] == 0) && (remainders.back() == 1)){
            remainders.pop_back();
            remainders.pop_back();
            break;
        }
    }
    return remainders[n % remainders.size()];
  }
};

int main(void) {
  int64_t n;
  int m;
  std::cin >> n >> m;
  std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}