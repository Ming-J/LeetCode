#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto& str : queries){
            ans.push_back(check(str,pattern));
        }
        return ans; 
    }
    
    bool check(string &str , string &pattern){
        if(pattern.size() > str.size()){
            return false;
        }
        int str_i = 0, pat_i = 0;
        while(str_i < str.size()){
            bool str_cap = (str[str_i] >='A' && str[str_i] <='Z');
            if(pat_i == pattern.size()){
                if(str_cap) return false;
                else{
                    ++str_i;
                    continue;
                }
            }
            bool pat_cap = (pattern[pat_i] >='A' && pattern[pat_i] <='Z');
            if(str_cap == pat_cap){
                if(str_cap && str[str_i] != pattern[pat_i]){
                    return false;
                }
                if(str[str_i] == pattern[pat_i]) pat_i++;
                str_i++;
            }else if(str_cap && !pat_cap){
                return false;
            }else{
                str_i++;   
            }
        }
        return (pattern.size()==pat_i)? true:false;
    }
};
