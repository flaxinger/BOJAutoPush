#include <bits/stdc++.h>

using namespace std;
int len, n, min_start;
map<int, int> road;
vector<pair<int, pair<int, int>>> shortcut;


bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first < b.first;
}

// Shortcut first = start
// Shortcut second first = end
// Shortcut second second = cost;
// current cost = i - e + i - start;
// recursion = find_road(i - start);
void find_road(int idx){

    road[idx] = idx;
    if(idx <= min_start){
        return;
    }

    int s, e, c, minimum;
    //cout << "calculating " << idx << endl;
    for(int j = n-1; j >= 0; j--){
        s = shortcut[j].first;
        e = shortcut[j].second.first;
        c = shortcut[j].second.second;

        if(e <= idx && c < (e - s) && e > s && s >= 0){
            find_road(s);
            minimum = (idx - e) + c + road[s];
            //cout << "ROAD[" << idx << "]\t" << s << " " << e << " " << c << " minimum is " << minimum << endl;
            if(minimum < road[idx]) road[idx] = minimum;
        }
    }
}


void solve(){
    cin >> n >> len;
    int a, b, c, result;
    min_start = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        shortcut.push_back({a, {b, c}});
        if(a < min_start) min_start = a;
    }
    //fill(road, road+10001, INT_MAX);
    sort(shortcut.begin(), shortcut.end(), compare);

    find_road(len);
    cout << road[len];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}