#include "llrec.h"
#include "iostream"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //check head node is nullptr
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
//check if current node val is less than or equal to pivot
  if(head->val <= pivot){
    // std::cout << "less than pivot " << head->val << std::endl;
  // if node is less or equal, check if head
      smaller = head;
      head = head->next;
      llpivot(head, smaller->next, larger, pivot);
    }
  
  else{
      larger = head;
      head = head->next;
      llpivot(head, smaller, larger->next, pivot);
  }
}
