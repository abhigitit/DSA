/*
Zip LinkedList
half, reverse second half
merge
*/

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};
LinkedList* reverse(LinkedList* head)
{
  if(!head or !head->next)
      return head;
  LinkedList* temp = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return temp;
}

LinkedList* merge(LinkedList* head1, LinkedList* head2)
{
  LinkedList* iter1 = head1;
  LinkedList* iter2 = head2;
  while(iter1 and iter2)
    {
     LinkedList* nxt1 = iter1->next;
      LinkedList* nxt2 = iter2->next;
      iter1->next = iter2;
      iter2->next = nxt1;
      iter1 = nxt1;
      iter2 = nxt2;
    }

  return head1;
}
LinkedList *zipLinkedList(LinkedList *head) {
  if(!head or !head->next)
      return head;
  LinkedList* slow = head;
  LinkedList* fast = head;
  while(fast and fast->next)
    {
    slow = slow->next;
    fast = fast->next->next;
    }
  LinkedList* temp = slow->next;;
  slow->next = nullptr;
  LinkedList* head2 = reverse(temp);
  return merge(head,head2);
}
