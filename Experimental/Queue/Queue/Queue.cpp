#include <iostream>

using namespace std;

class Queue
{
private:
    class Node
    {
    private:
        Node* next;
        int data;

    public:
        Node(int value, Node* nextNode)
        {
            data = value;
            next = nextNode;
        }

        ~Node() {}

        void setNext(Node* nextNode) { next = nextNode; }
        Node* getNext() { return next; }
        int getData() { return data; }
    };

    Node* head;
    Node* tail;

public:
    Queue() { head = NULL; tail = NULL; }
    ~Queue() { emptyList(); }

    void enqueue(int data)
    {
        Node* newNode = new Node(data, NULL);

        if (tail)
        {
            tail->setNext(newNode);
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
    }

    int dequeue()
    {
        if (!head) throw exception();
        
        Node* nodeToDequeue = head;
        int data = nodeToDequeue->getData();

        head = head->getNext();
        if (!head)
        {
            tail = NULL;
        }
        
        delete nodeToDequeue;
        return data;
    }

    void displayQueue()
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
    void emptyList()
    {
        Node* temp;

        while (head)
        {
            temp = head->getNext();
            delete head;
            head = temp;
        }
        tail = NULL;
    }            
};

int main()
{
    Queue* myQueue = new Queue();
    myQueue->displayQueue();

    myQueue->enqueue(1);
    myQueue->displayQueue();
    myQueue->enqueue(2);
    myQueue->displayQueue();

    cout << myQueue->dequeue() << endl;
    myQueue->displayQueue();
    cout << myQueue->dequeue() << endl;
    myQueue->displayQueue();

    try
    {
        myQueue->dequeue();
    }
    catch (exception e)
    {
        cout << "Exception properly thrown" << endl;
    }

    char c;
    cin >> c;
    return 0;
}
