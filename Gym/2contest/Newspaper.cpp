#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        unordered_map <char, int> map;
        for(int j = 0; j < l; j++){
            char a;
            int v;
            cin >> a;
            cin >> map[a];
        }
        int lines;
        cin >> lines;
        int count = 0;
        getchar();
        for(int j = 0; j < lines; j++){
            string s;
            getline(cin, s);
            for(int k = 0; k < s.length(); k++){
                count += map[s.at(k)];
            }
        }
        cout << (count / 100) << ".";
        cout << setw(2)  << setfill('0') << (count % 100) << "$" << endl;
    }
}