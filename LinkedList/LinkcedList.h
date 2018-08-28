#pragma once

template<typename T>
struct NODE
{
	T data;
	NODE* next;
	NODE(T _data) : data(_data), next(nullptr) {}
};

template<typename T>
class LinkedList
{
private:
	NODE<T>* head;

public:
	LinkedList() : head(nullptr) {}

	bool InsertFront(T data);
	bool DeleteNode(NODE<T>* node);
	bool DeleteAll();
	const NODE<T>* GetHead() const;
	const T GetData(int index) const;
};

template<typename T>
inline bool LinkedList<T>::InsertFront(T data)
{
	NODE<T>* newNode = new NODE<T>(data);
	if (!newNode)
		return false;

	newNode->next = head;
	head = newNode;

	return true;
}

template<typename T>
inline bool LinkedList<T>::DeleteNode(NODE<T>* deleteNode)
{
	NODE<T>* pre = head;

	if (!head || !deleteNode)
		return false;

	if (head == deleteNode)
	{
		head = head->next;
		delete deleteNode;
		return true;
	}

	while (pre)
	{
		if (pre->next == deleteNode)
		{
			pre->next = deleteNode->next;
			delete deleteNode;
			return true;
		}
		pre = pre->next;
	}

	return false;
}

template<typename T>
inline bool LinkedList<T>::DeleteAll()
{
	NODE<T>* current = head;
	while (current)
	{
		NODE<T>* next = current->next;
		std::cout << "데이터 : " << current->data << " 삭제" << std::endl;
		delete current;
		current = next;
	}

	return true;
}

template<typename T>
inline const NODE<T>* LinkedList<T>::GetHead() const
{
	return head;
}

template<typename T>
inline const T LinkedList<T>::GetData(int index) const
{
	NODE<T>* current = head;
	if (!head)
		throw;

	for (int i = 0; i < index; i++)
	{
		if (current)
			current = current->next;
		else
			throw;
	}

	if (!current)
		throw;

	return current->data;
}
