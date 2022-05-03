#include <iostream>
#include <string>
#include <list> // 텍스트 에디터는 리스트가 제일 효율적이다.
using namespace std;


int main(){
    string s;
    int n;
    cin >> s;
    cin >> n;

    list<char> L;

    for(auto c : s){
        L.push_back(c);
    }

    auto cursor = L.end(); // cursor initialize
    
    while (n--) {
    char command;
    cin >> command;
    if (command == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
    else if (command == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (command == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B'
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L)
    cout << c;
}