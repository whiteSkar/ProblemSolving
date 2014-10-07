#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

#define TEMP 158

struct node {
	short name;
	short numChild;
	short numBeingLowestCommonAncestor;
	short numOfAncestors;
	short childNameList[TEMP];
	struct node *ancestorList[TEMP];
	struct node *ancestor;
	struct node *childList[TEMP];
	/*
	short *childNameList;			// why this method goes over the limit?
	struct node **ancestorList;
	struct node *ancestor;
	struct node **childList;
	*/
};

bool operator<(const node& a, const node& b) 
{
	return a.name < b.name;
}

int numOfNodes = 0;
struct node node_list[800];


void setToAncestor( struct node &ancestor );
void storeAncestors( struct node *targetNode, const struct node *currentNode );
void findLowestCommonAncestor( const struct node *node1, const struct node *node2 );
struct node* findNode( int name );
void sortNodeList();
void printResult();

int main( void )
{
	string input;
	stringstream s1( input );
	int numOfPairs = 0;

	//ifstream cin( "Test Case.txt" );

	while ( cin >> numOfNodes )
	{
		if ( numOfNodes == 0 )
		{
			continue;
		}
		int firstRun = 1;

		for ( int i = 0; i < numOfNodes; i++ )
		{
			getline( cin, input, ':' );
			s1.str( input );
			s1 >> node_list[i].name;
			s1.clear();

			getline( cin, input, '(' );
			getline( cin, input, ')' );
			s1.str( input );
			s1.seekg( 0, ios::beg ) ;
			s1 >> node_list[i].numChild;
			s1.clear();

			node_list[i].numBeingLowestCommonAncestor = 0;
			node_list[i].numOfAncestors = 0;
			node_list[i].ancestor = NULL;

			/*
			if ( firstRun == 1 )
			{
				node_list[i].ancestorList = new struct node*[TEMP];
				node_list[i].childList = new struct node*[TEMP];
			}
			*/

			if ( node_list[i].numChild >= 0 )
			{
				/*
				if ( firstRun == 1)
				{
					node_list[i].childNameList = new short[TEMP];
				}
				*/

				for ( int j = 0; j < node_list[i].numChild; j++ )
				{
					cin >> node_list[i].childNameList[j];
				}
			}
		}
		firstRun = 0;

		for ( int i = 0; i < numOfNodes; i++ )
		{
			if ( node_list[i].numChild > 0 )
			{
				for ( int j = 0; j < node_list[i].numChild; j++ )
				{
					node_list[i].childList[j] = findNode( node_list[i].childNameList[j] );
				}
			}
			setToAncestor( node_list[i] );
		}

		for ( int i = 0; i < numOfNodes; i++ )
		{
			storeAncestors( &node_list[i], &node_list[i] );
		}

		cin >> numOfPairs;

		for ( int i = 0; i < numOfPairs; i++ )
		{
			int node1name, node2name;

			getline( cin, input, '(' );
			getline( cin, input, ',' );
			s1.str( input );
			s1.seekg( 0, ios::beg ) ;
			s1 >> node1name;
			s1.clear();

			getline( cin, input, ')' );
			s1.str( input );
			s1.seekg( 0, ios::beg );
			s1 >> node2name;
			s1.clear();

			struct node *node1;
			struct node *node2;

			for ( int j = 0; j < numOfNodes; j++ )
			{
				if ( node_list[j].name == node1name )
				{
					node1 = &node_list[j];
				}
				if ( node_list[j].name == node2name )
				{
					node2 = &node_list[j];
				}
			}

			findLowestCommonAncestor( node1, node2 );			
		}
		sortNodeList();
		printResult();
	}
	return 0;
}


void setToAncestor( struct node &currentNode )
{
	for ( int i = 0; i < currentNode.numChild; i++ )
	{
		currentNode.childList[i]->ancestor = &currentNode;
	}
}

void storeAncestors( struct node *targetNode, const struct node *currentNode )
{
	if ( targetNode == currentNode )
	{
		targetNode->ancestorList[targetNode->numOfAncestors] = targetNode;
		targetNode->numOfAncestors++;
	}

	if ( currentNode->ancestor )
	{
		targetNode->ancestorList[targetNode->numOfAncestors] = currentNode->ancestor;
		targetNode->numOfAncestors++;
		storeAncestors( targetNode, currentNode->ancestor);
	}
}

void findLowestCommonAncestor( const struct node *node1, const struct node *node2 )
{
	if ( node1 && node2 )
	{
		for ( int i = 0; i < node1->numOfAncestors; i++ )
		{
			for ( int j = 0; j < node2->numOfAncestors; j++ )
			{
				if ( node1->ancestorList[i]->name == node2->ancestorList[j]->name )
				{
					node1->ancestorList[i]->numBeingLowestCommonAncestor++;
					return;
				}
			}
		}
	}
}

struct node* findNode( int name )
{
	for ( int i = 0; i < numOfNodes; i++)
	{
		if ( node_list[i].name == name )
		{
			return &node_list[i];
		}
	}
	return NULL;
}

void sortNodeList()
{
	sort( node_list, node_list+numOfNodes );
}

void printResult()
{
	for ( int i = 0; i < numOfNodes; i++ )
	{
		if ( node_list[i].numBeingLowestCommonAncestor > 0 )
		{
			cout << node_list[i].name << ":" << node_list[i].numBeingLowestCommonAncestor << endl;
		}
	}
}

