#include <string>
using namespace std;
/*
E6-30.cpp:15:7: error: non-void function 'str_subrange' should return a value
      [-Wreturn-type]
      return;   //error1 n
*/
bool str_subrange(const string &str1, const string &str2)
{
  // same sizes: return normal equality test
  if (str1.size() == str2.size())
    return str1 == str2; // ok: == return bool
  //find the size of the smaller string; conditional operator
  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

  //look at each element up to the size of the smaller string
  for (decltype(size) i = 0; i != size; ++i){
    if (str1[i] != str2[i])
      return;	//error1 no return value; compiler shoud detect error	
    }
  //error2 control might flow off the end of the function without a
  //return the compiler might not detect this error
}
