#include <iostream>
using namespace std;

int tripleStep(int n){
  if(n == 0) return 1;
  if(n == 1) return tripleStep(n-1);
  if(n == 2) return tripleStep(n-1) + tripleStep(n-2);
  return tripleStep(n-3) + tripleStep(n-2) + tripleStep(n-1); 
}


int main(){
  cout<<tripleStep(37)<<endl;
}
