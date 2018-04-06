//
//  SolutionStrings.cpp
//  HackerRankAlgorithms
//
//  Created by Apoorv on 15/03/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionStrings.hpp"

string super_reduced_string(string s){
    string str = "";
    for (char x: s) {
        if (str.back() == x) {
            str.pop_back();
        }
        else {
            str.push_back(x);
        }
    }
    return str.length() ==0 ? "Empty String" : str;
}

int camelcase(string s) {
    // Complete this function
    int count = 1;
    for(char x: s)
    {
        if (x>=65 && x<= 91) {
            count++;
        }
    }
    return count;
}

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int count = 0;
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    int found = 0;
    int all = (1<<4)-1;
    for(char x: password)
    {
        if (numbers.find(x) != -1) {
            found |= 1<<0;
        }
        else if (lower_case.find(x) != -1) {
            found |= 1<<1;
        }
        else if (upper_case.find(x) != -1) {
            found |= 1<<2;
        }
        else if (special_characters.find(x) != -1) {
            found |= 1<<3;
        }
        
    }
    if (n>=6 && (all == found)) {
        return  count;
    }
    if (!(found & 1)) {
        count++;
    }
    if (!(found & 1<<1)) {
        count++;
    }
    if (!(found & 1<<2)) {
        count++;
    }
    if (!(found & 1<<3)) {
        count++;
    }
    if ((n+count)>=6) {
        return count;
    }
    else {
        return (count + (6-count-n));
    }
    return count;
}

string caesarCipher(string s, int k) {
    k = k%26;
    for (int i=0; i<s.length(); i++) {
        if (s[i]>=97 && s[i]<=122) {
            s[i] = (s[i] + k)>122 ? 97 + (s[i] + k)%123 : s[i] + k;
        }
        else if (s[i]>=65 && s[i]<=90) {
            s[i] = (s[i] + k) > 90 ? 65 + (s[i] + k) %91 : s[i] + k;
        }
        else {
            
        }
    }
    return s;
}

int marsExploration(string s) {
    int count = 0;
    int i = 0;
    while (i<s.length()) {
        if (s[i] != 'S'){
            count ++;
        }
        if ( s[i+1] != 'O') {
            count++;
        }
        if (s[i+2] != 'S') {
            count++;
        }
        i+= 3;
    }
    return count;
}

string hackerrankInString(string s) {
    string p = "hackerrank";
    int j=0;
    for (char x: s) {
        if (x == p[j]) {
            j++;
        }
    }
    if (j == p.length()) {
        return "YES";
    }
    return "NO";
}

string pangram(string s) {
    set<char> d;
    for (char x : s) {
        if (x>=65 && x<=90) {
            d.insert(x);
        }
        else if(x>=97 && x<=122 ) {
            d.insert(x-32);
        }
        else {
            
        }
    }
    if (d.size() == 26) {
        return "pangram";
    }
    return "not pangram";
}

void weightedStrings() {
    set<long> d;
    string s;
    cin >> s;
    int i = 0;
    int l = s.length();
    char last = '0';
    long lastVal = 0;
    while (i<l) {
        if (s[i] == last) {
            lastVal += (s[i]-96);
        }
        else {
            last = s[i];
            lastVal = s[i]-96;
        }
        d.insert(lastVal);
        i ++;
    }
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if (d.find(x) != d.end()) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}

bool isPalindrome(string &s, int i, int j) {
    while (i<j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++; j--;
    }
    return true;
}

int palindromeIndex(string s){
    // Complete this function
    int i = 0, j = s.length()-1;
    while (i<j && s[i] == s[j]) {
        i++; j--;
    }
    if (i<j) {
        if (isPalindrome(s, i, j-1)) {
            return j;
        }
        else {
            return i;
        }
    }
    return -1;
}

int anagram(string s){
    int n = s.length();
    if (n&1 || n==0) {
        return -1;
    }
    vector<int> aplhabets1(26, 0);
    vector<int> aplhabets2(26, 0);
    int i=0, j = n/2;
    while (i<j) {
        aplhabets1[ s[i++] - 'a']++;
    }
    while (j<n) {
       aplhabets2[ s[j++] - 'a']++;
    }
    int t = 0;
    for (int x = 0; x<26; x++) {
        t+= abs(aplhabets1[x] - aplhabets2[x]);
    }
    return t/2;
}

int makingAnagrams(string s1, string s2){
    // Complete this function
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 == 0 ) {
        return n2;
    }
    if (n2 == 0 ) {
        return n1;
    }
    vector<int> aplhabets1(26, 0);
    vector<int> aplhabets2(26, 0);
    int i=0, j = 0;
    while (i<n1) {
        aplhabets1[ s1[i++] - 'a']++;
    }
    while (j<n2) {
        aplhabets2[ s2[j++] - 'a']++;
    }
    int t = 0;
    for (int x = 0; x<26; x++) {
        t+= abs(aplhabets1[x] - aplhabets2[x]);
    }
    return t;
}

string gameOfThrones(string s){
    int n = s.length();
    
    if (n <= 1 ) {
        return "YES";
    }
    vector<int> aplhabets(26, 0);
    for(char x: s) {
        aplhabets[x - 'a']++;
    }
    bool foundOdd = false;
    for (int i=0; i<26; i++) {
        if (aplhabets[i]&1) {
            if (foundOdd) {
                return "NO";
            }
            foundOdd = true;
        }
    }
    return "YES";
}

string twoStrings(string s1, string s2){
    vector<bool> d(26, false);
    for (char x: s1) {
        d[x - 'a'] = true;
    }
    for (char x: s2) {
        if(d[x - 'a'])
            return "YES";
    }
    return "NO";
}
