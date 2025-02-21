#include <iostream>
#include <chrono>
#include <vector>

// Structure without alignment
struct UnalignedData {
    char a;
    int b;
    double c;
};

// Structure with alignment to 32 bytes
struct alignas(32) AlignedData {
    char a;
    int b;
    double c;
};

// Function to perform some operations on UnalignedData
void process_unaligned(std::vector<UnalignedData>& data) {
    for (auto& element : data) {
        element.b = (element.b * 2 + 3) % 5;
    }
}

// Function to perform some operations on AlignedData
void process_aligned(std::vector<AlignedData>& data) {
    for (auto& element : data) {
        element.b = (element.b * 2 + 3) % 5;
    }
}

int main() {
    const size_t size = 1000000;

    // Create vectors of unaligned and aligned data
    std::vector<UnalignedData> unaligned_data(size);
    std::vector<AlignedData> aligned_data(size);

    // Measure time for processing unaligned data
    auto start = std::chrono::high_resolution_clock::now();
    process_unaligned(unaligned_data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Unaligned process time: " << elapsed.count() << " s\n";

    // Measure time for processing aligned data
    start = std::chrono::high_resolution_clock::now();
    process_aligned(aligned_data);
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Aligned process time:   " << elapsed.count() << " s\n";

    return 0;
}