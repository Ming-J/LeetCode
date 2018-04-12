#include <iostream>
using namespace std;

string acidNaming(string acid_name) {
  // Complete this function
  int strSize = acid_name.size();
  string prefix;
  if(strSize > 5){
    prefix = acid_name.substr(0, 5);
  }
  string suffix;
  if(strSize > 2){
    suffix = acid_name.substr(strSize - 2, 2);
  }
  bool preCheck = prefix == "hydro";
  bool suCheck = prefix == "ic";
  if(preCheck && suCheck){
    return "non-metal acid";
  }else if(suCheck){
    return "polyatomicacid acid";
  }else{
    return "not an acid";
  }
}

int main() {
  int n;
  string result = acidNaming("wqe");
  cout<<result<<endl;
  /*  cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string acid_name;
        cin >> acid_name;
        string result = acidNaming(acid_name);
        cout << result << endl;
	}*/
    return 0;
}
