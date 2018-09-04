#include <iostream>
#include <cmath>
using namespace std;

class coord{
public:
  coord(string str){
    //RXCY
    //A12
    size_t rPos = str.find('R',0);
    size_t iPos = str.find_first_of("1234567890");
    size_t cPos = str.find_last_of('C');
    if(cPos!=string::npos&& rPos== 0 &&rPos+1!=cPos &&rPos+1==iPos){
      row = stoi(str.substr(rPos+1,cPos-rPos));
      col = stoi(str.substr(cPos+1));
      excelType = false;
    }else{
      size_t nonInt = str.find_first_of("1234567890");
      row = stoi(str.substr(nonInt));
      string colStr = str.substr(0,nonInt);
      col = 0;
      for(size_t i  = 0; i < colStr.size(); ++i){	
	col += (colStr[i] - 'A' + 1 ) * pow(26,colStr.size() - i - 1);
      }
      excelType = true;
      
    }
  }

  string convert(){
    if(excelType){
      return "R"+to_string(row)+"C"+to_string(col);
    }else{
      return convert26(col)+to_string(row);
    }
  }

private:
  long row;
  long col;
  bool excelType;

  string convert26(int r){
    string res = "";
    while(r > 0){
      char c;
      if( r % 26 == 0){
	c = 'Z';
	r = r/26 - 1;
      }else{
	c = r%26+'A'-1;
	r /= 26;
      }
      res = c + res;
    }
    return res;
  }
};


int main(){
  long n;
  cin>>n;
  for(long i = 0; i < n; ++i){
    string s;
    cin>>s;
    coord test(s);
    cout<<test.convert()<<endl;
  }
}
