#include <bits/stdc++.h>

using namespace std;


priority_queue<int, vector<int>, greater<int>> classrooms;
vector<pair<int, int>> courses;
int n;

bool compare(pair<int, int> a, pair<int, int> b){

    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void place(int f, int s){

    if(!classrooms.empty())
        if(classrooms.top() <= f) classrooms.pop();
    classrooms.push(s);
}


void solve(){
    cin >> n;

    int c_name, c_start, c_end;
    for(int i = 0; i < n; i++){
        cin >> c_name >> c_start >> c_end;
        courses.push_back({c_start, c_end});
    }

    sort(courses.begin(), courses.end(), compare);

    //for(int i = 0; i < n; i++) cout << courses[i].first << " " << courses[i].second << endl;
    

    for(int i = 0; i < n; i++){
        place(courses[i].first, courses[i].second);
    }

    cout << classrooms.size();
}






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}