#3713. Longest Balanced Substring I
class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        max_len = 0
        for i in range(n):
            counts = [0]*26
            distinct_char = 0
            for j in range(i, n):
                char_id = ord(s[j])-ord('a')
                if counts[char_id] == 0:
                    distinct_char += 1
                counts[char_id] += 1
                current_len = j-i+1
                if current_len%distinct_char == 0:
                    target_count = current_len//distinct_char
                    is_balanced = True
                    for k in range(26):
                        if counts[k]>0 and counts[k]!=target_count:
                            is_balanced = False
                            break
                    if is_balanced:
                        max_len = max(max_len, current_len)
        return max_len
