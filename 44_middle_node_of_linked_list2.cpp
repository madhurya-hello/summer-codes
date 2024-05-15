// https://leetcode.com/problems/middle-of-the-linked-list/description///
// https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            if(fast->next==NULL){
                return slow;
            }
            fast=fast->next;
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};