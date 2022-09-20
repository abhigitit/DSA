/*
Arrange even numbers after odd numbers in LL

*/


#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    int val;
    
    node(int a)
    {
        val = a;
        next = nullptr;
    }
};

node* arrange_even_odd(node* head)
{
  node* even = new node(0);
  node* etail = even;
  
  node* odd = new node(0);
  node* otail = odd;
  
  while(head)
  {
      if(head->val%2==0)
      {
          etail->next = head;
          etail = etail->next;
          head = head->next;
          etail->next = nullptr;
      }
      else
      {
          otail->next = head;
          otail = otail->next;
          head = head->next;
          otail->next = nullptr;
      }
      
   
      
  }
     otail->next = even->next;
  return odd->next;
    
}
int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    node* temp = head;
    while(temp)
    {
    cout<<temp->val<<endl;
    temp=temp->next;
    }
    cout<<"Seperating odd and even"<<endl;
    node* ans = arrange_even_odd(head);
    while(ans)
    {
    cout<<ans->val<<endl;
    ans=ans->next;
    }
    return 0;
}
