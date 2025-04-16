#include "bits/stdc++.h"

using namespace std;
using ll = long long;


struct date{
    int d;
    int is_birth;
    int id;
};

bool my_compare(date& d1, date& d2){
    if (d1.d < d2.d)
        return true;
    else if (d1.d == d2.d && d1.is_birth < d2.is_birth)
        return true;
    return false;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<date> arr;
    for (int i = 0; i < n; ++i){
        int ds, ms, ys, de, me, ye; cin >> ds >> ms >> ys >> de >> me >> ye;
        if (ye - ys > 80){
            ye = ys + 80;
            de = ds;
            me = ms;
        }
        else if (ye - ys == 80){
            if (me > ms){
                me = ms;
                de = ds;
            }
            else if (me == ms){
                if (de > ds)
                    de = ds;
            }
        }
        if (ye - ys < 18)
            continue;
        else if (ye - ys == 18){
            if (me < ms)
                continue;
            else if (me == ms){
                if (de <= ds)
                    continue;
            }
        }
        ys += 18;
        arr.push_back({ds + ms * 100 + ys * 10000, 1, i});
        arr.push_back({de + me * 100 + ye * 10000, 0, i});
    }
    sort(arr.begin(), arr.end(), my_compare);
    int cnt = 0, ans = 0;
    for (date& d : arr){
        if (d.is_birth){
            cnt++;
        }
        else{
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
