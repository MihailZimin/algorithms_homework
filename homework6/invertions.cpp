#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(vector<ll>& arr){
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';
}

void merge(vector<ll>& arr, int l, int mid, int r, ll& cnt){
    int it1 = 0, it2 = 0;
    vector<ll> merge_arr;
    while (l + it1 < mid && mid + it2 < r){
        if (arr[l + it1] <= arr[mid + it2]){
            merge_arr.push_back(arr[l + it1]);
            ++it1;
        }
        else{
            merge_arr.push_back(arr[mid + it2]);
            cnt += mid - l - it1;
            ++it2;
        }
    }
    while (l + it1 < mid){
        merge_arr.push_back(arr[l + it1]);
        ++it1;
    }
    while (mid + it2 < r){
        merge_arr.push_back(arr[mid + it2]);
        ++it2;
    }
    for (int i = l; i < r; ++i){
        arr[i] = merge_arr[i - l];
    }
}

void merge_sort(vector<ll>& arr, int l, int r, ll& cnt){
    if (r - l <= 1)
        return;
    int mid = (r + l) / 2;
    merge_sort(arr, l, mid, cnt);
    merge_sort(arr, mid, r, cnt);
    merge(arr, l, mid, r, cnt);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll cnt = 0;
    merge_sort(arr, 0, n, cnt);
    cout << cnt << '\n';
}
