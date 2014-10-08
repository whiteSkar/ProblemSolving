#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

void printPermutationsHelper(string str, string permutatedString)
{
	if (str.length() == 0)
	{
		cout << permutatedString << endl;
		return;
	}

	for (unsigned int i = 0; i < str.length(); ++i)
		printPermutationsHelper(str.substr(0, i) + str.substr(i + 1), permutatedString + str[i]);
}

void printPermutations(string str)
{
	if (str.length() == 0) return;

	printPermutationsHelper(str, "");
}

void printPermutationsHelper(string str, string permutatedString, int m)
{
	if (permutatedString.length() == m)
	{
		cout << permutatedString << endl;
		return;
	}

	for (unsigned int i = 0; i < str.length(); ++i)
		printPermutationsHelper(str.substr(0, i) + str.substr(i + 1), permutatedString + str[i], m);
}

void printPermutations(string str, int m)
{
	int length = str.length();
	if (length == 0 || m == 0) return;
	if (m < 0 || m > length) throw exception();

	printPermutationsHelper(str, "", m);
}

void printPermutationsAllowRepHelper(string str, string permutatedString, int m)
{
	if (permutatedString.length() == m)
	{
		cout << permutatedString << endl;
		return;
	}

	for (unsigned int i = 0; i < str.length(); ++i)
		printPermutationsAllowRepHelper(str, permutatedString + str[i], m);
}

void printPermutatedAllowReps(string str, int m)
{
	int length = str.length();
	if (length == 0 || m == 0) return;
	if (m < 0 || m > length) throw exception();

	printPermutationsAllowRepHelper(str, "", m);
}

void printCombinationsHelper(string str, string combinatedString, int m)
{
	if (combinatedString.length() == m)
	{
		cout << combinatedString << endl;
		return;
	}

	for (unsigned int i = 0; i < str.length(); ++i)
		printCombinationsHelper(str.substr(i + 1), combinatedString + str[i], m);
}

void printCombinations(string str, int m)
{
	int length = str.length();
	if (length == 0 || m == 0) return;
	if (m < 0 || length < m) throw exception();

	printCombinationsHelper(str, "", m);
}

typedef struct node Node;
struct node
{
	int data;
	Node* left;
	Node* right;
};

typedef pair<Node*, int> nodeLevelPair;
void printTreeLevelByLevel(Node* root)
{
	if (!root) throw exception();

	queue<nodeLevelPair> unvisitedNodes;
	int curLevel = 0;

	unvisitedNodes.push(nodeLevelPair(root, curLevel));

	while (!unvisitedNodes.empty())
	{
		nodeLevelPair curPair = unvisitedNodes.front();
		unvisitedNodes.pop();
		Node* curNode = curPair.first;
		
		if (curLevel != curPair.second)
		{
			cout << endl;
			curLevel = curPair.second;
		}

		if (curNode->left)
			unvisitedNodes.push(nodeLevelPair(curNode->left, curLevel + 1));
		if (curNode->right)
			unvisitedNodes.push(nodeLevelPair(curNode->right, curLevel + 1));

		cout << curNode->data << " ";
	}
}

const int N = 7;
void setRowOrColToZero(int matrix[N][N])
{
	unordered_set<int> rows;
	unordered_set<int> cols;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (matrix[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}

	for (auto it = rows.begin(); it != rows.end(); ++it)
	{
		int row = *it;
		for (int i = 0; i < N; ++i)
			matrix[row][i] = 0;
	}

	for (auto it = cols.begin(); it != cols.end(); ++it)
	{
		int col = *it;
		for (int i = 0; i < N; ++i)
			matrix[i][col] = 0;
	}
}

int isBalancedHelper(Node* root, bool* isBalanced)
{
	if (!isBalanced || !root) return 0;

	int leftHeight = isBalancedHelper(root->left, isBalanced);
	int rightHeight = isBalancedHelper(root->right, isBalanced);

	int diff = abs(leftHeight - rightHeight);
	if (diff > 1)
	{
		*isBalanced = false;
		return 0;
	}

	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root)
{
	if (!root) return true;
	
	bool isBalanced = true;

	isBalancedHelper(root, &isBalanced);
	
	return isBalanced;
}

bool isUnivalHelper(Node* node, int value)
{
	if (!node) return true;

	if (node->data != value)
		return false;

	return isUnivalHelper(node->left, value) && isUnivalHelper(node->right, value);
}

bool isUnival(Node* root)
{
	if (!root) return true;

	int value = root->data;
	
	return isUnivalHelper(root, value);
}

void printMatirx(int matrix[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

typedef struct lnode LNode;
struct lnode
{
	int data;
	LNode* next;
};

void merge(LNode** head, LNode* midNext)
{
	LNode* it1 = *head;
	LNode* it2 = midNext;
	LNode* newHead = nullptr;
	LNode* newIt = nullptr;

	if (it1->data <= it2->data)
	{
		newHead = it1;
		newIt = it1;
		it1 = it1->next;
	}
	else
	{
		newHead = it2;
		newIt = it2;
		it2 = it2->next;
	}

	while (it1 && it2)
	{
		if (it1->data <= it2->data)
		{
			newIt->next = it1;
			it1 = it1->next;
		}
		else
		{
			newIt->next = it2;
			it2 = it2->next;
		}
		newIt = newIt->next;
	}

	while (it1)
	{
		newIt->next = it1;
		it1 = it1->next;
		newIt = newIt->next;
	}

	while (it2)
	{
		newIt->next = it2;
		it2 = it2->next;
		newIt = newIt->next;
	}

	*head = newHead;
}

LNode* getMiddle(LNode* head)
{
	if (!head) return nullptr;

	int size = 0;
	LNode* temp = head;

	while (temp)
	{
		temp = temp->next;
		size++;
	}

	int mid = size / 2;
	if (size % 2 == 0) mid--;
	for (int i = 0; i < mid; ++i)
		head = head->next;

	return head;
}

void sortLinkedList(LNode** head)
{
	if (!head || !*head) throw exception();
	if (!(*head)->next) return;

	LNode* mid = getMiddle(*head);
	LNode* midNext = mid->next;
	
	mid->next = nullptr;
	sortLinkedList(head);
	sortLinkedList(&midNext);
	merge(head, midNext);
}

void printLinkedList(LNode* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	string str = "abcde";
	printCombinations(str, 4);
	cout << endl;

	Node* root = new Node();
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();
	Node* node4 = new Node();
	Node* node5 = new Node();
	Node* node6 = new Node();
	Node* node7 = new Node();
	Node* node8 = new Node();
	Node* node9 = new Node();

	root->data = 0;
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	node6->data = 6;
	node7->data = 7;
	node8->data = 8;
	node9->data = 9;

	root->left = node1;
	root->right = node4;
	node1->left = node2;
	node2->right = node3;
	node4->left = node5;
	node4->right = node6;
	node6->left = node7;
	node6->right = node8;
	node7->left = node9;

	printTreeLevelByLevel(root);

	int matrix[N][N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			matrix[i][j] = 1;
	matrix[1][1] = 0;
	matrix[2][3] = 0;
	matrix[2][4] = 0;
	matrix[3][4] = 0;
	matrix[4][0] = 0;
	matrix[6][6] = 0;

	cout << "Original Matrix" << endl;
	printMatirx(matrix);
	setRowOrColToZero(matrix);
	cout << "New Matrix" << endl;
	printMatirx(matrix);
	cout << endl;

	cout << "Is Tree balanced? " << (isBalanced(node6) ? "Yes" : "No") << endl;
	cout << endl;

	cout << "Is Tree unival? " << (isUnival(root) ? "Yes" : "No") << endl;	// tested
	cout << endl;

	LNode* head = new LNode();
	LNode* lnode1 = new LNode();
	LNode* lnode2 = new LNode();
	LNode* lnode3 = new LNode();
	LNode* lnode4 = new LNode();
	LNode* lnode5 = new LNode();

	head->next = lnode1;
	lnode1->next = lnode2;
	lnode2->next = lnode3;
	lnode3->next = lnode4;
	lnode4->next = lnode5;
	lnode5->next = nullptr;

	head->data = 6;
	lnode1->data = 3;
	lnode2->data = 10;
	lnode3->data = 5;
	lnode4->data = 0;
	lnode5->data = -1;

	cout << "Before sorting" << endl;
	printLinkedList(head);
	sortLinkedList(&head);
	cout << "After sorting" << endl;
	printLinkedList(head);

	char c;
	cin >> c;
	return 0;
}