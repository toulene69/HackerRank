//
//  SolutionCII.cpp
//  CrackingCodingInterview
//
//  Created by Apoorv on 22/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionCII.hpp"

Contact::Contact(){
    root = new Trie;
}

Contact::~Contact(){
    free(root);
}

void Contact::add_contact(string contact){
    Trie *node = root;
    for(char x : contact) {
        if (node->child.find(x) == node->child.end()) {
            node->child[x] = new Trie;
        }
        node = node->child[x];
        node->count++;
    }
}

int Contact::find_partial(string partial){
    Trie *node = root;
    for(char x: partial) {
        if (node->child.find(x) == node->child.end()) {
            return 0;
        }
        node = node->child[x];
    }
    return node->count;
}

void contact_search() {
    Contact c;
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            c.add_contact(contact);
        }
        else {
            cout << c.find_partial(contact) <<endl;
        }
    }
}

void running_median() {
    int n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    double median = 0.0;
    int num;
    cin>>n;
    while (n>0) {
        cin>>num;
        if (minHeap.size() < maxHeap.size()) {
            if (num<median) {
                int left_max = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(left_max);
            }
            else {
                minHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top() )/2.0;
        }
        else if (minHeap.size() == maxHeap.size()) {
            if (num < median) {
                maxHeap.push(num);
                median = maxHeap.top();
            }
            else {
                minHeap.push(num);
                median = minHeap.top();
            }
        }
        else {
            if (num<median) {
                maxHeap.push(num);
            }
            else {
                int right_min = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(right_min);
            }
            median = (double)(maxHeap.top() + minHeap.top() )/(double)2;
        }
        cout <<setiosflags(ios::fixed) << setprecision(1)<<median<<endl;
        n--;
    }
}

bool checkBST_util(TreeNode *node, int min, int max, vector<int> &inorder) {
    if (!node) {
        return true;
    }
    if (node->data < min || node->data > max) {
        return false;
    }
    if(node->left && node->left->data == node->data)
        return false;
    if(node->right && node->right->data == node->data)
        return false;
    bool l = checkBST_util(node->left,min,node->data-1, inorder);
    inorder.push_back(node->data);
    bool r =checkBST_util(node->right,node->data-1,max, inorder);
    return l&&r;
}


int last_val = INT_MIN;
bool checkBST(TreeNode* root) {
    if (!root) {
        return true;
    }
    if (!checkBST(root->left)) {
        return false;
    }
    if (last_val != INT_MIN && root->data <= last_val) {
        return false;
    }
    last_val = root->data;
    return checkBST(root->right);
}

void MyQueue:: push(int x) {
    this->stack_newest_on_top.push(x);
}
    
void MyQueue:: pop() {
    if (!this->stack_oldest_on_top.empty()) {
        this->stack_oldest_on_top.pop();
    }
    else {
        while (!this->stack_newest_on_top.empty()) {
            this->stack_oldest_on_top.push(this->stack_newest_on_top.top());
            this->stack_newest_on_top.pop();
        }
        this->stack_oldest_on_top.pop();
    }
}
    
int MyQueue::  front() {
    if (!this->stack_oldest_on_top.empty()) {
        return this->stack_oldest_on_top.top();
    }
    else {
        while (!this->stack_newest_on_top.empty()) {
            this->stack_oldest_on_top.push(this->stack_newest_on_top.top());
            this->stack_newest_on_top.pop();
        }
        return this->stack_oldest_on_top.top();
    }
}

bool is_balanced(string expression) {
    stack<char> s;
    for(char x: expression) {
        if(s.empty()){
            s.push(x);
        }
        else {
            if (x == '(' || x== '{' || x== '[') {
                s.push(x);
            }
            else {
                char t = s.top();
                switch (x) {
                    case ')':
                        if (t == '(') {
                            s.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    case '}':
                        if (t == '{') {
                            s.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    case ']':
                        if (t == '[') {
                            s.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    default:
                        return false;
                        break;
                }
            }
        }
    }
    if (s.empty()) {
        return true;
    }
    return false;
}

bool has_cycle(Node* head) {
    Node *slow,*fast;
    slow = head;
    fast = head->next;
    while (slow != NULL && fast->next != NULL ) {
        if (slow==fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> dict;
    for (string x : magazine) {
        if (dict[x] == 0) {
            dict[x] = 1;
        }
        else {
            dict[x]++;
        }
    }
    for (string x : ransom) {
        if (dict[x] == 0) {
            return false;
        }
        else {
            dict[x]--;
        }
    }
    return true;
}

int number_needed(string a, string b) {
    int m = a.length();
    int n = b.length();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0,j=0,c=0;
    while (i<m && j<n) {
        if (a[i]==b[j]) {
            i++;j++;
        }
        else if (a[i]<b[j]) {
            c++;i++;
        }
        else {
            c++;j++;
        }
    }
    if (i<m) {
        c+= (m-i);
    }
    if (j<n) {
        c += (n-j);
    }
    return c;
}

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    if (k==0) {
        return a;
    }
    int shifts = k;
    if (shifts % n == 0) {
        return a;
    }
    if (shifts>n) {
        shifts = shifts % n;
    }
    deque<int> dq (a.begin(),a.end());
    while (shifts>0) {
        int t = dq.front();
        dq.pop_front();
        dq.push_back(t);
        shifts--;
    }
    vector<int> res (dq.begin(),dq.end());
    return res;
}


