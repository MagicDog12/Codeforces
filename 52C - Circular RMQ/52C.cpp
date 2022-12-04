#include <iostream>
#include<conio.h>
#define inf 1000000000
using namespace std;

long long int arr[1000060];
long long int t[2622000];
long long int lazy[2622000];

void build(long long int node, long long int a, long long int b)
{
	t[node] = inf;
	
	if (a==b)
	{
		t[node]=arr[a];
		return;
	}
	
	build(node*2, a, (a+b)/2);
	build(node*2+1, (a+b)/2+1, b);
	
	t[node] = min( t[node*2] , t[node*2+1] );
}

long long int query(long long int node, long long int a, long long int b, long long int i, long long int j)
{
	if(a>b || a>j || b<i) return inf;
	
	if (lazy[node] !=0 )
	{
		t[node]+=lazy[node];
		
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if (a>=i && b<=j) return t[node];
	
	long long int q1=query(node*2, a, (a+b)/2, i, j);
	long long int q2=query(node*2+1, (a+b)/2+1, b, i, j);
	
	return min(q1, q2);
}

void update(long long int node, long long int a, long long int b, long long int i, long long int j, long long int inc)
{
	if(a>b) return;
	
	if (lazy[node]!=0)
	{
		t[node] += lazy[node];
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if(a>b||a>j||b<i) return;
	
	if (a>=i && b<=j)
	{
		t[node]+=inc;
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}
	
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = min(t[node*2], t[node*2+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	long long int N;
	long long int M; 
	
	cin>>N;
	
	build(1,0,N-1);
	for (long long int i = 0; i < 2622000; ++i) lazy[i]=0;
	
	for(long long int i = 1; i <= N; i++)
	{
		long long int V;
		cin>>V;
		update(1, 0, N-1, i-1, i-1, V);
	}
	
	cin>>M;
	
	for(long long int i = 0; i < M; i++)
	{
		long long int L; 
		long long int R; 
		long long int C;
		
		cin>>L; 
		cin>>R;
		
		if(cin.peek() == '\n')
		{
			if(L <= R) cout<<query(1, 0, N-1, L, R)<<endl;
			else cout<<min(query(1, 0, N-1, 0, R), query(1, 0, N-1, L, N-1))<<endl;	
		}	
		else
		{
			cin>>C;
			
			if(L <= R) update(1, 0, N-1, L, R, C);
			else
			{
				update(1, 0, N-1, 0, R, C);
				update(1, 0, N-1, L, N-1, C);
			}
		}
	}
	
	return 0;
}