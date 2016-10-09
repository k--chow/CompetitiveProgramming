#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

vector<int> steps;
vector<Node*> heads;

void interweave(Node* current, Node* head)
{
    for (int i=0; i<steps.size(); i++)
    {
        current = head;
        int counter = 1;
        int step = steps[i];
        Node* listHead = heads[i];
        while (current && listHead)
        {

            Node* next = current->next;
            if (counter % step == 0) {
                current->next = listHead;
                listHead = listHead->next;
                current = current->next;
                current->next = next;
            }
            current = next;
            counter++;

        }
    }
}

void print(Node* head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    Node* head, *current;
    for(int i=0; i<n; i++)
    {
        int element; cin >> element;
        if (i == 0) {
            current = head = new Node(element);
        } else {
            current->next = new Node(element);
            current = current->next;
        }

    }
    int lists; cin >> lists;
    for(int i=0; i<lists; i++)
    {
        //steps
        int step; cin >> step;
        steps.push_back(step);
        //size
        int size; cin >> size;
        Node* listHead = NULL, *current = listHead;
        for(int j=0; j<size; j++)
        {
            int element; cin >> element;
            if (j == 0) {
                listHead = new Node(element);
                current = listHead;
            } else {
                current->next = new Node(element);
                current = current->next;
            }

        }
        heads.push_back(listHead);
    }
    //call interweave function
    interweave(current, head);
    print(head);
}
