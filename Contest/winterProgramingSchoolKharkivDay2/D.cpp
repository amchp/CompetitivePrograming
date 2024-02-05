#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, m;
    cin >> n >> s >> m;
    vi a(4);
    forn(i, m){
        int v;
        cin >> v;
        ++a[v];
    }
    int ans = 0;
    int f = 0;
    while(a[3]){
        --a[3];
        f += 3;
        int dif = s - f;
        if(dif <= 0){
            ++ans;
            f = 0;
            continue;
        }
        if(dif < 3){
            if(dif == 1 && a[1] == 0 && a[2] >= 2){
                ++a[3];
                a[2] -= 2;
            }
            else if(dif == 1 && a[1]){
                --a[1];
            }
            else if(a[2]){
                --a[2];
            }else{
                continue;
            }
            ++ans;
            f = 0;
        }
    }
    while(a[2]){
        --a[2];
        f += 2;
        int dif = s - f;
        if(dif <= 0){
            ++ans;
            f = 0;
            continue;
        }
        if(dif < 2 && a[1]){
            --a[1];
            ++ans;
            f = 0;
        }
    }
    while(a[1]){
        --a[1];
        ++f;
        int dif = s - f;
        if(dif <= 0){
            ++ans;
            f = 0;
        }
    }
    cout << min(ans, n) << el;
}