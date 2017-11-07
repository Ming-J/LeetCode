class Solution{
public:
  bool validPalindrome(string s){
    bool flag=false;
    int j=s.size()-1;
    int i=0;
    while(i<j){
      if(s[i]!=s[j]){
	if(flag){
	  return false;
	}else{
	  if(s[i+1]==s[j]&&s[j-1]==s[i]){
	    if(s[i+2]==s[j-1]){
	      i++;
	    }else{
	      j--;
	    }
	  }else if(s[i+1]==s[j]){
	    i++;
	  }else if(s[j-1]==s[i]){
	    j--;
	  }
	  flag=true;
	}
      }else{
	i++;
	j--;
      }
    }    
    return true;
  }
};
