/*

��ũ�帮��Ʈ����

head�� tail�� �������� �־����� �� ������ �߰��� �ϴ� �Լ��� �ۼ�.

���Ұ� 0���� ��, 1���� ��, 3���� �� ��� �����ؾ� �Ѵ�.

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
		return false;		// ������ ������ ����� ���� ��带 Ž���ؼ� ������(�߿�)

	Element* pre = head;

	if (head == elem)
	{
		if (head == tail)		// ���Ұ� �� �����̸�
			tail = nullptr;
		head = head->next;
		delete elem;
		/*if (!head)
		tail = nullptr;		// ���Ұ� �� �����̸�
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
			tail = pre;					�̰͵� ����
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