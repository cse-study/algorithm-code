"""
LeetCode 345 문제: Reverse Vowels of a String
https://leetcode.com/problems/reverse-vowels-of-a-string/
"""


class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']

        vowel_idx = list()
        for i, c in enumerate(s):
            if c in vowels:
                vowel_idx.append(i)

        s = list(s)
        for i in range(len(vowel_idx) - 1):
            if i >= len(vowel_idx) / 2:
                break

            c_first = s[vowel_idx[i]]
            c_second = s[vowel_idx[-i - 1]]
            s[vowel_idx[i]] = c_second
            s[vowel_idx[-i - 1]] = c_first

        return ''.join(s)
