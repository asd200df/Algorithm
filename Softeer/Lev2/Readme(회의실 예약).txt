회의실 예약 [21년 재직자 대회 예선] 문제 설계

#1 
1. input 
	vector<string> vector<struct> 
2. vector(ing) sort, vector(uct) sort
3. ...










-----

# unordered_map

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> myMap;

    // unordered_map<string, vector<int>> um;

    // 새로운 key-value 쌍 추가
    myMap.insert(make_pair("one", 1));
    myMap.insert(make_pair("two", 2));
    myMap.insert(make_pair("three", 3));

    // key를 사용하여 value 출력
    cout << "The value of key 'two' is " << myMap["two"] << endl;

    // iterator를 사용하여 모든 key-value 쌍 출력
    for (auto i = myMap.begin(); i != myMap.end(); i++) {
        cout << "Key: " << i->first << ", Value: " << i->second << endl;
    }

    return 0;
}





# unordered_multimap

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  std::unordered_multimap<string, int> myMap;

  // 여러 개의 value를 key "apple"에 추가합니다.
  myMap.insert(make_pair("apple", 1));
  myMap.insert(make_pair("apple", 2));
  myMap.insert(make_pair("apple", 3));

  // key "apple"의 모든 value를 출력합니다.
  auto range = myMap.equal_range("apple");
  for (auto it = range.first; it != range.second; ++it) {
    cout << it->first << ": " << it->second << endl;
  }

  return 0;
}





#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, vector<int>> um;
    um["key1"] = {1, 2, 3};
    um["key2"] = {4, 5};
    
    for (auto& p : um) {
        cout << "key: " << p.first << ", values: ";
        for (auto& v : p.second) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}




