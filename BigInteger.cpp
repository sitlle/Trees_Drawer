#include "BigInteger.h"

int32_t BigInteger::size() const {
    return static_cast<int32_t>(a.size());
}

BigInteger BigInteger::inverseSign() {
    sign *= -1;
    return (*this);
}

BigInteger BigInteger::normalize(int newSign) {
    for (int i = static_cast<int32_t>(a.size()) - 1; i > 0 && a[i] == '0'; i--) {
        a.erase(a.begin() + i);
    }
    if (static_cast<int32_t>(a.size()) == 1 && a[0] == '0') {
        sign = 1;
    } else {
        sign = newSign;
    }
    return *this;
}

BigInteger& BigInteger::operator=(std::string other) {
    if (other[0] == '-') {
        a = other.substr(1);
    } else {
        a = other;
    }
    std::reverse( a.begin(), a.end() );
    if (other[0] == '-') {
        this->normalize(-1);
    } else {
        this->normalize(1);
    }
    return *this;
}

bool BigInteger::operator<(const BigInteger &other) const {
    if (sign != other.sign) {
        return sign < other.sign;
    }
    if (a.size() != other.a.size()) {
        if (sign == 1) {
            return a.size() < other.a.size();
        }
        return a.size() > other.a.size();
    }
    for (int i = static_cast<int32_t>(a.size()) - 1; i >= 0; i--) {
        if (a[i] != other.a[i]) {
            if (sign == 1) {
                return a[i] < other.a[i];
            }
            return a[i] > other.a[i];
        }
    }
    return false;
}

BigInteger BigInteger::operator+(BigInteger other) {
    if (sign != other.sign) {
        return *this - other.inverseSign();
    }
    BigInteger c;
    for (int i = 0, carry = 0; i < a.size() || i < other.size() || carry; i++) {
        if (i < a.size()) {
            carry += a[i] - 48;
        }
        if (i < other.a.size()) {
            carry += other.a[i] - 48;
        }
        c.a += char(carry % 10 + 48);
        carry /= 10;
    }
    return c.normalize(sign);
}

BigInteger BigInteger::operator-(BigInteger other) {
    if (sign != other.sign) {
        return *this + other.inverseSign();
    }
    int s = sign;
    sign = other.sign = 1;
    if (*this < other) {
        return ((other - (*this)).inverseSign()).normalize(-s);
    }
    BigInteger c;
    for (int i = 0, borrow = 0; i < a.size(); i++) {
        if (i < other.size()) {
            borrow = a[i] - borrow - other.a[i];
        } else {
            borrow = a[i] - borrow - 48;
        }
        if (borrow >= 0) {
            c.a += char(borrow + 48);
        } else {
            c.a += char(borrow + 58);
        }
        if (borrow >= 0) {
            borrow = 0;
        } else {
            borrow = 1;
        }
    }
    return c.normalize(s);
}

BigInteger BigInteger::operator*(BigInteger other) {
    BigInteger c("0");
    for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {
        while(k--)
            c = c + other;
        other.a.insert(other.a.begin(), '0');
    }
    return c.normalize(sign * other.sign);
}

BigInteger BigInteger::operator/(BigInteger other) {
    if (other.size() == 1 && other.a[0] == '0') {
        other.a[0] /= (other.a[0] - 48);
    }
    BigInteger c("0"), d;
    for( int j = 0; j < a.size(); j++ ) {
        d.a += "0";
    }
    int dSign = sign * other.sign;
    other.sign = 1;
    for( int i = (int)a.size() - 1; i >= 0; i-- ) {
        c.a.insert( c.a.begin(), '0');
        c = c + BigInteger(a.substr( i, 1));
        while (!(c < other)) {
            c = c - other;
            d.a[i]++;
        }
    }
    return d.normalize(dSign);
}

BigInteger BigInteger::operator%(BigInteger other) {
    if (other.size() == 1 && other.a[0] == '0' ) {
        other.a[0] /= (other.a[0] - 48);
    }
    BigInteger c("0");
    other.sign = 1;
    for ( int i = (int)a.size() - 1; i >= 0; i-- ) {
        c.a.insert( c.a.begin(), '0');
        c = c + BigInteger(a.substr( i, 1));
        while( !(c < other ) )
            c = c - other;
    }
    return c.normalize(sign);
}

void BigInteger::print() {
    if (sign == -1) {
        putchar('-');
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        putchar(a[i]);
    }
}