/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }; 
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3= (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p=l3;
    int val=0;

    //进位初始为0
    int c=0;
    while(l1||l2){
        int val=c+(l1?l1->val:0)+(l2?l2->val:0);
        //如果val大于等于10的话，肯定产生了进位
        c=val/10;
        val=val%10;
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=val;
        node->next=NULL;
        p->next=node;
        p=p->next;
        if(l1){
            l1=l1->next;
        }
        if(l2){
            l2=l2->next;
        }
    }
    if(c!=0){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=c;
        node->next=NULL;
        p->next=node;
        p=p->next;
    }
    
    return l3->next;
    
    
}
