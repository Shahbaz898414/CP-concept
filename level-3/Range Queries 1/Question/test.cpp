//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int powerup(int N, int K, vector<int> &arr) {

      long long rq=0;
      long long en=K;

      for (int i = N-1; i >=0; i--)
      {
        /* code */
        if(arr[i]==0){
          en+=K;
        }else {
          rq+=(long long)arr[i];
        }

        if(rq<=en)  return i;
      }
      

        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> energyArr(N);
        for(int i=0;i<N;i++)
            cin>>energyArr[i];

            // cout<<"1 sh"<<endl;
        Solution obj;
        int res = obj.powerup(N, K, energyArr);

        // cout<<"1"<<endl;
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends


/*


int solve(Node* root, int k,int l,int r){
    if(root==NULL){
        return 0;
    }
    // if(l==k && r==k){
    //     return root->data;
    // }
    int suml=root->data,sumr=root->data,sum=0;
    if(l<k && root->left!=NULL){
        suml+=solve(root->left,k,l+1,r);
    }
    if(r<k && root->right!=NULL){
        sumr+=solve(root->right,k,l,r+1);
    }
    sum=max(suml,sumr);
    
    return sum;
}

int solve1( Node* root, int k){
    int ans=0;
    if(root==NULL){
        return 0;
    }
    ans=max(ans,solve(root,k,0,0));
    ans=max(ans,solve1(root->left,k));
    ans=max(ans,solve1(root->right,k));
    return ans;
}

class Solution {
  public:
    int maximumSum(int n, Node* root, int k) {
        // code here
        int ans=0;
        ans=solve1(root,k);
        
        return ans;
    }
};



*/




/*


class Solution {
  private:
    int hlpr(Node* root, int kr,int kl){
        if(root==nullptr) {
            return 0;
        }
        int maxsm=0;
        if(kr>0){
            maxsm=max(hlpr(root->right, kr-1, kl),maxsm);
        }
        if(kl>0){
            maxsm= max(hlpr(root->left, kr, kl-1),maxsm);
        }
        return maxsm+root->data;
    }
  public:
    int maximumSum(int n, Node* root, int k) {
        int maxsm=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(node==nullptr) continue;
            maxsm=max(hlpr(node,k,k),maxsm);
            q.push(node->left);
            q.push(node->right);
        }
        return maxsm;
    }
};



*/