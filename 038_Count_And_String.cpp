/*=========================================================== 
The count-and-say sequence is the sequence of integers with the first five
terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

 ============================================================*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

class Solution{
public:
  string countAndSay(int n){
    string result;
    for(int i=0;i<n;i++){
      if(i==0){
	result="1";
      }else{
	int count=1;
	int slength=result.size();
	string partial;
	for(int j=0;j<slength;j++){
	  if(j+1<slength&&result[j]==result[j+1]){
	    count++;
	  }else{
	    //stringstream ss;
	    //ss<<count;
	    char buffer[16];
	    sprintf(buffer,"%d",count);
	    partial=partial+buffer+result[j];
	    count=1;
	  }
	}
	result=partial;
      }
    }
    return result;
  }
};


int main(){
  Solution test;
  test.countAndSay(5);
}
