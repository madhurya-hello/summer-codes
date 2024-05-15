// https://leetcode.com/problems/reverse-linked-list/description/
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
private:
    void insertAtTail(ListNode* ele, ListNode* &head){
        ListNode* temp=head;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=ele;
        ele->next=NULL;
        head=temp;
    }
private:
    ListNode* pleaseReverse(ListNode* &head){
        // base case
        if(head->next==NULL){
            return head;
        }

        ListNode* newHead = pleaseReverse(head->next);
        insertAtTail(head, newHead);
        return newHead;
    }

public:
    ListNode* reverseList(ListNode* head) {

        if (head==NULL || head->next==NULL){
            return head;
        }     
        return pleaseReverse(head);

    }
};