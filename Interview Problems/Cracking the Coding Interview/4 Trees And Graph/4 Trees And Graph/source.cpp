#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class BNode
{
private:
	BNode* left;
	BNode* right;
	BNode* parent;
	int data;

public:
	BNode(int data)
	{
		left = NULL;
		right = NULL;
		parent = NULL;
		this->data = data;
	}
	~BNode() {}

	BNode* getLeft() { return left; }
	BNode* getRight() { return right; }
	BNode* getParent() { return parent; }
	int getData() { return data; }

	void setLeft(BNode* left) { this->left = left; }
	void setRight(BNode* right) { this->right = right; }
	void setParent(BNode* parent) { this->parent = parent; }
	void setData(int data) { this->data = data; }
};

class GNode
{
private:
	int data;
	vector<GNode*> nodes;

public:
	GNode(int data)
	{
		this->data = data;
	}
	~GNode() {}

	int getData() { return data; }
	vector<GNode*>& getNodes() { return nodes; }
	
	void setData(int data) { this->data = data; }
	void linkNode(int data)
	{
		GNode* node = new GNode(data);
		nodes.push_back(node);
	}
};

int getMaxHeight(BNode* root)
{
	if (!root) return 0;

	return max(getMaxHeight(root->getLeft()), getMaxHeight(root->getRight()));
}

int getMinHeight(BNode* root)
{
	if (!root) return 0;

	return 1 + min(getMinHeight(root->getLeft()), getMinHeight(root->getRight()));
}

bool isBalanced(BNode* root)
{
	if (!root) throw exception();

	int diff = getMaxHeight(root) - getMinHeight(root);

	return diff <= 1;
}

bool findRoute(GNode* node, GNode* targetNode, unordered_map<GNode*, bool> &visitedNodes)
{
	if (node == targetNode) return true;

	visitedNodes.insert(pair<GNode*, bool>(node, true));
	auto nodes = node->getNodes();
	for (auto it = nodes.begin(); it != nodes.end(); ++it)	// const it?
	{
		if (visitedNodes.find(*it) != visitedNodes.end())
			continue;
		if (findRoute(*it, targetNode, visitedNodes))
			return true;
	}
	return false;
}

bool isThereARoute(GNode* node1, GNode* node2)
{
	if (!node1 || !node2) throw exception();

	unordered_map<GNode*, bool> visitedNodes;
	bool isFound = findRoute(node1, node2, visitedNodes);

	if (!isFound)
	{
		visitedNodes.clear();
		isFound = findRoute(node2, node1, visitedNodes);
	}
	return isFound;
}

BNode* getBinaryTree(int arr[], int size)
{
	if (!arr || size < 0) throw exception();
	if (size == 0) return NULL;

	if (size == 1)
		return new BNode(arr[0]);

	int mid = size / 2;
	
	BNode* subRoot = new BNode(arr[mid]);
	subRoot->setLeft(getBinaryTree(arr, mid));
	subRoot->setRight(getBinaryTree(arr + mid + 1, size - mid - 1));

	return subRoot;
}

vector<BNode*> findLevelLinkedList(BNode* root)
{
	if (!root) throw exception();

	vector<BNode*> linkedLists;
	queue<pair<BNode*, int>> unvisitedNodes;
	int curLevel = 0;
	BNode* head = NULL;
	unvisitedNodes.push(pair<BNode*, int> (root, curLevel));

	while (!unvisitedNodes.empty())
	{
		pair<BNode*, int> tempNodePair = unvisitedNodes.front();	// queue == front, stack == top
		unvisitedNodes.pop();
		BNode* tempNode = tempNodePair.first;
		int level = tempNodePair.second;

		if (tempNode->getLeft())
			unvisitedNodes.push(pair<BNode*,int>(tempNode->getLeft(), level + 1));
		if (tempNode->getRight())
			unvisitedNodes.push(pair<BNode*, int>(tempNode->getRight(), level + 1));

		if (level != curLevel)
		{
			curLevel = level;
			linkedLists.push_back(head);
			head = NULL;
		}

		tempNode->setRight(head);
		tempNode->setLeft(NULL);
		head = tempNode;
	}
	
	linkedLists.push_back(head);
	return linkedLists;
}

BNode* getLeftMostNode(BNode* node)
{
	if (!node) throw exception();

	while (node->getLeft())
		node = node->getLeft();

	return node;
}

BNode* getInorderSuccessor(BNode* node)
{
	if (!node) throw exception();

	if (node->getRight())
		return getLeftMostNode(node->getRight());
	if (!node->getParent() && node->getParent()->getLeft() == node)
		return node->getParent();

	node = node->getParent();

	while (node)
	{
		if (node->getParent() && node != node->getParent()->getLeft())
		{
			node = node->getParent();
			continue;
		}
		node = node->getParent();
		break;
	}
	return node;
}

bool findNode(BNode* root, BNode* node)
{
	if (!root || !node) return false;
	if (root == node ) return true;

	return findNode(root->getLeft(), node) || findNode(root->getRight(), node);
}

BNode* findCommonAncestor(BNode* root, BNode* node1, BNode* node2)
{
	if (!root || !node1 || !node2) 
		return false;

	if (root == node1 || root == node2)
		return root;
	
	if (node1 == node2)
		return node1;

	bool isNode1OnLeft = findNode(root->getLeft(), node1);
	bool isNode2OnLeft = findNode(root->getLeft(), node2);

	if (isNode1OnLeft && !isNode2OnLeft)
		return root;
	else if (isNode1OnLeft && isNode2OnLeft)
		return findCommonAncestor(root->getLeft(), node1, node2);
	else
		return findCommonAncestor(root->getRight(), node1, node2);
}

bool isSubTree(BNode* bigRoot, BNode* smallRoot)
{
	if (!bigRoot || !smallRoot) throw exception();
	
	return findNode(bigRoot->getLeft(), smallRoot) || findNode(bigRoot->getRight(), smallRoot);
}

void printPath(const vector<int> &vect, int start)
{
	for (unsigned int i = start; i < vect.size(); ++i)
		cout << vect.at(i) << " ";
	cout << endl;
}

void findPath(BNode* root, int sum, vector<int> vect)
{
	if (!root) 
		return;

	int temp = sum;
	vect.push_back(root->getData());
	
	for (int i = vect.size() - 1; i >= 0; --i)
	{
		temp -= vect[i];
		if (temp == 0)
			printPath(vect, i);
	}

	findPath(root->getLeft(), sum, vect);
	findPath(root->getRight(), sum, vect);
}

void printPathToSum(BNode* root, int sum)
{
	if (!root) throw exception();
	
	vector<int> vect;

	findPath(root, sum, vect);
}

typedef struct nbnode NBNode;
struct nbnode
{
	int value;
	vector<NBNode*> *children;
};

typedef pair<NBNode*, int> nodeAndLevel;

void printTreeByLevel(NBNode* root)
{
	if (!root) return;

	queue<nodeAndLevel> nodeQueue;
	nodeQueue.push(nodeAndLevel(root, 0));

	int prevLevel = 0;
	while (!nodeQueue.empty())
	{
		NBNode* curNode = nodeQueue.front().first;
		int curLevel = nodeQueue.front().second;
		nodeQueue.pop();

		for (auto it = curNode->children->begin(); it != curNode->children->end(); ++it)
			nodeQueue.push(nodeAndLevel(*it, curLevel + 1));

		if (prevLevel != curLevel)
			cout << endl;
		cout << " " << curNode->value;
		prevLevel = curLevel;
	}

	cout << endl;
}

int main()
{
	NBNode* root = new NBNode();
	root->value = 0;
	root->children = new vector<NBNode*>();
	NBNode* node1 = new NBNode();
	node1->value = 1;
	node1->children = new vector<NBNode*>();
	NBNode* node2 = new NBNode();
	node2->value = 2;
	node2->children = new vector<NBNode*>();
	NBNode* node3 = new NBNode();
	node3->value = 3;
	node3->children = new vector<NBNode*>();
	NBNode* node4 = new NBNode();
	node4->value = 4;
	node4->children = new vector<NBNode*>();
	NBNode* node5 = new NBNode();
	node5->value = 5;
	node5->children = new vector<NBNode*>();
	NBNode* node6 = new NBNode();
	node6->value = 6;
	node6->children = new vector<NBNode*>();
	NBNode* node7 = new NBNode();
	node7->value = 7;
	node7->children = new vector<NBNode*>();
	NBNode* node8 = new NBNode();
	node8->value = 8;
	node8->children = new vector<NBNode*>();
	NBNode* node9 = new NBNode();
	node9->value = 9;
	node9->children = new vector<NBNode*>();

	root->children->push_back(node1);

	root->children->push_back(node2);
	root->children->push_back(node3);
	node1->children->push_back(node4);
	node1->children->push_back(node5);
	node2->children->push_back(node6);
	node2->children->push_back(node7);
	node6->children->push_back(node8);
	node8->children->push_back(node9);

	printTreeByLevel(root);

	delete root;
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
	delete node8;
	delete node9;

	char c;
	cin >> c;
	return 0;
}