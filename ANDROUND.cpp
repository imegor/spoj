
/*Created by Karan Kanojia 
https://www.spoj.com/problems/ANDROUND/ */

#include <bits/stdc++.h>
#define MAX 1111111
#define lim 1e9+7
#define ll long long 
#define SQRT 1060
#define sci(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define pfi(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define pfcase(t) printf("Case #%d:\n",t);
#define pf(d) printf("%s\n",d);

using namespace std; 

ll arr[MAX], tree[4*MAX+1];
void init(int left, int right, int index){
	if(left == right){tree[index] = arr[left];}
	else{
		int mid = (left+right)/2;
		init(left,mid,2*index); init(mid+1,right,2*index+1);
		tree[index] = tree[2*index] & tree[2*index+1];
	}
}

ll query(int left, int right, int index,int ql ,int qr){
	if(qr < left || ql > right){return 8589934591;}
	else if(ql <= left && qr >= right){return tree[index];}
	else{
		int mid = (left+right)/2;
		ll l = query(left,mid,2*index,ql,qr);
		ll r = query(mid+1,right,2*index+1,ql,qr);
		return l&r;
	}
}

int main(){

	//File handling start 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//File Handing ends 

	//Code starts from here
	int t; sci(t);
	while(t--){
		int N,K; sci(N); sci(K); for(int i=0 ;i<N; i++){scl(arr[i]);}
		if(2*K >= N){
            ll buff = 8589934591;
            for(int i=0; i<N; i++){buff = buff & arr[i];}
            for(int i=0 ;i<N; i++){printf("%lld ", buff);} 
            	pf("");
        }else{
            init(0,N-1,1);ll answer[N];
		for(int i=0; i<N;i++){
			int l = ((i-K)%N + N) %N;
			int r = ((i+K)%N + N) %N;
			if(l <= r) {
				answer[i] = query(0,N-1,1,l,r);
			} else{
				answer[i] = query(0,N-1,1,l,N-1)&query(0,N-1,1,0,r);
			}
			printf("%lld ", answer[i]);
		} 
		
        }pf("");
	}

	
}
