y#include <iostream>
using namespace std;

int main(){
  int participants,kthPlace;
  scanf("%d %d",participants,kthPlace);
  for(int i=0;i<participants;i++){
    int score;
    scanf("%d ",score);
    cout<<score<<endl;
  }
}
