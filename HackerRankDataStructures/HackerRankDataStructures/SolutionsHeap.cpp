//
//  SolutionsHeap.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 27/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionsHeap.hpp"
#include <fstream>

void sweet_cookie()
{
    ifstream myfile ;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
    if(myfile.is_open())
        cout<<"open"<<endl;
    int n,k;
    myfile>>n >> k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int i=0;
    while (i<n) {
        int x;
        myfile>>x; minHeap.push(x);
        i++;
    }
    long count=0;
    while (minHeap.size()>1 && minHeap.top()<k) {
        int t = minHeap.top();
        minHeap.pop();
        t = t + 2*minHeap.top();
        minHeap.pop();
        minHeap.push(t);
        count++;
    }
    if (minHeap.top()<k) {
        cout << -1<<endl;
    }
    else{
        cout<<count<<endl;
    }
    myfile.close();
}

class MinHeap
{
private:
    vector<long> h;
    unordered_map<int, int> m;
public:
    MinHeap(){
        h.push_back(INT_MIN);
    }
    
    void insert(int e) {
        h.push_back(e);
        int i = h.size()-1;
        m[e] = i;
        while (i/2>=1 && h[i/2] > h[i]) {
            m[h[i/2]] = i;
            m[h[i]] = i/2;
            h[i/2] = h[i/2] ^ h[i];
            h[i] = h[i/2]^h[i];
            h[i/2] = h[i/2]^h[i];
            i = i/2;
        }
    }
    
    void remove(int e) {
        unordered_map<int, int>::iterator it = m.find(e);
        int i = it->second;
        m.erase(it);
        int n = h.size();
        h[i] = INT_MIN;
        while (i/2>=1 && h[i/2] > h[i]) {
            m[h[i/2]] = i;
            m[h[i]] = i/2;
            h[i/2] = h[i/2] ^ h[i];
            h[i] = h[i/2]^h[i];
            h[i/2] = h[i/2]^h[i];
            i = i/2;
        }
        h[1] = h[n-1];
        h.pop_back();
        n--; i =1;
        while (i*2 <n) {
            int id;
            if (i*2+1 <n) {
                id = h[i*2] <= h[2*i+1] ? i*2 : i*2+1 ;
            }
            else {
                if (h[i] > h[2*i]) {
                    id = 2*i;
                }
                else {
                    break;
                }
            }
            m[h[i]] = id;
            m[h[id]] = i;
            int temp = h[id];
            h[id] = h[i];
            h[i] = temp;
            i = id;
        }
    }
    
    int minimum() {
        if (h.size()==1) {
            return -1;
        }
        return h[1];
    }
};

void heap_util()
{
    ifstream myfile ;
        myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
        if(myfile.is_open())
            cout<<"open"<<endl;
    int n;
    myfile>>n;
    MinHeap h;
    while (n>0) {
        int op;
        myfile>>op;
        switch (op) {
            case 1:
            {
                int v;
                myfile>>v;
                h.insert(v);
                break;
            }
            case 2:
            {
                int v;
                myfile>>v;
                h.remove(v);
                break;
            }
            case 3:
            {
                cout<<h.minimum()<<endl;
                break;
            }
            default:
                break;
        }
        n--;
    }
    myfile.close();
}
