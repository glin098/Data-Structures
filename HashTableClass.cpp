#include <iostream>
#include <vector>
#include <list>

// insert, remove, search, print

class HashTable{
  private:
  int buckets;
  std::list<int> *table;

  public:
  HashTable(int a){ //constructor
    buckets = a;
    table = new std::list<int>[buckets];
  }

  int getHash(int a){ // function to get hash value
    return a % buckets;
  }

  void insert(int key){ // index is equal to the hash value, and push back the key
    int index = getHash(key);
    table[index].push_back(key);
    }

  void remove(int key){
    int index = getHash(key); // index is equal to the hash value
    std::list<int> :: iterator i = table[index].begin();
    for(; i != table[index].end(); i++){ // iterates through the end of the table
      if(*i == key){
        break;
      }
    }
    if(i != table[index].end()){
      table[index].erase(i); // removes key value when found it thorugh iteration
    }
  }

  void search(int key){
    int a = 0;
    int index = getHash(key);
    std::list<int>::iterator i =table[index].begin();
    for(;i!=table[index].end(); i++){
      if(*i==key){
        a = 1; // element is present
        break;
      }
    }
    if(a == 1){
      std::cout<<"element is already present";
    }
    else{
      std::cout<<"element is not present";
    }
  }

  void printTable(){
    for(int i = 0; i < buckets; i++){
      std::cout << i;
      for(auto x : table[i]){
        std::cout << " ----> " << x;
      }
      std::cout << std::endl;
    }
  }
};

int main(){
  HashTable obj(8);

  std::cout << "inserting elements" << std::endl;
  std::cout << "obj.insert(13);" << std::endl;
  std::cout << "obj.insert(16);" << std::endl;
  std::cout << "obj.insert(20);" << std::endl;
  std::cout << "obj.insert(8);" << std::endl;
  std::cout << "obj.insert(9);" << std::endl;
  std::cout << "obj.insert(10);" << std::endl;
  std::cout << "obj.insert(12);" << std::endl;
  std::cout << std::endl;

  // inserting values
  obj.insert(13);
  obj.insert(16);
  obj.insert(20);
  obj.insert(8);
  obj.insert(9);
  obj.insert(10);
  obj.insert(12);
  std::cout <<"display table: " << std::endl;
  obj.printTable(); // display
  std::cout << std::endl;

  // searching for elements
  std::cout << "searching for elements" << std::endl;
  std::cout << "obj.search(20);" << std::endl;
  obj.search(20);
  std::cout << std::endl;
  std::cout << "obj.search(2);" << std::endl;
  obj.search(2);
  std::cout << std::endl <<std::endl;

  // removing elements
  std::cout << "removing elements" << std::endl;
  std::cout << "obj.remove(13);" << std::endl;
  std::cout << "obj.remove(20);" << std::endl;
  obj.remove(13);
  obj.remove(20);
  std::cout << std::endl;
  std::cout <<"display table: " << std::endl;
  obj.printTable(); // display


}
