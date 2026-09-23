class Solution {
public:
    bool check(string &s, int left,int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int left=0, right = n-1;
        while(left < right)
        {
            if(tolower(s[left]) != tolower(s[right]))
            {
                return check(s,left+1,right) || check(s,left,right-1);
            }
                left++;
                right--;
        }
        return true;
    }
};