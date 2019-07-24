#include <iostream>
#include <string>
#include <vector>
class Heap {
private:

	std::vector<unsigned long> tree;

	void siftUp() {
		unsigned long i = tree.size() - 1;
		while (i > 0) {
			if (tree[i] > tree[(i - 1) / 2]) {
				std::swap(tree[i], tree[(i - 1) / 2]);
				i = (i - 1) / 2;
			}
			else {
				break;
			}
		}
	}

	void siftDown() {
		unsigned long i = 0, n = tree.size();
		while (2 * i + 1 < n) {
			if (2 * i + 2 < n) {
				if ((tree[i] < tree[2 * i + 2]) && (tree[2 * i + 1] < tree[2 * i + 2])) {
					std::swap(tree[i], tree[2 * i + 2]);
					i = 2 * i + 2;
				}

				else {
					if (tree[i] < tree[2 * i + 1]) {
						std::swap(tree[i], tree[2 * i + 1]);
						i = 2 * i + 1;
					}

					else {
						break;
					}
				}
			}

			else {
				if (tree[i] < tree[2 * i + 1]) {
					std::swap(tree[i], tree[2 * i + 1]);
					i = 2 * i + 1;
				}

				else {
					break;
				}
			}
		}
	}

public:

	unsigned long ExtractMax() {
		if (!tree.empty()) {
			unsigned long result = tree[0];
			tree[0] = tree[tree.size() - 1];
			tree.erase(tree.end() - 1);
			siftDown();
			return result;
		}

		else {
			return -1;
		}
	}

	void Insert(int value) {
		tree.push_back(value);
		siftUp();
	}

};

int main() {
	int commands_amount = 0;
	std::cin >> commands_amount;
	Heap heap;
	for (int i = 0; i < commands_amount; i++) {
		std::string str;
		std::cin >> str;
		if (str == "Insert") {
			unsigned long digit = 0;
			std::cin >> digit;
			heap.Insert(digit);
		}
		else {
			if (str == "ExtractMax") {
				std::cout << heap.ExtractMax() << std::endl;
			}
		}
	}
	return 0;
}