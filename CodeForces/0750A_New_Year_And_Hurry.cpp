#include <iostream>
using namespace std;

int getmins(int problems){
  return (problems+1)*(problems)/2;
}

int main(){
  int problem, timeToMeeting, timeLimit = 240;
  //problem = 3;
  //timeToMeeting = 222;
  cin>>problem>>timeToMeeting;
  timeLimit -= timeToMeeting;
  int lo = 0;
  int hi = problem;
  while( lo <= hi ){
    int mid = (lo + hi)/2;
    int minsToFinishUntilMid = getmins(mid)*5;
    //cout<< mid <<' ' << minsToFinishUntilMid <<' '<<timeLimit<<endl;
    bool checkMid = (mid == problem);
    if( checkMid ||(
	  minsToFinishUntilMid <= timeLimit && getmins(mid+1)*5 > timeLimit)){
      cout<<mid<<endl;
      return 0;
    }else if( minsToFinishUntilMid < timeLimit ){
      lo = mid + 1;
    }else{
      hi = mid - 1;
    }
  }
}
