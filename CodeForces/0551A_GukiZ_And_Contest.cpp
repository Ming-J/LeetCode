#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void contest(vector< pair<int,int> >& student){
  sort(student.begin(),student.end(),greater<pair<int,int> >());
  vector<int> afterContest(student.size());
  int rank = 1;
  afterContest[student[0].second] = rank;
  for(size_t i = 1; i < student.size(); ++i){
    if(student[i].first == student[i-1].first){ 
      afterContest[student[i].second] = afterContest[student[i-1].second];
    }else{
      afterContest[student[i].second] = i+1;
    }
  }
  for(size_t i = 0; i < afterContest.size(); ++i){
    cout<<afterContest[i]<<' ';
  }
}

int main(){
  int n;
  cin>>n;
  vector<pair<int,int> > student(n);
  for(size_t i = 0; i < student.size(); ++i){
    int s;
    cin>>s;
    student[i] = make_pair(s,i);
  }
  contest(student);
}
