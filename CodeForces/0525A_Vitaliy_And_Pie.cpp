#include <iostream>
#include <vector>
using namespace std;

class Door{
public:
  Door(string passage){
    vector<int> keys(26,0);
    int count = 0;
    for(size_t i = 0; i + 1 < passage.size(); i+=2){
      char curKey = passage[i];
      char curDoor = passage[i+1];
      if(toupper(curKey) != curDoor){
	if(keys[curDoor-'A'] > 0){
	  --keys[curDoor-'A'];
	}else{
	  ++count;
	}
	++keys[curKey-'a'];
      }
    }
    key = count;
  }
  int getKey(){return key;}
private:
  int key;

};




int main(){
  int n;
  cin>>n;
  string passage;
  cin>>passage;
  Door d(passage);
  cout<<d.getKey()<<endl;
}
