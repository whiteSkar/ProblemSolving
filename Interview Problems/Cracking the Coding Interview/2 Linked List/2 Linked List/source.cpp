#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Node
{
private:
	Node* next;
	int data;

public:
	Node(int data)
	{
		next = NULL;
		this->data = data;
	}
	~Node() {}

	void setNext(Node* next)
	{
		this->next = next;
	}
	void setData(int data)
	{
		this->data = data;
	}

	Node* getNext()
	{
		return next;
	}

	int getData()
	{
		return data;
	}
};

void removeDuplicates(Node* head)
{
	if (!head) throw exception();

	unordered_map <int, bool> hashMap;
	hashMap.insert(pair<int, bool>(head->getData(), true));
	
	while (head->getNext())
	{
		Node* temp = head;
		head = head->getNext();

		if (hashMap.find(head->getData()) == hashMap.end())
		{
			hashMap.insert(pair<int, bool>(head->getData(), true));
		}
		else
		{
			temp->setNext(head->getNext());
			delete head;
			head = temp;
		}
	}
}

void removeDuplicateWithNoAdditionalMemory(Node* head)
{
	if (!head) throw exception();

	Node* curNode = head;

	while (curNode->getNext())
	{
		int data = curNode->getNext()->getData();
		Node* it = head;
		bool isDup = false;

		while (it != curNode->getNext())
		{
			if (it->getData() == data)
			{
				isDup = true;
				break;
			}
			it = it->getNext();
		}

		if (isDup)
		{
			Node* temp = curNode->getNext();
			curNode->setNext(curNode->getNext()->getNext());
			delete temp;
			continue;
		}
		curNode = curNode->getNext();
	}
}

Node* findNthToTheLastNode(Node* head, int n)
{
	if (!head || n < 0) throw exception();

	int length = 0;
	Node* it = head;
	
	while (it)
	{
		length++;
		it = it->getNext();
	}

	if (n >= length) throw exception();

	int m = length - n - 1;
	for (int i = 0; i < m; ++i)
		head = head->getNext();

	return head;
}

void deleteThisNode(Node* node)	// Assume it's in the middle
{
	if (!node)
		throw exception();

	Node* nextNode = node->getNext();

	node->setData(nextNode->getData());
	node->setNext(nextNode->getNext());
	delete nextNode;
}

Node* addTwoNumbers(Node* node1, Node* node2)
{
	if (!node1 || !node2) throw exception();

	Node* head = NULL;
	int carry = 0;

	while (node1 && node2)
	{
		int result = node1->getData() + node2->getData() + carry;

		if (result > 9)
		{
			carry = 1;
			result = result % 10;	// or -10
		}
		else
		{
			carry = 0;
		}

		Node* temp = head;
		head = new Node(result);
		head->setNext(temp);
		node1 = node1->getNext();
		node2 = node2->getNext();
	}

	while (node1)
	{
		int result = node1->getData() + carry;
		if (result > 9)
		{
			carry = 1;
			result -= 10;
		}
		else
		{
			carry = 0;
		}
		
		Node* temp = head;
		head = new Node(result);
		head->setNext(temp);
		node1 = node1->getNext();
	}

	while (node2)
	{
		int result = node2->getData() + carry;
		if (result > 9)
		{
			carry = 1;
			result -= 10;
		}
		else
		{
			carry = 0;
		}
		
		Node* temp = head;
		head = new Node(result);
		head->setNext(temp);
		node2 = node2->getNext();
	}

	return head;
}

Node* getStartOfCyclic(Node* head)
{
	if (!head) throw exception();

	Node* faster = head;
	Node* slower = head;

	do
	{
		faster = faster->getNext()->getNext();
		slower = slower->getNext();
	} while (faster != slower);

	slower = head;

	while (slower != faster)
	{
		slower = slower->getNext();
		faster = faster->getNext();
	}

	return faster;
}

void displayList(Node* root)
{
	while (root)
	{
		cout << root->getData() << " ";
		root = root->getNext();
	}
	cout << endl;
}

void deleteList(Node* root)
{
	if (!root) throw exception();

	while (root)
	{
		Node* temp = root;
		root = root->getNext();
		delete temp;
	}
}


int main()
{
	Node* root = new Node(0);
	Node* one = new Node(1);
	Node* two = new Node(2);
	Node* three = new Node(3);
	Node* four = new Node(4);
	Node* five = new Node(5);
	Node* dupOne = new Node(1);
	Node* dupThree = new Node(3);

	root->setNext(one);
	one->setNext(two);
	two->setNext(three);
	three->setNext(dupThree);
	dupThree->setNext(four);
	four->setNext(five);
	five->setNext(dupOne);

	displayList(root);
	removeDuplicateWithNoAdditionalMemory(root);
	displayList(root);

	int n = 2;
	cout << n << "th to the last node is: " << findNthToTheLastNode(root, n)->getData() << endl;

	//deleteThisNode(four);	// This complicate the last function
	displayList(root);

	Node* num1 = new Node(3);
	Node* num12 = new Node(1);
	Node* num13 = new Node(5);

	Node* num2 = new Node(5);
	Node* num22 = new Node(9);
	Node* num23 = new Node(2);

	num1->setNext(num12);
	num12->setNext(num13);
	num2->setNext(num22);
	num22->setNext(num23);

	displayList(num1);
	cout << "         + " << endl;
	displayList(num2);
	cout << "----------" << endl;
	Node* result = addTwoNumbers(num1, num2);
	displayList(result);

	five->setNext(one);
	cout << "Start of cyclic is: " << getStartOfCyclic(root)->getData() << endl;
	five->setNext(NULL);

	deleteList(num1);
	deleteList(num2);
	deleteList(result);
	deleteList(root);
	char c;
	cin >> c;
	return 0;
}