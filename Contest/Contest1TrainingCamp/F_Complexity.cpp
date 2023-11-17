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
#include <queue>
#include <array>
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<int> v(26,0);
    cin >> s;
    int complexity = 0;
    for(int i = 0; i < s.length(); ++i){
        if(v[s.at(i)-'a'] == 0)complexity++;
        v[s.at(i)-'a']++;
    }
    sort(v.begin(), v.end());
    int i = 0;
    int ans = 0;
    while(v[i] == 0 && i < 26){
        i++;
    }
    while(complexity > 2){
        ans += v[i];
        complexity--;
        i++;
    }
    cout << ans << el;
}