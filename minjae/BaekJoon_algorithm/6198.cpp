#include <iostream> 
#include <stack>// using stack
#include <utility>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n;
    cin >> n;
    long long result;
    long long h;

    while(n--){
        cin >> h;
        while(!s.empty() && s.top() <= h)
            s.pop();
        result += s.size();
        s.push(h);
    }
    cout << result;
}