class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Handle multiplication by zero

        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0); // Result can be at most len1 + len2 digits

        // Reverse iterate through both numbers
        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Multiply digits
                int sum = mul + result[i + j + 1]; // Add to the result position

                result[i + j + 1] = sum % 10; // Current digit
                result[i + j] += sum / 10; // Carry to the next position
            }
        }

        // Convert result vector to string
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product.push_back(num + '0');
            }
        }

        return product.empty() ? "0" : product; // Return "0" if product is empty
    }
};