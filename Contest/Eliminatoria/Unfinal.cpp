#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>

typedef long long ll;
typedef long double ld;


using namespace std;

const int INF = 1 << 30;

const int MAXN = 100;


int n, k, ans;
vector<char> pTeams[MAXN];
unordered_map<char, int> teams;
int dp[MAXN][26];


bool maxSize(vector<char> i1, vector<char> i2)
{
    return (i1.size() < i2.size());
}

int maxi(int i, int equipos){
    if(i >= n){
        return equipos;
    }
    int maximum = 0;
    bool pass = false; 
    for(int j = 0; j < pTeams[i].size(); ++j){
        int curL = pTeams[i][j] - 'A';
        if(dp[i][curL] != -1){
            return dp[i][curL];
        }
        if(teams[pTeams[i][j]] < k){
            pass = true;
            teams[pTeams[i][j]]++;
            dp[i][curL] = maxi(i+1, equipos+1);
            teams[pTeams[i][j]]--;
        }
        maximum = max(maximum, dp[i][curL]);
    }
    if(!pass)maximum = maxi(i+1, equipos);
    return maximum;
}

int main(){
    string s;
    cin >> n;
    int mCarrer[n];
    unordered_map<char, int> m[n];
    getchar();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j){
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i < n; ++i){
        mCarrer[i] = 0;
        getline(cin, s);
        for(int j = 0; j < s.length(); ++j){
            if(s.at(j) != ' ')m[i][s.at(j)]++;
        }
        for(auto const& [key, val] : m[i]){
            mCarrer[i] = max(mCarrer[i], val);
        }
    }
    cin >> k;
    for(int i = 0; i < n; ++i){
        for(auto const& [key, val] : m[i]){
            if(mCarrer[i] == val)pTeams[i].push_back(key);
        }
    }
    sort(pTeams, pTeams + n, maxSize);
    cout << maxi(0, 0) << endl;
    return 0;
}