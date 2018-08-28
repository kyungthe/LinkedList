#include <iostream>
#include "MyStack.h"

using namespace std;

int main()
{
	MyStack<int> myStack;

	for (int i = 0; i < 10; i++)
		myStack.Push(i);
	
	/*int size = static_cast<int>(myStack.Size());
	for (int i = 0; i < size; i++)
		cout << myStack.Pop() << endl;*/

	return 0;
}