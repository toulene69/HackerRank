//
//  SolutionStacks.cpp
//  HackerRankDataStructures
//
//  Created by Apoorv on 22/02/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionStacks.hpp"
#include <fstream>
#include <math.h>

void andOr()
{
    vector <long int> v;
    stack <long int> s;
    long int temp,i,n;
    long long max_xor=0,min_xor;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    for(i=0;i<n;i++)
    {
        while(!s.empty())
        {
            min_xor=v[i]^s.top();
            if(min_xor>max_xor)
                max_xor=min_xor;
            if(v[i]<s.top())
                s.pop();
            else
                break;
        }
        s.push(v[i]);
    }
    cout<<max_xor<<endl;
}

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            // We are naive, but not stupid, if
            // the number has a divisor other
            // than 1 or itself, we return immediately.
            return false;
        }
    }
    return true;
}
int nthPrime(int n) {
    int candidate, count;
    for(candidate = 2, count = 0; count < n; ++candidate) {
        if (isPrime(candidate)) {
            ++count;
        }
    }
    // The candidate has been incremented once after the count reached n
    return candidate-1;
}

void waiter_problem(vector<int>n, int q){
    vector<vector<int>> p;
    vector<int>preA = n;
    
    for (int i=1; i<=q; i++) {
        if (preA.size()==0) {
            break;
        }
        vector<int>ai;
        vector<int>b;
        int prime = nthPrime(i);
        for (int j=preA.size()-1; j>=0; j--) {
            if (preA[j]%prime == 0) {
                b.push_back(preA[j]);
            }
            else{
                ai.push_back(preA[j]);
            }
        }
        preA = ai;
        p.push_back(b);
    }
    if (preA.size() != 0) {
        p.push_back(preA);
    }
    for (vector<int>b : p) {
        for (int j=b.size()-1; j>=0; j--) {
            cout<<b[j]<<endl;
        }
    }
}

typedef struct Operation{
    int type;
    string append;
    int len;
    Operation(int t=0, string s="", int k=0):type(t),append(s),len(k){}
}Operation;

class TextEditor
{
private:
    string str;
    stack<Operation> ops;
public:
    TextEditor(){}
    
    void append(string w) {
        Operation op(1,w,0);
        ops.push(op);
        str += w;
    }
    
    void delet(int k){
        string sub = str.substr(str.length()-k,k);
        Operation op(2,sub,k);
        ops.push(op);
        while (k>0) {
            str.pop_back();
            k--;
        }
    }
    
    void print_k(int k){
        cout<<str[k-1]<<endl;
    }
    
    void undo() {
        Operation op = ops.top();
        ops.pop();
        switch (op.type) {
            case 1:
            {
                int l = op.append.length();
                while (l>0) {
                    str.pop_back();
                    l--;
                }
                break;
            }
            case 2:
            {
                str += op.append;
                break;
            }
            default:
                break;
        }
    }
};

void texteditor ()
{
    TextEditor txt;
    int q;
    cin>>q;
    while (q>0) {
        int t;
        cin>>t;
        if (t==1) {
            string s;
            cin>>s;
            txt.append(s);
        }
        else if (t==2) {
            int x;
            cin>>x;
            txt.delet(x);
        }
        else if (t==3) {
            int x;
            cin>>x;
            txt.print_k(x);
        }
        else {
            txt.undo();
        }
        q--;
    }
}

long largestRectangle(vector <int> h) {
    stack<int>s;
    long max_area = 0;
    long area_with_top = 0;
    int n = h.size();
    int i=0;
    while (i<n) {
        if (s.empty() || h[i]>=h[s.top()]) {
            s.push(i++);
        }
        else {
            int tp = s.top();
            s.pop();
            area_with_top = h[tp] * (s.empty()?i: i- s.top()-1);
            if (max_area<area_with_top) {
                max_area = area_with_top;
            }
        }
    }
    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        area_with_top = h[tp] * (s.empty()?i: i- s.top()-1);
        if (max_area<area_with_top) {
            max_area = area_with_top;
        }
    }
    return max_area;
}

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
