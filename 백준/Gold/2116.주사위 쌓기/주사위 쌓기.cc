#include <bits/stdc++.h>
using namespace std;

int N, arr[6];

class dice{
public:
    pair<int, int> nums[3];
    int head;
    int bot;
    int head_idx;
    dice(int* a){
        for(int i = 0; i < 3; i++){
            this->nums[i].first = a[i*2];
            this->nums[i].second = a[i*2+1];
        }
    }
    
    void set_head(int below){
        for(int i = 0; i < 3; i++){
            if(this->nums[i].first == below){ 
                this->bot = nums[i].first;
                this->head = nums[i].second;
                head_idx= i;
                return;
            }
            if(this->nums[i].second == below){
                this->head= nums[i].first;
                this->bot = nums[i].second;
                head_idx = i;
                return;
            }
        }
    }
    int best(){
        int b=0;
        for(int i = 0; i < 3; i++){
            if(i!=head_idx){
                if(nums[i].first > b) b = nums[i].first;
                if(nums[i].second > b) b = nums[i].second;
            }
        }
        return b;
    }
    int get_head(){
        return head;
    }
};

void swapf(int a, int b){
    int s = arr[a];
    arr[a] = arr[b];
    arr[b] = s;
}

void solve(){
    cin >> N;
    vector<dice> box;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 6; j++)
            cin >> arr[j];
        swapf(1, 5);
        swapf(4, 3);
        //cout << "translated to ... ";
        for(int j = 0; j < 6; j++){
            //if(j%2 == 0) cout << " [";
            //cout << arr[j] << ' ';
            //if(j%2 == 1) cout << "], ";

        }
        //cout << endl;
        box.push_back(dice(arr));
    }
    int ans = 0, tans;
    for(int i = 1; i <= 6; i++){
        box[0].set_head(i);
        tans = box[0].best();
        // cout << "start" << endl;
        // cout << "accumulate = " << tans << ", bottom = " << i << ", top = " << box[0].get_head() << endl;
        for(int j = 1; j < box.size(); j++){
            box[j].set_head(box[j-1].get_head());
            tans +=box[j].best();
            // cout << "accumulate = " << tans << "(added " << box[j].best() << ", bottom = " << box[j-1].get_head() << ", top = " << box[j].get_head() << endl;
        }
        if(tans > ans) ans = tans;
        // cout << "----> ans = " << ans << ", tans = " << tans << endl;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //test();
    solve();
    return 0;
}
