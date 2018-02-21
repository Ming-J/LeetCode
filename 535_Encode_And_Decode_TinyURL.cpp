#include <iostream>
#include <unordered_map>
using namespace std;
// using the hash function to help us hash, could also use to store
// them in vector and return the index, limited by the size of int
// can also use a random function to help us create a key
class Solution {
public:
  unordered_map<string, string> hash;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    auto fn = hash.hash_function();
    string abv = to_string(fn(longUrl));
    hash[abv] = longUrl;
    return "http://tinyurl.com/" + abv;
  }
  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string code = shortUrl.substr(19);
    //cout<<code<<endl;
    return hash[code];
  }
};

int main(){
  string web = "www.google.com";
  Solution test;
  string res = test.encode(web);
  cout<<res<<endl;
  cout<<test.decode(res)<<endl;
}
