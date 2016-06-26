void rotate(int** A, int n11, int n12) {
    int i=0,j=0,d=1,temp;
    temp=A[0][0];
    while(i<n11&&j<n12){
        if(d==-1)
        break;
        switch(d){
            case 1:
                if(i==n11-1){
                    printf("%d ",A[i][j]);
                    A[i][j]=A[i][j+1];
                    j++;
                    d=2;
                }
                else{
                    A[i][j]=A[i+1][j];
                    i++;
                }
                break;
            case 2:
                if(j==n12-1){
                    printf("%d ",A[i][j]);
                    A[i][j]=A[i-1][j];
                    i--;
                    d=3;
                }
                else{
                    A[i][j]=A[i][j+1];
                    j++;
                }
                break;
            case 3:
                if(i==0){
                    printf("%d ",A[i][j]);
                    A[i][j]=A[i][j-1];
                    j--;
                    d=4;
                }
                else{
                    A[i][j]=A[i-1][j];
                    i--;
                }
                break;
            case 4:
                if(j==1){
                    printf("%d ",A[i][j]);
                    A[i][j]=temp;
                    d=-1;
                    break;
                }
                else{
                    A[i][j]=A[i][j-1];
                    j--;
                }
        }
    }
}

