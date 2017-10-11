#include <unordered_map>
struct sequence{
    unordered_map<char,int> hash;
    vector< vector<int> > dna;
    string seq;
    sequence(string S){
        seq=S;
        vector<int> row(S.size(),-1);
        dna.assign(S.size(),row);
        hash['A']=1;
        hash['C']=2;
        hash['G']=3;
        hash['T']=4;
    }
    void nuc(){
        for(int i=0;i<dna.size();i++){
            for(int j=i;j<dna[i].size();j++){
                if(i==j){
                    dna[i][j]=hash[seq[j]];
                }else{
                    dna[i][j]=min(dna[i][j-1],hash[seq[j]]);
                }
                cout<<dna[i][j]<<" ";
            }
            cout<<endl;
        }
    }
     int getmin(int p,int q){
        return dna[p][q];    
    }
};

struct sstwo{
  unordered_map<char,int> hash;
  vector< vector<int> > dna;
  string seq;
      sstwo(string S){
        seq=S;
        vector<int> row(S.size(),0);
        dna.assign(4,row);
        hash['A']=1;
        hash['C']=2;
        hash['G']=3;
        hash['T']=4;
    }
    void nuc(){
      for(int i=0;i<seq.size();i++){
	if(seq[i]=='A'){
	  dna[0][i]++;
	}
	if(seq[i]=='C'){
	  dna[1][i]++;
	}
	if(seq[i]=='G'){
	  dna[2][i]++;
	}
	if(seq[i]=='T'){
	  dna[3][i]++;
	}
      }   
    }
     int getmin(int p,int q){
       for(int i=0;i<4;i++){
	 for(int j=p;j<=q;j++){
	   if(dna[i][j]==1){
	     return i;
	   }
	 }
       }    
    }
};
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
  vector<int> ans(P.size(),0);
  sstwo virus(S);
  virus.nuc();
    for(int i=0;i<P.size();i++){
        int p=P[i];
        int q=Q[i];
        int ch=virus.getmin(p,q);
	if(ch=='A'){
	  ans[i]=1;
	}
	if(ch=='C'){
	  ans[i]=2;
	}
	if(ch=='G'){
	  ans[i]=3;
	}
	if(ch=='T'){
	  ans[i]=4;
	}
    }
    return ans;
}
