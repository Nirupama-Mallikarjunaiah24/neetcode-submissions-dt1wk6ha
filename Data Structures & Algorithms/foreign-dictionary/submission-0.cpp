class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj; // to avoid repetition of the conclusion
        unordered_map<char,int> indegree; // the letters arent going to be in order sp not using an array rather a hashmap
        for( string w: words) { // can have more than just 26 characters so considered all and just initialising everything
            for( char c: w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size()-1;++i) {
            string w1= words[i], w2 = words[i+1];
            int minlen = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.substr(0,minlen) == w2.substr(0,minlen)) {
                return ""; // a substring was placed before - so the order is wrong and the entire dictionary cant be used
            }
            for(int j = 0; j<minlen;++j) {
                if(w1[j] !=w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) { // doesnt already exist then insert
                        adj[w1[j]].insert(w2[j]); // a->b , a comes before b
                        indegree[w2[j]]++; // b's indegree is incremented
                    }
                    break;
                }
            }
        }

        queue<char> q;

        for ( auto& deg: indegree) {
            if(deg.second == 0) {
                q.push(deg.first);
            }
        }

        string res;
        while( !q.empty()){
            char c = q.front(); q.pop();
            res+=c;

            for( char neigh: adj[c]) {
                indegree[neigh]--;
                if( indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return res.size() == indegree.size() ? res: "";
        
    }
};
