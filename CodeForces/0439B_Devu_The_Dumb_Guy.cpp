/*
  Tech n subjects, ith subject has c chapters. 
  His pre chapter learning power of a subject is x hours.
  x decrease by 1 every subject, can not smaller than 1
  min time to understand all subjectt
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  //inputs
  int subjects, lpc;
  cin>>subjects>>lpc;
  vector<int> chapters(subjects);
  for(auto& c : chapters) cin>>c;

  //sort 
  sort(chapters.begin(),chapters.end());

  //traverse the array, and obtain the time needed for each subject
  //as well as decreasing
  unsigned long long int hours = 0;
  auto func = [&](int i){
    hours += static_cast<unsigned long long int>(i) *
    static_cast<unsigned long long int>(lpc);
    if(lpc > 1) --lpc;
  };
  for_each(chapters.begin(),chapters.end(),func);
  cout<<hours<<endl;
}
