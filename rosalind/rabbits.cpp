#include <iostream>
#include <vector>

int64_t CountRabbits(int n, int64_t k) {
    std::vector<int64_t> f(n + 1);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + k * f[i - 2];
    }
    return f[n];
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << CountRabbits(n, k);
    return 0;
}