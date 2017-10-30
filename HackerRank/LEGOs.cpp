#include <iostream>
using namespace std;
void checkequal(int &val,int &check){
  if(val==check){
    check=0;
    val=1;
  }
}

int productOfLegoTypes(int a, int b, int c, int d, int p, int q) {
  if(a==b&&b==c&&c==d){
    return a*b;
  }
  checkequal(a,q);
  checkequal(a,p);
  checkequal(b,q);
  checkequal(b,p);
  checkequal(c,q);
  checkequal(c,p);
  checkequal(d,q);
  checkequal(d,p);
  return a*b*c*d
  // Return the product of r and s
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int b;
        int c;
        int d;
        cin >> a >> b >> c >> d;
        int p;
        int q;
        cin >> p >> q;
        int answer = productOfLegoTypes(a, b, c, d, p, q);
        cout << answer << endl;
    }
    return 0;
}
