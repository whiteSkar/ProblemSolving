#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void displayArray(int data[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << data[i] << " ";
    cout << endl;
}

void selectionSort(int data[], int size)
{
    if (!data || size < 0) throw exception();

    for (int i = 0; i < size; ++i)
    {
        int minIndex = i;

        for (int j = i+1; j < size; ++j)
        {
            if (data[j] < data[minIndex])
                minIndex = j;
        }

        swap(data[minIndex], data[i]);
    }
}

int findMinIndex(int data[], int size)
{
    int minIndex = 0;
    
    for (int i = 1; i < size; ++i)
    {
        if (data[i] < data[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void selectionSortRecursive(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    swap(data[0], data[findMinIndex(data, size)]);

    selectionSortRecursive(data + 1, size - 1);
}

void insertionSort(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    int curPos = 0;
    
    for (int i = 1; i < size; ++i)
    {
        if (data[i] < data[curPos])
        {
            int j = curPos;
            while (j > 0)
            {
                if (data[i] > data[j-1])
                    break;
                j--;
            }
            
            int temp = data[i];
            copy(data + j, data + i, data + j + 1);
            data[j] = temp;
        }
        curPos++;
    }
}

void quickSort(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    vector<int> tempData(data, data + size);

    int midIndex = size / 2;
    int midValue = data[midIndex];
    int left = 0, right = size - 1;

    for (int i = 0; i < size; ++i)
    {
        if (i == midIndex)
            continue;

        if (tempData[i] < midValue)
            data[left++] = tempData[i];
        else
            data[right--] = tempData[i];
    }
    if (left != right) throw exception();

    data[left] = midValue;
    quickSort(data, left);
    quickSort(data + left + 1, size - left - 1);
}

void merge(int data[], int datasize, int leftData[], int leftSize, int rightData[], int rightSize)
{
    int target = 0, left = 0, right = 0;

    while (left < leftSize && right< rightSize)
    {
        if (leftData[left] <= rightData[right])
            data[target++] = leftData[left++];
        else
            data[target++] = rightData[right++];
    }

    copy(leftData+left, leftData+leftSize, data+target);
    copy(rightData+right, rightData+rightSize, data+target);
}

void mergeSort(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    int mid = size / 2;
    int* leftData = new int[mid];
    int* rightData = new int[size-mid];

    copy(data, data+mid, leftData);
    copy(data+mid, data+size, rightData);

    mergeSort(leftData, mid);
    mergeSort(rightData, size-mid);

    merge(data, size, leftData, mid, rightData, size-mid);

    delete[] leftData;
    delete[] rightData;
}

void slectionSortStable(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    for (int i = 0; i < size; ++i)
    {
        int minIndex = findMinIndex(data+i, size-i) + i;
        int temp = data[minIndex];

        copy(data+i, data+minIndex, data+i+1);
        data[i] = temp;
    }
}

void selectionSortStableUsingDoublyLinkedList()
{
    // Comeback
}

struct Employee {
    string surName;
    string givenName;
};
typedef struct Employee Employee;

bool comparator(const Employee &a, const Employee &b)
{
    if (a.surName == b.surName)
        return a.givenName < b.givenName;

    return a.surName < b.surName;
}

void sortEmployees(Employee data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    sort(data, data+size, comparator);
}

void quickSortInplace(int data[], int size)
{
    if (!data || size < 0) throw exception();
    if (size <= 1) return;

    int pivotIndex = size / 2;
    int pivotValue = data[pivotIndex];
    int left = 0, right = size - 1;

    while (left < right)
    {
        int temp = data[right];
        if (data[left] > pivotValue)
        {
            if (&data[right] == &data[pivotIndex])
            {
                right--;
                continue;
            }
            data[right--] = data[left];
            data[left] = temp;
        }
        else
            left++;
    }
    if (left != right) throw exception();

    swap(data[pivotIndex], data[left]);
    pivotIndex = left;

    quickSortInplace(data, pivotIndex);
    if (pivotIndex + 1 < size)
        quickSortInplace(data + pivotIndex + 1, size - pivotIndex - 1);
}

struct Node{
    int data;
    Node* next;
    Node* prev;
};
typedef struct Node Node;

Node* findMinNode(Node* node)
{
    if (!node) throw exception();

    Node* minNode = node;

    while (node->next)
    {
        if (node->next->data < minNode->data)
            minNode = node->next;
        node = node->next;
    }
    return minNode;
}

Node* selectionSortStableUsingDoublyLinkedList(Node* head)
{
    if (!head) throw exception();

    Node* curNode = head;

    while (curNode->next)
    {
        Node* minNode = findMinNode(curNode);
        minNode->prev->next = minNode->next;
        
        if (minNode->next)
            minNode->next->prev = minNode->prev;
        minNode->next = curNode;

        if (curNode->prev)
        {
            minNode->prev = curNode->prev;
            minNode->prev->next = minNode;
        }
        else
        {
            minNode->prev = NULL;
            curNode->prev = minNode;
            head = minNode;
        }
    }

    return head;
}

int main()
{
    const int dataSize = 10;
    int data[dataSize] = {1, 3, 2, 4, 0, 10, 9, 8, 12, 7};
    quickSortInplace(data, 10);
    displayArray(data, dataSize);

    Employee employees[5];
    employees[0].surName = "abc";
    employees[0].givenName = "given ccc";
    employees[1].surName = "bbc";
    employees[1].givenName = "given";
    employees[2].surName = "abc";
    employees[2].givenName = "given abc";
    employees[3].surName = "aaa";
    employees[3].givenName = "given";
    employees[4].surName = "abc";
    employees[4].givenName = "given bbc";
    sortEmployees(employees, 5);
    for (int i = 0; i < 5; ++i)
        cout << employees[i].surName << " " << employees[i].givenName << endl;
    cout << endl;

    Node head;
    head.data = 10;
    Node one;
    one.data = 1;
    Node two;
    two.data = 2;
    Node three;
    three.data = 3;
    Node four;
    four.data = 4;
    Node five;
    five.data = 5;
    Node six;
    six.data = 6;
    Node seven;
    seven.data = 7;

    head.prev = NULL;
    head.next = &two;
    two.prev = &head;
    two.next = &one;
    one.prev = &two;
    one.next = &three;
    three.prev = &one;
    three.next = &seven;
    seven.prev = &three;
    seven.next = &six;
    six.prev = &seven;
    six.next = &four;
    four.prev = &six;
    four.next = &five;
    five.prev = &four;
    five.next = NULL;

    // 10 2 1 3 7 6 4 5
    Node* it = selectionSortStableUsingDoublyLinkedList(&head);
    while (it)
    {
        cout << it->data << " " ;
        it = it->next;
    }
    cout << endl;


    char c;
    cin >> c;
    return 0;
}