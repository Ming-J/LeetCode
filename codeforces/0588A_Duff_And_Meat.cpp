#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

/*
Way over complicated the problems.  We can use a val to keep track the
min price.  And for each day, we check to see if today's price is
smaller, and we just multiple the quantity we needed.
*/

int main(){
  int n, k, p;
  cin>>n;
  vector<int> kilo(n,0);
  vector<pair<int,int> > price(n,make_pair(0,0));
  for(int i = 0; i < n; ++i){
    cin>>k>>p;
    kilo[i] = k;
    price[i] = make_pair(p,i);
  }
  vector<int> sumT(n+1,0);
  partial_sum(kilo.begin(),kilo.end(),sumT.begin()+1);
  auto cmp = [](const pair<int,int> &lhs, const pair<int,int> &rhs){
    if(lhs.first == rhs.first){
      return lhs.second > rhs.second;
    }else{
      return lhs.first > rhs.first;
    }
  };
  priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(cmp) >
    pq(cmp, price);
  int money = 0;
  int days = n;
  while(!pq.empty()){
    int minP = pq.top().first;
    int dayP = pq.top().second;
    if(dayP < days){
      money += (sumT[days] - sumT[dayP]) * minP;
      days = dayP;
    }
    pq.pop();
  }
  cout<<money<<endl;
}
