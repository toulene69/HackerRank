//
//  SolutionTrees.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 14/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionTrees.hpp"
#include <unordered_map>
#include <iostream>
#include <fstream>

#include <map>
#include <algorithm>
const int mod = 1e9 + 7;

const int maxn = 2e5 + 10;

vector<int> G[maxn];
vector<int> Q[maxn];
map<int, pair<int, int> > Node[maxn];
int dis[maxn];
int ans[maxn];

void update(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

void dfs(int u, int fa)
{
    for (int v : G[u])
    {
        if (v == fa)
            continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
    for (int v : Q[u])
        Node[u][v] = make_pair(u, 1ll * dis[u] * u % mod);
    for (int v : G[u])
    {
        if (Node[u].size() < Node[v].size())
            swap(Node[u], Node[v]);
        for (auto p : Node[v])
        {
            int i = p.first;
            auto it = Node[u].find(i);
            if (it == Node[u].end())
            {
                Node[u].insert(p);
                continue;
            }
            long long a = p.second.first, b = p.second.second, c = it->second.first, d = it->second.second;
            update(ans[i], (a * d % mod + b * c % mod + mod - (2 * dis[u] * a % mod * c % mod) % mod) % mod);
            update(it->second.first, a);
            update(it->second.second, b);
        }
    }
}

void kittyTreeSolution()
{
    ifstream myfile ;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
    if(myfile.is_open())
        cout<<"open"<<endl;
    
    int n, q;
    
    cin >> n;
    cin >> q;
    
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u;
        cin >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < q; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int u;
            cin >> u;
            Q[u].push_back(i);
        }
    }
    dfs(1, 0);
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    myfile.close();
}


class TreeSwap {
public:
    node *root;
    unordered_map<int, node*> dict;
    TreeSwap(){
        root = (node*)malloc(sizeof(node));
        root->data = 1;
        dict[1] = root;
    }
    void insert(int i, int l , int r){
        node *ln = NULL;
        node *rn = NULL;
        if (l != -1) {
            ln = (node*)malloc(sizeof(node));
            ln->data = l;
        }
        if (r != -1) {
            rn = (node*)malloc(sizeof(node));
            rn->data = r;
        }
        node *p = dict[i];
        if (p) {
            p->left = ln;
            p->right = rn;
        }
        dict[l] = ln;
        dict[r] = rn;
    }
    
    void inorder(node *root){
        if (!root) {
            return;
        }
        inorder(root->left);
        cout << root->data <<" ";
        inorder(root->right);
    }
    
    void swap(int k){
        queue<node*>q;
        q.push(root);
        int d = 1;
        while (!q.empty()) {
            queue<node*> t;
            while (!q.empty()) {
                node *n = q.front();
                q.pop();
                if (n->left) {
                    t.push(n->left);
                }
                if (n->right) {
                    t.push(n->right);
                }
                if (d%k ==0) {
                    node *temp = n->left;
                    n->left = n->right;
                    n->right = temp;
                }
            }
            d++;
            q = t;
        }
    }
};

void swapper_util()
{
    int n;
    int t;
    cin>>n;
    TreeSwap bt;
    for (int i=1; i<=n; i++)
    {
        int a, b;
        cin>>a; cin>>b;
        bt.insert(i, a, b);
    }
    cin>>t;
    for (int i = 0; i<t; i++) {
        int k;
        cin>>k;
        bt.swap(k);
        bt.inorder(bt.root);
    }
}

node *lca_util(node *root, int &v1, int &v2, int &c) {
    if (!root) {
        return root;
    }
    if (root->data == v1 && root->data == v2) {
        c = 2;
        return root;
    }
    
    node *l = lca_util(root->left, v1, v2, c);
    node *r = lca_util(root->right, v1, v2, c);
    if (l && r) {
        return root;
    }
    else if (l || r){
        if (root->data == v1 || root->data == v2) {
            c++;
            return root;
        }
        else {
            if (l) {
                return l;
            }
            else {
                return r;
            }
        }
    }
    else {
        if (root->data == v1 || root->data == v2) {
            c++;
            return root;
        }
        return NULL;
    }
}

node *lca(node *root, int v1,int v2)
{
    if (!root) {
        return NULL;
    }
    int c = 0;
    node *r = lca_util(root, v1, v2, c);
    if (c == 2) {
        return r;
    }
    else {
        return NULL;
    }
}

void decode_huff(node1 * root,string s)
{
    string res = "";
    node1 *t = root;
    int n=s.length();
    for(char x: s){
        if (x == '0') {
            t = t->left;
        }
        else {
            t = t->right;
        }
        if (t->data != '\0') {
            res.push_back(t->data);
            t = root;
        }
    }
    cout<<res;
}

node * insert(node * root, int value) {
    
    node *n = (node*)malloc(sizeof(node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    if (!root) {
        return n;
    }
    node *t = root;
    while (true) {
        if (t->data>value ) {
            if (t->left) {
                t = t->left;
            }
            else {
                break;
            }
        }
        else{
            if (t->right) {
                t = t->right;
            }
            else{
                break;
            }
        }
    }
    if (t->data>value ) {
        t->left = n;
    }
    else{
        t->right = n;
    }
    return root;
}

void preOrder(node *root) {
    if (!root) {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


//int height(Node* root) {
//    // Write your code here.
//    if (root) {
//        return -1;
//    }
////    if (root->left == NULL && root->right == NULL) {
////        return 0;
////    }
//    int l= height(root->left);
//    int r = height(root->right);
//    return max(l,r)+1;
//}

void left_side(node *root){
    if (!root) {
        return;
    }
    left_side(root->left);
    cout<<root->data<<" ";
}
void right_side(node *root) {
    if (!root) {
        return;
    }
    cout<<root->data<<" ";
    right_side(root->right);
}

void levelOrder(node * root) {
    queue<node*>q;
    vector<int>res;
    q.push(root);
    while (!q.empty()) {
        node* n = q.front();
        q.pop();
        res.push_back(n->data);
        if (n->left) {
            q.push(n->left);
        }
        if (n->right) {
            q.push(n->right);
        }
    }
    for(int x:res){
        cout<<x<<" ";
    }
}

int curmax = INT_MIN;
bool checkBST(node* root) {
    if (!root) {
        return true;
    }
    if (checkBST(root->left)) {
        if (curmax<root->data) {
            curmax = root->data;
        }
        else {
            return false;
        }
        return checkBST(root->right);
    }
    return false;
}
