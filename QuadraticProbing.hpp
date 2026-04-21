#pragma once
#include "HashTableClosed.hpp"
#include <cmath>

template <typename T>
class QuadraticProbing : public HashTableClosed<T> {
public:
    explicit QuadraticProbing(int size = 101)
        : HashTableClosed<T>(size) {}

    int probeIndex(const T& key, int i) const override {
        // TODO: Implement quadratic probing
        return (this->hash1(key) + (int)pow(i, 2)) % this->M;
    }

   
};
