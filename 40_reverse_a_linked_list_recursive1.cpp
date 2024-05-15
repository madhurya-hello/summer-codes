// https://leetcode.com/problems/reverse-linked-list/description/
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
private:
    ListNode* pleaseReverse(ListNode* &head, ListNode* prv){
        // base case
        if(head==NULL){
            return prv;
        }
        ListNode* nxt = head->next;
        head->next = prv;
        prv=head;
        head=nxt;
        return pleaseReverse(head, prv);
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prv=NULL;
        
        return pleaseReverse(head, prv);

    }
};