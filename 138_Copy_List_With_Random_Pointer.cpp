#include <iostream>
using namespace std;
/*
  Split this question into three parts:
  1. Inserting a duplicate node right after to kept the order of list
     1->2->3->4->NULL ====> 1->1'->2->2'->3->3'->4->4'->NULL
  2. Copying the random node for the duplicates
     dup -> random = realRan -> next  since real Random's next is the duplicate
  3. Split the Lists back into two, one original, one copy
*/
//Definition for singly-linked list with a random pointer.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
void print(RandomListNode* n1);
void printRan(RandomListNode* n1);
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL){
      return NULL;
    }
    RandomListNode* temp = head;
    insertingDup(temp);
    temp = head;
    insertingRandom(temp);
    temp = head;
    head = head->next;
    removeOrigin(temp);
    return head;
  }
  void insertingDup(RandomListNode *temp){
    while(temp != NULL){
      RandomListNode* rest = temp -> next;
      RandomListNode* duplicateCurr = new RandomListNode(temp -> label + 10);
      temp -> next = duplicateCurr;
      duplicateCurr -> next = rest;
      temp = duplicateCurr->next;
    }
  }
  void insertingRandom(RandomListNode * temp){
    while(temp != NULL){
      if(temp -> random != NULL){
	RandomListNode* dup = temp -> next;
	RandomListNode* realRan = temp -> random;
	dup -> random = realRan -> next;
      }
      temp = temp -> next -> next;
    }
  }
  void removeOrigin(RandomListNode* temp){
    while(temp -> next -> next != NULL){
      RandomListNode* dup = temp -> next;
      RandomListNode* tempNext = dup -> next;
      dup -> next = tempNext -> next;
      temp -> next = tempNext;
      temp = tempNext;
    }
    temp -> next = temp -> next -> next;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  RandomListNode* n1 = new RandomListNode(1);
  RandomListNode* n2 = new RandomListNode(2);
  RandomListNode* n3 = new RandomListNode(3);
  RandomListNode* n4 = new RandomListNode(4);
  n1 -> next = n2;
  n2 -> next = n3;
  n3 -> next = n4;
  n1 -> random = n3;
  n2 -> random = n4;
  n4 -> random = NULL;
  n3 -> random = n2;
  print(n1);
  cout<<endl;
  printRan(n1);
  Solution test;
  cout<<endl;
  print(test.copyRandomList(n1));
  cout<<endl;
  printRan(test.copyRandomList(n1));
  cout<<endl<<"after"<<endl;
  print(n1);
  cout<<endl;
  printRan(n1);
}

void print(RandomListNode* n1){
  while(n1 != NULL){
    cout << n1 -> label << "->";
    n1 = n1 -> next;
  }
}
void printRan(RandomListNode* n1){
  while(n1 != NULL){
    cout << n1 -> label << "->";
    n1 = n1 -> random;
  }
}
