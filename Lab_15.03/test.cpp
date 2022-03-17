#include <iostream>
#include <cmath>

using namespace std;
float sum_rec(float const psi[], float const pdf[], unsigned size) {
    float sum = 0.f;
    int size_1 = 0;
    if (size == 1) {
        sum = psi[0] * pdf[0];
        return sum;
    }
    if (size % 2 == 0) {
        size_1 = size / 2;
    }
    else {
        size_1 = size / 2 + 1;
    }
    float psi_1[100] = { 0 };
    float pdf_1[100] = { 0 };
    for (int idx = 0; idx < size_1; idx++) {
        psi_1[idx] = psi[idx + size / 2];
        pdf_1[idx] = psi[idx + size / 2];
    }
    return sum_rec(psi, pdf, size / 2) + sum_rec(psi_1, pdf_1, size_1);
}


float mean_rec(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    return sum_rec(psi, pdf, size) * dv;
}

float sum_neigh(float const psi[], float const pdf[], unsigned size) {
    float psipdf[100] = { 0 };
    for (int idx = 0; idx < size; idx++) {
        psipdf[idx] = psi[idx] * pdf[idx];
    }
    for (int idx = 0; idx < size; idx++) {
        cout << psipdf[idx] << " ";
    }
    cout << '\n';
    for (int step = 1; step < size; step = step * 2) {
        for (int idx = 0; idx < size; idx = idx + step) {
            if (idx + step > size) {
                continue;
            }
            psipdf[idx] = psipdf[idx] + psipdf[idx + step];
        }
    }
    return psipdf[0];
}

float mean_of_neigh(float const psi[], float const pdf[], float const dv, unsigned size) {
    return sum_neigh(psi, pdf, size) * dv;
}

float sum_kahan(float const psi[], float const pdf[], unsigned size) {
    float psipdf[100] = { 0 };
    float sum = 0.f;
    float t = 0.f;
    for (int idx = 0; idx < size; idx++) {
        psipdf[idx] = psi[idx] * pdf[idx];
    }
    for (int idx = 0; idx < size; idx++) {
        float y = psipdf[idx] - t;
        float z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    return sum;
}

float kahan_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    return sum_kahan(psi, pdf, size) * dv;
}

void func_defenition(float psi[], float pdf[], float T, float f_pi) {
    const int size = 100;
    for (int i = 0; i < size; i++) {
        psi[i] = abs(i/10.0 - size/20.0);
        pdf[i] = 1 / (sqrt(f_pi * T)) * exp(-(i/10.0 - size / 20.0) * (i/10.0 - size / 20.0) / T);
    }
}

int main(){
    float const f_pi = 3.14159265359f;
    float psi[100] = { 0 };
    float pdf[100] = { 0 };
    func_defenition(psi, pdf, 2, f_pi);
    cout<< mean_of_neigh(psi, pdf, 0.1, 100);
}
