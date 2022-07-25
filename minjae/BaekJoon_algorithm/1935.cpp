#include <iostream>
#include <string>
#include <stack>
using namespace std;

int alpha[26];

int main(){
    cin.tie(0); // cin cout 빠르게 하기위해
    cin.sync_with_stdio(0);
    
    int n; cin >> n;
    string str; cin >> str;

    for(int i=0; i<n; i++){
        cin >> alpha[i];
    }

    stack<double> s;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='+' || str[i]== '-' || str[i] == '*' || str[i] == '/'){
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            switch(str[i]){
                case '+':
                    s.push(b+a); break;
                case '-':
                    s.push(b-a); break;
                case '*':
                    s.push(b*a); break;
                case '/':
                    s.push(b/a); break;
            }
        }
        else        s.push(alpha[str[i]-'A']);
    }

    double result = s.top();
    cout << fixed;
    cout.precision(2);
    cout << result << '\n';

}