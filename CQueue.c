typedef struct {
    int* inputStack;
    int* outputStack;
    int inputHead;
    int outputHead;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *a = (CQueue*)malloc(sizeof(CQueue));
    a->inputStack = (int*)malloc(sizeof(int)*10000);
    a->outputStack = (int*)malloc(sizeof(int)*10000);
    a->inputHead = -1;
    a->outputHead = -1;
    return a;
}

void cQueueAppendTail(CQueue* obj, int value) {
    obj->inputStack[++(obj->inputHead)] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    int res;
    if(obj->outputHead > -1){
        res = obj->outputStack[(obj->outputHead)--];
    }else{
        while(obj->inputHead > -1){
            int temp = obj->inputStack[(obj->inputHead)--];
            obj->outputStack[++obj->outputHead] = temp;
        }
        if(obj->outputHead > -1){
            res = obj->outputStack[(obj->outputHead)--];
        }else{
            res = -1;
        }
    }
    return res;
}

void cQueueFree(CQueue* obj) {
    free(obj->inputStack);
    free(obj->outputStack);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/