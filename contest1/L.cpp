#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
const int cCpresicion = 20;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::cout << std::fixed;
    std::cout << std::setprecision(cCpresicion);
    std::string s;
    std::string t;
    std::cin >> s >> t;
    int n = s.size();
    int m = t.size();
    std::vector<int> wh(n);
    for (int i = 0; i < n; i++) {
        int pos;
        std::cin >> pos;
        wh[pos - 1] = i + 1;
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == m) {
                break;
            }
            if (wh[i] <= mid) {
                continue;
            }
            if (s[i] == t[j]) {
                j++;
            }
        }
        if (j == m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << l << '\n';
}