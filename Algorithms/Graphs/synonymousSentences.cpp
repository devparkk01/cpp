/*
Rippling interview question

https://leetcode.com/problems/synonymous-sentences/description/

*/
#include<bits/stdc++.h>


class Solution {
public:
    // we use bfs approach to solve this problem 
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, vector<string>> graph; 

        for(auto &synonym: synonyms) {
            graph[synonym[0]].push_back(synonym[1]);
            graph[synonym[1]].push_back(synonym[0]);
        }
        // stores list of unique synonymous sentences
        set<string> ansSet; 
        queue<string>q; 
        // Add the initial sentence into the queue
        q.push(text);

        while(!q.empty()) {
            string poppedText = q.front(); q.pop(); 
            ansSet.insert(poppedText);
            // istringstream to split the poppedText
            istringstream sin(poppedText);
            string word;
            // wordsList stores poppedText split by whitespace
            vector<string>wordsList;
            while( sin >> word) {
                wordsList.push_back(word);
            }
            // iterate through each word in the wordsList 
            for(int i = 0 ; i < wordsList.size() ; ++i) {
                // if wordsList[i] exist in the hashmap, then it means this word has some synonyms
                if( graph.find(wordsList[i]) != graph.end()) {
                    // iterate through all synonyms of this word
                    for(auto &synonym: graph[wordsList[i]]) {
                        string originalWord = wordsList[i];
                        wordsList[i] = synonym; 
                        // construct synonymous sentence
                        ostringstream sout; 
                        for(int j = 0; j < wordsList.size() ; ++j) {
                            sout << wordsList[j] ; 
                            if (j != wordsList.size() - 1) {
                                sout << " ";
                            }
                        }
                        // if we have not already found this synonymous sentence 
                        if (! ansSet.count(sout.str())) {
                            // add it to the set as well as queue
                            ansSet.insert(sout.str());
                            q.push(sout.str());
                        }
                        // VERY IMPORTANT: set it back to originalWord
                        wordsList[i] = originalWord; 
                    }
                }
            }



        }
        return vector<string>(ansSet.begin(), ansSet.end());


    }
};