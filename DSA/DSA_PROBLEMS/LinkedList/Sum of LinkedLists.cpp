/*

AlgoExpert

*/

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
LinkedList* dummy = new LinkedList(0);
  LinkedList* curr = dummy;
  int carry = 0;

  while(linkedListOne or linkedListTwo or carry)
  {
    int v1 = linkedListOne ? linkedListOne->value : 0;
    int v2 = linkedListTwo ? linkedListTwo->value : 0;
    int sum = v1+v2+carry;

    carry = sum/10;
    sum=sum%10;
    
    dummy->next = new LinkedList(sum);
    dummy = dummy->next;

    linkedListOne = linkedListOne ? linkedListOne->next : nullptr;
    linkedListTwo = linkedListTwo ? linkedListTwo->next :nullptr;

   
    
  }
  
  return curr->next;
}
