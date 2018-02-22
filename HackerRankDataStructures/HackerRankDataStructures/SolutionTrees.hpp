//
//  SolutionTrees.hpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 14/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#ifndef SolutionTrees_hpp
#define SolutionTrees_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>



typedef struct node1
{
    int freq;
    char data;
    node1 * left;
    node1 * right;
    
}node1;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

struct node
{
    int data;
    node* left;
    node* right;
};

void kittyTreeSolution();
bool checkBST(node* root) ;
void swapper_util();
node *lca(node *root, int v1,int v2);

using namespace std;
#include <stdio.h>

#endif /* SolutionTrees_hpp */
