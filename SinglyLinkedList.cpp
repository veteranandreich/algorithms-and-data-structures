#include <iostream>

template <typename type>
struct Element
{
	type value;
	Element* next = nullptr;
};

template <typename type>
class SinglyLinkedList 
{
	private:
		Element <type> *top = new Element <type>;

	public: 
		void Push(const type& element)
		{
			Element <type>* a = new Element <type>;
			a->next = top->next;
			a->value = element;
			top->next = a;
		};

		void Print()
		{
			Element <type> *element = top->next;
			while (element != nullptr) {
				std::cout << element->value << std::endl;;
				element = element->next;
			}
		};
};

int main()
{
	/*
	EXAMPLE:
	SinglyLinkedList <int> list;
	list.Push(5);
	list.Push(6);
	list.Push(7);
	list.Print(); 
	*/
}

