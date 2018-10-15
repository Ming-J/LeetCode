#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
void sortInner(char* begin, char* end){
  std::sort(begin+1,end-1,std::greater<char>());
} 

char* sortTheInnerContent(const char* words, int length) {
  char cpy[length];
  std::strcpy(cpy,words);
  char* res = new char[length];
  res[0]='\0';
  char* token;
  token = std::strtok(cpy," ");
  while(token != NULL){
    std::cout<<"s"<<std::endl;
    if(strlen(token) > 2) sortInner(token,token+std::strlen(token));
    if(res != NULL && res[0] == '\0') {std::strcpy(res, token);}
    else std::strcat(res, token);
    token = std::strtok(NULL, " ");
    if(token!=NULL) strcat(res," ");
  }
  return res;
}

int main(){
  const char* input = "w   absfads";
  std::cout<<sortTheInnerContent(input,strlen(input));
}
