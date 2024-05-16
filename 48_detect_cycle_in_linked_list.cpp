//https://www.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   // Your code here
   map<Node*, bool> mp;
   
   Node* temp=head;
   
   while (temp!=NULL){
       if(mp[temp]==true){
           return true;
       }
       mp[temp, true];
       temp=temp->next;
   }
   return false;
}

