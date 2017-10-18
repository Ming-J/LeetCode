#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
      ListNode* tail=head;
      while(tail->next!=NULL){
	tail=tail->next;
      }
      while(head->next!=NULL){
	ListNode* temp=head->next;
	head->next=tail;
	tail->next=temp;
	tail=getLast(temp,last);
	head=temp;
      }
    }

  ListNode* getLast(ListNode* head, ListNode* end){
    while(head->next!=end){
      head=head->next;
    }
    return head;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
