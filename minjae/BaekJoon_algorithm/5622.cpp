#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int count =0;

    for (int i=0; i<a.length(); i++){
        if ((a[i] == 'A') || (a[i] == 'B') || (a[i] == 'C')){
            count += 3;
        }
        if ((a[i] == 'D') || (a[i] == 'E') || (a[i] == 'F')){
            count += 4;
        }
        if ((a[i] == 'G') || (a[i] == 'H') || (a[i] == 'I')){
            count += 5;
        }
        if ((a[i] == 'J') || (a[i] == 'K') || (a[i] == 'L')){
            count += 6;
        }
        if ((a[i] == 'M') || (a[i] == 'N') || (a[i] == 'O')){
            count += 7;
        }
        if ((a[i] == 'P') || (a[i] == 'Q') || (a[i] == 'R') || (a[i] == 'S')){
            count += 8;
        }
        if ((a[i] == 'T') || (a[i] == 'U') || (a[i] == 'V')){
            count += 9;
        }
        if ((a[i] == 'W') || (a[i] == 'X') || (a[i] == 'Y') || (a[i] == 'Z')){
            count += 10;
        }

    }

    cout << count << endl;
    return 0;
}
