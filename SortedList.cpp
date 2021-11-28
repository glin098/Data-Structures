#include <iostream>
#include <string>

// FIX: When removing from an empty list or removing the item that doesn't exist, it fails. 

// defining structure used to create nodes
struct Node{
  int data;
  struct Node *next;
};

template <typename T>
class SortedList{
  private:
  // the head pointer is initialized to null
  Node * head = NULL;

  public:
  void sortedInsert(T data){ // adding new node to sorted list
    Node * temp = head; // creation of temporary head that is the head
    Node * newNode = new Node; // creation of a new node
    newNode->data = data; // the data in the new node is equal to the data input in the parameter
    newNode->next = NULL; // the next pointer of the new node is a null pointer

    if(head == NULL || head->data >= newNode->data){ // if the head equals null or the data of the head is greater than or equal to the data of the new node
      newNode->next = head;
      head = newNode;
    }
    else{ 
      while(temp->next != NULL && temp->next->data < newNode->data){
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode; // place the new node in the temporary node where there is a spot
    }
  }

  void remove(T data){ //remove an existing node from sorted list
    Node * temp = head; // set temporary node to the head 
    Node * prev = NULL; // set new pointer named previous to null
    Node * tempNext = NULL; // set a new temporary next pointer as null as well

    if(size() == 0){ // if list is empty
      std::cout << "Cannot remove from an empty list.";
      return;
    }
    

    // while the data in the head is not equal to the data and the head is not null
    while(temp != NULL && temp->data != data){ 
      prev = temp; // the previous pointer will be set as the temp, which is set to the data in the head
      temp = temp->next; // going forward until it doesnt satisfy the while loop anymore
    }

    if(temp == NULL){ // if there is no value in the head(temp pointer set to null) there will be no data found
      std::cout << "DATA NOT FOUND.";
    }
    else if(prev == NULL){ // else if the previous pointer is null
      tempNext = temp->next;
      head = tempNext; // the head pointer is equal to the temporary next value
      delete temp; // delete the temporary head pointer
    }
    else{
      tempNext = temp->next; // the temporary next pointer will be set as the next value after temp, the head
      prev->next = tempNext;
      delete temp; // delete the temporary head pointer
    }
  }

  // to see if the sorted list contains a certain element
  bool contains(T data){
    // while true, if the data is contained in the head, return true, otherwise, return false, then go on to the next value after the head and so on
    Node * temp = head;
    while(1){
      if(temp->data == data){
        return true;
      }
      else{
        return false;
      }
      temp = temp->next;
    }
  }
  
  
  void print(){ // prints the sorted list
    if(head != NULL){
      Node * temp = head;
      while(temp){
        std::cout << temp->data << "  ";
        temp = temp->next;
      }
    }
    else{
      std::cout << "List is empty";
    }
    return;
  }

  int size(){ // counts the number of elements in the sorted list
    Node * temp = head;
    int count {0}; // sent counter to zero initially
    while(temp != NULL){
      count++; // increment each time there is something in the list
      temp = temp->next; // go on to next element
    }
    return count;
  }


/*
  void sort(){ // sorting the elements of the list in order
    Node *cur, *nCur; 
		cur = head; // current pointer starts with the head
		nCur = head->next; // next current value after the head and will keep going to the next value

		for (int i = size() - 1; i >= 0; i--) {
      cur = head;
      nCur = head->next;
			for (int j = 0; j < size() - 1; j++) {
				if (cur->data > nCur->data) { // if current data is greater than the next data
					std::swap(cur->data, nCur->data); // swap data
				}
				cur = nCur;
				nCur = nCur->next; //will keep going to the next value
			}	
		}
  }
  */
};

int main(){
  SortedList <int> obj;
  std::cout << "obj.sortedInsert(20);" << std::endl;
  std::cout << "obj.sortedInsert(1);" << std::endl;
  std::cout << "obj.sortedInsert(3);" << std::endl;
  std::cout << "obj.sortedInsert(5);" << std::endl;
  std::cout << "obj.sortedInsert(4);" << std::endl;
  std::cout << "obj.sortedInsert(2);" << std::endl << std::endl;
  obj.sortedInsert(20);
  obj.sortedInsert(1);
  obj.sortedInsert(3);
  obj.sortedInsert(5);
  obj.sortedInsert(4);
  obj.sortedInsert(2);
  std::cout << "Sorted List with int data type: " << std:: endl;
  obj.print();
  std::cout << "\nList size: " << obj.size() << std::endl <<std::endl;

  std::cout << "obj.remove(1)" << std::endl;
  std::cout << "obj.remove(3)" << std::endl;
  std::cout << "obj.remove(9)" << std::endl;
  obj.remove(1);
  obj.remove(3);
  obj.remove(9);
  std::cout << "(Element 9 is not in the list) \nAfter remove function: " << std:: endl;
  obj.print();
  std::cout << "\nList size: " << obj.size() << std::endl;

  std::cout << "\nContains data value 2?(1 = True; 0 = False) " << obj.contains(2) << std::endl;
  std::cout << "Contains data value 3?(1 = True; 0 = False) " << obj.contains(3) << std::endl;

  // with char type
  SortedList <char> obj2;
  std::cout << std::endl;
  std::cout << "With char type: " << std::endl; 
  std::cout << "obj2.sortedInsert('q');  --> ASCII value 113" << std::endl;
  std::cout << "obj2.sortedInsert('s');  --> ASCII value 115" << std::endl;
  std::cout << "obj2.sortedInsert('r');  --> ASCII value 114" << std::endl;
  std::cout << "obj2.sortedInsert('c');  --> ASCII value 99" << std::endl;
  std::cout << "obj2.sortedInsert('a');  --> ASCII value 97" << std::endl;
  std::cout << "obj2.sortedInsert('y');  --> ASCII value 121" << std::endl << std::endl;
  obj2.sortedInsert('q');
  obj2.sortedInsert('s');
  obj2.sortedInsert('r');
  obj2.sortedInsert('c');
  obj2.sortedInsert('a');
  obj2.sortedInsert('y');
  std::cout << "Sorted List with char datatype: " << std:: endl;
  obj2.print();
  std::cout<< std::endl << "a   c    q    r    s    y"<<std::endl<<"(prints out ascii values of the characters)" <<std::endl;
  std::cout << "\nList size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.remove('r') --> ASCII value 114" << std::endl;
  std::cout << "obj2.remove('a') --> ASCII value 97" << std::endl;
  obj2.remove('r');
  obj2.remove('a');
  std::cout << "After remove function: " << std:: endl;
  obj2.print();
  std::cout<< std::endl << "c    q    s    y"<<std::endl<<"(prints out ascii values of the characters)" <<std::endl;
  std::cout << "\nList size: " << obj2.size() << std::endl << std::endl;

  // testing delete function: removing from empty list and removing item that doesn't exist
  SortedList <int> obj3;
  std::cout <<"Testing remove from empty list: " <<std::endl <<std::endl;
  
  std::cout << "SortedList: " <<std::endl;
  obj3.print();
  std::cout << std::endl <<std::endl;
  std::cout << "obj3.remove(3);" <<std::endl;
  obj3.remove(3);


  std::cout << std::endl << "\n\nTesting remove for element that does not exist: \n\nobj3.sortedInsert(6); \nobj3.sortedInsert(3); \n" <<std::endl;

  obj3.sortedInsert(6);
  obj3.sortedInsert(3);

  std::cout<<"SortedList: "<<std::endl;
  obj3.print();

  std::cout << "\n\nobj3.remove(4);\n";
  obj3.remove(4);

}
