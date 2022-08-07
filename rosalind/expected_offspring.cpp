//
// Created by Nik Kuchin on 07.03.2021.
//
#include <iostream>
#include <algorithm>

int main() {
    double a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    double ans = 0;
    ans += a;
    ans += b;
    ans += c;
    ans += 0.75 * d;
    ans += 0.5 * e;

    std::cout << ans * 2.;
    return 0;
}