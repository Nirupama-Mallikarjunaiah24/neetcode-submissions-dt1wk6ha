class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if( endWord.empty() || beginWord.empty() || endWord.length() != beginWord.length()) {
            return 0;
        }

        int n = beginWord.size();
        unordered_map<string, vector<string>> hash; // this is like the adjacency map
        for(string word: wordList) {
            for ( int i = 0; i < n; ++i) {
                string key = word.substr(0,i)+"*"+word.substr(i+1);
                hash[key].push_back(word);
            }
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_map<string,bool> visited;
        visited[beginWord] = true;

        while ( !q.empty()) {
            auto word = q.front();
            q.pop();

            for ( int i = 0; i < n;++i) {
                string newword = word.first.substr(0,i)+"*"+word.first.substr(i+1);
                for ( string neighbor: hash[newword]) {
                    if(neighbor == endWord)
                        return word.second+1;
                    
                    if(visited[neighbor] != true) {
                        visited[neighbor] = true;
                        q.push({neighbor,word.second+1});
                    }
                }
            }
        }
        return 0;


    }
};
