#include<limits.h>

int reverse(int x){
    int temp = x, i;
    long result = 0;
    while(temp != 0){
        int n = temp % 10;
        result = result * 10 + n;
        temp /= 10;
        if(result>INT_MAX || result < INT_MIN){
            result = 0;
        }
    }
    
    return (int)result;
}