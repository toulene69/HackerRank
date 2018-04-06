//
//  AhoCorasickAlgorithm.cpp
//  HackerRankAlgorithms
//
//  Created by Apoorv on 31/03/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "AhoCorasickAlgorithm.hpp"
#include <fstream>

typedef struct TriNode {
    unordered_map<char, TriNode*> childs;
    TriNode *failTo;
    vector<int> matches;
}TriNode;

class NPatternMatch
{
private:
    TriNode *root;
    unordered_map<string, int> dict;
public:
    NPatternMatch(vector<int>&health, vector<string> &genes) {
        root = new TriNode();
        root->failTo = NULL;
        construstTrie(genes);
        buildFails();
    }
    
    vector<int> matchDNAGenes(string s, int l, int r) {
        vector<int> mat;
        TriNode *temp = root;
        int n = s.length();
        for (int i=0; i<n; i++) {
            char x = s[i];
            while (temp != NULL && temp->childs.find(x) == temp->childs.end()) {
                temp = temp->failTo;
            }
            if (temp != NULL) {
                TriNode *node = temp->childs[x];
                for (auto it = node->matches.begin(); it != node->matches.end(); it++) {
                    if (*it >=l && *it<=r) {
                        mat.push_back(*it);
                    }
                }
                temp = node;
            }
            else {
                temp = root;
            }
        }
        return mat;
    }
    
private:
    void construstTrie(vector<string> &patterns) {
        for(int z = 0; z<patterns.size(); z++) {
            string p = patterns[z];
            TriNode *temp = root;
            unordered_map<char, TriNode*>:: iterator it;
            for(int i=0; i<p.length(); i++) {
                char x = p[i];
                it = temp->childs.find(x);
                if (it == temp->childs.end()) {
                    temp->childs[x] = new TriNode();
                }
                temp = temp->childs[x];
            }
            temp->matches.push_back(z);
        }
    }
    
    void buildFails() {
        queue<TriNode*> q;
        TriNode *cur, *fail;
        for (unordered_map<char, TriNode*> :: iterator it = root->childs.begin(); it!= root->childs.end(); it++) {
            it->second->failTo = root;
            q.push(it->second);
        }
        while (!q.empty()) {
            cur = q.front(); q.pop();
            fail = cur->failTo;
            for (unordered_map<char, TriNode*> :: iterator it = cur->childs.begin(); it!= cur->childs.end(); it++) {
                TriNode *child = it->second;
                char curVal = it->first;
                q.push(child);
                while (fail != NULL && fail->childs.find(curVal) == fail->childs.end()) {
                    fail = fail->failTo;
                }
                if (fail == NULL) {
                    child->failTo = root;
                }
                else {
                    child->failTo = fail->childs[curVal];
                    child->matches.insert(child->matches.end(), child->failTo->matches.begin(), child->failTo->matches.end());
                }
            }
        }
    }
};

void solution()
{
    fstream myfile;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankAlgorithms/HackerRankAlgorithms/input.txt");
    int n;
    myfile >> n;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
        myfile >> genes[genes_i];
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
        myfile >> health[health_i];
    }
    NPatternMatch obj(health,genes);
    long mn=INT_MAX,mx=INT_MIN;
    int s;
    myfile >> s;
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        myfile >> first >> last >> d;
        vector<int> matches = obj.matchDNAGenes(d, first, last);
        long res = 0;
        for(int i : matches) {
            res += health[i];
        }
        mn = min(mn, res);
        mx = max(mx, res);
    }
    cout<< mn << " " << mx;
    myfile.close();
}
