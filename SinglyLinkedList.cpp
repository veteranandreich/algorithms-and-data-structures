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
	size_t list_size = 0;
	void Push_first(const type& element)
	{
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		bottom->next = new_element;
		top->next = new_element;
		list_size++;
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
			list_size++;
		}
	}

	void Print()
	{
		Element <type>* element = top->next;
		while (element != nullptr)
		{
			std::cout << element->value << std::endl;
			element = element->next;
		}
	}

	Element<type>* Find(const type& target)
	{
		Element <type>* element = top->next;
		while (element != nullptr)
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
			bottom->next->next = new_element;
			bottom->next = new_element;
			list_size++;
		}
	}

	void Insert(Element<type>* previous_element, const type& element)
	{
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		if (previous_element->next == nullptr) bottom->next = new_element;
		else new_element->next = previous_element->next;
		previous_element->next = new_element;
		list_size++;
	}

	void Erase(Element<type>* previous_element)
	{
		if (previous_element->next != nullptr)
		{
			Element<type>* _ = previous_element->next->next;
			delete previous_element->next;
			previous_element->next = _;
			list_size--;
		}
	}

	Element<type>* Pop()
	{
		Element<type>* _ = top->next;
		top->next = top->next->next;
		list_size--;
		return _;
	}

	size_t Size()
	{
		return list_size;
	}

	Element<type>* Begin()
	{
		return top->next;
	}

	Element<type>* End()
	{
		return bottom->next;
	}

};

int main()
{
	//Example Program:
	/* 
	SinglyLinkedList <int> list;
	list.Push(5);
	list.Push_back(8);
	Element <int>* b = list.Find(5);
	list.Insert(b, 6);
	list.Insert(b, 7);
	for (Element <int>* b = list.Begin(); b != nullptr; b = b->next)
	{
		std::cout << b->value<< std::endl;
	}
	*/
}
