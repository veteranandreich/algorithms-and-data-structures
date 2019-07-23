""" Задача №1
По данной непустой строке s длины не более 104, состоящей из строчных букв латинского алфавита, постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках запишите коды букв в формате "letter: code". В последней строке выведите закодированную строку.


Sample Input 1:

a

Sample Output 1:

1 1
a: 0
0
Sample Input 2:

abacabad

Sample Output 2:

4 14
a: 0
b: 10
c: 110
d: 111
01001100100111

Задача №2

Восстановите строку по её коду и беспрефиксному коду символов. 

В первой строке входного файла заданы два целых числа k и l через пробел — количество различных букв, встречающихся в строке, и размер получившейся закодированной строки, соответственно. В следующих k строках записаны коды букв в формате "letter: code". Ни один код не является префиксом другого. Буквы могут быть перечислены в любом порядке. В качестве букв могут встречаться лишь строчные буквы латинского алфавита; каждая из этих букв встречается в строке хотя бы один раз. Наконец, в последней строке записана закодированная строка. Исходная строка и коды всех букв непусты. Заданный код таков, что закодированная строка имеет минимальный возможный размер.

В первой строке выходного файла выведите строку s. Она должна состоять из строчных букв латинского алфавита. Гарантируется, что длина правильного ответа не превосходит 104 символов.

Sample Input 1:

1 1
a: 0
0
Sample Output 1:

a
Sample Input 2:

4 14
a: 0
b: 10
c: 110
d: 111
01001100100111
Sample Output 2:

abacabad
"""


import heapq
from collections import Counter


class Node:
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def walk(self, code, pref):
        self.left.walk(code, pref + "0")
        self.right.walk(code, pref + "1")


class Leaf:
    def __init__(self, char):
        self.char = char

    def walk(self, code, pref):
        code[self.char] = pref or "0"


def huffman_decode(en, codes):
    pointer = 0
    decoded_str = ''
    while pointer < len(en):
        for c in codes:
            if en.startswith(codes[c], pointer):
                decoded_str += c
                pointer += len(codes[c])
    return decoded_str


def huffman_encode(s):
    freq_list = []
    for c, freq in Counter(s).items():
        freq_list.append((freq, len(freq_list), Leaf(c)))
    heapq.heapify(freq_list)
    count = len(freq_list)
    while len(freq_list) > 1:
        freq1, _, left = heapq.heappop(freq_list)
        freq2, _, right = heapq.heappop(freq_list)
        heapq.heappush(freq_list, (freq1 + freq2, count, Node(left, right)))
        count += 1
    code = {}
    if freq_list:
        freq_list[0][2].walk(code, "")
    return code


def main_encode():
    string = input()
    code = huffman_encode(string)
    encoded = "".join(code[c] for c in string)
    print(len(code), len(encoded))
    for c in code:
        print(f'{c}: {code[c]}')
    print(encoded)


def main_decode():
    code_length, encoded_length = map(int, input().split())
    codes = {}
    for _ in range(code_length):
        c, code = input().split(": ")
        codes[c] = code
    encoded = input()
    decoded = huffman_decode(encoded, codes)
    print(decoded)


if __name__ == "__main__":
    main_decode()
