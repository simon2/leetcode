/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<math.h>
typedef struct node node;
struct node{
    int value;
    int position;
    node* next;
};

int hash(int value, int numsSize){
    return abs(value % numsSize);
}

void hash_insert(node** hash_table, int value, int position, int numsSize){
    printf("insert\n");
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->position = position;
    int hash_code = hash(value, numsSize);
    new_node->next = hash_table[hash_code];
    hash_table[hash_code] = new_node;
}

int hash_search(node** hash_table, int value, int numsSize){
    printf("search\n");
    int hash_code = hash(value, numsSize);
    printf("hash_code:%d\n",hash_code);
    node* p = hash_table[hash_code];
    while(p != NULL){
        if(p->value == value){
            return p->position;
        }
        p = p -> next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    node** hash_table = (node**)malloc(sizeof(node*)*numsSize);
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int)*2);
    int i;
    for(i=0;i<numsSize;i++){
        hash_table[i] = NULL;
    }
    for(i=0;i<numsSize;i++){
        int temp = hash_search(hash_table, nums[i], numsSize);
        printf("%d\n",temp);
        if(temp != -1){
            result[0] = temp;
            result[1] = i;
            printf("%d %d\n",result[0],result[1]);
            break;
        }else{
            hash_insert(hash_table, target-nums[i], i, numsSize);
        }
    }
    //printf("%d %d\n",result[0],result[1]);
    return result;
}