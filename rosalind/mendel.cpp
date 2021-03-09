//
// Created by Nik Kuchin on 07.03.2021.
//
#include <iostream>
#include <algorithm>

double CalcProbability(double k, double m, double n) {
    double prob_homo_dom = k / (k + m + n);
    double prob_hetero = m / (k + m + n);
    double prob_homo_rec = n / (k + m + n);

    double sec_prob_homo_dom = k / (k + m + n - 1);
    double sec_prob_hetero = m / (k + m + n - 1);
    double sec_prob_homo_rec = n / (k + m + n - 1);
    return prob_homo_dom
    + prob_hetero * sec_prob_homo_dom + 0.75 * prob_hetero * ((m - 1) / (k + m + n - 1)) + 0.5 * prob_hetero * sec_prob_homo_rec
    + prob_homo_rec * sec_prob_homo_dom + 0.5 * prob_homo_rec * sec_prob_hetero;
}

int main() {
    double k, m, n;
    std::cin >> k >> m >> n;
    std::cout << CalcProbability(k, m, n);
    return 0;
}
