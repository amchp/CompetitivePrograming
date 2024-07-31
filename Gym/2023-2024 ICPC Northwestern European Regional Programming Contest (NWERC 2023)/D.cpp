#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
int dx[] = {1,1, -1, -1};
int dy[] = {1,-1, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<vi> brd(7, vi(24, 0));
    forn(i, 7){
        string s;
        cin >> s;
        forn(j, 24)if(s[j] == '.')brd[i][j] = 1;
    }
    int d, h;
    cin >> d >> h;
    int e = 1<<7;
    double ans = 0;
    forn(num, e){
        int ch = 0;
        forn(i, 7){
            if(num & (1 << i))++ch;
        }
        if(ch != d)continue;
        vi cnts(24);
        forn(j, 24){
            forn(i, 7){
                if(num & (1 << i))cnts[j] += brd[i][j];
            }
        }
        sort(all(cnts), greater<int>());
        int sm = 0;
        forn(i, h)sm += cnts[i];
        ans = max(ans, double(sm) / double(d*h));
    }
    cout << ans << el;
}