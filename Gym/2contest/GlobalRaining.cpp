#include <iostream>
#include <deque>
#include <stack>

using namespace std;

int main(){
    int n, lvl;
    int liters;
    cin >> n;
    char c, p;
    getchar();
    while(n--){
        string s, water;
        getline(cin, s);
        s = s + "\\";
        water = "";
        for(int i = 0; i < s.length() - 1; ++i){
            int count = 0;
            c = s.at(i);
            if(c == '\\'){
                count = 1;
                int j;
                for(j = i + 1; j < s.length(); j++){
                    c = s.at(j);
                    if(c == '\\'){
                        count++;
                    }
                    else if (c == '/' ){
                        count--;
                    }
                    if(count == 0){ 
                        water = water + s.substr(i, j - i + 1);
                        break;
                    }
                }
                if(j < s.length() - 1) i = j;
            }
        }
        stack<char> stck;
        lvl = -1;
        liters = 0;
        for(int i = 0; i < water.length(); ++i){
            c = water.at(i);
            if(c == '\\'){
                stck.push('\\');
                lvl++;
            }
            else if(c == '_' && !stck.empty()){
                stck.push('_');
            }
            else if(c == '/' && !stck.empty()){
                while(stck.top() != '\\'){
                    stck.pop();
                    liters += 1 + lvl;
                }
                stck.pop();
                liters += 1 + 2*lvl;
                lvl--;
            }
        }
        cout << liters << endl;
    }
}