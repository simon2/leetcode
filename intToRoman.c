char * intToRoman(int num){
    char* result = (char*)malloc(sizeof(char)*20);
    int temp = num;
    int devide = 1000;
    int i = 0;
    while(devide > 0){
        int m = temp / devide;
        int n;
        if(devide == 1000){
            for(n=0;n<m;n++){
                result[i++] = 'M';
            }
        }else if(devide == 100){
            if(m==9){
                result[i++] = 'C';
                result[i++] = 'M';
            }else if(m==4){
                result[i++] = 'C';
                result[i++] = 'D';
            }else if(m>=5){
                result[i++] = 'D';
                for(n=0;n<m-5;n++){
                    result[i++] = 'C';
                }
            }else{
                for(n=0;n<m;n++){
                    result[i++] = 'C'; 
                }
            }
        }else if(devide == 10){
            if(m==9){
                result[i++] = 'X';
                result[i++] = 'C';
            }else if(m==4){
                result[i++] = 'X';
                result[i++] = 'L';
            }else if(m>=5){
                result[i++] = 'L';
                for(n=0;n<m-5;n++){
                    result[i++] = 'X';
                }
            }else{
                for(n=0;n<m;n++){
                    result[i++] = 'X'; 
                }
            }
        }else{
            if(m==9){
                result[i++] = 'I';
                result[i++] = 'X';
            }else if(m==4){
                result[i++] = 'I';
                result[i++] = 'V';
            }else if(m>=5){
                result[i++] = 'V';
                for(n=0;n<m-5;n++){
                    result[i++] = 'I';
                }
            }else{
                for(n=0;n<m;n++){
                    result[i++] = 'I'; 
                }
            }
        }
        temp = temp - (m * devide);
        devide /= 10;
    }
    result[i] = '\0';
    return result;
}