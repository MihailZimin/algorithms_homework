#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    priority_queue<int> arr;
    for (int i = 0; i < k; ++i) {
        int temp; cin >> temp;
        arr.push(temp);
    }
    for (int i = 0; i < n - k; ++i){
        int temp; cin >> temp;
        int nmax = arr.top();
        if (nmax > temp){
            arr.pop();
            arr.push(temp);
        }
    }
    vector<int> ans(k);
    int cnt = k - 1;
    while (!arr.empty()){
        ans[cnt] = arr.top();
        arr.pop();
        cnt--;
    }
    for (int i = 0; i < k; ++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
