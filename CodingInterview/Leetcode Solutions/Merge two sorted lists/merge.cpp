class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) {return l2;}
        if(l2==nullptr) {return l1;}
        
        ListNode *tmp,*side,*main,*head=(l1->val>l2->val?l2:l1);
        if(head==l1){main=l1,side=l2;}
        else{main=l2,side=l1;}
        
        while(main->next!=nullptr){
            if(main->next->val<=side->val){
                main=main->next;
            }
            else{
                tmp=main->next;
                main->next=side;
                side=tmp;
            }
        }
        main->next=side;
        return head;
    }
};
