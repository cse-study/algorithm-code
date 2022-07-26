#include <iostream>
#include <string>
using namespace std;
// using array build deck

int main(){
    int arr[20002]={0};
    int n,head(10001),tail(10001),val;
    string a;
    cin >> n;

    while(n--){ // detail 하게 확인해고 test해봐야함
        cin >> a;
        if(a =="push_front"){
            cin >> val;
            if(head == tail){
                arr[head] = val;
                head--;
                tail++;
            }
            else{
                arr[head] = val;
                head--;
            }
        }
        else if (a=="push_back"){
            cin >> val;
            if(head == tail){
                arr[tail] = val;
                head--;
                tail++;
            }
            else{
                arr[tail] = val;
                tail++;
            }
        }
        else if (a=="pop_front"){
            if(tail-head <= 1)
                cout << "-1\n";
            else{
                int k = arr[head+1];
                cout << k << '\n';
                head++;
            }
        }
        else if (a=="pop_back"){
            if(tail-head <= 1)
                cout << "-1\n";
            else{
                int k = arr[tail-1];
                cout << k << '\n';
                tail--;
            }
        }
        else if (a=="size"){
            if(tail == head) // initial size is 0
                cout << "0\n";
            else
                cout << tail - head - 1 << '\n';
        }
        else if (a=="empty"){
            if (tail - head <= 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (a=="front"){
            if (tail - head <= 1)
                cout <<"-1\n";
            else
                cout << arr[head+1] << '\n';
        }
        else{ // a == "back"{
            if (tail - head <= 1)
                cout <<"-1\n";
            else
                cout << arr[tail-1] << '\n';
        }

    }
}