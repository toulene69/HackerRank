//
//  SolutionDisjointSets.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 27/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionDisjointSets.hpp"
#include <fstream>

#define MOD 1000000007
#define s(a) scanf("%d",&a);

vector<int> edges[100009];
long long int visited[100009];
long long int  count1[100009];
long long int B[100009],C[100009],D[100009];

void dfs1(int x, int temp)
{
    if(visited[x] == 0)
        visited[x] = temp;
    for(int i = 0 ; i< edges[x].size() ; i++)
    {
        if(visited[edges[x][i]] == 0)
            dfs1(edges[x][i],temp);
    }
    return;
}


void kunduTree()
{
    int n,i,a,b;
    char c;
    s(n);
    for(i=0 ; i< n -1 ; i++)
    {
        s(a);
        s(b);
        cin>>c;
        if( c != 'r')
        {
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
    }
    int temp = 1;
    for(i=1 ; i<=n ; i++)
    {
        if(visited[i] == 0)
        {
            dfs1(i,temp);
            temp++;
        }
    }
    for(i=1 ; i<= n ; i++)
        count1[visited[i]]++;
    long long int sum = 0;
    B[n-1] = count1[n];
    for(i=n-2;i>=0;i--) B[i] = (B[i+1] + count1[i+1])%MOD;
    for(i=1;i<n-1;i++) C[i] = (count1[i+1]*B[i+1])%MOD;
    
    D[n-2] = C[n-2];
    for(i=n-3;i>=1;i--) D[i] = (D[i+1] + C[i])%MOD;
    
    for(i=0;i<n-2;i++) sum = (sum + count1[i+1]*D[i+1])%MOD;
    cout<< ( MOD + sum )%MOD<<endl;
}
/*
int get_parent(int i, vector<int>& parent)
{
    if (parent[i] == i) {
        return i;
    }
    else return parent[i] = get_parent(parent[i], parent);
}

void merge_commun(int a, int b, vector<int>&parent, vector<int>&size)
{
    int pa = get_parent(a, parent);
    int pb = get_parent(b, parent);
    if (pa == pb) {
        return;
    }
    if (size[pa]>=size[pb]) {
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    else {
        parent[pa] = pb;
        size[pb] += size[pa];
    }
}

void merge_communities()
{
    int n;
    cin>>n;
    vector<int>parent(n+1,-1);
    vector<int> size(n+1,1);
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    int q;
    cin>>q;
    while (q>0) {
        char op;
        cin>>op;
        if (op == 'M') {
            int a,b;
            cin>>a>>b;
            merge_commun(a,b,parent,size);
        }
        else {
            int a;
            cin>>a;
            cout<<size[get_parent(a, parent)];
        }
        q--;
    }
}

void connected_components()
{
    ifstream myfile ;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
    if(myfile.is_open())
        cout<<"open"<<endl;
    int n;
    myfile>>n;
    vector<int>parent(2*n+1,-1);
    vector<int> size(2*n+1,1);
    int small = INT_MAX;
    int large = 1;
    for (int i=1; i<=2*n; i++) {
        parent[i] = i;
    }
    int j=0;
    while (j<n) {
    
        int a,b;
        myfile>>a>>b;
        merge_commun(a,b,parent,size);
        j++;
    }
    for (int i=1; i<=2*n; i++) {
        int sz = size[get_parent(i, parent)];
        if (sz==1) {
            continue;
        }
        if (sz<small) {
            small = sz;
        }
        if (sz>large) {
            large = sz;
        }
    }
    cout<<small<<" "<<large;
    myfile.close();
}
*/
