class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;  // freq-signature -> grouped anagrams

        for (const auto& s : strs) {
            vector<int> count(26, 0);  // frequency of a-z

            for (char c : s)
                count[c - 'a']++;      // map char to index [0..25]

            string key = to_string(count[0]);  // start building unique freq signature

            for (int i = 1; i < 26; ++i)
                key += ',' + to_string(count[i]);  // append remaining counts

            res[key].push_back(s);  // same signature => same anagram group
        }

        vector<vector<string>> result;

        for (const auto& pair : res)
            result.push_back(pair.second);  // extract grouped values

        return result;
    }
};