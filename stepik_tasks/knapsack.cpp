/* Первая строка содержит количество предметов 1≤n≤103 и вместимость рюкзака 0≤W≤2⋅106. Каждая из следующих n строк задаёт стоимость 0≤ci≤2⋅106 и объём 0<wi≤2⋅106 предмета (n, W, ci, wi — целые числа). Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.

Sample Input:

3 50
60 20
100 50
120 30
Sample Output:

180.000

*/



#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
  double weight;
  double value;
};

bool cmp(const Item &a, const Item &b){
    return (a.value/a.weight > b.value/b.weight);
    }

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
  double value = 0.0;

  sort(items.begin(), items.end(), cmp);
  for (auto &item:items) {
    if (capacity > item.weight) {
      capacity -= item.weight;
      value += item.value;
    } else {
      value += item.value * (static_cast <double>(capacity) / item.weight);
      break;
    }
  }

  return value;
}

int main(void) {
  int number_of_items;
  int knapsack_capacity;
  std::cin >> number_of_items >> knapsack_capacity;
  std::vector <Item> items(number_of_items);
  for (int i = 0; i < number_of_items; i++) {
    std::cin >> items[i].value >> items[i].weight;
  }

  double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

  std::cout.precision(10);
  std::cout << max_knapsack_value << std::endl;
  return 0;
}