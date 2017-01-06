#include<iostream>
void merge(int arr[], int l,int m,int r)
{//forming left and right arrays
l_length=m-l+1;
r_length=r-l;
int L[l_length];
int R[r_length];
for(int i=0;i<l_length;i++)
{L[i]=arr[l+i];}
for(int j=0;j<r_length;j++)
{R[i]=arr[m+j+1];}

// forming the merged array of size from l to r
int i=0;
int j=0;
int k=0;
if (L[i]<R[j])
{
{arr[k]=L[i];
i++;
}
else{arr[k]=R[j];
j++;
}
k++;
}
while(i<n1)
{arr[k]=L[i];
i++;
k++
}
while(j<n2)
{arr[k]=R[j];
j++;
k++;
}
}
void mergesort(int arr[],int l,int r)
{

if(l<r)
{
m=(l+(r-1))/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
    }


}
}

