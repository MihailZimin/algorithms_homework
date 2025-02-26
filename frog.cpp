#include <bits/stdc++.h>

int main(){
    int n, k; std::cin >> n >> k;
    std::string str;
    std::cin >> str;
    int l = 0;
    int r = n+1;
    while (r - l > 1){
        int mid = (r + l) / 2;
        int jump = 0;
        int coord = -1;
        bool possible = true;
        int cnt = 0;
        for (int i = 0; i < n; ++i){
            jump++;
            if (jump > mid){
                if (i - coord >= jump){
                    possible = false;
                    break;
                }
                else{
                    jump = i - coord;
                    ++cnt;
                }
            }
            if (str[i] == '1'){
                coord = i;
            }
        }
        if (jump != 0) cnt++;
        if (possible == true && cnt <= k) r = mid;
        else l = mid;
    }
    std::cout << r << '\n';


    return 0;
}
