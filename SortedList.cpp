#include <iostream>

struct Node{
  int data;
  struct Node *next;
};

class SortedList{
  private:
  Node * head = NULL;

  public:
  void insert(int data){ 
    Node * temp1 = head;
    Node * temp = new Node;
    temp->data = data; 
    temp->next = NULL;

    if(head == NULL){ 
      head = temp;
    }
    else{
      while(temp1->next){
        temp1 = temp1->next;
      }
      temp1->next = temp;
    }
  }

  void remove(int data){
    Node * temp1 = head;
    Node * prev = NULL;
    Node * tempNext = NULL;

    while(temp1->data != data && temp1 != NULL){
      prev = temp1;
      temp1 = temp1->next;
    }
    if(temp1 == NULL){
      std::cout << "DATA NOT FOUND.";
    }
    else if(prev == NULL){
      tempNext = temp1->next;
      head = tempNext;
      delete temp1;
    }
    else{
      tempNext = temp1->next;
      prev->next = tempNext;
      delete temp1;
    }
  }

  bool contains(int data){
    Node * temp1 = head;
    while(1){
      if(temp1->data == data){
        return true;
      }
      else{
        return false;
      }
      temp1 = temp1->next;
    }
  }
  
  
  void print(){
    if(head != NULL){
      Node * temp1 = head;
      while(temp1){
        std::cout << temp1->data << "  ";
        temp1 = temp1->next;
      }
    }
    else{
      return;
    }
    return;
  }

  int size(){
    Node * temp1 = head;
    int count {0};
    while(temp1 != NULL){
      count++;
      temp1 = temp1->next;
    }
    return count;
  }
};

int main(){
  SortedList obj;

  obj.insert(1);
  obj.insert(2);
  obj.insert(3);
  obj.insert(4);
  obj.insert(5);
  std::cout << "Before remove function: " << std:: endl;
  obj.print();
  std::cout << "\nSize: " << obj.size() << std::endl;

  obj.remove(1);
  obj.remove(3);
  std::cout << std::endl;
  std::cout << "After remove function: " << std:: endl;
  obj.print();
  std::cout << "\nSize: " << obj.size() << std::endl;

  std::cout << "\nContains data value 2?(1 = True; 0 = False) " << obj.contains(2) << std::endl;
  std::cout << "Contains data value 3?(1 = True; 0 = False) " << obj.contains(3) << std::endl;
}