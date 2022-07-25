#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num,stu,apple,res=0;
    cin >> num;
    while(num--){
        cin >> stu >> apple;
        res += apple%stu;
    }
    cout << res;
}