#include <iostream>
#include <vector>
using namespace std;

class balance{
private:
  vector<int> trip;
  int total;
public:
  balance(int people){
    trip.assign(people,0);
  }
  void transcation(int person,int money){
    trip[person-1]+=money;
    total+=money;
  }
  void rebalance(){
    int ave=total/trip.size();
    int dif=total-(ave*trip.size());
    for(size_t i=0;i<trip.size();i++){
      if(i==0){
	trip[i]=trip[i]-ave-dif;
      }else{
	trip[i]-=ave;
      }
    }
  }
  void print(){
    for(size_t i=0;i<trip.size();i++){
      cout<<i+1<<" "<<trip[i]<<endl;
    }
  }
};
