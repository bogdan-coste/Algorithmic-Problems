class Solution {
    public static int lengthOfLongestSubstring(String s) {

        int sLength = s.length();

        int[] britishAsciiAlphabet = new int[128];

        int i = 0;
        int max = 0;
        int right = 0;

        while(i < sLength){
            
            while(right < sLength){

                char ch = s.charAt(right);

                if(britishAsciiAlphabet[ch] > 0){
                    break;
                }

                britishAsciiAlphabet[ch]++;

                right++;
            }

            int sequenceLength = right - i;

            if(sequenceLength > max){
                max = sequenceLength;
            }

            char ch = s.charAt(i);

            britishAsciiAlphabet[ch]--;

            i++;
        }

        return max;

    }
}
