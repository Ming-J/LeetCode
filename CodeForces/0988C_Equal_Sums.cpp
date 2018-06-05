#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
using namespace std;

int main(){
  //Getting all inputs
  int arrN;
  cin>>arrN;
  vector<vector<int> > sequences(arrN);
  for(auto& s: sequences){
    int n;
    cin>>n;
    s.assign(n,0);
    for(int& i: s) cin>>i;
  }
  //calculating all seq sum
  vector<int> sums;
  //tuple{sum,seqNumber,elementIndex}
  vector<tuple<int,int,int> > partialSums;
  for(size_t i = 0; i < sequences.size(); ++i){
    vector<int> seq = sequences[i];
    int seqSum = accumulate(seq.begin(),seq.end(),0);
    auto func = [&,count = 0](int x) mutable{
      return tuple<int,int,int>(seqSum - x,i,count++);
    };
    transform(seq.begin(),seq.end(),back_inserter(partialSums),func);
  }
  sort(partialSums.begin(), partialSums.end());
  for(size_t i = 0; i < partialSums.size() - 1; ++i){
    int sum1 = get<0>(partialS#ums[i]);
    int sum2 = get<0>(partialSums[i+1]);
    int seq1 = get<1>(partialSums[i]);
    int seq2 = get<1>(partialSums[i+1]);
    int ind1 = get<2>(partialSums[i]);
    int ind2 = get<2>(partialSums[i+1]);
    if(sum1==sum2&&(seq1!=seq2)){
	cout<< "YES" <<endl;
	cout<<seq1+1<<" "<<ind1+1<<endl;
	cout<<seq2+1<<" "<<ind2+1<<endl;
	return 0;
      }
  }
  cout<<"NO"<<endl;
}
