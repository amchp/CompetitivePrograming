#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> st;
    while(n != 1 && !st.count(n)){
        st.insert(n);
        string s = to_string(n);
        int nxt = 0;
        for(char& c : s){
            int num = c - '0';
            nxt += num * num;
        }
        n = nxt;
        // db(n);
        // cout << n << ' ';
    }
    // cout << el;
    if(n == 1)cout << "HAPPY" << el;
    else cout << "UNHAPPY" << el;
}