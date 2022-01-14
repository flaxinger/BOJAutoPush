#include <bits/stdc++.h>
using namespace std;

std::vector<string> nums;
string temp_nums[1001];




bool leftIsFirst(string a, string b){
    
    if(a.length() != b.length()){
        if(a.length() < b.length()) return true;
        else return false;
    }
    else{
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i = 0; i < a.length(); i++){
            if(a[i]<='9') sum1+= (a[i]-'0');
        }
        for(int i = 0; i < b.length(); i++){
            if(b[i]<='9') sum2+= (b[i]-'0');
        }  
        //cout << sum1 << " " << sum2 << endl;
        if(sum1 < sum2) return true;
        else if(sum2 < sum1) return false;  
        else{
            for(int i = 0; i < a.length(); i++){
                if(a[i] < b[i]) return true;
                if(a[i] > b[i]) return false;
            }
        }
    }
    return true;
}

void merge(int start, int end){
    int mid = (start + end)/2;
    
    int i  = start;
    int j = mid +1;
    int k = start;
    
    while(i <= mid && j <= end){
        if(leftIsFirst(nums[i], nums[j])){
            temp_nums[k++] = nums[i++];
        }
        else 
            temp_nums[k++] = nums[j++];
    }   
    
    int tmp = i>mid ? j : i;
    
    while(k <= end) temp_nums[k++] = nums[tmp++];
    
    for(int i = start;i<=end;i++) nums[i] = temp_nums[i];
}


void sort(int start, int end){
    int mid;
    //cout << start << end << endl;
    if(start<end){
        mid = (start+end)/2;
        sort(start, mid);
        sort(mid+1, end);
        merge(start, end);
    }
}

void solve(){
    
    int c;
    cin >> c;
    string buff;
    
    for(int i = 0; i < c; i++){
        cin >> buff;
        nums.push_back(buff);
    }
    
    sort(0, c-1);
    
    for(int i = 0; i < c; i++){
        cout << nums[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}

