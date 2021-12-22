class Solution {
    public:
        int numSpecialEquivGroups(vector<string>& A) {
            set<string> s;
            for (const string& a : A) {
                string odd;
                string even;
                for (int i = 0; i < a.size(); ++i) {
                    if (i % 2)
                        odd += a[i];
                    else
                        even += a[i];
                }
                sort(begin(odd), end(odd));
                sort(begin(even), end(even));
                s.insert(odd + even);
            }
            return s.size();
    }
};