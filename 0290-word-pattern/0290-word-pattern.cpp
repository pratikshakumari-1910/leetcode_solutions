class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word)
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for (int i = 0; i < pattern.size(); i++) {
            if (mp.count(pattern[i]) && mp[pattern[i]] != words[i])
                return false;

            if (rev.count(words[i]) && rev[words[i]] != pattern[i])
                return false;

            mp[pattern[i]] = words[i];
            rev[words[i]] = pattern[i];
        }

        return true;
    }
};
