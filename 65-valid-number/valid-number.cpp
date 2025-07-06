class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();

        // Helper to consume digits
        auto isDigits = [&](int& i) {
            int start = i;
            while (i < n && isdigit(s[i])) i++;
            return i > start;
        };

        // Skip leading/trailing whitespaces if needed (not required per spec)

        // Optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool isNumeric = false;

        // Integer part
        if (isDigits(i)) {
            isNumeric = true;
        }

        // Decimal part
        if (i < n && s[i] == '.') {
            i++;
            // At least one digit on either side of the dot
            if (isDigits(i)) isNumeric = true;
        }

        // Exponent part
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            // Must have digits after e
            if (!isDigits(i)) return false;
        }

        // Must reach the end of the string
        return isNumeric && i == n;
    }
};