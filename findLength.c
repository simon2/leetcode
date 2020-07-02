/******* My naive solustion using recursion ******/
/******* Didn't pass for time limitation *********/
int recursiveFindLength(int* A, int startA, int endA, int* B, int startB, int endB){
    int lengthA = endA - startA + 1;
    int lengthB = endB - startB + 1;
    if(lengthA == 0 || lengthB == 0){
        return 0;
    }
    if(lengthA == lengthB){
        int i;
        for(i=0;i<lengthA;i++){
            if(A[startA+i] != B[startB+i]){
                break;
            }
        }
        if(i == lengthA){
            return i;
        }else{
            int res[4];
            res[0] = recursiveFindLength(A,startA+1,endA,B,startB,endB);
            res[1] = recursiveFindLength(A,startA,endA-1,B,startB,endB);
            res[2] = recursiveFindLength(A,startA,endA,B,startB+1,endB);
            res[3] = recursiveFindLength(A,startA,endA,B,startB,endB-1);
            int j,max=-1;
            for(j=0;j<4;j++){
                if(res[j]>max){
                    max = res[j];
                }
            }
            return max;
        }
    }else{
        int res[4];
            res[0] = recursiveFindLength(A,startA+1,endA,B,startB,endB);
            res[1] = recursiveFindLength(A,startA,endA-1,B,startB,endB);
            res[2] = recursiveFindLength(A,startA,endA,B,startB+1,endB);
            res[3] = recursiveFindLength(A,startA,endA,B,startB,endB-1);
            int j,max=-1;
            for(j=0;j<4;j++){
                if(res[j]>max){
                    max = res[j];
                }
            }
            return max;
    }
}

int findLength(int* A, int ASize, int* B, int BSize){
    return recursiveFindLength(A,0,ASize-1,B,0,BSize-1);
}
/********** End of my naive solution *************/

/********** Better way using DP ******************/
int findLength(int* A, int ASize, int* B, int BSize){
    int table[ASize+1][BSize+1];
    memset(table, 0, sizeof(table));
    int i, j;
    int max = 0;
    for(i=ASize-1;i>=0;i--){
        for(j=BSize-1;j>=0;j--){
            if(A[i]==B[j]){
                table[i][j] = table[i+1][j+1] + 1;
                if(table[i][j]>max){
                    max = table[i][j];
                }
            }else{
                table[i][j] = 0;
            }
        }
    }
    return max;
}
/********** end of DP solution *******************/
