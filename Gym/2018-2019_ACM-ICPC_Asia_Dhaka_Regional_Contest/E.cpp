#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define pb push_back
using namespace std;


typedef vector<int> vi;

int toInt(vi a){
    return (a[0] * 60 + a[1]) * 60 + a[2];
}
int check(string &s){
    string num;
    int cnt = 0;
    vector<vi> a(2);
    char type = s[0];
    int idx = 0;
    for(char c : s){
        if(c == ':'){
            cnt++;
            if(cnt == 1){
                num = "";
                continue;
            }
            a[idx].pb(stoi(num));
            if(cnt == 4){
                ++idx;
            }
            num = "";
            continue;
        }
        num += c;
    }
    a[1].pb(stoi(num));
    a[0] = max(a[0], vi{8,30,0});
    if(type == 'D'){
        if(a[0] > vi{9,30,0})return 1;
    }else{
        if(a[0] > vi{12,30,0})return 1;
    }
    int time = toInt(a[1]) - toInt(a[0]);
    if(type == 'D'){
        return time < 8 * 3600;
    }else{
        return time < 9 * 3600;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout << fixed << setprecision(2);
    int n;

    while((cin >> n) && n){;
        int val = 0;
        forn(i, n){
            string s;
            cin >> s;
            val += check(s);
        }
        if(val > 3){
            cout<<"Issue Show Cause Letter"<<el;
        }else if(val > 0){
            cout<<val<<" Point(s) Deducted"<<el;
        }else{
            cout<<"All OK"<<el;
        }
    }
}