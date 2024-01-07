#include <bits/stdc++.h>
using namespace std;
// vector<long long>seg;
// void build(vector<int>&nums,int ind,int low,int high){
//     if(low==high){
//         seg[ind] = nums[low];
//         return;
//     }
//     int mid = (low+high)/2;
//     build(nums,2*ind+1,low,mid);
//     build(nums,2*ind+2,mid+1,high);
//     seg[ind] = (seg[2*ind+1]^seg[2*ind+2]);
// }
// long long query(int ind,int low,int high,int l,int r){
//     // no overlap
//     if(high<l || low>r)return 0;

//     // complete overlap
//     if(low>=l && high<=r)return seg[ind];

//     // partial overlap
//     int mid = (low+high)/2;
//     long long left = query(2*ind+1,low,mid,l,r);
//     long long right = query(2*ind+2,mid+1,high,l,r);
//     return (left^right);
// }
// void update(int ind,int low,int high,int i,int val){
//     if(low==high){
//         seg[ind] = val;
//         return;
//     }

//     int mid = (low+high)/2;

//     if(mid>=i) update(2*ind+1,low,mid,i,val);
//     else update(2*ind+2,mid+1,high,i,val);

//     seg[ind] = (seg[2*ind+1]^seg[2*ind+2]);
// }



// template <typename T>
class SegmentTree{
    vector<long long>seg,lazy;
    public:
    SegmentTree(int n,int val){
        seg.resize(4*n,val);
        lazy.resize(4*n,val);
    }
    void build(vector<int>&nums,int ind,int low, int high){
        if(low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(nums,2*ind+1,low,mid);
        build(nums,2*ind+2,mid+1,high);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    long long query(int ind,int low,int high,int l,int r){
        // update the node if some updates are left in lazy
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            // propogate lazy update downwards if the node is not leaf
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            // clear lazy
            lazy[ind]=0;
        }
        // no overlap
        if(l>high || r<low)return 0;

        // complete overlap
        if(low>=l && high<=r) return seg[ind];

        // partial overlap
        int mid = (low+high)/2;
        long long left = query(2*ind+1,low,mid,l,r);
        long long right = query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
    // increase a range by val
    void rangeUpdate(int ind,int low,int high,int l,int r,int val){
        // update previous remaining updates
        // and propagate downwards
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1)*lazy[ind];
            // propogate lazy update downwards
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }

            lazy[ind]=0;
        }
        // no overlap
        // we don't do anything and return
        if(high<l || r<low)return;

        // complete overlap
        if(low>=l && high<=r){
            // update value in seg tree
            seg[ind]+=(high-low+1)*val;
            //prop down if not leaf
            if(low!=high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        } 

        // partial overlap
        int mid = (low+high)/2;
        rangeUpdate(2*ind+1,low,mid,l,r,val);
        rangeUpdate(2*ind+2,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    // point update(replace value at index i with val)
    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        
        if(mid>=i)update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);

        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    SegmentTree seg(n,0);
    seg.build(nums,0,0,n-1);
    for(int i = 0;i<q;i++){
        int type,l,r;
        cin>>type>>l>>r;
        l--;
        if(type==1){
            seg.update(0,0,n-1,l,r);
        }
        else {
            r--;
            cout<<seg.query(0,0,n-1,l,r)<<endl;
        }
    }
    return 0;
}


