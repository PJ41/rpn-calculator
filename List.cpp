//List.cpp

#include "List.h"

List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  head->previous = NULL;
  tail->next = NULL;
  tail->previous = head;
  count = 0;  
}

List::List(const List &source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List &List::operator=(const List &source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {

	  insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if(head->next == tail && tail->previous == head)
    return true;
  return false;
  
}

void List::makeEmpty() {
  int val;
  while(!isEmpty()){
    val = head->next->value;
    remove(val);
  }
  count = 0;
}

ListItr List::first() {
  return head->next;
}

ListItr List::last() {
  return tail->previous;
}

void List::insertAfter(int x, ListItr position) {
  ListNode *node = new ListNode();
  node->value = x;
  ListNode *p = position.current;
  ListNode *a = p->next;
  node->previous = p;
  node->next = a;
  p->next = node;
  a->previous = node;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  ListNode *node = new ListNode();
  node->value = x;
  ListNode *p = position.current;
  ListNode *b = p->previous;
  node->next = p;
  node->previous = b;
  p->previous = node;
  b->next = node;
  count++;
}

void List::insertAtTail(int x) {
  ListNode *node = new ListNode();
  node->value = x;
  ListItr position = last();
  ListNode *p = position.current;
  ListNode *a = p->next;
  node->previous = p;
  node->next = a;
  p->next = node;
  a->previous = node;
  count++;
}


void List::remove(int x) {
  ListItr temp = find(x);
  ListNode *a = temp.current->next;
  ListNode *b = temp.current->previous;
  a->previous = b;
  b->next = a;
  delete temp.current;
  count--;
  
}

ListItr List::find(int x) {
  ListItr temp = first();
  while(true){
    if(x == temp.current->value){
      return temp;
    }
    else{
      temp.moveForward();
      if(temp.current == tail){
	return temp;
      }	
    }    
  }  
}

int List::size() const {
  return count;
}

void printList(List &source, bool direction) {
  ListItr temp;
  if(direction){
    temp = source.first();
    while(!temp.isPastEnd()){
      cout << "[" << temp.retrieve()  << "] ";
      temp.moveForward();
    }
    cout << endl;
  }
  else{
    temp = source.last();
    while(!temp.isPastBeginning()){
      cout << "[" << temp.retrieve()  << "] ";
      temp.moveBackward();
    }
    cout << endl;
  }
}
