#include <iostream>
#include <vector>
using namespace std;

class volcanoes{
private:
  vector< vector<int> > vol;
public:
  volcanoes(int n){
    for(int i=0;i<n;i++){
      vector<int> row(n,0);
      vol.push_back(row);
    }
  }
  void impact(int x, int y, int w){
    vol[x][y]==w;
    impacthelp(x,y,w,1);
  }
  void impacthelp(int x, int y, int w, int s){
    while(w>s){
    int r1=x-s;
    int r2=x+s;
    int c1=y-s;
    int c2=y+s;
    for(int i=r1;i<=r2;i++){
      if(i>=0&&i<vol.size()&&c1>=0&&c1<vol.size()){
	vol[i][c1]+=(w-s);
      }
    }
    for(int i=r1;i<=r2;i++){
      if(i>=0&&i<vol.size()&&c2>=0&&c2<vol.size()){
	vol[i][c2]+=(w-s);
      }
    }
    for(int i=c1+1;i<c2;i++){
      if(i>=0&&i<vol.size()&&r1>=0&&r1<vol.size()){
	vol[r1][i]+=(w-s);
      }
    }
    for(int i=c1+1;i<c2;i++){
      if(i>=0&&i<vol.size()&&r2>=0&&r2<vol.size()){
	vol[r2][i]+=(w-s);
      }
    }
    s++;
    }
  }
  
  int printvol(){
    int max=0;
    for(int i=0;i<vol.size();i++){
      for(int j=0;j<vol[i].size();j++){
	if(vol[i][j]>max){
	  max=vol[i][j];
	}
	cout<<vol[i][j];
      }
      cout<<endl;
    }
    return max;
  }
  
};

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    volcanoes v(n);
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        int w;
        cin >> x >> y >> w;
	v.impact(x,y,w);
        // Write Your Code Here
        //cout<<w<<endl;
    }
    cout<<v.printvol()<<endl;;
    return 0;
}
