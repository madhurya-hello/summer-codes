// https://www.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   // Your code here
   Node* slow = head;
   Node* fast = head;
   
   while(fast!=NULL){
       if(fast->next!=NULL){
           fast=fast->next;
           slow=slow->next;
       }
       fast=fast->next;
       
       if(slow==fast){
           return true;
       }
       
       if(fast==NULL){
           return false;
       }
       
   }
   
   
}