bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    int temp = x, count = x<0 ? 1 : 0, i;
    while(temp > 0){
        count++;
        temp /= 10;
    }
    int* intarray = (int*)malloc(sizeof(int)*count);
    temp = x;
    for(i=0;i<count;i++){
        intarray[i] = temp % 10;
        temp /=10;
    }
    int front = 0;
    int rear = count-1;
    while(front<=rear){
        if(intarray[front]==intarray[rear]){
            front++;
            rear--;
        }else{
            return false;
        }
    }
    return true;
}