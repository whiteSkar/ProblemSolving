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
	const vector<GNode*>& getNodes() { return nodes; }
	
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

bool findRoute(GNode* node, GNode* targetNode, unordered_map<GNode*, bool> visitedNodes)
{
	if (node == targetNode) return true;

	visitedNodes.insert(pair<GNode*, bool>(node, true));
	vector<GNode*> nodes = node->getNodes();
	for (vector<GNode*>::iterator it = nodes.begin(); it != nodes.end(); ++it)	// const it?
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

int main()
{


	char c;
	cin >> c;
	return 0;
}