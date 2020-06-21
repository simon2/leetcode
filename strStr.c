int strStr(char * haystack, char * needle){
    int result = -1;
    int a = 0;
    if(haystack[0] == '\0' && haystack[0] == needle[0]){
        return 0;
    }
    while(haystack[a] != '\0'){
        int i = 0;
        while(needle[i] != '\0' && haystack[a+i] == needle[i]){
            i++;
        }
        if(needle[i] == '\0'){
            result = a;
            break;
        }
        a++;
    }
    return result;
}