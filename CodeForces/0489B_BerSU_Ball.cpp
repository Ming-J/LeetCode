#include <iostream>
#include <vector>
using namespace std;

void readSkill( vector<int>& skillList, int n){
  for(int i = 0; i < n; i++){
    int temp;
    cin>>temp;
    skillList[temp-1]++;
  }
}

int main(){
  vector<int> bskill(100,0);
  vector<int> gskill(100,0);
  int n;
  cin>>n;
  readSkill(bskill,n);
  cin>>n;
  readSkill(gskill,n);
  int count=0;
  for( int i = 1; i < 100; i++){
    bool boy = ( bskill[i-1] > 0 || bskill[i] >0 );
    bool girl = ( gskill[i-1] > 0 || gskill[i] >0 );
    if(boy && girl){
      int bDancer = bskill[i-1] + bskill[i];
      int gDancer = gskill[i-1] + gskill[i];
      int match = min(bDancer,gDancer);
      count += match;
      for( int j = 0 ; j < match; j++){
	if(bskill[i-1]>0){
	  bskill[i-1]--;
	}else{
	  bskill[i]--;
	}
      }
      for( int j = 0 ; j < match; j++){
	if(gskill[i-1]>0){
	  gskill[i-1]--;
	}else{
	  gskill[i]--;
	}
      }
    }
  }
  cout<<count<<endl;
}
