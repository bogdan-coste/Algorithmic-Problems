class Solution {
    public static String minWindow(String s, String t) {

        int[] britishAsciiAlphabet = new int[128];
        int tLength = t.length();

        for(char ch: t.toCharArray()){
            britishAsciiAlphabet[ch]++;
        }

        int i = 0;
        int sLength = s.length();
        int max = sLength + 1;
        boolean found = false;

        int startIdx = 0;
        int endIdx = 0;

        int right = 0;
        int zeroedItems = 0;
        while(i < sLength){

            while(right < sLength && zeroedItems < tLength){

                int currentChar = s.charAt(right);

                if (britishAsciiAlphabet[currentChar] > 0) {
                    zeroedItems++;
                }

                britishAsciiAlphabet[currentChar]--;

                right++;
            }

            if (zeroedItems == tLength) {
                found = true;

                int currentWindowLen = right - i;

                if (currentWindowLen < max) {
                    max = currentWindowLen;
                    startIdx = i;
                    endIdx = right;
                }
            }

            int charToRemove = s.charAt(i);
            britishAsciiAlphabet[charToRemove]++;

            if (britishAsciiAlphabet[charToRemove] > 0) {
                zeroedItems--;
            }

            i++;
        }

        if(found) {
            return s.substring(startIdx, endIdx);
        }

        return "";
    }
}
