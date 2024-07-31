#include<bits/stdc++.h>

#define fore(i,l,r) for(int i = l ; i<= (int)r; ++i)
#define el '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;

typedef vector<int> vi;
typedef long long ll;

deque<char> sol(ll k){
    if(k == 1){
        deque<char> ans;
        ans.push_back('2');
        return ans;
    }
    if(k & 1){
        deque<char> ans = sol(k - 1);
        ans.push_front('*');
        ans.push_front('2');
        ans.push_front('(');
        ans.push_back(')');
        return ans;
    }
    deque<char> ans = sol(k / 2);
    ans.push_front('(');
    ans.push_back(')');
    ans.push_back('^');
    ans.push_back('2');
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        deque<char> ans = sol(n);
        for(char& c : ans){
            cout << c;
        }
        cout << el;
    }
    return 0;
}