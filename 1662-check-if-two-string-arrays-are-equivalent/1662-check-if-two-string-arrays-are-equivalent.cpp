class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
//         string a,b;
        
//         for(auto it1 : word1) a+=it1;
        
//         for(auto it2 : word2) b+=it2;
        
//         if(a.compare(b)==0) return 1;
        
//         return 0;
        
        
        int p1 = 0, p2 = 0; // inner pointer
	int w1 = 0, w2 = 0; // outer pointer

	while (w1 < word1.size() && w2 < word2.size()) {
		string curr1 = word1[w1], curr2 = word2[w2];

		if (curr1[p1] != curr2[p2]) return false;

		if (p1 < curr1.length() - 1) {
			p1++;
		} else {
			p1 = 0;
			w1++;
		}

		if (p2 < curr2.length() - 1) {
			p2++;
		} else {
			p2 = 0;
			w2++;
		}
	}

	return w1 == word1.size() && w2 == word2.size();
    }
};