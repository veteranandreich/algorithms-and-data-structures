/* По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.

В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 0≤l≤r≤109, задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.

Sample Input 1:

3
1 3
2 5
3 6
Sample Output 1:

1
3 
Sample Input 2:

4
4 7
1 3
2 5
5 6
Sample Output 2:

2
3 6 

*/



#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

bool cmp(const Segment &a, const Segment &b){
    return (a.second < b.second);
    }

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;
  sort(segments.begin(), segments.end(), cmp);
  int right_border = segments[0].second;
  result.push_back(right_border);
  for (auto s : segments) {
    if ((s.first <= right_border) and (right_border <= s.second)) {
        continue;
    }
    else {
        result.push_back(s.second);
        right_border = s.second;
    }
  }

  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (auto &s:segments) {
    std::cin >> s.first >> s.second;
  }

  auto points = get_covering_set(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << " ";
  }
  std::cout << std::endl;
}