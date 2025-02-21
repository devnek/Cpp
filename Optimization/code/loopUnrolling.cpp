#include <iostream>
#include <vector>


void vector_multiply_add(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, std::vector<int>& result) {
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] * b[i] + c[i];
    }
}

void vector_multiply_add_unrolled(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, std::vector<int>& result) {
    size_t i = 0;
    size_t n = a.size();

    // Unroll the loop by a factor of 8
    for (; i <= n - 8; i += 8) {
        result[i] = a[i] * b[i] + c[i];
        result[i + 1] = a[i + 1] * b[i + 1] + c[i + 1];
        result[i + 2] = a[i + 2] * b[i + 2] + c[i + 2];
        result[i + 3] = a[i + 3] * b[i + 3] + c[i + 3];
        result[i + 4] = a[i + 4] * b[i + 4] + c[i + 4];
        result[i + 5] = a[i + 5] * b[i + 5] + c[i + 5];
        result[i + 6] = a[i + 6] * b[i + 6] + c[i + 6];
        result[i + 7] = a[i + 7] * b[i + 7] + c[i + 7];
    }

    // Handle remaining elements
    for (; i < n; ++i) {
        result[i] = a[i] * b[i] + c[i];
    }
}

