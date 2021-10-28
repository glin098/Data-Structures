#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Deque{
    public:
    vector<string> _v;
    int cap{10};
    int size{0};
    int front{cap - 1};
    int back{0};

    Deque(){
      _v.resize(cap);
    }

    bool push_front(string value){
      if (size != cap){
        _v[front] = value;
        front = (front - 1 + cap) % cap;
        size++;
        return true;
      }
      else{
      return false;
      }
    }
    
    bool push_back(string value){
      if (size != cap){
        _v[back] = value;
        back = (back + 1) % cap;
        size++;
        return true;
      }
      else{
      return false;
      }
    }
    
    bool pop_front(){
      if(size != 0){
        front = (front + 1) % cap;
        size--;
        return true;
      }
      else{
        return false;
      }
    }

    bool pop_back(){
      if(size != 0){
        back = (back - 1 + cap) % cap;
        size--;
        return true;
      }
      else{
        return false;
      }
    }
    
    string peek_front(){
      return _v[(front + 1) % cap];
    }

    string peek_back(){
      return _v[(back - 1 + cap) % cap];
    }

    int getLength(){
      return size;
    }

    bool isEmpty(){
      return size == 0;
    }

    void print_deque(){
      for(int i = 0; i < _v.size(); i++){
        cout << _v.at(i) << ' ';
      }
    }
};

int main(){
  Deque obj;
  obj.push_back("1");
  obj.push_back("2");
  obj.push_front("3");
  obj.push_front("4");
  obj.pop_front(); // size is -1, but the value of 4 is still visibly there
  obj.push_front("5"); // overrides the 4 and places 5
  obj.pop_back(); // size is -1, value of 2 is still there
  obj.push_back("6"); // value of 6 overrides 2

  cout << "peep_front function (return the last value of front index): " << obj.peek_front() << endl;

  cout << "peep_back function (return the last value of back index): " << obj.peek_back() << endl;
  cout << endl;

  cout << "Deque: " << endl;
  obj.print_deque();
  cout << endl;

  cout << "\nLength: " << obj.getLength() << endl;
  cout << "Is Empty(0 = False, 1 = True): " << obj.isEmpty() << endl;
}
