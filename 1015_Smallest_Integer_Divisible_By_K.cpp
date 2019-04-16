#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0) return -1;
        int length = 1;
        int num = 0;
        while(K >= length){
            num = (num * 10 + 1) % K;
            if(num  == 0) return length;
            length++;
       }
        return - 1;
    }
};
