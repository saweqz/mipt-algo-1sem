#include <cstdint>
#include <iostream>
#include <vector>

const int cMax = 256;
const int cBait = 8;
int Get(uint64_t x, int it) {
    int su = 0;
    for (int j = it * cBait; j < it * cBait + cBait; j++) {
        int cu_bit = ((x >> j) & 1);
        su += cu_bit * (1 << (j - it * cBait));
    }
    return su;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<uint64_t> a(n);
    for (auto& x : a) {
        std::cin >> x;
    }
    std::vector<uint64_t> temp(n);
    std::vector<std::vector<uint64_t>> by_bi(cMax);
    for (int it = 0; it < cBait; it++) {
        for (int i = 0; i < n; i++) {
            by_bi[Get(a[i], it)].push_back(a[i]);
        }
        int j = 0;
        for (int i = 0; i < cMax; i++) {
            for (auto x : by_bi[i]) {
                temp[j++] = x;
            }
            by_bi[i].clear();
        }
        a = temp;
    }

    for (auto& x : a) {
        std::cout << x << " ";
    }
}