class Solution {
public:
   string countAndSay(int n) {
    if (n == 1) return "1";

    string current = "1";

    for (int i = 2; i <= n; ++i) {
        string next = "";
        int len = current.length();

        for (int j = 0; j < len; ) {
            char digit = current[j];
            int count = 0;

            // Count occurrences of the same digit
            while (j < len && current[j] == digit) {
                ++count;
                ++j;
            }

            // Append count and digit to next term
            next += to_string(count) + digit;
        }

        current = next; // Prepare for next iteration
    }

    return current;
}
};



