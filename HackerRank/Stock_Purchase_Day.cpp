using namespace std;

int stockPurchaseDay(vector <int> A, int xi) {
  // Complete this function
  for(size_t i=A.size();i>0;i--){
    if(A[i-1]<=xi){
      return i+1;
    }
  }
  return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int xi;
        cin >> xi;
        int result = stockPurchaseDay(A, xi);
        cout << result << endl;
    }
    return 0;
}
