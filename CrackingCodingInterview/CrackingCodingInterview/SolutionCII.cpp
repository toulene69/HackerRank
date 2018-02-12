//
//  SolutionCII.cpp
//  CrackingCodingInterview
//
//  Created by Apoorv on 22/01/18.
//  Copyright © 2018 presonal. All rights reserved.
//

#include "SolutionCII.hpp"

long long make_change(vector<int> coins, int money) {
    int m = coins.size();
    int n = money;
    sort(coins.begin(), coins.end());
    vector<vector<long long>> dp(m , vector<long long>(n+1,0));
    for (int i=0; i<m; i++) {
        dp[i][0] = 1;
    }
    for (int i=0; i<m; i++) {
        for (int j=1; j<=n; j++) {
            if (i==0) {
                if (coins[i]>j) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i][j-coins[i]];
                }
            }
            else {
                if (coins[i]>j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
                }
            }
        }
    }
    return dp[m-1][n];
}


int numWays(int n) {
    vector<int> dp(n+1,0);
    
    for (int i=1; i<=n; i++) {
        if(i==1){
            dp[i] = 1;
        }
        else if(i==2){
            dp[i] = 2;
        }
        else if(i==3){
            dp[i] = 4;
        }
        else {
            dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
        }
        
    }
    return dp[n];
}

void check_primality(int n){
    int sqt = sqrt(n)+1;
    for (int i=2; i<=sqt; i++) {
        if (n%i == 0){
            cout<<"Not prime"<<endl;
            return;
        }
    }
    cout<<"Prime"<<endl;
}

void check_primality(vector<int> nums) {
    
//    int maxN = *max_element(nums.begin(), nums.end());
//    vector<bool> b(maxN+1,true);
//    int sqt = sqrt(maxN);
//    b[0] = false;
//    b[1] = false;
//    for (int i=2; i<sqt; i++) {
//        if (b[i]) {
//            int k = 2;
//            while ((i*k)<=maxN) {
//                b[i*k] = false;
//                k++;
//            }
//        }
//    }
    for (int i=0; i<nums.size(); i++) {
        check_primality(nums[i]);
//        if (b[nums[i]]) {
//            cout<<"Prime"<<endl;
//        }
//        else {
//            cout<<"Not prime"<<endl;
//        }
    }
}

/**********************************************************************/
    Graph::    Graph(int n) {
        this->n = n;
        adj.resize(n, vector<int>());
    }
    
    void Graph:: add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> Graph:: shortest_reach(int start) {
        vector<int> visited(n,-1);
        queue<int> q;
        q.push(start);
        int level = 1;
        visited[start] = 0;
        while (!q.empty()) {
            queue<int> t;
            while(!q.empty()){
                int n = q.front();
                for(int x:adj[n]){
                    if (visited[x] == -1) {
                        visited[x] = level;
                        t.push(x);
                    }
                }
                q.pop();
            }
            q = t;
            level++;
        }
        return visited;
    }


vector<int> dirx = {1,0,-1,0,-1,-1,1,1};
vector<int> diry = {0,1,0,-1,1,-1,-1,1};

void dfs(vector<vector<int>> grid, vector<vector<bool>> &visited, int i, int j, int &m, int &n, int *count){
    if (i<0 || i>=m) {
        return;
    }
    if (j<0 || j>=n) {
        return;
    }
    if (grid[i][j] ==1 && !visited[i][j]) {
        (*count)++;
        visited[i][j] = true;
        for (int x = 0; x<8; x++) {
            dfs(grid, visited, i+dirx[x], j+diry[x], m, n, count);
        }
    }
}

int get_biggest_region(vector< vector<int> > grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited (m, vector<bool>(n,false));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int c = 0;
                
                dfs(grid, visited, i, j, m, n, &c);
                res = max(res, c);
            }
        }
    }
    return res;
}

void iceCream(vector <int> arr, int money) {
    // Complete this function
    unordered_map<int, int> dict;
    for (int i=0; i<arr.size(); i++) {
        if (dict.find(arr[i]) != dict.end()) {
            cout << dict[arr[i]]+1 << " " << i+1<<endl;
        }
        else {
            dict[money - arr[i]] = i;
        }
    }
}


int getSum(vector<int>& BITree, int index)
{
    int sum = 0; // Initialize result
    
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
        
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(vector<int>& BITree, int n, int index, int val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
        
        // Update index to that of parent in update View
        index += index & (-index);
    }
}

long countInversions(vector<int> arr) {
    
    long invcount = 0; // Initialize result
    int n = arr.size();
    // Find maximum element in arr[]
    vector<int> temp(arr.begin(),arr.end());
    
    sort(temp.begin(), temp.end());
    
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // lower_bound() Returns pointer to the first element
        // greater than or equal to arr[i]
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
    }
    
    // Create a BIT with size equal to maxElement+1 (Extra
    // one is used so that elements can be directly be
    // used as index)
    vector<int> BIT(n+1, 0);
    
    // Traverse all elements from right.
    for (int i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
        
        // Add current element to BIT
        updateBIT(BIT, n, arr[i], 1);
    }
    
    return invcount;
}


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


