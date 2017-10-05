#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
public:
  ListNode* reverseBetween(ListNode* head, int m, int n){
    if(head==NULL){
      return head;
    }
    ListNode* beforeM=head;
    for(int i=0;i<m;i++){
      beforeM=beforeM->next;
    }
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
