class Solution {
public:
    bool isPalindrome(long long x) {
        
      if(x < 0) return false;

      long long bkp = x;

      long long ogl = 0;

      while(x != 0){
        ogl = ogl * 10 + x % 10;
        x = x / 10;
      }

      return bkp == ogl;
    }
};
