// https://leetcode.com/problems/middle-of-the-linked-list/description///
// https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        int index;
        if(count&1){            // if count is odd
            index = count/2;
        }
        else{                   // if count is even  
            index = (count/2);
        }

        temp=head;
        for (int i=0; i<index; i++){
            temp=temp->next;
        }

        return temp;
        
    }
};