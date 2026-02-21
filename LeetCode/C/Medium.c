// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* current = dummyHead; 
    int carry = 0; 
    while(l1 != NULL ||l2 != NULL || carry != 0) {
        int val1 = l1 != NULL ? l1->val : 0;
        int val2 = l2 != NULL ? l2->val : 0;
        int total = val1 + val2 + carry; 
        carry = total/10; 
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val = total%10; 
        current->next->next = NULL; 
        current = current->next; 
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    return dummyHead->next;
}
