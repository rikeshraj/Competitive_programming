// 2. Add Two Numbers
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            if (l1 != null) {
                carry += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                carry += l2.val;
                l2 = l2.next;
            }
            current.next = new ListNode(carry % 10);
            carry /= 10;
            current = current.next;
        }
        return dummy.next;
    }
}


// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
    public boolean hasAllCodes(String s, int k) {
        if(s.length() < (1 << k)) return false; 
        Set<String> see = new HashSet<>();
        for(int i=0; i<s.length()-k; i++) {
            see.add(s.substring(i, i+k));
            if(see.size() == (1 << k)) return true; 
        }
        return see.size() == (1 << k);
    }
}


// 3713. Longest Balanced Substring I
class Solution {
    public int longestBalanced(String s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int[] counts = new int[26];
            int distinctChar = 0;
            for (int j = i; j < n; j++) {
                int charId = s.charAt(j) - 'a';
                if (counts[charId] == 0) {
                    distinctChar++;
                }
                counts[charId]++;
                int currentLen = j - i + 1;
                if (currentLen % distinctChar == 0) {
                    int targetCount = currentLen / distinctChar;
                    boolean isBalanced = true;
                    for (int k = 0; k < 26; k++) {
                        if (counts[k] > 0 && counts[k] != targetCount) {
                            isBalanced = false;
                            break;
                        }
                    }
                    if (isBalanced) {
                        maxLen = Math.max(maxLen, currentLen);
                    }
                }
            }
        }
        return maxLen;
    }
}

