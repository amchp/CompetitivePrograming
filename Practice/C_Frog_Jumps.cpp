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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    getchar();
    while(t--){
        string s;
        getline(cin, s);
        int n = s.length();
        s = s + 'R';
        int pos;
        int l = 0;
        int r = n+1;
        int m;
        while(l+1 < r){
            pos = 0;
            m = (l + r) / 2;
            for(int j = 0; j < s.length(); ++j){
                if(s.at(j) == 'L' && pos != 0)pos--;
                else if(s.at(j) == 'R'){
                    pos = min(pos + m, n + 1);
                    if(pos == n + 1)break;
                }
            }
            if(pos == n + 1)r = m;
            else l = m;
        }
        cout << r << el;
    }
}