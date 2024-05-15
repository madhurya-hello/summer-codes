// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
    
    private:
    Node* pleaseReverse(Node* head, Node* prv){
        Node* store=head;
        while(head!=NULL){
            Node* nxt=head->next;
            head->next=prv;
            prv=head;
            head=nxt;
        }
        Node* firstHead=prv;
        
        head=prv;
        prv=NULL;
        while(head!=NULL){
            Node* nxt=head->prev;
            head->prev=prv;
            prv=head;
            head=nxt;
        }
        
        return firstHead;
    }
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* prv=NULL;
        return pleaseReverse(head, prv);
    }
};