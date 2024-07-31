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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define el '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool past;
    if(s == "TRUTH")past = true;
    else past = false;
    forn(i, n - 1){
        cin >> s;
        bool now;
        if(s == "TRUTH")now = true;
        else now = false;
        if(past)past = now;
        else if(!past)past = !now;
    }
    if(past)cout << "TRUTH" << el;
    else cout << "LIE" << el;
}