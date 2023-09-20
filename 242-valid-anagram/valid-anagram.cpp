class Solution {
public:
    bool isAnagram(string s, string t) {
        // onordered map has unique keys so the chars in the string are stored only once
        unordered_map<char, int>frequency;
        // storing the frequency of chars in string s
        for(auto x:s)
            frequency[x]++;
        // deleting the frequency of common chars in t
        for(auto x:t)
            frequency[x]--;
        for(auto x: frequency){
            if(x.second !=0)
                return false;
        }
        // if frequency is zero, its anagram 
        return true;
    }

};