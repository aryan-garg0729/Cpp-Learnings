#include <iostream>
#include <climits>
#include <math.h>
#include<string.h>
using namespace std;
/* --------------------------loot money-------------------
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot*/

int maxMoneyLooted(int *arr, int n,int loot){
	if(n<=0){
        return loot;
    }
    int a = 0,b = 0;
    a = maxMoneyLooted(arr+2,n-2,loot+arr[0]);
    b = maxMoneyLooted(arr+1,n-1,loot);
    
    return max(a,b);
}

int maxMoneyLooted_mem(int *arr, int n,int* loot){
    if(n<=0){
        return 0;
    }
	if(loot[n]!=-1){
        return loot[n];
    }
    
    int a = 0,b = 0;
    a = maxMoneyLooted_mem(arr+2,n-2,loot)+arr[0];
    b = maxMoneyLooted_mem(arr+1,n-1,loot);
    
    loot[n] = max(a,b);
    return loot[n];
}
int maxMoneyLooted_mem(int *arr, int n){
    int*ans = new int[n+1];
    for(int i = 0;i<n+1;i++){
        ans[i] = -1;
    }
    return maxMoneyLooted_mem(arr,n,ans);
}

int maxMoneyLootedDP(int *arr, int n){
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
    //loot[n] gives max loot if n houses were present
    loot[1] = arr[0];
    loot[2] = max(arr[0],arr[1]);

    for(int i = 3;i<n+1;i++){
        loot[i] = max(loot[i-2]+arr[i-1],loot[i-1]);
    }
    
    return loot[n];
}


