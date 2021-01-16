#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using vi=vector<int>;

// Assuming sizeof b is greater equal to size of a
vi addition(vi a, vi b){
	int n=a.size(), m=b.size(), carry=0;
	vi c(m+1, 0);

	int i=m-1, j=n-1, k=m;
	while(1){
		if(j>=0){
			c[k]=a[j]+b[i]+carry;
			carry=c[k]/10;
			c[k]%=10;
			i--;
			j--;
			k--;
			continue;
		}
		if(i>=0){
			c[k]=b[i]+carry;
			carry=c[k]/10;
			c[k]%=10;
			i--;
			k--;
			continue;
		}
		break;
	}
    c[k]=carry;
	for(auto e:c){
		cout<<e;
	}
	cout<<"\n";
	return c;
}

int main(){
	int t, n, k;

	addition({1, 2}, {1, 0});

	return 0;
}
