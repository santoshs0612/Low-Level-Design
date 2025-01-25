#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename K, typename V>
class HashMap{

private:
  static const int DEFAULT_CAPACITY = 16;
  static constexpr float LOAD_FACTOR_THRESHOLD = 0.75;
  vector<list<pair<K,V>>> table;
  int capacity;
  int size;
  // hash Function 
  int hashFunction(const K&key) const{
    return hash<K>{}(key) % capacity;
  }
// resize and rehashing
void resize(){
  if(size < capacity *LOAD_FACTOR_THRESHOLD){
    return;
  }
  int newCapacity = capacity * 2;
  vector<list<pair<K,V>>> newTable(newCapacity);
  for(const auto& bucket : table){
    for(const auto& entry : bucket){
      int index = hash<K>{}(entry.first)%newCapacity;
      newTable[index].emplace_back(entry.first, entry.second);
    }
  }
  table = std::move(newTable);
  capacity = newCapacity;
}

public:
  HashMap(int initiaCapacity = DEFAULT_CAPACITY){
    capacity = initiaCapacity;
    size =0;
    table.resize(capacity);
  }
  // insert or Update a key-value Pair 
  void put(const K& key, const V& value){
    int index = hashFunction(key);

    for(auto & it:table[index]){
      if(it.first == key){
        it.second = value; // update existing value
        return;
      }
    }
    // key not found, insert a new key-value pair
    table[index].emplace_back(key, value);
    size++;
    resize();
  }
  // get the value associated with a key
  V get(const K& key) const{
    int index = hashFunction(key);
    for(const auto& it:table[index]){
      if(it.first == key){
        return it.second;
      }
    }
    throw runtime_error("Key Not Found");
  }
  // remove a key-value pair
  void remove(const K& key){
    int index = hashFunction(key);
    for(auto it=table[index].begin();it!=table[index].end();it++){
      if(it->first == key){
        table[index].erase(it);
        size--;
        return;
      }
    }
    throw runtime_error("Key Not Find");
  }

// check if the key exists in the map
  bool containsKey(const K& key) const{
    int index = hashFunction(key);
    for(const auto& it: table[index]){
      if(it.first == key){
        return true;
      }
    }
    return false;
  }
  // get the number of key-value pairs in the map
  int getSize() const{
    return size;
  }
  //print hashMap 
  void print() const{
    for(int i=0;i<capacity;i++){
      cout<<"["<<i<<"]";
      for(const auto& it:table[i]){
        cout<< "->"<<it.first<<":"<<it.second;
      }
      cout<<endl;
    }
  }
  
};




int main() { 
  std::cout << "Hello To Map Design!\n";
  HashMap<int, string> hashMap;
  hashMap.put(1, "one");
  hashMap.put(2, "two");
  hashMap.put(3, "three");
  hashMap.put(4, "four");

  cout<<"Value of four: "<<hashMap.get(4)<<endl;
  if(!hashMap.containsKey(5)){
    cout<<"Key 5 not found"<<endl;
  }
  hashMap.remove(2);
  hashMap.print();


}