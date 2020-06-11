/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode newListNode(int x){
    struct ListNode temp;
    temp.val = x;
    temp.next = NULL;
    return temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result;
    int carry = 0;
    struct ListNode* first = l1;
    struct ListNode* second = l2;
    int a;
    int sum = first->val + second->val + carry;
    if(sum>=10){
            a = sum - 10;
            carry = 1;
        }else{
            a = sum;
            carry = 0;
        }
    result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result -> val = a; result -> next = NULL;
    first = first -> next;
    second = second -> next;
    struct ListNode* current = result;
    while(first!=NULL && second!=NULL){
        sum = first->val + second->val + carry;
        if(sum>=10){
            a = sum - 10;
            carry = 1;
        }else{
            a = sum;
            carry = 0;
        }
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = a;
        current->next->next = NULL;
        first = first -> next;
        second = second -> next;
        current = current -> next;
    }
    while(first){
        sum = first->val + carry;
        if(sum>=10){
            a = sum - 10;
            carry = 1;
        }else{
            a = sum;
            carry = 0;
        }
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = a;
        current->next->next = NULL;
        first = first -> next;
        current = current -> next;
    }
    while(second){
        sum = second->val + carry;
        if(sum>=10){
            a = sum - 10;
            carry = 1;
        }else{
            a = sum;
            carry = 0;
        }
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = a;
        current->next->next = NULL;
        second = second -> next;
        current = current -> next;
    }
    if(carry==1){
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));;
        current->next->val = 1;
        current->next->next = NULL;
    }
    struct ListNode* m = result;
    return result;
}