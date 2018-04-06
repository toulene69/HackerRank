//
//  SolutionSorting.cpp
//  HackerRankAlgorithms
//
//  Created by Apoorv on 03/04/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionSorting.hpp"
#include <algorithm>


int partition_util ( vector<int> &A,int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
        /*rearrange the array by putting elements which are less than pivot
         on one side and which are greater that on other. */
        
        if ( A[ j ] < piv) {
            swap (A[ i ],A [ j ]);
            i += 1;
        }
    }
    swap ( A[ start ] ,A[ i-1 ] ) ;  //put the pivot element in its proper place.
    return i-1;                      //return the position of the pivot
}

int parti (vector<int> &arr, int l, int r){
    int p = arr[l];
    int i = l+1;
    for(int j= l+1; j<=r; j++){
        if (arr[j]<p) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[l], arr[i-1]);
    return i-1;
}

int median_util(vector<int>arr, int l, int r){
    if(l==r){
        return arr[l];
    }
    int p = parti(arr, l, r);
    if(p == arr.size()/2)
        return arr[p];
    else if(p< arr.size()/2) {
        return median_util(arr,p+1, r);
    }
    else {
        return median_util(arr,l, p-1);
    }
}

int findMedian(vector <int> arr) {
    // Complete this function
    return median_util(arr, 0, arr.size()-1);
    sort(arr.begin(), arr.end());
    return arr[arr.size()/2];
}

int activityNotifications(vector <int> expenditure, int d) {
    vector<int> expenses (201, 0);
    int res = 0;
    int n = expenditure.size();
    for (int i=0; i<d; i++) {
        expenses[expenditure[i]]++;
    }
    for (int i = d; i<n; i++) {
        vector<int> prefix (201, 0);
        prefix[0] = expenses[0];
        long median = 0.0;
        if (d&1) {
            int count = 0;
            int m = (d>>1) + 1;
            for (int x=0; x<201; x++) {
                count += expenses[x];
                if (count>=m) {
                    median = 2*x;
                    break;
                }
            }
        }
        else {
            int count = 0, a =-1 , b =-1;
            int f = (d>>1);
            int s = (d>>1) + 1;
            for (int x=0; x<201; x++) {
                count += expenses[x];
                if (count>=f && a == -1) {
                    a = x;
                }
                if (count >= s && b == -1) {
                    b = x;
                    break;
                }
            }
            median = (a + b );
        }
        if (expenditure[i] >= median) {
            res ++;
        }
        expenses[expenditure[i-d]]--; expenses[expenditure[i]]++;
    }
    return res;
}


int lilysHomework(vector <int> arr) {
    int res = 0;
    unordered_map<int, int> d;
    vector<int> t (arr.begin(), arr.end());
    sort(t.begin(), t.end());
    for (int i=0; i<arr.size(); i++) {
        d.insert(make_pair(arr[i], i));
    }
    for (int i =0 ; i<arr.size(); i++) {
        if (arr[i] != t[i]) {
            res++;
            d[arr[i]] = d[t[i]];
            swap(arr[i], arr[d[t[i]]]);
        }
    }
    return res;
}

int util(vector<int> arr) {
    int asc = lilysHomework(arr);
    reverse(arr.begin(), arr.end());
    int desc = lilysHomework(arr);
    return min(asc, desc);
}
