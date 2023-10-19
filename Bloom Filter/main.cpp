/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on May 14, 2023, 11:36 AM
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <bitset>
#include <functional>

template<typename T, size_t N>
class BloomFilter {
public:
    BloomFilter() {
        for (size_t i = 0; i < N; ++i) {
            hashFunctions[i] = [i](const T& value) { return std::hash<T>()(value) + i; };
        }
    }

    void insert(const T& value) {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(value) % filter.size();
            filter.set(index);
        }
    }

    bool contains(const T& value) const {
        for (const auto& hashFunction : hashFunctions) {
            if (!filter.test(hashFunction(value) % filter.size())) {
                return false;
            }
        }
        return true;
    }

    void printBitVector() const {
        for (size_t i = 0; i <= 14; ++i) {
            std::cout << filter.test(i);
        }
        std::cout << std::endl;
    }

private:
    std::bitset<1024> filter;
    std::array<std::function<size_t(const T&)>, N> hashFunctions;
};

int main() {
    BloomFilter<std::string, 9> bloomFilter;

    std::ifstream inputFile("random_inputs.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    std::string input;
    while (std::getline(inputFile, input)) {
        bloomFilter.insert(input);
    }

    inputFile.close();

    bloomFilter.printBitVector();

    return 0;
}
