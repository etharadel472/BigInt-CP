#include <iostream>
#include <string>
using namespace std;

class BigInt {
    string number;    // Stores the number as a string
    bool isNegative;  // True if number is negative

    // ==================== START MEMBER 1 (Core & Setup) ====================
    // Remove unnecessary leading zeros from the number string
    void removeLeadingZeros() {
        // TODO: Implement this function
    }

    // Compare absolute values of two BigInts (ignore signs)
    // Returns: 1 if |this| > |other|, 0 if equal, -1 if |this| < |other|
    int compareMagnitude(const BigInt& other) const {
        // TODO: Implement this function
        return 0;
    }

public:
    // Default constructor - initialize to zero
    BigInt() {
        // TODO: Implement this constructor
    }

    // Constructor from 64-bit integer
    BigInt(int64_t value) {
        // TODO: Implement this constructor
    }

    // Constructor from string representation
    BigInt(const string& str) {
        // TODO: Implement this constructor
    }

    // Copy constructor
    BigInt(const BigInt& other) {
        // TODO: Implement this constructor
    }

    // Destructor
    ~BigInt() {
        // TODO: Implement if needed
    }

    // Assignment operator
    BigInt& operator=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }
    // ===================== END MEMBER 1 (Core & Setup) =====================


    // ================= START MEMBER 2 (Streams & Unary - Part 1) =================
    // Unary negation operator (-x)
    BigInt operator-() const {
        BigInt result;
        // TODO: Implement negation logic
        return result;
    }

    // Unary plus operator (+x)
    BigInt operator+() const {
        BigInt result;
        // TODO: Implement this operator
        return result;
    }
    // ================== END MEMBER 2 (Streams & Unary - Part 1) ==================


    // ==================== START MEMBER 4 (Addition - Part 1) ====================
    // Addition assignment operator (x += y)
    BigInt& operator+=(const BigInt& other) {
        string result;

        if (isNegative == other.isNegative) {
            int i = static_cast<int>(number.size()) - 1;
            int j = static_cast<int>(other.number.size()) - 1;
            int carry = 0;

            while (i >= 0 || j >= 0 || carry != 0) {
                int sum = carry;

                if (i >= 0)
                    sum += number[i--] - '0';

                if (j >= 0)
                    sum += other.number[j--] - '0';

                result = char('0' + sum % 10) + result;
                carry = sum / 10;
            }
        } else {
            int comparison = compareMagnitude(other);

            if (comparison == 0) {
                number = "0";
                isNegative = false;
                return *this;
            }

            const string& larger = comparison > 0 ? number : other.number;
            const string& smaller = comparison > 0 ? other.number : number;
            bool resultNegative = comparison > 0 ? isNegative : other.isNegative;
            int i = static_cast<int>(larger.size()) - 1;
            int j = static_cast<int>(smaller.size()) - 1;
            int borrow = 0;

            while (i >= 0) {
                int digit = larger[i--] - '0' - borrow;

                if (j >= 0)
                    digit -= smaller[j--] - '0';

                borrow = 0;

                if (digit < 0) {
                    digit += 10;
                    borrow = 1;
                }

                result = char('0' + digit) + result;
            }

            isNegative = resultNegative;
        }

        number = result;
        removeLeadingZeros();
        return *this;
    }
    // ===================== END MEMBER 4 (Addition - Part 1) =====================


    // =================== START MEMBER 5 (Subtraction - Part 1) ===================
    // Subtraction assignment operator (x -= y)
    BigInt& operator-=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }
    // ==================== END MEMBER 5 (Subtraction - Part 1) ====================


    // ================= START MEMBER 6 (Multiplication - Part 1) =================
    // Multiplication assignment operator (x *= y)
    BigInt& operator*=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }
    // ================== END MEMBER 6 (Multiplication - Part 1) ==================


    // ================= START MEMBER 7 (Division & Mod - Part 1) =================
    // Division assignment operator (x /= y)
    BigInt& operator/=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }

    // Modulus assignment operator (x %= y)
    BigInt& operator%=(const BigInt& other) {
        // TODO: Implement this operator
        return *this;
    }
    // ================== END MEMBER 7 (Division & Mod - Part 1) ==================


    // ==================== START MEMBER 4 (Addition - Part 2) ====================
    // Pre-increment operator (++x)
    BigInt& operator++() {
        *this += BigInt(1);
        return *this;
    }

    // Post-increment operator (x++)
    BigInt operator++(int) {
        BigInt temp(*this);
        ++(*this);
        return temp;
    }
    // ===================== END MEMBER 4 (Addition - Part 2) =====================


    // =================== START MEMBER 5 (Subtraction - Part 2) ===================
    // Pre-decrement operator (--x)
    BigInt& operator--() {
        // TODO: Implement this operator
        return *this;
    }

    // Post-decrement operator (x--)
    BigInt operator--(int) {
        BigInt temp;
        // TODO: Implement this operator
        return temp;
    }
    // ==================== END MEMBER 5 (Subtraction - Part 2) ====================


    // ================= START MEMBER 2 (Streams & Unary - Part 2) =================
    // Convert BigInt to string representation
    string toString() const {
        // TODO: Implement this function
        return "";
    }

    // Output stream operator (for printing)
    friend ostream& operator<<(ostream& os, const BigInt& num) {
        // TODO: Implement this operator
        return os;
    }

    // Input stream operator (for reading from input)
    friend istream& operator>>(istream& is, BigInt& num) {
        // TODO: Implement this operator
        return is;
    }
    // ================== END MEMBER 2 (Streams & Unary - Part 2) ==================

    // Friend declarations for comparison operators
    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
};


// ==================== START MEMBER 4 (Addition - Part 3) ====================
// Binary addition operator (x + y)
BigInt operator+(BigInt lhs, const BigInt& rhs) {
    lhs += rhs;
    return lhs;
}
// ===================== END MEMBER 4 (Addition - Part 3) =====================


// =================== START MEMBER 5 (Subtraction - Part 3) ===================
// Binary subtraction operator (x - y)
BigInt operator-(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}
// ==================== END MEMBER 5 (Subtraction - Part 3) ====================


// ================= START MEMBER 6 (Multiplication - Part 2) =================
// Binary multiplication operator (x * y)
BigInt operator*(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}
// ================== END MEMBER 6 (Multiplication - Part 2) ==================


// ================= START MEMBER 7 (Division & Mod - Part 2) =================
// Binary division operator (x / y)
BigInt operator/(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}

// Binary modulus operator (x % y)
BigInt operator%(BigInt lhs, const BigInt& rhs) {
    BigInt result;
    // TODO: Implement this operator
    return result;
}
// ================== END MEMBER 7 (Division & Mod - Part 2) ==================


// ======================= START MEMBER 3 (Comparisons) =======================
// Equality comparison operator (x == y)
bool operator==(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}

// Inequality comparison operator (x != y)
bool operator!=(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}

// Less-than comparison operator (x < y)
bool operator<(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}

// Less-than-or-equal comparison operator (x <= y)
bool operator<=(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}

// Greater-than comparison operator (x > y)
bool operator>(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}

// Greater-than-or-equal comparison operator (x >= y)
bool operator>=(const BigInt& lhs, const BigInt& rhs) {
    // TODO: Implement this operator
    return false;
}
// ======================== END MEMBER 3 (Comparisons) ========================


int main() {
    cout << "=== BigInt Class Test Program ===" << endl << endl;
    cout << "NOTE: All functions are currently empty." << endl;
    cout << "Your task is to implement ALL the functions above." << endl;
    cout << "The tests below will work once you implement them correctly." << endl << endl;

    /*
    // Test 1: Constructors and basic output
    cout << "1. Constructors and output:" << endl;
    BigInt a(12345);              // Should create BigInt from integer
    BigInt b("-67890");           // Should create BigInt from string
    BigInt c("0");                // Should handle zero correctly
    BigInt d = a;                 // Should use copy constructor
    cout << "a (from int): " << a << endl;        // Should print "12345"
    cout << "b (from string): " << b << endl;     // Should print "-67890"
    cout << "c (zero): " << c << endl;            // Should print "0"
    cout << "d (copy of a): " << d << endl << endl; // Should print "12345"

    // Test 2: Arithmetic operations
    cout << "2. Arithmetic operations:" << endl;
    cout << "a + b = " << a + b << endl;          // Should calculate 12345 + (-67890)
    cout << "a - b = " << a - b << endl;          // Should calculate 12345 - (-67890)
    cout << "a * b = " << a * b << endl;          // Should calculate 12345 * (-67890)
    cout << "b / a = " << b / a << endl;          // Should calculate (-67890) / 12345
    cout << "a % 100 = " << a % BigInt(100) << endl << endl; // Should calculate 12345 % 100

    // Test 3: Relational operators
    cout << "3. Relational operators:" << endl;
    cout << "a == d: " << (a == d) << endl;       // Should be true (12345 == 12345)
    cout << "a != b: " << (a != b) << endl;       // Should be true (12345 != -67890)
    cout << "a < b: " << (a < b) << endl;         // Should be false (12345 < -67890)
    cout << "a > b: " << (a > b) << endl;         // Should be true (12345 > -67890)
    cout << "c == 0: " << (c == BigInt(0)) << endl << endl; // Should be true (0 == 0)

    // Test 4: Unary operators and increments
    cout << "4. Unary operators and increments:" << endl;
    cout << "-a: " << -a << endl;                 // Should print "-12345"
    cout << "++a: " << ++a << endl;               // Should increment and print "12346"
    cout << "a--: " << a-- << endl;               // Should print "12346" then decrement
    cout << "a after decrement: " << a << endl << endl; // Should print "12345"

    // Test 5: Large number operations
    cout << "5. Large number operations:" << endl;
    BigInt num1("12345678901234567890");
    BigInt num2("98765432109876543210");
    cout << "Very large addition: " << num1 + num2 << endl;
    cout << "Very large multiplication: " << num1 * num2 << endl << endl;

    // Test 6: Edge cases and error handling
    cout << "6. Edge cases:" << endl;
    BigInt zero(0);
    BigInt one(1);
    try {
        BigInt result = one / zero;               // Should throw division by zero error
        cout << "Division by zero succeeded (unexpected)" << endl;
    } catch (const runtime_error& e) {
        cout << "Division by zero correctly threw error: " << e.what() << endl;
    }
    cout << "Multiplication by zero: " << one * zero << endl;        // Should be "0"
    cout << "Negative multiplication: " << BigInt(-5) * BigInt(3) << endl;  // Should be "-15"
    cout << "Negative division: " << BigInt(-10) / BigInt(3) << endl;       // Should be "-3"
    cout << "Negative modulus: " << BigInt(-10) % BigInt(3) << endl;        // Should be "-1"
    */

    return 0;
}
