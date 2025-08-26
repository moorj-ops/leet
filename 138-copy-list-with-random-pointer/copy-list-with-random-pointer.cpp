/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create beech ke nodes
        Node* curr=head;
        while(curr!=NULL){
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        //linking the rondom links
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* dummy=new Node(0);
        Node* copycurr=dummy;
        curr=head;
        while(curr){
            copycurr->next=curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            copycurr=copycurr->next;
        }
        return dummy->next;
    }
};