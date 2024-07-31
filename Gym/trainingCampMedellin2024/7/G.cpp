#include<bits/stdc++.h>

#define sz(a) a.size()
#define forn(i,n) for(int i = 0; i <n;++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;


vector<pair<char, char>> dif(5);
map<int, int> pos;

bool check(){
    forn(i, 5){
        if(!(pos[dif[i].fi] < pos[dif[i].se]))return false;
    }
    return true;
}

bool sol(){
    forn(i, 5){
        string s; 
        cin >> s;
        if(s[1] == '>'){
            dif[i] = {s[2], s[0]};
        }else{
            dif[i] = {s[0], s[2]};
        }
    }
    vector<char> vc = {'A', 'B', 'C', 'D', 'E'};
    do{
        forn(i, 5){
            pos[vc[i]] = i;
        }
        if(check()){
            forn(i, 5)cout << vc[i];
            cout << el;
            return true;
        }
    }while(next_permutation(all(vc)));
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    if(!sol())cout << "impossible" << el;
}