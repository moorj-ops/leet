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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }
        if(cnt==k){
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* next=NULL;
            int c=0;
            while(curr!=NULL && c<k){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                c++;

            }
            head->next=reverseKGroup(curr,k);
            return prev;

        }
        return head;
    }
};
