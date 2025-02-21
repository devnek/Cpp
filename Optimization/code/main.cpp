#include <iomanip> // For std::setw
#include <chrono>
#include "loopUnrolling.h"


int main() {
    const size_t size = 50 * 1024 * 1024; // Larger dataset
    std::vector<int> a(size, 1), b(size, 2), c(size, 3), result(size);

    auto start = std::chrono::high_resolution_clock::now();
    vector_multiply_add(a, b, c, result);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << std::left << std::setw(30) << "Normal multiply-add:" << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    vector_multiply_add_unrolled(a, b, c, result);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << std::left << std::setw(30) << "Unrolled multiply-add:" << diff.count() << " s\n";

    return 0;
}