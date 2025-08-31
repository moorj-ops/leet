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
    ListNode* findnthnode(ListNode* head, int n) {
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }
    return temp;
}

    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        ListNode *tail=head;
        if (!head || k == 0) return head;

        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        //check if k is the multiple of k
        if(k%len==0){
            return head;
        }
        k=k%len;
        //make the list cicular
        tail->next=head;
        ListNode* newlastnode=findnthnode(head,len-k);
        head=newlastnode->next;
        newlastnode->next=NULL;
        return head;


    }   
};