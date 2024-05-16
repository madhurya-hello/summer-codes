// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
private:
    ListNode* undoReverse(ListNode* head, ListNode* prev){
        // base case
        if(head==NULL){
            return prev;
        }
        ListNode* next=head->next;
        head->next=prev;
        prev=head;
        head=next;
        return undoReverse(head, prev);

    }
    ListNode* pleaseReverse(ListNode* &head, int k){
        // base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // reversing k nodes
        int count =0;
        ListNode* prev=NULL;
        ListNode* store=head;
        while(count!=k){

           if(head==NULL){                  // if 'k' no. of terms are not present at the end of the list, we dont have to reverse it
            return undoReverse(prev, NULL);
           }
            
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
            count++;
        }

        // recursive call
        store->next=pleaseReverse(head, k);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return pleaseReverse(head, k);
    }
};