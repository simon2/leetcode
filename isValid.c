
bool isValid(char * s){
    char* stack = (char*)malloc(sizeof(char)*10000);
    int top = -1;
    int i = 0;
    bool result = true;
    while(s[i] != '\0'){
        switch (s[i]){
            case '(':
                stack[++top] = '(';
                break;
            case ')':
                if(top!=-1 && stack[top]=='('){
                    top--;
                }else{
                    result = false;
                }
                break;
            case '[':
                stack[++top] = '[';
                break;
            case ']':
                if(top!=-1 && stack[top]=='['){
                    top--;
                }else{
                    result = false;
                }
                break;
            case '{':
                stack[++top] = '{';
                break;
            case '}':
                if(top!=-1 && stack[top]=='{'){
                    top--;
                }else{
                    result = false;
                }
                break;
        }
        if(!result){
            break;
        }
        i++;
    }
    if(top != -1) result = false;
    return result;
}