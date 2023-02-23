#include <iostream>
#include <string>
#include <ctime>
#include "windows.h"
#pragma once

class Node;

using namespace std;

class List
{
public:
	List();
	~List();

	void push_front(string data);
	void push_middle(string data);
	void push_back(string data);
	void pop_front();
	void pop_middle();
	void pop_back();
	void clear();
	int GetSize() { return size; }

	string& operator[](const int index);
private:
	class Node
	{
	public:
		Node *pNext, *pPrev;
		string data;

		Node(string data = "", Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

	};
	int size;
	Node *head, *tail;

};
