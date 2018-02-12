//
//  main.cpp
//  CrackingCodingInterview
//
//  Created by Apoorv on 19/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SolutionCII.hpp"

vector<int> computeLPS(string input){
    int n = input.size();
    std::vector<int> lps(n,0);
    int len = 0, i =1;
    while(i<n) {
        if (input[i] == input[len])
        {
            i++;
            len++;
            lps[i] = len;
        }
        else {
            if (len>0)
            {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmp_match(string txt, string pat) {
    int m = pat.length();
    int n = txt.length();
    int i=0, j=0;
    vector<int> lps = computeLPS(pat);
    while(i<n) {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j==m)
        {
            cout << "Found at "<< i-j;
            j = lps[j-1];
        }
        else if (i<n && pat[j] != txt[i]) {
            
            if (j!=0)
            {
                j = lps[j-1];
            }
            else {
                i++;
            }
            
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v = {2, 1, 3, 1, 2};
    //vector<int> r = array_left_rotation( v,5,1);
//    vector<string> s1 = {"give", "me", "one", "grand", "today", "night"};
//    vector<string> s2 = {"give", "one", "grand", "today"};
//    Node *n1 = (Node*) malloc(sizeof(Node));
//    Node *n2 = (Node*) malloc(sizeof(Node));
//    Node *n3 = (Node*) malloc(sizeof(Node));
//    Node *n4 = (Node*) malloc(sizeof(Node));
//    n1->data = 1; n1->next = n2;
//    n2->data = 2; n2->next = n3;
//    n3->data = 3; n3->next = n4;
//    n4->data = 4; n4->next = NULL;
   // kmp_match("abcdabds", "cda");
//    TreeNode *t1 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t2 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t3 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t4 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t5 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t6 = (TreeNode*) malloc(sizeof(TreeNode));
//    TreeNode *t7 = (TreeNode*) malloc(sizeof(TreeNode));
//    t1->data = 1; t2->data = 2; t3->data = 3; t4->data = 4; t5->data = 5; t6->data = 6; t7->data = 7;
//    t4->left = t2; t4->right = t6;
//    t2->left = t1; t2->right = t3; t6->left = t5; t6->right = t7;
   // cout << checkBST(t4);
    vector<int> t = {2,5,3,6};
    vector<vector<int>> g ={{1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 1},
                            {1, 1, 1, 0}};
//    int n;
//    cin >> n;
//    int num;
//    for (int i=0; i<n; i++) {
//        scanf("%d",&num);
//        t.push_back(num);
//    }
//    cout << get_biggest_region(g);
    
//    iceCream(t, 4);
    
    cout<< make_change(t,10);
    return 0;
}

//int main() {
//    int queries;
//    ifstream myfile ;
//    myfile.open("/Volumes/Apoorv/programming/HackerRank/CrackingCodingInterview/CrackingCodingInterview/input.txt");
//    if(myfile.is_open())
//        cout<<"open"<<endl;
//    myfile >> queries;
//
//    for (int t = 0; t < queries; t++) {
//
//        int n, m;
//        myfile >> n;
//        // Create a graph of size n where each edge weight is 6:
//        Graph graph(n);
//        myfile >> m;
//        // read and set edges
//        for (int i = 0; i < m; i++) {
//            int u, v;
//            myfile >> u >> v;
//            u--, v--;
//            // add each edge to the graph
//            graph.add_edge(u, v);
//        }
//        int startId;
//        myfile >> startId;
//        myfile.close();
//        startId--;
//        // Find shortest reach from node s
//        vector<int> distances = graph.shortest_reach(startId);
//
//        for (int i = 0; i < distances.size(); i++) {
//
//            if(i==startId) {
//                continue;
//            }
//            if(distances[i] == -1){
//                cout<<-1<< " ";
//            }
//            else{
//                cout<< 6*distances[i] << " ";
//            }
//
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

void median() {
    int n,a,sum;
    cin >> n;
    multiset<int>mn,mx;
    for(int i = 0;i<n;i++){
        cin >> a;
        mx.insert(a);
        if(mn.size()>0){
            if(mx.size()==mn.size()+1){
                int b=*(--mn.end());
                if(*mx.begin()<b){
                    mx.erase(mx.find(*mx.begin()));
                    mx.insert(b);
                    mn.erase(mn.find(b));
                    mn.insert(a);
                }
            }
            else{
                mn.insert(*mx.begin());
                mx.erase(mx.find(*mx.begin()));
            }
        }
        else{
            if(mx.size()>1){
                mn.insert(*mx.begin());
                mx.erase(mx.find(*mx.begin()));
            }
        }
        if(mn.size()+1==mx.size()||mn.size()==0){
            sum=*mx.begin();
            cout<<sum<<".0\n";
        }
        else{
            sum=*mx.begin()+*(--mn.end());
            cout<<sum/2;
            if(sum%2)cout<<".5\n";
            else cout<<".0\n";
        }
    }
}
