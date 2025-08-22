/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middlenode(ListNode* head){
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* prev = NULL;
            while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
        if (prev) prev->next = NULL; 
        return slow;
    }
    ListNode* mergeLL(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(l1!=NULL && l2!=NULL){
           if(l1->val <= l2->val){
            temp->next=l1;
            l1=l1->next;
           } else{
            temp->next=l2;
            l2=l2->next;
           }
           temp=temp->next;
        }
        if(l1!=NULL){
            temp->next=l1;
        }
        else{
            temp->next=l2;
        }
    return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle=middlenode(head);
       
        ListNode* left=sortList(head);
        ListNode* right=sortList(middle);
        return mergeLL(left,right);
        
    }
};