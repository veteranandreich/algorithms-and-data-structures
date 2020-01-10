#include <iostream>

template <typename type>
struct Element
{
	type value;
	Element* next = nullptr;
};

template <typename type>
class SinglyLinkedList final
{	
private:
	Element <type>* top;
	Element <type>* bottom;
	size_t list_size;

public:
	SinglyLinkedList()
	{
		top = new Element <type>;
		bottom = new Element <type>;
		list_size = 0;
		top->next = bottom;
		bottom->next = top;
	}
	void Push(const type& element)
	{
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		new_element->next = top->next;
		top->next = new_element;
		if (list_size == 0)
		{
			bottom->next = new_element;
		}
		list_size++;
	}

	void Print()
	{
		Element <type>* element = top->next;
		while (element != bottom)
		{
			std::cout << element->value << std::endl;
			element = element->next;
		}
	}

	Element<type>* Find(const type& target)
	{
		if (list_size == 0)
		{
			return nullptr;
		}
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
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		bottom->next->next = new_element;
		bottom->next = new_element;
		new_element->next = bottom;
		list_size++;
	}

	void Insert(Element<type>* previous_element, const type& element)
	{
		Element <type>* new_element = new Element <type>;
		new_element->value = element;
		new_element->next = previous_element->next;
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
		if (list_size == 0)
		{
			return nullptr;
		}
		else
		{
			Element<type>* _ = top->next;
			top->next = top->next->next;
			list_size--;
			return _;
		}
	}

	size_t Size()
	{
		return list_size;
	}

	Element<type>* Begin()
	{
		if (list_size == 0)
		{
			return nullptr;
		}
		return top->next;
	}

	Element<type>* End()
	{
		if (list_size == 0)
		{
			return nullptr;
		}
		return bottom->next;
	}
	
	SinglyLinkedList<type>* Copy()
	{
		SinglyLinkedList<type>* new_list = new SinglyLinkedList();
		Element <type>* element = top->next;
		while ((element != nullptr) && (element != bottom))
		{
			new_list->Push_back(element->value);
			element = element->next;
		}
		return new_list;
	}
	
	void Sort()
	{

	}

	~SinglyLinkedList()
	{
		auto a = this->Pop();
		while (list_size != 0)
		{
			delete a;
			a = this->Pop();
		}
		delete top;
		delete bottom;
	}
};
