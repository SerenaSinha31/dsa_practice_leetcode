class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> uniquenumbers;

        // All possible 3-digit even numbers from digits without repetition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && k != i) {
                        int first = digits[i];
                        int second = digits[j];
                        int third = digits[k];
                        
                        
                        if (first != 0 && third % 2 == 0) {
                            int number = first * 100 + second * 10 + third;
                            uniquenumbers.insert(number);
                        }
                    }
                }
            }
        }
        return uniquenumbers.size();
    }
};
