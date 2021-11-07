#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Deque{
    public:
    vector<string> _v;
    int cap{5}; // capacity, initialized to 5
    int size{0};
    int front{-1};
    int back{-1}; 

    Deque(){
      _v.resize(cap);
    } 

    bool push_front(string value){
      // if the array is not full
      if ((back + 1) % cap != front){
        // there are no elements in the array
        if (front == -1){
          // the front and back value both point to the first index zero
          front = 0;
          back = 0;
          // insert the value at index zero
          _v[front] = value;
          size++;
        }
        else{
          // else decrement the front and add the new element at the index of front
          if (front == 0){ // if the front is at index zero
            // front will be equal to the last index
            front = cap - 1;
          }
          else{
            front --; // if front != 0, decrement the front
          }
          _v[front] = value; // adds the value at _v[front]
          size++;
        }
      }
      // else, if the array is full, create a temporary vector with 2 * capacity
      else if (size == cap){
        _resize(2*cap);
      }
      return true;
    }
    
    bool push_back(string value){
      // if array is not full
      if ((back + 1) % cap != front){
        // if there are no elements in the array
        if (back == -1){
          // the front and back value will both point to 
          // the first index zero
          front = 0;
          back = 0;
          // insert the value at index zero
          _v[back] = value;
          size++;
        }
        else{
          // else increment the back and add the new value at index
          if (back == cap - 1){ // if the back is at the capacity of index - 1
            back = 0; // set back equal to zero, the first index
          }
          else{
            back++; // else increase the index and add the value at said index
          }
          _v[back] = value; // adds the value at _v[back]
          size++;
        }
      }
      // else, if the array is full, create a temporary vector with 2 * capacity
      if (size == cap){
        _resize(2*cap);
      }
      return true;
    }

    void _resize(int newSize){
      // set new index to the value of the front
      int index = front;
      vector<string> temp_v(2*cap);
        for (int i = 0; i < size; i++){
          // setting each index of the temporary vector with the index of the original vector starting with the front value which is the new index
          temp_v[i] = _v[index];
          // each time it looks, 1 is added to the index value and mod with the capacity
          index = (index+1)% cap;
        }
        swap(_v, temp_v); // swapping the values of the original vector with the temporary vector, the temporary vector ultimately gets destroyed after the function
        cap = 2 * cap;
        //set the front value to the value of the capacity and the back value to the size of the vector (number of elements)
        front = cap;
        back = size;
    }
    
    bool pop_front(){
      // if the array is not empty
      if (front != -1){
        // if there is only one element in the array
        // make both front and back equal to -1
        if (front == back){
          front = -1;
          back = -1;
        }
        else{
          // else increment the front
          if (front == cap - 1){
            front = 0;
          }
          else{
            front++;
          }
        }
      }
      size--;
      return true;
    }

    bool pop_back(){
      // if the array is not empty
      if (front != -1){
        // if there is only one element in the array
        // make both front and back equal to -1
        if (front == back){
          front = -1;
          back = -1;
        }
        else{
          // else decrement the back
          if (back == 0){
            back = cap - 1;
          }
          else{
            back--;
          }
        }
      }
      size--;
      return true;
    }
    
    string peek_front(){
      // if the array is not empty, return the value at index of front
      if (front != -1){
        return _v[front];
      }
      else{
        return NULL;
      }
    }

    string peek_back(){
      // if the array is not empty, return the value at index of back
      if (front != -1){
        return _v[back];
      }
      else{
        return NULL;
      }
    }

    int getLength(){
      return size;
    }

    bool isEmpty(){
      if (front == -1){
        return true;
      }
      else{
        return false;
      }
    }

    void print_deque(){
      for(int i = 0; i < _v.size(); i++){
        int index = (front + i) % cap;
        cout << _v[index] << ' ';
      }
    }
};

int main(){
  Deque obj;

  // empty
  cout << "Empty case: \n";
  cout << "Deque: " << endl; 
  obj.print_deque();
  cout << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // pushing front first value
  cout << "push_front(\"1\"):" << endl;
  obj.push_front("1");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // pushing front second value
  cout << "push_front(\"2\"):" << endl;
  obj.push_front("2");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // pushing back third value
  cout << "push_back(\"4\"):" << endl;
  obj.push_back("4");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // pushing back fourth value
  cout << "push_back(\"3\"):" << endl;
  obj.push_back("3");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // pushing front fifth value
  cout << "push_front(\"5\"):" << endl;
  obj.push_front("5");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // popping front value
  cout << "pop_front():" << endl;
  obj.pop_front();
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // popping back value
  cout << "pop_back():" << endl;
  obj.pop_back();
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;

  // Resizing
  obj.push_front("6");
  obj.push_back("7");
  cout << "Pushing value so that it resizes: " << endl;
  obj.push_front("8");
  obj.push_back("9");
  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;
  cout << "peek_front(): " << obj.peek_front() << endl;
  cout << "peek_back(): " << obj.peek_back() << endl;
  cout << "Length: " << obj.getLength()<< endl;
  cout << "Is Empty(0 = False | 1 = True): " << obj.isEmpty() << endl;
  cout << endl << endl;
}
