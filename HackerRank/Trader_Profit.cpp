#include <iostream>
#include <vector>
using namespace std;

int traderProfit(int k, int n, vector <int> A) {
  // Complete this function
  vector< vector<int> > max;
  
  return 0;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}
