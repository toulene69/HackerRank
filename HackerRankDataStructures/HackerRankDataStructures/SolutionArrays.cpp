//
//  SolutionArrays.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 12/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionArrays.hpp"

void max_num()
{
    
    int n,m;
    
    cin>>n>>m;
    vector<int>arr(n,0);
    while (m>0) {
        int a,b,k;
        cin>>a; cin>>b; cin>>k;
        arr[a-1] += k;
        arr[b] -= k;
        m--;
    }
    long long s = 0, res = INT_MIN;
    for (int i=0; i<n; i++) {
        s += arr[i];
        res = max(res, s);
    }
    cout<<res;
}

vector <int> leftRotation(vector <int> a, int d) {
    int n = a.size();
    if (d==0 || d== n) {
        return a;
    }
    if (n==0 || n==1) {
        return a;
    }
    for (int i=0; i<n; i++) {
        int curI = i;
        int newI = (curI - d) < 0 ? ((curI - d)+n)%n : (curI - d)%n ;
        int temp = a[curI];
        int temp2;
        while (a[newI]>0) {
            temp2 = a[newI];
            a[newI] = -temp;
            temp = temp2;
            curI = newI;
            if (newI == i) {
                break;
            }
            newI = (newI - d) < 0 ? ((newI - d)+n)%n : (newI - d)%n ;
        }
    }
    for (int i=0; i<n; i++) {
        if (a[i]<0) {
            a[i] = -a[i];
        }
    }
    return a;
}

int hourGlassMaxSum(vector<vector<int>> arr) {
    int m = arr.size();
    int n = arr[0].size();
    int mSum = INT_MIN;
    for (int i=2; i<m; i++) {
        for (int j = 2; j<n; j++) {
            mSum = max(mSum, (arr[i-2][j-2] + arr[i-2][j-1] + arr[i-2][j] + arr[i-1][j-1] + arr[i][j-2] + arr[i][j-1] + arr[i][j]));
        }
    }
    return mSum;
}

void dynamicArray() {
    int N,q;
    cin>>N;
    cin>>q;
    vector<vector <int>> arr(N, vector<int>());
    int lastAns = 0;
    while (q>0) {
        int op,x,y;
        cin>>op; cin>>x; cin>>y;
        int i = (x^lastAns)%N;
        if (op==1) {
            arr[i].push_back(y);
        }
        else {
            int v = y%arr[i].size();
            lastAns = arr[i][v];
            cout<<endl<<lastAns;
        }
        q--;
    }
}
