//
//  SolutionStacks.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 22/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionStacks.hpp"
#include <fstream>

long gameOfTwoStacks(vector<int>a, vector<int>b, int x){
    long count = 0;
    int i=0, j=0;
    int m = a.size();
    int n = b.size();
    long s = 0;
    while (i<m && s+a[i]<=x) {
        s+=a[i];
        i++;
    }
    count = i;
    while (j<n && i>=0) {
        s+=b[j];
        j++;
        while (s>x && i>=0) {
            i--;
            s -= a[i];
        }
        if (s<=x && i+j>count) {
            count = i+j;
        }
    }
    
    return count;
}

int equalStacks(vector<int> v1, vector<int> v2, vector<int> v3)
{
    if (v1.size()==0 || v2.size() ==0 || v3.size()==0) {
        return 0;
    }
    vector<long> s1, s2, s3;
    s1.push_back(v1[v1.size()-1]);
    s2.push_back(v2[v2.size()-1]);
    s3.push_back(v3[v3.size()-1]);
    int i = 0;
    for ( i=v1.size()-2; i>=0; i--) {
        s1.push_back( v1[i]+s1.back());
    }
    for ( i=v2.size()-2; i>=0; i--) {
        s2.push_back( v2[i]+s2.back());
    }
    for ( i=v3.size()-2; i>=0; i--) {
        s3.push_back( v3[i]+s3.back());
    }
    while (!s1.empty() && !s2.empty() && !s3.empty()) {
        if (s1.back() == s2.back() && s2.back() == s3.back()) {
            return s1.back();
        }
        long m = max(s1.back(), max(s2.back(), s3.back()));
        while (s1.back() > s2.back() || s1.back() > s3.back()) {
            s1.pop_back();
            if (s1.empty())
            {
                return 0;
            }
        }
        while (s2.back() > s1.back() || s2.back() > s3.back()) {
            s2.pop_back();
            if (s2.empty()) {
                return 0;
            }
        }
        while (s3.back() > s2.back() || s3.back() > s2.back()) {
            s3.pop_back();
            if (s3.empty()) {
                return 0;
            }
        }
    }
    if (s1.empty() || s2.empty() || s3.empty()) {
        return 0;
    }
    return s1.back();
}

string isBalanced(string s) {
    // Complete this function
    stack<char> st;
    bool flag = true;
    for(char x: s){
        if (x=='(' || x == '{' || x=='[') {
            st.push(x);
        }
        else {
            if (st.empty()) {
                flag = false;
                break;
            }
            if (st.top() =='(' || st.top() == '{' || st.top()=='[') {
                if (x== ')' && st.top() == '(') {
                    st.pop();
                }
                else if (x== '}' && st.top() == '{') {
                    st.pop();
                }
                else if (x== ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
        }
    }
    if (flag && st.empty()) {
        return "YES";
    }
    return "NO";
}

void maximumElement()
{
    ifstream myfile ;
    myfile.open("/Volumes/Apoorv/programming/HackerRank/HackerRankDataStructures/HackerRankDataStructures/input.txt");
    if(myfile.is_open())
        cout<<"open"<<endl;
    stack<int> s;
    stack<int> max_s;
    int n;
    myfile>>n;
    for (int i=0; i<n; i++) {
        int o;
        myfile>>o;
        switch (o) {
            case 1:
                int n;
                myfile>>n;
                if (s.empty() || n>=max_s.top()) {
                    max_s.push(n);
                }
                s.push(n);
                break;
            case 2:
                if (s.top() == max_s.top()) {
                    max_s.pop();
                }
                s.pop();
                break;
            case 3:
                cout<<max_s.top()<<endl;
                break;
            default:
                break;
        }
    }
}
