#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>


using namespace std;


#define ford(i,n) for(int i = n-1; i>= 0 ; i--)
#define forn(i,n) for(int i = 0; i<n ; i++)
#define el '\n'
typedef vector<int> vi;

void solve(){
    string s,t;
    cin>>s>>t;
    int n = s.size(),m = t.size();
    vector<vi> nxt (n+1,vi(26,-1));
    ford(i,n-1){
        forn(j,26){
            if(s[i] -'a' == j){
                nxt[i][j] = i;
            }else nxt[i][j] = nxt[i+1][j];
        }
    }
    int idx = 0;
    int cnt = 1;
    bool sepuede =0;
    forn(i,m){
        if(nxt[idx][t[i]-'a'] != -1){
            idx = nxt[idx][t[i]-'a'] + 1;
        }else{
            idx = 0;
            cnt++;
            if(nxt[idx][t[i]-'a'] == -1) {
                sepuede = 0;
                break;
            }
            idx = nxt[idx][t[i]-'a'] + 1;
        }
        if(idx >= n){
            idx = 0;
            cnt++;
        }
    }
    if(sepuede){
        cout<<cnt<<el;
    }else cout<<cnt<<el;
}

int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}