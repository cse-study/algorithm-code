#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector <string> croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string a;
    cin >> a;
    int count =0;

    for (int i =0; i<croatia.size(); ++i){
        while(1){
            count = a.find(croatia[i]);
            if( count == string::npos)
                break;
            a.replace(count,croatia[i].length(), "#");
        }
    }


    cout << a.length() << endl;
    return 0;
}
