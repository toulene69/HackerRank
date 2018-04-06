//
//  main.cpp
//  HackerRankAlgorithms
//
//  Created by Apoorv on 15/03/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include <iostream>
#include "SolutionStrings.hpp"
#include "AhoCorasickAlgorithm.hpp"
#include <fstream>
#include "SolutionSorting.hpp"
#include "FenwickTree.hpp"

// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.


// Builds the string matching machine.
// arr -   array of words. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i]
//         in the text.
// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive.
int buildMatchingMachine(vector<string> &arr, vector<vector<int>>&g, vector<int>&out, vector<int>&f)
{
    
    // Initially, we just have the 0 state
    int states = 1;
    
    // Construct values for goto function, i.e., fill g[][]
    // This is same as building a Trie for arr[]
    for (int i = 0; i < arr.size(); ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
        
        // Insert all characters of current word in arr[]
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
            
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
            
            currentState = g[currentState][ch];
        }
        
        // Add current word in output function
        out[currentState] |= (1 << i);
    }
    
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    for (int ch = 0; ch < 26; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
    
    // Now, let's build the failure function
    
    
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
    
    // Iterate over every possible input
    for (int ch = 0; ch < 26; ++ch)
    {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
    
    // Now queue has states 1 and 3
    while (q.size())
    {
        // Remove the front state from queue
        int state = q.front();
        q.pop();
        
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        for (int ch = 0; ch < 26; ++ch)
        {
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1)
            {
                // Find failure state of removed state
                int failure = f[state];
                
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                    failure = f[failure];
                
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
                
                // Merge output values
                out[g[state][ch]] |= out[failure];
                
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
    
    return states;
}

// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.
int findNextState(vector<vector<int>>&g, vector<int>&f, int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';
    
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];
    
    return g[answer][ch];
}

// This function finds all occurrences of all array words
// in text.
long searchWords(vector<string> &arr, vector<vector<int>>&g, vector<int>&out, vector<int>&f, vector<int>&h, string text, int l, int r)
{
    // Preprocess patterns.
    // Build machine with goto, failure and output functions
    
    
    // Initialize current state
    int currentState = 0;
    
    // Traverse the text through the nuilt machine to find
    // all occurrences of words in arr[]
    
    long res = 0;
    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(g,f,currentState, text[i]);
        
        // If match not found, move to next state
        if (out[currentState] == 0)
            continue;
        
        // Match found, print all matching words of arr[]
        // using output function.
        for (int j = 0; j < arr.size(); ++j)
        {
            if (out[currentState] & (1 << j) && (j>=l && j<=r))
            {
                res+= h[j];
            }
        }
    }
    return res;
}

void solution1()
{
    fstream myfile;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankAlgorithms/HackerRankAlgorithms/input.txt");
    int n;
    myfile >> n;
    vector<string> genes(n);
    int maxs = 0;
    for(int genes_i = 0; genes_i < n; genes_i++){
        myfile >> genes[genes_i];
        maxs += genes[genes_i].length();
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
        myfile >> health[health_i];
    }
    
    
    // Maximum number of characters in input alphabet
    
    
    // OUTPUT FUNCTION IS IMPLEMENTED USING out[]
    // Bit i in this mask is one if the word with index i
    // appears when the machine enters this state.
    vector<int> out(maxs,0);
    
    // FAILURE FUNCTION IS IMPLEMENTED USING f[]
    vector<int> f(maxs, -1);
    
    // GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
    vector<vector<int>> g(maxs, vector<int>(26,-1));
    buildMatchingMachine(genes, g, out, f);
    
    long mn=INT_MAX,mx=INT_MIN;
    int s;
    myfile >> s;
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        myfile >> first >> last >> d;
        long res = searchWords(genes, g, out, f, health, d, first, last);
        mn = min(mn, res);
        mx = max(mx, res);
    }
    cout<< mn << " " << mx;
    myfile.close();
}

// Driver program to test above
//int main()
//{
////    string arr[] = {"he", "she", "hers", "his"};
////    string text = "ahishers";
////    int k = sizeof(arr)/sizeof(arr[0]);
////
////    searchWords(arr, k, text);
//
//    return 0;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    //solution1();
    vector<int> v = {2,5,3,1};
    //cout <<  lilysHomework(v);
    fstream myfile;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankAlgorithms/HackerRankAlgorithms/input.txt");
//    int t;
//    myfile >> t;
//    for(int a0 = 0; a0 < t; a0++){
        int n;
        myfile >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            myfile >> arr[arr_i];
        }
    cout << util(arr);
//        long result = insertionSort(arr);
//        cout << result << endl;
//    }
    return 0;
}

