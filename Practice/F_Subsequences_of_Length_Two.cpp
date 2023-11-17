#include <vector>
#include <map>
#include <unordered_map>
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

int n, k;
string s, t;
map<string, int> dp; 

int maximize(string cS, int position, int changes){
    if(dp[cS] != 0){
        return dp[cS];
    }else if(changes == 0 || position == n){
        int first = 0;
        int total = 0;
        for(int i = 0; i < n; ++i){
            if(cS.at(i) == t.at(0) && t.at(0) == t.at(1)){
                total += first;
                first++;
            }
            else if(cS.at(i) == t.at(0))first++;
            else if(cS.at(i) == t.at(1)) total += first;
        }
        dp[cS] = total;
        return total;
    }else{
        char temp = cS.at(position);
        cS[position] = t.at(0);
        string nS1 = cS;
        cS[position] = t.at(1);
        string nS2 = cS;
        cS[position] = temp;
        dp[cS] = max(maximize(cS, position+1, changes), max(maximize(nS1, position+1, changes-1), maximize(nS2, position+1, changes-1)));
        return dp[cS];
    }
}



int main(){
    cin >> n >> k;
    getchar();
    getline(cin , s);
    getline(cin, t);
    cout << maximize(s, 0, k) << el;

}