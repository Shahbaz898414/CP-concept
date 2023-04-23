#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  
  int n; cin >> n;
    int v;
    int pos = 1;
    int posOpening, posDepth, posWidthMax;
    int depth = 0;
    int depthMax = 0;
    int widthMax = 0;
    for(int i=0; i<n; i++) {
        cin >> v;
        if(v==1) { 
            if(depth==0)
                posOpening = pos;
            depth++;
            if(depth>depthMax) {
                depthMax = depth;
                posDepth = pos;
            }
        }
        else { 
            depth--;
            if(depth==0) {
                int width = pos-posOpening+1;
                if(width>widthMax) {
                    widthMax = width;
                    posWidthMax = posOpening;
                }
            }
        }
        pos++;
    }
    cout << depthMax << ' ' << posDepth << ' ';
    cout << widthMax << ' ' <<  posWidthMax << endl;

  




  return 0;
}