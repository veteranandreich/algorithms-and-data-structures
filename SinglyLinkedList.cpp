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
	Element <type>* top = new Element <type>;
	Element <type>* bottom = new Element <type>;
	void Push_first(const type& element)
	{
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		bottom->next = new_element;
		new_element->next = bottom;
		top->next = new_element;
	}

public:
	void Push(const type& element)
	{
		if (top->next == nullptr)
		{
			Push_first(element);
		}
		else
		{
			Element <type>* new_element = new Element <type>;
			new_element->value = element;
			new_element->next = top->next;
			top->next = new_element;
		}
	};

	void Print()
	{
		Element <type>* element = top->next;
		while (element != bottom)
		{
			std::cout << element->value << std::endl;
			element = element->next;
		}
	};

	Element<type>* Find(const type& target)
	{
		Element <type>* element = top->next;
		while (element != bottom)
		{
			if (element->value == target) return element;
			element = element->next;
		}

		return nullptr;
	}

	void Push_back(const type& element)
	{
		if (top->next == nullptr)
		{
			Push_first(element);
		}
		else
		{
			Element <type>* new_element = new Element <type>;
			new_element->value = element;
			new_element->next = bottom;
			bottom->next->next = new_element;
		}
	}


};

int main()
{
	/* 
	EXAMPLE:
	SinglyLinkedList <int> list;
	list.Push(5);
	list.Push(6);
	list.Push(7);
	list.Push_back(8);
	list.Print();
	Element <int>* b = list.Find(5);
	if (b != nullptr) std::cout << b->value; 
	*/
}
