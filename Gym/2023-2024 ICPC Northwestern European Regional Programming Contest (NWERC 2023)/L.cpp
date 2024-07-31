#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
int dx[] = {0,-1, 1, 0};
int dy[] = {-1,0, 0, 1};


int n, k;
int nmship;

bool inside(int x, int y){
    return (x >= 1 && x <= n) && (y >= 1 && y <= n);
}

bool query(int x, int y){
    cout << x << ' ' << y << endl;
    string s;
    cin >> s;
    if(s == "miss")return false;
    if(s == "sunk")nmship += 1;
    return true;
}

void search_ship(int x, int y){
    int iships = nmship;
    forn(i, 4){
        int cx = x + dx[i], cy = y + dy[i];
        forn(_, 4){
            if(inside(cx, cy))query(cx, cy);
            if(nmship == k)return;
            cx += dx[i];
            cy += dy[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    nmship = 0;
    vector<ii> pos;
    int total = 0;
    for(int x = 4; x <= n+n; x += 5){
        for1(y, n){
            if(inside(x - (y - 1), y)){
                if(query(x - (y - 1), y)){
                    pos.pb({x - (y - 1), y});
                }
            }
        }
    }
    assert(sz(pos) == k);
    for(auto& [x, y] : pos){
        search_ship(x, y);
        if(nmship == k)break;
    }
    assert(nmship == k);
}