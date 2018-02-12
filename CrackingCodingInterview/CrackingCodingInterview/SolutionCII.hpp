//
//  SolutionCII.hpp
//  CrackingCodingInterview
//
//  Created by Apoorv on 22/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#ifndef SolutionCII_hpp
#define SolutionCII_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <stack>
#include <functional>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

typedef struct TrieNode{
    unordered_map<char, TrieNode*> child;
    int count=0;
    
}Trie;

class Contact {
private:
    Trie *root;
public:
    Contact();
    ~Contact();
    void add_contact(string contact);
    int find_partial(string partial);
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

struct Node {
    int data;
    struct Node* next;
};

class MyQueue {
private:
    int d;
public:
    stack<int> stack_newest_on_top, stack_oldest_on_top;
    void push(int x);
    void pop();
    int front();
};

class Graph {
private:
    int n;
    vector<vector<int>> adj;
public:
    Graph(int n);
    void add_edge(int u, int v);
    
    vector<int> shortest_reach(int start);
        
    
};

long long make_change(vector<int> coins, int money);
int numWays(int n);
void check_primality(vector<int> nums);
int get_biggest_region(vector< vector<int> > grid);
void iceCream(vector <int> arr, int money);
long countInversions(vector<int> arr);
void contact_search();
void running_median() ;
bool checkBST(TreeNode* root);
bool is_balanced(string expression);
bool has_cycle(Node* head);
bool ransom_note(vector<string> magazine, vector<string> ransom);
vector<int> array_left_rotation(vector<int> a, int n, int k) ;
int number_needed(string a, string b);

#endif /* SolutionCII_hpp */
