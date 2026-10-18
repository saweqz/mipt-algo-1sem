#include <cmath>
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (auto& x : a) {
        std::cin >> x;
    }
    for (auto& y : b) {
        std::cin >> y;
    }
    int query;
    std::cin >> query;
    while (query-- > 0) {
        int x;
        std::cin >> x;
        int std::left = 0;
        int std::right = n;
        while (std::right - std::left > 1) {
            int mid = (std::left + std::right) / 2;
            if (std::max(a[mid] + x, b[mid]) == b[mid]) {
                std::left = mid;
            } else {
                std::right = mid;
            }
        }
        int ans = std::max(a[0] + x, b[0]);
        int where = 0;
        for (int i = std::left; i <= std::right; i++) {
            if (i >= 0 && i < n) {
                int temp = std::max(a[i] + x, b[i]);
                if (temp < ans) {
                    ans = temp;
                    where = i;
                }
            }
        }
        std::cout << where + 1 << '\n';
    }
}