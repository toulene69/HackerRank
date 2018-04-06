//
//  main.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 12/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include <iostream>
#include "SolutionArrays.hpp"
#include "SolutionTrees.hpp"
#include "SolutionStacks.hpp"
#include "SolutionsHeap.hpp"
#include "SolutionDisjointSets.hpp"
#include "Treap.hpp"
#include <fstream>

void gameOfStack()
{
    ifstream myfile ;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
    if(myfile.is_open())
        cout<<"open"<<endl;
    int g;
    myfile >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        myfile >> n >> m >> x;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
            myfile >> a[a_i];
        }
        vector<int> b(m);
        for(int b_i = 0; b_i < m; b_i++){
            myfile >> b[b_i];
        }
        cout<< gameOfTwoStacks(a,b,x)<<endl;
        // your code goes here
    }
    myfile.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<int> v = {1,2,3,4,5,6,7,8,9};
//    vector<int>r = leftRotation(v, 8);
//    node* n1 = (node*)malloc(sizeof(node)); n1->left = NULL; n1->right = NULL;
//    node* n2 = (node*)malloc(sizeof(node)); n2->left = NULL; n2->right = NULL;
//    node* n3 = (node*)malloc(sizeof(node)); n3->left = NULL; n3->right = NULL;
//    node* n4 = (node*)malloc(sizeof(node)); n4->left = NULL; n4->right = NULL;
//    node* n5 = (node*)malloc(sizeof(node)); n5->left = NULL; n5->right = NULL;
//    node* n6 = (node*)malloc(sizeof(node)); n6->left = NULL; n6->right = NULL;
//    node* n7 = (node*)malloc(sizeof(node)); n7->left = NULL; n7->right = NULL;
//
//    n1->data = 1; n2->data = 2; n3->data = 3; n4->data = 4; n5->data = 5; n6->data = 6; n7->data = 7;
//    n4->left = n2; n4->right = n7;
//    n2->left = n1; n2->right = n3;
//    n7->left = n5; //n7->right = n6;
    //cout<< lca(n4, 2, 1)->data;
    //swapper_util();
    //kittyTreeSolution();
    //cout << checkBST(n4);
    //max_num();
//    ifstream myfile ;
//    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
//    if(myfile.is_open())
//        cout<<"open"<<endl;
    vector<int> v1 = {3, 3, 4, 4, 9};
    vector<int> v2 = {2, 1, 8, 5};
    vector<int> v3 = {1, 1, 4, 1};
    
    driver();
//    myfile.close();
    return 0;
}

