#include <iostream>
#include <vector>

const int cN = 100'000;

int l[cN];
int r[cN];

bool Bigger(int i, int j) { return l[i] < l[j]; }

std::vector<int> Merge(std::vector<int>& left, std::vector<int>& right) {
    int n = left.size();
    int m = right.size();
    std::vector<int> result(n + m);

    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (Bigger(left[i], right[j])) {
            result[i + j] = left[i];
            i++;
        } else {
            result[i + j] = right[j];
            j++;
        }
    }
    while (i < n) {
        result[i + j] = left[i];
        i++;
    }
    while (j < m) {
        result[i + j] = right[j];
        j++;
    }
    return result;
}

void Mergesort(std::vector<int>& p, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int m = (l + r) / 2;
    Mergesort(p, l, m);
    Mergesort(p, m, r);
    std::vector<int> left;
    std::vector<int> right;
    for (int i = l; i < m; i++) {
        left.push_back(p[i]);
    }
    for (int i = m; i < r; i++) {
        right.push_back(p[i]);
    }
    std::vector<int> result = Merge(left, right);
    int wh = 0;
    for (int i = l; i < r; i++) {
        p[i] = result[wh];
        wh++;
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    Mergesort(p, 0, n);

    std::vector<int> l_answer;
    std::vector<int> r_answer;
    int cur_left = l[p[0]];
    int max_right = r[p[0]];
    for (int j = 0; j < n; j++) {
        int i = p[j];
        if (max_right < l[i]) {
            l_answer.push_back(cur_left);
            r_answer.push_back(max_right);
            cur_left = l[i];
            max_right = r[i];
        }
        max_right = std::max(max_right, r[i]);
    }
    l_answer.push_back(cur_left);
    r_answer.push_back(max_right);
    std::cout << l_answer.size() << '\n';
    for (int i = 0; i < (int)(l_answer.size()); i++) {
        std::cout << l_answer[i] << " " << r_answer[i] << '\n';
    }
}