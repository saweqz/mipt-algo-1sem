#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
const int cCpresicion = 20;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout << std::fixed;
    std::cout << std::setprecision(cCpresicion);
    int n;
    std::cin >> n;
    std::vector<long double> pref(n + 1);
    for (int i = 0; i < n; i++) {
        long double x;
        std::cin >> x;
        pref[i + 1] = pref[i] + std::log(x);
    }
    int q;
    std::cin >> q;
    while (q-- > 0) {
        int l;
        int r;
        std::cin >> l >> r;
        long double su = pref[r + 1] - pref[l];
        int len = r - l + 1;
        std::cout << std::exp(su / len) << '\n';
    }
}