#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& array){
  int zero = 0;
  for(int i = 0; i < array.size(); ++i){
    if(array[i] == 0){
      swap(array[i],array[zero++]);
    }
  }
}


int main(){
  vector<int> input = {1,1,1,1,1,1,0,0,1,1,0};
  sort(input);
  for(auto i : input) cout<< i << ' ';
}
