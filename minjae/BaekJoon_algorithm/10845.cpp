#include <iostream> // 큐 구현 배열로했음
#include <string>
using namespace std;

int main(){
    int arr[10001];
    int n,push,head(0),tail(0); // 큐는 선입선출이라 꼬리와 머리 정의한다.
    string a;
    cin >> n;

    while(n--){
        cin >> a;
        if(a == "push"){
            cin >> push;
            arr[tail] = push;
            tail++;
        }
        else if(a =="pop"){
            if(head == tail)
                cout << "-1\n";
            else{
                int pop = arr[head];
                cout << pop << '\n';
                head++;
            } 
        }
        else if(a == "size")
            cout << tail-head << '\n';
        else if (a == "empty")
            if(tail-head == 0)
                cout << "1\n";
            else    
                cout << "0\n";
        else if(a == "front"){
            if(tail-head == 0)
                cout << "-1\n";
            else
                cout << arr[head] << '\n';
        }
        else{ // a == "back"
            if(tail-head == 0)
                cout << "-1\n";
            else
                cout << arr[tail-1] << '\n';
        }
    }
}