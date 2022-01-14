#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;

int n, q;

vector<string> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += to_string(x);
    }
    s += s;
    
    for (int i = 0; i < n; i++) {
        string x;
        for (int j = 0; j < n; j++) {
            x += s[i + j];
        }
        p.push_back(x);
    }
    
    for (int i = 0; i < n * 2; i++) {
        int x = s[i] - '0' - 1;
        s[i] = (x + 2) % 4 + '0' + 1;
    }
    reverse(all(s));
    
    for (int i = 0; i < n; i++) {
        string x;
        for (int j = 0; j < n; j++) {
            x += s[i + j];
        }
        p.push_back(x);
    }

    cin >> q;
    vector<string> ans;
    while (q--) {
        string ss;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ss += to_string(x);
        }
        if (find(all(p), ss) != p.end()) ans.push_back(ss);
    }
    cout << ans.size() << '\n';
    for (string i: ans) {
        for (char c: i) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}