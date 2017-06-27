/*---------------------------------------------------
  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 < x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ¡ô   ¡ô

The above arrows point to positions where the corresponding bits are different.

So apperently there are a way easier way to do this problem using XOR bitwise calculation
But i did not go with that particular approach, I convert the int to bit string and make sure they are equal length. After the length are the same, i would compare them.
 ----------------------------------------------------*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    string xval=baseOf2(x);
    string yval=baseOf2(y);
    int diffcounter=0;
    //make sure the two string are equal length
    while(xval.size()!=yval.size()){
      if(xval.size()>yval.size()){
	yval.insert(0,"0");
      }else{
	xval.insert(0,"0");
      }
    }
    //get the difference in string
    for(int i=0;i<xval.size();i++){
      if(xval[i]!=yval[i]){
	diffcounter++;
      }
    }
    return diffcounter;
  }
  //simple function to convert integer to base of 2.(Only positive int)
  string baseOf2(int val){
    string sval;
    int valmod;
    while(val>0){
      valmod=val%2;
      val=val/2;
      stringstream ss;
      ss<<valmod;
      sval.insert(0,ss.str());
    }
    return sval;
  }
};

int main(){
  Solution test;
  cout<<test.hammingDistance(3,1)<<endl;
  cout<<"Hello World"<<endl;
}
