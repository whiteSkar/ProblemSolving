#include <iostream>
#include <exception>

using namespace std;

class Stack
{
private:
	class Element
	{
	private:
		Element* next;
		int data;

	public:
		Element( Element* n = NULL, int value = 0 )
		{
			data = value;
			next = n;
		}
		~Element() {}
		int getData() { return data; }
		Element* getNext() { return next; }
	};

private:
	Element* head;

public:
	Stack()
	{
		head = NULL;
	}

	~Stack()
	{
		while ( head )
		{
			Element* temp = head->getNext();
			delete head;
			head = temp;
		}
	}

	void push( int data )
	{
		Element* elem = new Element( head, data );
		head = elem;
	}

	int pop()
	{
		if ( head )
		{
			Element* temp = head;
			head = head->getNext();
			int data = temp->getData();
			delete temp;
			
			return data;
		}

		throw exception();
	}

	void display()
	{
		Element* it = head;

		while ( it )
		{
			cout << it->getData() << " ";
			it = it->getNext();
		}
		cout << endl;
	}
};

int main()
{
	Stack st;
	st.display();

	st.push(1);
	st.push(2);
	st.push(3);
	st.display();

	st.pop();
	st.pop();
	st.display();

	st.pop();
	try
	{
		st.pop();
	}
	catch( exception e )
	{
		cout << "Catched an exception." << endl;
	}
	st.display();

	return 0;
}