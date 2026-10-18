#include <iostream>
#include <random>
#include <vector>

const int cMod = 1'000'4321;

std::mt19937 rnd(time(0));

int Quickselect(std::vector<int>& a, int k, int l, int r) {
    if (l == r) {
        return a[l];
    }
    int pivot = l + (rnd() % (r - l));
    std::vector<int> less;
    std::vector<int> more;
    std::vector<int> equal;
    for (int i = l; i <= r; i++) {
        if (a[i] < a[pivot]) {
            less.push_back(a[i]);
        }
    }
    for (int i = l; i <= r; i++) {
        if (a[i] > a[pivot]) {
            more.push_back(a[i]);
        }
    }
    for (int i = l; i <= r; i++) {
        if (a[i] == a[pivot]) {
            equal.push_back(a[i]);
        }
    }
    int cu = l;
    for (auto& x : less) {
        a[cu++] = x;
    }
    for (auto& x : equal) {
        a[cu++] = x;
    }
    for (auto& x : more) {
        a[cu++] = x;
    }
    int less_size = (int)(less.size());
    int equal_size = (int)(equal.size());
    if (less_size >= k) {
        return Quickselect(a, k, l, l + less_size - 1);
    }
    if (k <= less_size + equal_size) {
        return equal[0];
    }
    int new_l = l + less_size + equal_size;
    return Quickselect(a, k - less_size - equal_size, new_l, r);
}

const int cConst1 = 123;
const int cConst2 = 45;

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::cin >> a[0] >> a[1];
    for (int i = 2; i < n; i++) {
        a[i] = (a[i - 1] * cConst1 + a[i - 2] * cConst2) % (cMod);
    }
    std::cout << Quickselect(a, k, 0, n - 1) << '\n';
}