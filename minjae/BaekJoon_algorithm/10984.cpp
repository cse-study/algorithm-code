#include <iostream>
#include <iomanip>
using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        double sub, total_sub=0;
        double score, av_score=0;
        for(size_t i=0; i<n; i++){
            cin >> sub >> score;
            total_sub += sub;
            av_score += score*sub;
        }
        cout << total_sub << " ";\
        cout << setprecision(2) << av_score/total_sub << '\n';

    }
}