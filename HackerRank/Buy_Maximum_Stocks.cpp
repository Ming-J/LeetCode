#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct product{
  int sprice;
  int pday;
  product(int price,int day){
    sprice=price;
    pday=day;
  }
  bool operator<(const product &p) const {
    return sprice<p.sprice;
  }
  bool operator>(const product &p) const{
    return sprice>p.sprice;
		}
  bool operator<=(const product &p) const {
    return sprice<=p.sprice;
  }
  bool operator>=(const product &p) const{
    return sprice>=p.sprice;
  }
};

long buyMaximumProducts(int n, long long k, vector <int> a) {
    // Complete this function
    long long stockprice=0;
    vector<product> arr;
    for(int i=0;i<n;i++){
      arr.push_back(product(a[i],i+1));
    }
    sort(arr.begin(),arr.end());
    int count=0;
    for(int i=0;i<arr.size();i++){
      int allow=arr[i].pday;
      if(k>=(stockprice+(arr[i].sprice*allow))){
	stockprice+=(arr[i].sprice*allow);
	count+=allow;
      }else{
	while(allow>0){
	  if(k>=stockprice+arr[i].sprice){
	    stockprice+=arr[i].sprice;
	    count++;
	  }
	  allow--;
	}
      }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long k;
    cin >> k;
    long result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
    return 0;
}
