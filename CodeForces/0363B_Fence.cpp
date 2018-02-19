#include <iostream>
#include <vector>
using namespace std;

int findConsecutive(vector<int> fen, int gap){
  int gapSum = 0;
  for( size_t i = 0; i < gap; i++){
    gapSum += fen[i];
  }
  int minGap = gapSum;
  int plankStart = 0;
  for( size_t i = 1; i <= fen.size() - gap; i++){
    int newgap = gapSum + fen[i+gap-1] - fen[i-1];
    if( minGap > newgap){
      plankStart = i;
      minGap = newgap;
    }
    gapSum = newgap;
  }
  return plankStart;
}

int main(){
  int gap, n, k;
  vector<int> fence;
  cin>>n>>gap;
  fence.resize(n,0);
  for( size_t i = 0; i < n; i++ ){
    cin>>k;
    fence[i]=k;
  }
  cout<<findConsecutive(fence,gap)+1<<endl;
}
