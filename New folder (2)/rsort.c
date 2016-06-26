rsort(arr[],n){
	b[n],max=INT_MIN,i,j,k,exp=1;
	for(i=0;i<n;i++){
		if(max<a[i])
			max=a[i];
	}
	while(max>0){
		int bin[10]={0};
		for(i=0;i<n;i++)
			bin[(a[i]/exp)%10]++;
		for(i=1;i<=9;i++)
			bin[i]+=bin[i+1];
		for(i=n-1;i>=0;i--)
			b[--bin[a[i]/exp%10]]=a[i];	
		for(i=0;i<n;i++)
			a[i]=b[i];
		max=max/10;
		exp=exp*10;
	}
}

