#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> input;
  for(int i = 0; i < n; i++){
    int bo;
    cin>>bo;
    input.push_back(bo);
  }
  int max_end_here = 0;
  int max_so_far = 0;
  int start = 0;
  pair<int,int> index (0,0);
  for(int i = 0; i < input.size(); i++){
    int cur = input[i]==0? 1 : -1;
    max_end_here += cur;
    if(max_end_here > max_so_far){
      max_so_far = max_end_here;
      index.second = i;
      index.first = start;
    }
    if(max_end_here < 0){
      max_end_here = 0;
      start = i+1<=input.size()-1?i+1:i;
      // current one is negative value, initial to next
    }
  }
  if(index.second == 0 ){
    index.first = start;
    index.second = input.size()-1;
  }
  //cout<<max_so_far<<' '<<index.first<<' '<<index.second<<endl;
  int one = 0;
  for( int i = 0; i < input.size(); i++){
    if(input[i] == 1 && (i < index.first || i>index.second)){
      one++;
    }else if(input[i] == 0 && i >= index.first && i <= index.second){
      one++;
    }
  }
  cout<<one<<endl;
}
