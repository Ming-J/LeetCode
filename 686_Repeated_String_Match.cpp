#include <iostream>
#include <string>
using namespace std;

/*To be able to check if B is a substring of A. First the size of A
  has to be greater of equal to B. So we will increment A to itself
  until the size of A is greater or equal to. And we can use the find
  function to see if B is a substring.

  If we can not find it, we will double the size of A again for more
  verifcation.
*/

class Solution{
public:
  int repeatedStringMatch(string A, string B){
    int count=1;
    string concatA=A;
    while(concatA.size()<B.size()){
      concatA+=A;
      count++;
    }
    size_t find=concatA.find(B);
    if(find==string::npos){
      concatA+=A;
      return concatA.find(B)!=string::npos?++count:-1;
    }else{
      return count;
    }
  }
};
