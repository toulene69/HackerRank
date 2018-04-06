//
//  FenwickTree.cpp
//  HackerRankAlgorithms
//
//  Created by Apoorv on 04/04/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "FenwickTree.hpp"
#include <iostream>

#define MAXN 100002
#define MAX 1000002
int n,a[MAXN],c[MAX] ;

class FenwickTree{
private:
    vector<int>tree;
    
public:
    FenwickTree(vector<int>a){
        tree = vector<int>(a.size()+1, 0);
        for(int i=0; i<a.size(); i++) {
            tree[i+1] = a[i];
        }
        
        for (int i =1; i<tree.size(); i++) {
            int idx2 = i + (i & -i);
            if (idx2 < tree.size()) {
                tree[idx2] += tree[i];
            }
        }
    }
    
    long prefixSum(int i){
        long s = 0;
        i++;
        while (i>0) {
            s+= tree[i];
            i = i - (i & (-i));
        }
        return s;
    }
    
    long rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l);
    }
    
    void updateTree(int i, int k) {
        i++;
        while (i<tree.size()) {
            tree[i] += k;
            i = i + (i & (-i));
        }
    }
};

void merge(vector<int>&a, long l, long m, long r, long long &count) {
    vector<int> t(r-l+1, 0);
    long i = l, j = m+1, x = 0;
    while (i<=m && j<=r ) {
        if (a[i] <= a[j]) {
            t[x++] = a[i++];
        }
        else {
            count +=  (m-i+1);
            t[x++] = a[j++];
        }
    }
    while (i<=m) {
        t[x++] = a[i++];
    }
    while (j<=r) {
        t[x++] = a[j++];
    }
    for (long i = l, id =0 ; i<=r; i++) {
        a[i] = t[id++];
    }
}

void merge_sort(vector<int> &a, long l, long r, long long &count) {
    if (l>=r) {
        return;
    }
    long m = l + ((r-l)>>1);
    merge_sort(a, l, m, count);
    merge_sort(a, m+1, r, count);
    merge(a,l,m,r,count);
}

long insertionSort(vector <int> &arr) {
    // Complete this function
    long long count = 0;
    int runs ;
    scanf("%d",&runs) ;
    while(runs--)
    {
        scanf("%d",&n) ;
        for(int i = 0;i < n;i++) scanf("%d",&a[i]) ;
        long long ret = 1LL * n * (n - 1) / 2 ;
        memset(c,0,sizeof c) ;
        for(int i = 0;i < n;i++)
        {
            for(int j = a[i];j > 0;j -= j & -j)
            {
                ret -= c[j] ;
            }
            for(int j = a[i];j < MAX;j += j & -j)
            {
                c[j]++ ;
            }
        }
        cout << ret << endl ;
    }
    return count;
}

void fenwick()
{
    std::vector<int> array{ 1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5 };
    FenwickTree bit(array);
    std::cout << "Array: ";
    for (int val : array) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;
    
    std::cout << "Prefix sum of first 13 elements: " << bit.prefixSum(12) << std::endl;
    std::cout << "Prefix sum of first 7 elements: " << bit.prefixSum(6) << std::endl;
    std::cout << "Range sum from pos 1 to pos 5: " << bit.rangeSum(1, 5) << std::endl;
    std::cout << std::endl;
    
    bit.updateTree(4, 2);
    std::cout << "Add 2 to element at pos 4" << std::endl;
    std::vector<int> new_array;
    for (int idx = 0; idx < array.size(); idx++) {
        new_array.push_back(bit.rangeSum(idx, idx));
    }
    std::cout << "Array: ";
    for (int val : array) {
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;
    
    std::cout << "Prefix sum of first 13 elements: " << bit.prefixSum(12) << std::endl;
    std::cout << "Prefix sum of first 7 elements: " << bit.prefixSum(6) << std::endl;
    std::cout << "Range sum from pos 1 to pos 5: " << bit.rangeSum(1, 5) << std::endl;
    std::cout << std::endl;
}
