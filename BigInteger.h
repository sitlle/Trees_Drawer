#pragma once
#include<bits/stdc++.h>

class BigInteger {
public:
    std::string a;
    int sign;

    BigInteger() = default;
    ~BigInteger() = default;
    explicit BigInteger(std::string b) {
        *this = std::move(b);
    }
    BigInteger(BigInteger& other) {
        a = other.a;
        sign = other.sign;
    }

    int32_t size() const;
    BigInteger inverseSign();
    BigInteger normalize(int newSign);

    BigInteger& operator = (std::string other);

    bool operator < (const BigInteger &other) const;

    bool operator == (const BigInteger &b) const {
        return a == b.a && sign == b.sign;
    }

    BigInteger operator + (BigInteger other);

    BigInteger operator - (BigInteger other);

    BigInteger operator * (BigInteger other);

    BigInteger operator / (BigInteger other);

    BigInteger operator % (BigInteger other);

    void print();
};
