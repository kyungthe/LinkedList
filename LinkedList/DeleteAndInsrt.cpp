/*

링크드리스트에서

head와 tail이 전역으로 주어졌을 때 삭제와 추가를 하는 함수를 작성.

원소가 0개일 때, 1개일 때, 3개일 때 모두 생각해야 한다.

*/


#include <iostream>

using namespace std;

struct Element
{
	int data;
	Element* next;
};

Element* head;
Element* tail;

bool Delete(Element* elem)
{
	if (!elem)
		return false;		// 없으면 마지막 노드의 다음 노드를 탐색해서 에러남(중요)

	Element* pre = head;

	if (head == elem)
	{
		if (head == tail)		// 원소가 한 개뿐이면
			tail = nullptr;
		head = head->next;
		delete elem;
		/*if (!head)
		tail = nullptr;		// 원소가 한 개뿐이면
		*/
		return true;
	}

	while (pre)
	{
		if (pre->next == elem)
		{
			if (pre->next == tail)
				tail = pre;
			pre->next = elem->next;
			delete elem;
			/*if(pre->next == nullptr)
			tail = pre;					이것도 가능
			*/
			return true;
		}
		pre = pre->next;
	}

	return false;
}

bool insertAfter(Element* elem, int data)
{
	Element* newElem = new Element();
	newElem->data = data;

	if (!elem)
	{
		newElem->next = head->next;
		head = newElem;
		if (!tail)
			tail = head;
		return true;
	}

	Element* pre = head;
	while (pre)
	{
		if (pre == elem)
		{
			newElem->next = pre->next;
			pre->next = newElem;
			if (pre == tail)
				tail = newElem;
			return true;
		}
		pre = pre->next;
	}

	return false;
}

int main()
{


	return 0;
}