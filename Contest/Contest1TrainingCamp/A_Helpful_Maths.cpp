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
    string s, nS, ans;
    getline(cin, s);
    vector<int> v(3, 0);
    for(int i = 0; i < s.length(); ++i){
        v[s.at(i) - '1']++;
    }
    char l;
    for(int i = 0; i < v.size(); ++i){
        l = '1'+i;
        for(int j = 0; j < v[i]; ++j){nS += l;nS += '+';}
    }
    nS = nS.substr(0, nS.length()-1);
    cout << nS << el;
}