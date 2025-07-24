class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string folder;

        while (getline(ss, folder, '/')) {
            if (folder.empty() || folder == ".") {
                // Ignore empty or current directory
                continue;
            } else if (folder == "..") {
                // Go to parent directory if possible
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // Valid directory name
                stack.push_back(folder);
            }
        }

        // Build the simplified path
        string result = "/";
        for (int i = 0; i < size(stack); ++i) {
            result += stack[i];
            if (i != size(stack) - 1) {
                result += "/";
            }
        }
        return result;
    }
};