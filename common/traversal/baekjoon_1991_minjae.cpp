#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node{
    char left;
    char right;
};

struct node tree[28];

void pre(char root){
    if(root == '.') return;
    else{
        cout << root;
        pre(tree[root].left);
        pre(tree[root].right);
    }
}

void in(char root){
    if(root == '.') return;
    else{
        in(tree[root].left);
        cout << root;
        in(tree[root].right);
    }
}

void post(char root){
    if(root == '.') return;
    else{
        post(tree[root].left);
        post(tree[root].right);
        cout << root;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n; cin >> n;
    char P,L,R;
    
    for(int i=0; i<n; i++){
        cin >> P >> L >> R;
        tree[P].left = L;
        tree[P].right = R;
    }
    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    cout << '\n';
}