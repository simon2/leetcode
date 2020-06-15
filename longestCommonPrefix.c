char * longestCommonPrefix(char ** strs, int strsSize){
    char* result = (char*)malloc(sizeof(char)*1000);
    int i=0, j=0, flag=1;
    if(strsSize==0){
        result[0] = '\0';
        return result;
    }
    while(flag){
        char same;
        if(strs[0][j]!='\0'){
            same = strs[0][j];
        }else{
            result[j] = '\0';
            break;
        }
        for(i=1;i<strsSize;i++){
            if(strs[i][j]=='\0' || same!=strs[i][j]){
                flag = 0;
                result[j] = '\0';  
                break;
            }
        }
        if(flag==1){
            result[j] = same;
        }
        j++;
    }
    return result;
}