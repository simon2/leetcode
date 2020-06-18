/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    if(temp1 == NULL){
        return temp2;
    }
    if(temp2 == NULL){
        return temp1;
    }
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = result;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val <= temp2->val){
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode -> val = temp1 -> val;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp1 = temp1 -> next;
        }else{
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode -> val = temp2 -> val;
            newNode -> next = NULL;
            temp -> next = newNode;
            temp2 = temp2 -> next;
        }
        temp = temp -> next;
    }
    if(temp1 != NULL){
        temp -> next = temp1;
    }
    if(temp2 != NULL){
        temp -> next = temp2;
    }
    return result->next;
}