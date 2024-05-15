// https://leetcode.com/problems/reverse-linked-list/description/
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prv=NULL;
        ListNode* nxt=NULL;
        while(head!=NULL){
            nxt = head->next;
            head->next = prv;
            prv=head;
            head=nxt;
            
        }
        head=prv;
        return head;
    }
};