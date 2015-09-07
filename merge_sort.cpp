//k temporary table, t initial table
//k,t are both global
void fusion(int l,int r){
	int mid,p,q,i;
	if (r>l){
		mid=(r+l)/2;
		fusion(l,mid);
		fusion(mid+1,r);
		p=l;q=mid+1;i=l;
//merge:
		while (p<=mid && q<=r){
			if (t[p]<t[q]){
				k[i]=t[p];i++;p++;
			}
			else{
				k[i]=t[q];i++;q++;
			}
		}
		if (p<=mid){
			for (int j=p;j<mid+1;j++){
				k[i]=t[j];i++;
			}
		}
		else{
			for(int j=q;j<r+1;j++){
				k[i]=t[j];i++;
			}
		}
		for (i=l;i<r+1;i++){
			t[i]=k[i];
		}
	}
}
