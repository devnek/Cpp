#include <iostream>
#include <vector>
#include <chrono>


void vector_multiply_add(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, std::vector<int>& result) ;

void vector_multiply_add_unrolled(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, std::vector<int>& result) ;