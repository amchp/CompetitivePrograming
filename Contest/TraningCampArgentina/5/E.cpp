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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'

typedef long long ll;


int main(){
    string s;
    cin>>s;
    int n = s.size();
    string ans = "";

    map<char,int> has;
    has['a']=1;
    has['e']=1;
    has['i']=1;
    has['o']=1;
    has['u']=1;
    has['y']=1;
    forn(i,n){
        if(!has[tolower(s[i])]){
            ans.push_back('.');
            ans.push_back(tolower(s[i]));
        }
    }
    cout<<ans<<"\n";
}