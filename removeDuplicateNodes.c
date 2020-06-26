/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int hash(int value){
    return abs(value % 1000);
}

void hash_insert(struct ListNode** hash_table, int value){
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = value;
    int hash_code = hash(value);
    new_node->next = hash_table[hash_code];
    hash_table[hash_code] = new_node;
}

int hash_search(struct ListNode** hash_table, int value){
    int hash_code = hash(value);
    struct ListNode* p = hash_table[hash_code];
    while(p != NULL){
        if(p->val == value){
            return 1;
        }
        p = p -> next;
    }
    return 0;
}

struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode** hash_table = (struct ListNode**)malloc(sizeof(struct ListNode*) * 1000);
    int i;
    for(i=0;i<1000;i++){
        hash_table[i] = NULL;
    }
    struct ListNode* temp = head;
    hash_insert(hash_table,temp->val);
    while(temp != NULL){
        struct ListNode* search = temp->next;
        if(search == NULL){
            break;
        }
        if(hash_search(hash_table, search->val)){
            struct ListNode* m = search;
            search = search->next;
            free(m);
            temp->next = search;
        }else{
            hash_insert(hash_table, search->val);
            temp->next = search;
            temp = temp->next;
        }
    }
    return head;
}