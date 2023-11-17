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
    while(t--){
        int n, x, y, diff, start, end, m, curM, l, cStart, cEnd;
        cin >> n >> x >> y;
        diff = y - x;
        vector<int> factors;
        for(int i = 1; i <= sqrt(diff); ++i){
            if(diff % i == 0){
                factors.push_back(i);
                factors.push_back(diff/i);
            }
        }
        end = INF;
        for(int i = 0; i < factors.size(); i++){
            curM = factors[i];
            if(x+curM*(n-1) < y)continue;
            cStart = x;
            cEnd = x+curM*(n-1);
            l = (int)min((cStart)/curM, (cEnd-y)/curM);
            cStart -= curM*l;
            cEnd -= curM*l;
            if(cStart == 0){
                cStart += curM;
                cEnd += curM;
            }
            if(cEnd < end){
                end = cEnd;
                start = cStart;
                m = curM;
            }
        }
        for(int i = 0; i < (end - start)/m + 1; i++){
            cout << i*m + start << " ";
        }
        cout << el;
    }
}