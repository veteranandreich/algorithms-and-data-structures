#include <iostream>

template<typename type>
struct Element
{
	type value;
	Element* next = nullptr;
	Element* prev = nullptr;
};

template<typename type>
class DoublyLinkesList
{
private:
	Element<type>* top = new Element<type>;
	Element<type>* bottom = new Element<type>;
	size_t size;

public:
	DoublyLinkesList()
	{
		top->next = bottom;
		bottom->prev = top;
		size = 0;
	}
	
	void Push(const type& value)
	{
		Insert(top, value);
	}

	void Push_back(const type& value)
	{
		Element<type>* new_element = new Element<type>;
		new_element->value = value;
		new_element->prev = bottom->prev;
		new_element->next = bottom;
		new_element->prev->next = new_element;
		size++;

	}

	void Insert(Element<type>* after_me, const type& value)
	{
		Element<type>* new_element = new Element<type>;
		new_element->next = after_me->next;
		new_element->prev = after_me;
		after_me->next->prev = new_element;
		after_me->next = new_element;
		new_element->value = value;
		size++;
	}

	void Print()
	{
		Element<type>* current_element = top->next;
		if (current_element == bottom) return;
		while (current_element != bottom)
		{
			std::cout << current_element->value << std::endl;
			current_element = current_element->next;
		}
	}

	size_t Size()
	{
		return size;
	}
};

