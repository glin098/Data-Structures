#include <iostream>
#include <vector>


template <typename T>
class MaxHeap{
  private:
  std::vector<T> vect; // vector to store heap elements
  
  int parent(int i){ // return index of parent at vect[i]
    return (i - 1) / 2;
  }

  int leftChild(int i){ // return the index of left child at vect[i]
    return 2 * i + 1;
  }

  int rightChild(int i){ // return the index of right child at vect[i]
    return 2 * i + 2;
  }

  void heapifyDown(int i){ // this function heapifies down from the node at the index
    int left = leftChild(i); // left index
    int right = rightChild(i); // right idex
    int largest = i; // the largest value is set to the parent initially

    if(left < size() && vect[left] > vect[i]){ // if left child is less than the size and the index of the left child is greater than the parent index
      largest = left; // set the largest to the left child
    }
    else{
      largest = i; // otherwise the largest is the parent
    }
    
    if(right < size() && vect[right] > vect[largest]){ // if the right child is less than the size and the index of the right child is greater than the index of largest
      largest = right; // largest is set to the right child
    }

    if(largest != i){ // if the largest value is not equal to the initial value that was set to the value of the parent
      std::swap(vect[i], vect[largest]); // if this if statement is satisfied, they will swap 
      heapifyDown(largest); // perform this function on largest
    }
  }

  void heapifyUp(int i){ // this function heapifies up from the node at the index
    if(i && vect[parent(i)] < vect[i]){ // if parent value is less than the child value when inserting they will swap 
      std::swap(vect[i], vect[parent(i)]); // swapping
      heapifyUp(parent(i));
    }
  }


  public:
  void insert(T data){
    vect.push_back(data); // inserts element at the back of the vector
    int index = size() - 1; // get the index of the value

    heapifyUp(index); // calls heapify up function so that it is a heap
  }

  // removes the value at index 0
  void pop(){
    if(isEmpty()){ // if the MaxHeap object is empty
    std::cout<< " MaxHeap is empty.";
      return; 
    }

    vect[0] = vect.back(); // takes the value at the very back of the vector and makes it equal to the index at 0
    vect.pop_back(); // delete the back value
    heapifyDown(0); // calls heapify down function
  }

  int peek(){
    if(isEmpty()){ // if the MaxHeap object is empty
      return -1;
    }
    else{
      return vect[0]; // else it will peek the value at index 0
    }
  }

  int size(){ // returns the size/length of the vector 
    return vect.size();
  }

  bool isEmpty(){ // fucntion to check if the maxheap is empty or not
    return size() == 0;
  }

  void print(){ // prints out the MaxHeap items
    std::cout << "MaxHeap items: " << std::endl;
    std::vector<int>::iterator i = vect.begin();
    while(i != vect.end()){
      std::cout << *i << " ";
      i++;
    }
  }
};

int main() {
  MaxHeap <int> obj;

  std::cout << "Pushing values into the MaxHeap: \n" << std::endl;

  // empty case
  std::cout << "Empty case: \n";
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(2);" <<std::endl;
  obj.insert(2);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(4);" <<std::endl;
  obj.insert(4);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(6);" <<std::endl;
  obj.insert(6);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(8);" <<std::endl;
  obj.insert(8);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(3);" <<std::endl;
  obj.insert(3);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(5);" <<std::endl;
  obj.insert(5);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(7);" <<std::endl;
  obj.insert(7);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(9);" <<std::endl;
  obj.insert(9);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << std::endl;

  std::cout << "obj.insert(46);" <<std::endl;
  obj.insert(46);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj.insert(1);" <<std::endl;
  obj.insert(1);
  obj.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Size: " << obj.size();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl<< std::endl;

  
  std::cout << "\nPopping values in MaxHeap: \n\n";
  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;

  std::cout << "obj.pop();" <<std::endl;
  obj.pop();
  obj.print();
  std::cout << std::endl << "Is Empty? " << obj.isEmpty();
  std::cout << std::endl << "Peek: " << obj.peek();
  std::cout << std::endl << "Size: " << obj.size() << std::endl << std::endl;


  MaxHeap <char> obj2;
  std::cout << "TESTING WITH CHAR VALUES: \n\nPushing values into the MaxHeap: \n" <<std::endl;

  // empty case
  std::cout << "Empty case: \n";
  obj2.print();
  std::cout << std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('A');" <<std::endl;
  obj2.insert('A');
  obj2.print();
  std::cout << "\nA " <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('W');" <<std::endl;
  obj2.insert('W');
  obj2.print();
  std::cout << "\nW  A" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('G');" <<std::endl;
  obj2.insert('G');
  obj2.print();
  std::cout << "\nW  A  G" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('C');" <<std::endl;
  obj2.insert('C');
  obj2.print();
  std::cout << "\nW  C  G  A" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('K');" <<std::endl;
  obj2.insert('K');
  obj2.print();
  std::cout << "\nW  K  G  A  C" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('O');" <<std::endl;
  obj2.insert('O');
  obj2.print();
  std::cout << "\nW  K  O  A  C  G" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;

  std::cout << "obj2.insert('Z');" <<std::endl;
  obj2.insert('Z');
  obj2.print();
  std::cout << "\nZ  K  W  A  C  G  O" <<std::endl;

  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Size: " << obj2.size();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl<< std::endl;


  std::cout << "\nPopping values in MaxHeap (char): \n\n";
  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nW  K  O  A  C  G" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nO  K  G  A  C" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nK  C  G  A" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nG  C  A" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nC  A" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "\nA" <<std::endl;
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

  std::cout << "obj2.pop();" <<std::endl;
  obj2.pop();
  obj2.print();
  std::cout << "Is Empty? " << obj2.isEmpty();
  std::cout << std::endl << "Peek: " << obj2.peek();
  std::cout << std::endl << "Size: " << obj2.size() << std::endl << std::endl;

} 
