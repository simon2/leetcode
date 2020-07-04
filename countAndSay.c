char * countAndSay(int n){
    int i, j, k;
    char * prev = "1";
    char * now;
    for(i=1;i<n;i++){
        j = 0;
        k = 0;
        char s;
        now = (char *)malloc(sizeof(char)*10000);
        while(prev[j]!='\0'){
            s = prev[j];
            int count = 0;
            while(prev[j]==s){
                count++;
                j++;
            }
            if(count>9){
                printf("%d\n",count);
            }
            char * count_char = (char *)malloc(sizeof(char)*5000);
            int digit = 10;
            int l = 0;
            while(count>0){
                count_char[l++] = (count % digit) + '0';
                count = count / digit;
            }
            while(l>0){
                now[k++] = count_char[--l];
            }
            now[k++] = s;
            free(count_char);
        }
        now[k] = "\0";
        prev = now;
    }
    return prev;
}