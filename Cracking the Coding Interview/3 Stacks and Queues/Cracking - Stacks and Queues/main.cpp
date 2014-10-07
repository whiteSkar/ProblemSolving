#include <iostream>
#include <stack>

using namespace std;

template <class T> class MyQueue
{
private:
	stack<T> stack1;
	stack<T> stack2;

public:
	MyQueue()
	{
	}

	~MyQueue()
	{
		// caller should deallocate each T since T can be either primitive or objects
	}
	
	void push(T data)
	{
		stack1.push(data);
	}

	void pop()
	{
		if (!stack2.empty())
			stack2.pop();
		else
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
		}
	}

	T top()
	{
		if (!stack2.empty())
			return stack2.top();
		else
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}

			return stack2.empty() ? NULL : stack2.top();
		}
	}
};

stack<int> sortStack(stack<int> st)
{
	stack<int> result;

	while (!st.empty())
	{
		int temp = st.top();
		st.pop();

		while (!result.empty() && temp < result.top())
		{
			st.push(result.top());
			result.pop();
		}
		result.push(temp);
	}
	
	return result;
}

int main()
{
	stack<int> myStack;
	myStack.push(2);
	myStack.push(0);
	myStack.push(1);
	myStack.push(5);
	myStack.push(6);
	myStack.push(3);
	
	myStack = sortStack(myStack);

	cout << "myStack is: " << endl;
	while (!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}
	cout << endl;

	cout << "myQueue is: " << endl;
	MyQueue<int> myQueue;
	myQueue.push(0);
	myQueue.push(1);
	myQueue.push(3);
	myQueue.push(2);
	myQueue.push(10);
	myQueue.push(9);
	myQueue.push(8);
	cout << myQueue.top() << endl;
	cout << myQueue.top() << endl;
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();
	cout << myQueue.top() << endl;
	myQueue.push(12);
	myQueue.push(20);
	
	cout << "myQueue at the end is:" << endl;
	while (myQueue.top())
	{
		cout << myQueue.top() << endl;
		myQueue.pop();
	}
	cout << endl;


	char c;
	cin >> c;
	return 0;
}