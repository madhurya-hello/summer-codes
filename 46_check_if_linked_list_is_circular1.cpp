//https://www.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   // Your code here
   if(head->next==NULL || head->next==head){
       return true;
   }
   
   Node* temp=head->next;
   while(temp!=head){
       temp=temp->next;
       if(temp==NULL){
           return false;
       }
   }
   return true;
   
}