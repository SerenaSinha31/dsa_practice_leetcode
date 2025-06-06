class Solution {
public:
    // Method that takes a string s and outputs a string based on certain logic
    string robotWithString(string s) {
        int charCount[26] = {0}; // Array to keep track of each character's frequency
      
        // Count the frequency of each character in the input string
        for (char ch : s) {
            ++charCount[ch - 'a'];
        }
      
        char minChar = 'a'; // Variable to keep track of the smallest character not used up
        string stack;       // Use a string as a stack to keep track of characters
        string answer;      // The resulting string that we'll build
      
        // Iterate over each character in the input string
        for (char ch : s) {
            // Decrement the count of the current character,
            // since we're going to process it
            --charCount[ch - 'a'];

            // Find the smallest character that still has remaining occurrences
            while (minChar < 'z' && charCount[minChar - 'a'] == 0) {
                ++minChar;
            }
          
            // Push the current character onto the stack
            stack.push_back(ch);
          
            // While the stack is not empty and the top of the stack is less than or equal
            // to the smallest character not used up, append it to the answer and pop it from the stack
            while (!stack.empty() && stack.back() <= minChar) {
                answer.push_back(stack.back());
                stack.pop_back();
            }
        }
      
        // Return the constructed answer string
        return answer;
    }
};