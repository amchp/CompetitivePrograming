#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int n, m;

ii sol(int cb, vvi& cur, ii bt){
    if(cb < 0)return bt;
    int q = ((m & (3 << cb)) >> cb) + 1;
    int ind = -1;
    int jnd = -1;
    // db(q);
    forn(i, 2){
        forn(j, 2){
            if(cur[i][j] == q){
                ind = 2 - i;
                jnd = j + 1;
                break;
            }
        }
    }
    // db(cb);
    assert(ind != -1);
    // db(ind);
    // db(jnd);
    if(ind == 2)bt.se += (1 << (cb / 2));
    if(jnd == 2)bt.fi += (1 << (cb / 2));
    if(q == 1)swap(cur[0][0], cur[1][1]);
    if(q == 4)swap(cur[0][1], cur[1][0]);
    return sol(cb - 2, cur, bt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    vvi cur = {{2, 3}, {1, 4}};
    int cb = 31 - __builtin_clz(n*n) - 2;
    --m;
    ii pr = sol(cb, cur, {1, 1});
    cout << pr.fi << ' ' << pr.se << el;
}