#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--){
        string s;
        getline(cin, s);
        bool possible = false;
        char prev = s.at(0);
        for(int i = 1; i < s.length(); ++i){
            if(prev < s.at(i)){
                possible = true;
                break;
            }
            prev = s.at(i);
        }
        if(!possible) cout << "no answer" << endl;
        else{
            int ind;
            char swap;
            vector<char> c;
            for(int i = s.length() - 1; i > -1; --i){
                for(int j = i - 1; j > -1; --j){
                    if(s.at(i) > s.at(j)){
                        ind = j;
                        swap = s.at(i);
                        for(int k = j; k < s.length(); ++k){
                            if(k != i)c.push_back(s.at(k));
                        }
                        goto stop;
                    }
                }
            }
            stop:
            sort(c.begin(), c.end());
            string output = s.substr(0, ind) + swap;
            for(int i = 0; i < c.size(); ++i){
                output = output + c[i];
            }
            cout << output << endl;
        }
    }
}