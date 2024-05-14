#include <bits/stdc++.h>
using namespace std;

int main() {
    string first;
    string second;
    cin >> first;
    cin >> second;
    string ans = "No";
    int count = 0;
    for(char & c : first) {
        char newchar = toupper(c);
        if(newchar == second[count]) count++;
        if(count == 2 && second[count] == 'X') {
            ans = "Yes";
            break;
        }
        if(count == 3) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}