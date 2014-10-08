#include <iostream>

using namespace std;

class StackEmptyException : public exception
{
public:
    StackEmptyException()
    {

    }
};

class Stack
{
private:
    class Node
    {
    private:
        Node* next;
        int data;

    public:
        Node(int value = 0, Node* nextNode = NULL)
        {
            data = value;
            next = nextNode;
        }
        ~Node() {}

        int getData()
        {
            return data;
        }
        
        Node* getNext()
        {
            return next;
        }
    };

    Node* head;

public:
    Stack()
    {
        head = NULL;
    }
    ~Stack()
    {
        emptyStack();
    }

    void push(int data)
    {
        Node* newNode = new Node(data, head);
        head = newNode;
    }

    int pop()
    {
        if (!head)
            throw StackEmptyException();

        int data = head->getData();
        Node* temp = head->getNext();
        delete head;
        head = temp;
        
        return data;
    }

    void displayStack()
    {
        Node* it = head;

        while (it)
        {
            cout << it->getData() << " ";
            it = it->getNext();
        }
        cout << endl;
    }

private:
    void emptyStack()
    {
        Node* temp = head;
        
        while (head)
        {
            temp = head->getNext();
            delete head;
            head = temp;
        }
    }
};

int main(int argc, char* argv[])
{
    Stack* myStack = new Stack();

    myStack->push(10);
    myStack->push(15);
    myStack->push(30);
    myStack->displayStack();

    myStack->pop();
    myStack->displayStack();
    myStack->pop();
    myStack->displayStack();
    myStack->pop();
    myStack->displayStack();

    try
    {
        myStack->pop();
    }
    catch (exception e)
    {
        cout << "Exception is properly thrown." << endl;
    }

    char c;
    cin >> c;
    return 0;
}