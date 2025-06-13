class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()  # Remove leading/trailing spaces
        words = s.split(' ')
        if not words:
            return 0
        return len(words[-1])
        