#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef double ld;

unordered_map<string, bool> dp;
int a, b;
int ans = 0;
vvi brd = vvi(4, vi(4, 0));
vi top(4, 0);
int dx[] = {-1, 0, 1, -1};
int dy[] = {-1, -1, -1, 0};

bool in(int i, int j){
    return i >= 0 && i < 4 && j >= 0 && j < 4;
}

int check_dir(int i, int j, int di, int dj){
    int ci = i + di;
    int cj = j + dj;
    int cans = 0;
    while(in(ci, cj)){
        if(brd[i][j] != brd[ci][cj])break;
        ++cans;
        ci += di;
        cj += dj;
    }
    return cans;
}

bool check(int i, int j){
    forn(k, 4){
        int di = dy[k];
        int dj = dx[k];
        if(check_dir(i, j, di, dj) + check_dir(i, j, -di, -dj) >= 2){
            return true;
        }
    }
    return false;
}

string brd_to_string(){
    string s = "";
    forn(i, 4){
        forn(j, 4){
            s += (brd[i][j] + '0');
        }
    }
    return s;
}

void sol(int turn){
    string s = brd_to_string();
    if(dp.count(s)){
        return;
    }
    dp[s] = true;
    forn(j, 4){
        if(top[j] == 4)continue;
        int i = top[j];
        ++top[j];
        brd[i][j] = turn;
        if(i == a && j == b){
            ans += turn == 2 && check(i, j);
        }
        else if(!check(i, j))sol(turn == 1 ? 2 : 1);
        brd[i][j] = 0;
        --top[j];
        assert(top[j] == i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int x;
    cin>>x;
    --x;
    cin >> a >> b;
    --a, --b;
    brd[0][x] = 1;
    ++top[x];
    sol(2);
    cout << ans << el;
}