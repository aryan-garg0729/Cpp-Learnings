#include <iostream>
#include <climits>
#include <math.h>
#include<string.h>
using namespace std;
// --------------------Fibonacci number---------------------
//Traditional method(Brute Force)
int fibo(int n) { // TC = O(2^n)
	if(n <= 1) {
		return n;
	}
	int a = fibo(n - 1);
	int b = fibo(n - 2);
	return a + b;
}

//memorisation technique: generally recursive(top-down approach)
int fibo_helper(int n, int *ans) { // TC = O(n)
	if(n <= 1) {
		return n;
	}

	// Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// Calculate output
	int a = fibo_helper(n-1, ans);
	int b = fibo_helper(n-2, ans);

	// Save the output for future use
	ans[n] = a + b;
	
	// Return the final output
	return ans[n];
}
int fibo_2(int n) {
	int *ans = new int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	return fibo_helper(n, ans);
}

//Dynamic programming *best*: generally iterative(bottom-up approach)
int fibo_3(int n){ // TC = O(n), it is better than fibo_2 as in rec space comp increases slightly
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2;i<n+1;i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}


// --------------------count Min Steps To One---------------------
int countMinStepsToOne(int n){ //brute force O(exponential)
	if(n==1){
        return 0;
    }

    int count = 0;
    int a = countMinStepsToOne(n-1)+1;
    int b = INT_MAX;
    int c = INT_MAX;
    if(n%3==0){
        b = countMinStepsToOne(n/3)+1;
    }
    
    if(n%2==0){
        c = countMinStepsToOne(n/2)+1;
    }
    
    return min(min(a,b),c);
    
}

int countMinStepsToOne_hepler(int n,int*ans){  //memorisation (O(n))
    if(n<=1){
        return 0;
    }

    // Check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }

    // Calculate output
    int count = 0;
    int a = countMinStepsToOne_hepler(n-1,ans)+1;
    int b = INT_MAX;
    int c = INT_MAX;
    if(n%3==0){
        b = countMinStepsToOne_hepler(n/3,ans)+1;
    }
    if(n%2==0){
        c = countMinStepsToOne_hepler(n/2,ans)+1;
    }
    
    // Save the output for future use
    ans[n] = min(min(a,b),c);

    // Return the final output
    return ans[n];

}
int countMinStepsToOne_2(int n) {
	int *ans = new int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	return countMinStepsToOne_hepler(n, ans);
}

int countMinStepsToOne_3(int n) { //DP (O(n))  *best*
	int ans[n+1];
    ans[0] = 0;
    ans[1] = 0;
	for(int i = 2; i <= n; i++) {
		int a = 1+ans[i-1];
        int b = INT16_MAX , c = INT16_MAX;
        if(i%2==0){
            b = 1+ans[i/2];
        }
        if(i%3==0){
            c = 1+ans[i/3];
        }
        ans[i] = min(min(a,b),c);
	}
	
	return ans[n];
}



// -----------------no of possible ways to climb staircase------------
int staircase(int n){// brute force
    if(n<0){
        return 0;
    }
    if(n<=1){
        return 1;
    }
    int count = 0;
    count+=staircase(n-1);
    count+=staircase(n-2);
    count+=staircase(n-3);
    return count;
}

long int staircase_(int n,long int*ans){
    if(n<0){
        return 0;
    }
    if(n<=1){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    long int count = 0;
    count+=staircase_(n-1,ans);
    count+=staircase_(n-2,ans);
    count+=staircase_(n-3,ans);
    ans[n] = count%1000000007;
    return ans[n];
}
long int staircase_2(int n){  // memorisation
    long int *ans = new long int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	return staircase_(n, ans);
}

long int staircase_3(int n){ //DP
    long int ans[n+1];
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2;i<n+1;i++){
        long int count = 0;
        if(i-1>=0){
            count += ans[i-1];
        }
        if(i-2>=0){
            count += ans[i-2];
        }
        if(i-3>=0){
            count += ans[i-3];
        }
        ans[i] = count%1000000007;
    }
    return ans[n];
}


// -----------------min count square sum------------
int minCount(int n){ //brute force
    if(n==0){
        return 0;
    }
    int count = INT_MAX;
    for(int i =1;i<=sqrt(n);i++){
        int a = 1+minCount(n-i*i);
        if(count>a){
            count = a;
        }
    }
    return count;
}

int minCount_helper(int n,int*ans){
    if(ans[n]!=-1){
        return ans[n];
    }
    
    for(int j = 2;j<n+1;j++){
        int count = INT_MAX;
        for(int i =1;i<=sqrt(j);i++){
        	int a = 1+ans[j-i*i];
        	if(count>a){
            	count = a;
        	}
    	}
        ans[j] = count;
    } 
    return ans[n];
}
int minCount(int n){
    int *ans = new int[n+1];
    for(int i = 0;i<n+1;i++){
        ans[i] = -1;
    }
    ans[0] = 0;
    ans[1] = 1;
    return minCount_helper(n,ans);
}



//------- h >= 0  no of balanced bt for height h for any number of nodes--------
int balancedBTs(int h) {
	if(h <= 1) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;


	//int ans = (x*x + 2*x*y) % mod;
	return ans;
}

int balancedBTs_helper(int h,int*ans){
    if(ans[h]!=-1){
        return ans[h];
    }
    int a = balancedBTs_helper(h-1,ans);
    int b = balancedBTs_helper(h-2,ans);
    int x = ((long)(a)*a)%1000000007;
    int y = 2*((long)(b)*a)%1000000007;
    
    ans[h] = (x+y)%1000000007;
    return ans[h];
}
int balancedBTs(int h) {
    int *ans = new int[h+1];
    for(int i = 0;i<h+1;i++){
        ans[i] = -1;
    }
    ans[0] = 1;
    ans[1] = 1;
    return balancedBTs_helper(h,ans);
}

int balancedBTs(int h) { 
    int *ans = new int[h+1];
    ans[0] = 1;
    ans[1] = 1;
    
    for(int i = 2;i<h+1;i++){
        int a = ans[i-1];
    	int b = ans[i-2];
    	int x = ((long)(a)*a)%1000000007;
    	int y = 2*((long)(b)*a)%1000000007;
        ans[i] = (x+y)%1000000007;
    }
    return ans[h]%1000000007;
}


// --------------------Min cost path---------------------
int helper(int**input,int m,int n,int i,int j){ //TC = O(3^n)
    if(i==m-1 && j == n-1){
        return input[i][j];
    }
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;
    if(i+1<m){
        a =input[i][j] + helper(input,m,n,i+1,j);
    }
    if(j+1<n){
        b =input[i][j] + helper(input,m,n,i,j+1);
    }
    if(i+1<m && j+1<n){
        c =input[i][j] + helper(input,m,n,i+1,j+1);
    }
    
    int cost = min(min(a,b),c);
    return cost;
}
int minCostPath(int **input, int m, int n){
	return helper(input,m,n,0,0);
}

int helper(int**input,int m,int n,int i,int j,int **output){ // TC = SC = O(n*m)
    if(i==m-1 && j == n-1){
        return input[i][j];
    }
    if(output[i][j]!=-1){
        return output[i][j];
    }
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;
    if(i+1<m){
        a =input[i][j] + helper(input,m,n,i+1,j,output);
    }
    if(j+1<n){
        b =input[i][j] + helper(input,m,n,i,j+1,output);
    }
    if(i+1<m && j+1<n){
        c =input[i][j] + helper(input,m,n,i+1,j+1,output);
    }
    
    int a = min(min(a,b),c);
    output[i][j] = a;
    return a;
}
int minCostPath(int**input, int m, int n){
    int **output = new int*[m];
    for(int i = 0;i<m;i++){
        output[i] = new int[n];
        for(int j = 0;j<n;j++){
            output[i][j] = -1;
        }
    }
    
	return helper(input,m,n,0,0,output);
}

int minCOst_DP(int**input, int m, int n) {// TC = SC = O(n*m)
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

    //remaining cells
	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}


//------------------------- LCS ---------------------
int LCS(string s,string t){//brute force
    //Base case
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    //Recursive calls
    if(s[0]==t[0]){
        return 1+LCS(s.substr(1),t.substr(1));
    }
    
    int a = LCS(s.substr(1),t);
    int b = LCS(s,t.substr(1));
    /* int c = LCS(s.substr(1),t.substr(1));   --->redundant
     return max(a,max(b,c));*/

    return max(a,b);
}

int LCS(string s,string t,int**output){
    //Base case
    if(s.size()==0 || t.size()==0){
        return 0;
    }

    //check if ans already exists
    int m = s.size();
    int n = t.size();
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    //Recursive calls
    if(s[0]==t[0]){
        ans = 1+LCS(s.substr(1),t.substr(1),output);
    }
    else{
        int a = LCS(s.substr(1),t);
        int b = LCS(s,t.substr(1));
        /* int c = LCS(s.substr(1),t.substr(1));   --->redundant*/
        ans = max(a,b);
    }
    output[m][n] = ans;
    return ans;
}
int LCS_mem(string s,string t){
    int m = s.size();
    int n = t.size();
    int* *output = new int*[m+1];
    for(int i = 0;i<m+1;i++){
        output[i] = new int[n+1];
        for(int j = 0;j<n+1;j++){
            output[i][j] = -1;
        }
    }
    return LCS(s,t,output);
}

int LCS_Dp(string s,string t){
    int m = s.size();
    int n = t.size();
    int* *output = new int*[m+1];

    for(int i = 0;i<m+1;i++){
        output[i] = new int[n+1];
    }

    //fill first row
    for(int i = 0;i<=n;i++){
        output[0][i] = 0;
    }
    //fill first col
    for(int i = 0;i<=m;i++){
        output[0][i] = 0;
    }
    //filling rest
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(s[m-i] == t[n-j]){ //as size reduces the first char of strings vary
                output[i][j] = 1+output[i-1][j-1]; //decreasing length of both strings
            }
            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                output[i][j] = max(a,b);
            }
        }
    }

    return output[m][n];

}


//------------------------- Edit Distance ----------------------
int editDistanceME(string s1, string s2) {//brute force TC = O(3^n)
	if(s1.size()==0 && s2.size()==0){
        return 0;
    }
    if(s1.size()==0){
        return s2.size();
    }

    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;

    if(s2.size()!=0 && s1[0]==s2[0]){
        return editDistanceME(s1.substr(1),s2.substr(1));
    }
    else{
    	a =1+editDistanceME(s1.substr(1),s2); //insert
    	if(s2.size()!=0){
        	b = 1+editDistanceME(s1.substr(1),s2.substr(1));//update
    	    c = 1+editDistanceME(s1,s2.substr(1));//delete
    	}
    }
    return min(b,min(a,c));
}
int editDistanceCN(string s1, string s2){//brute force TC = O(3^n)
    int n = s1.length();
    int m = s2.length();
    if (n == 0 || m == 0){
        //if anyone of m or n is 0 then we need to either insert or delete max(n,m) characters
        return max(n, m);
    }
    if (s1[0] == s2[0]){
        return editDistanceCN(s1.substr(1), s2.substr(1));
    }
    int deleteCost = editDistanceCN(s1, s2.substr(1));
    int insertCost = editDistanceCN(s1.substr(1), s2);
    int replaceCost = editDistanceCN(s1.substr(1), s2.substr(1));

    return 1 + min(deleteCost, min(insertCost, replaceCost));
}

int editDistance_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	if(s[0] == t[0]) {
		ans = editDistance_mem(s.substr(1), t.substr(1), output);
	}
	else {
		// Insert
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		// Delete
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans
	return ans;
}
int editDistance_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			ans[i][j] = -1;
		}
	}
	return editDistance_mem(s, t, ans);

}

int editDistanceDP(string s, string t){
    int m = s.size();
	int n = t.size(); //claculating length 
    
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {    //initialising ans array
			ans[i][j] = -1;
		}
	}
    
    //filling first row
    for(int i = 0;i<n+1;i++){
        ans[0][i] = i;   
    }
    //filling first col
    for(int i = 0;i<m+1;i++){
        ans[i][0] = i;
    }
    
    //filling rest cells
    for(int i = 1;i<m+1;i++){
        for(int j = 1;j<n+1;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                ans[i][j] = 1+min(ans[i][j-1],min(ans[i-1][j],ans[i-1][j-1]));
            }
        }
    }
    return ans[m][n];
}

//-------------------------knapsack--------------------------------
int knapsack(int *weight, int *values, int n, int maxWeight) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	// Recursive calls
    int x = 0;
    if(weight[0] <= maxWeight) {   //taking the first element
		x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	}
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);  //not taking first element 

	return max(x, y);
}

int knapsack_mem(int* weight, int* values, int n, int maxWeight,int**ans) {
    // Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

    if(ans[maxWeight][n]!=-1){
        return ans[maxWeight][n];
    }
	// Recursive calls
    int x = 0;
    if(weight[0] <= maxWeight) {   //taking the first element
		x = knapsack_mem(weight + 1, values + 1, n - 1, maxWeight - weight[0],ans)+ values[0];
	}
	int y = knapsack_mem(weight + 1, values+1, n-1, maxWeight,ans);//not taking first element 

	ans[maxWeight][n] = max(x, y);
    return ans[maxWeight][n];
}
int knapsack_mem(int* weight, int* value, int n, int maxWeight) {
	int**ans = new int*[maxWeight+1];
    for(int i =0;i<maxWeight+1;i++){
        ans[i] = new int[n+1];
        for(int j = 0;j<n+1;j++){
            ans[i][j] = -1;
        }
    }
    return knapsack_mem(weight,value,n,maxWeight,ans);
}

// ------------------- loot houses-------------------
int maxMoneyLooted(int *arr, int n){
    int*loot = new int[n+1];
    for(int i = 0;i<n+1;i++){
        loot[i] = -1;
    }

    if(n<=0){
        return 0;
    }
	if(loot[n]!=-1){
        return loot[n];
    }
    loot[1] = arr[0];
    loot[2] = max(arr[0],arr[1]);
    for(int i = 3;i<n+1;i++){
        loot[i] = max(loot[i-2]+arr[i-1],loot[i-1]);
    }
    
    return loot[n];
}

// ---------------------------Longest Increasing Subsequence--------------
int longestIncreasingSubsequence(int* arr, int n) {
	int *ans = new int[n];
    ans[0] = 1;
    for(int i = 1;i<n;i++){
        ans[i] = 1;
        for(int j = i-1;j>=0;j--){
            if(arr[i]<=arr[j]){
                continue;
            }
            int smallans = ans[j]+1;
            if(ans[i]<smallans){
                ans[i] = smallans;
            }
        }
    }
    int best = 0;
    for(int i = 0;i<n;i++){
        if(ans[i]>best){
            best = ans[i];
        }
    }
    return best;
}

// Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
int hel(int a, int b,int n,int*dp) {
	if(a<0){
        return 0;
    }
    if(a==0){
        return 1;
    }
    int ans = 0;
    for(int i = n+1;pow(i,b)<=a;i++){
        int m=hel(a-pow(i,b),b,i,dp);
        ans+=m;
    }
    // dp[a] = ans;
    return ans;
}
int getAllWays(int a, int b) {
    int*dp = new int[a+1];
    for(int i = 0;i<a+1;i++){
        dp[i] = -1;
    }
	int ans = hel(a,b,0,dp);
    return ans;
}

int main() {
	/*int n;
	cin >> n;
	cout << fibo_2(n) << endl;
	cout << fibo_3(n) << endl;
	cout << fibo(n) << endl;
	cout << staircase(n) << endl;*/
    string s,t;
    cin>>s>>t;
    cout<<LCS_Dp(s,t);
}

