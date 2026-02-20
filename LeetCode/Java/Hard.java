// 761. Special Binary String
class Solution {
    public String makeLargestSpecial(String s) {
        int count = 0; 
        int i = 0; 
        List<String> res = new ArrayList<>();
        for(int j=0; j<s.length(); j++) {
            if(s.charAt(j) == '1') {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                res.add('1' + makeLargestSpecial(s.substring(i+1, j)) + "0");
                i = j+1;
            }
        }
        Collections.sort(res, Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for(String str : res) {
            sb.append(str);
        }
        return sb.toString();
    }
}

