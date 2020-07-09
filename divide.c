#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

/***** my solution run out of time ***/
int divide(int dividend, int divisor){
    if(dividend == 0){
        return 0;
    }
    if(divisor == 1){
        return dividend;
    }
    if(divisor == -1){
        if(dividend == INT_MIN){
            return INT_MAX;
        }else{
            return -dividend;
        }
    }
    if(dividend == INT_MIN && divisor == INT_MIN){
        return 1;
    }
    if(divisor == INT_MIN){
        return 0;
    }

    int i = 0;
    if(dividend == INT_MIN){
        dividend += abs(divisor);
        i++;
    }
    int flag;
    if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)){
        flag = 1;
    }else{
        flag = -1;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    while(dividend >= divisor){
        dividend -= divisor;
        i++;
    }
    if(flag == 1){
        return i;
    }else{
        return -i;
    }
}
/**** end of my solution ***/

#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

int divide(int dividend, int divisor)
{
    int result = 0;
    if(dividend == 0)
		return 0;
    else if(dividend == INT_MIN && divisor == -1)
		return INT_MAX;
    else if(dividend == INT_MIN && divisor == 1)
		return INT_MIN;
    else if(dividend == INT_MIN && divisor == INT_MIN)
        return 1;
    else if(divisor == INT_MIN)
        return 0;

    bool negative = (dividend ^ divisor) < 0;

    if(dividend == INT_MIN){
        dividend += abs(divisor);
        result++;
    }
    int t = abs(dividend);
    int d = abs(divisor);

    for(int i = 31; i >= 0; i--){
        if((t >> i) >= d){
            result += 1 << i;
            t -= d << i;
        }
    }

    if(result == INT_MIN)
        return INT_MAX;
    else
        return negative ? -result : result;
    return 0;
}