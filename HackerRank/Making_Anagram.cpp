#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
  int arr[26]={0};
  int brr[26]={0};
   for(int i=0;i<a.size();i++){
     arr[a[i]-'a']++;
   }
   for(int i=0;i<b.size();i++){
     brr[b[i]-'a']++;
   }
   int count=0;
   for(int i=0;i<26;i++){
     while(arr[i]!=brr[i]){
       if(arr[i]>brr[i]){
	 arr[i]--;
       }else{
	 brr[i]--;
       }
       count++;
     }
   }
   return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
