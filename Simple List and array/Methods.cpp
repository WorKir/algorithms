#include "List.h"

using namespace std;

List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	clear();
}

void List::push_front(string data)
{
	if (tail == nullptr)
	{
		tail = head = new Node(data);
	}
	else
	{
		Node *current = this->tail;
		while (current->pPrev != nullptr)
		{
			current = current->pPrev;
		}
		this->head = current->pPrev = new Node(data);
		current->pPrev->pNext = current;
	}
	size++;
}

void List::push_middle(string data)
{
	if (size > 1)
	{
		int index = size / 2;
		//cout << "Enert index of the element: ";
		//cin >> index;
		if (index <= size)
		{
			int count = 0;

			Node *newEl = new Node(data);
			Node *current = head;
			while (count != index - 1)
			{
				current = current->pNext;
				count++;
			}
			newEl->pPrev = current;
			newEl->pNext = current->pNext;
			current->pNext->pPrev = newEl;
			current->pNext = newEl;
			size++;
		}
		else { cout << "Item doesn't exist" << endl; }
	}
	else { push_back(data); }
}

void List::push_back(string data)
{
	if (head == nullptr)
	{
		tail = head = new Node(data);
	}
	else
	{
		Node *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		this->tail = current->pNext = new Node(data);
		current->pNext->pPrev = current;
	}
	size++;
}

void List::pop_front()
{
	if (size)
	{
		Node *temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
	else{ cout << "List is empty" << endl; }
}

void List::pop_middle()
{
	if (size)
	{
		int index = size/2;
		//cout << "Enert index of the element: ";
		//cin >> index;
		int count = 0;
		Node *current = head;
		while (count != index - 1)
		{
			current = current->pNext;
			count++;
		}
		current->pNext->pPrev = current->pPrev;
		current->pPrev->pNext = current->pNext;
		delete current;
		size--;
	}
	else { cout << "List is empty" << endl; }
}

void List::pop_back()
{
	if (size)
	{
		Node *temp = tail;
		tail = tail->pPrev;
		delete temp;
		size--;
	}
	else { cout << "List is empty" << endl; }
}

void List::clear()
{
	if (size)
	{
		while (size)
		{
			pop_front();
		}
	}
	else { cout << "List is empty" << endl; }
}

string& List::operator[](const int index)
{
	int count = 0;
	Node *current = this->head;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}
