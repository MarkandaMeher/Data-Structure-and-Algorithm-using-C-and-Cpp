#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr){
    int i;
    printf("\nElements are \n");
    for(i=0;i<arr.length;i++)
    printf("%d",arr.A[i]);
}
void Append(struct Array *arr,int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}
void Insert(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index <= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
int Delete(struct Array *arr,int index){
    int x =0,i;
    if(index>=0 && index<arr->length){
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
}
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y=temp;
}
int LinearSearch(struct Array arr,int key){
    int i;
    for(i=0;i<arr.length;i++){
        if(key==arr.A[i])
        return i;
    }
    return -1;
}
int ImproveLinearSearch(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
int IBinarySearch(struct Array arr,int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while (l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        return mid;
        else if (key<arr.A[mid])
        h=mid-1;
        else
        l=mid+1;
    }
    return -1;
}
int RBinarySearch(int a[],int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid])
        return mid;
        else if(key<a[mid])
        return RBinarySearch(a,l,mid-1,key);
        else
        return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}
int Get(struct Array arr, int index){
    if(index>=0 && index<arr.length)
    return arr.A[index];

    return -1;
}
void Set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length)
    arr->A[index]=x;
}
int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for ( i = 0; i < arr.length; i++)
    {
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max; 
}
int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for ( i = 0; i < arr.length; i++)
    {
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min; 
}
int Sum(struct Array arr){
    int s =0;
    int i;
    for(i=0;i<arr.length;i++){
        s+=arr.A[i];
    }
    return s;
}
float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}
void InsertSort(struct Array *arr,int x){
    if(arr->length==arr->size)
    return;
    int i =arr->length-1;
    while(arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
void Rearrange(struct Array *arr){
    int i,j;
    i=0;j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}
struct Array* Merge(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && arr2->length){
        if(arr1->A[i]<arr2->A[j])
        arr3->A[k++]=arr1->A[i++];
        else
        arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
    arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}
int main(){
    struct Array arr={{2,-3,3,4,-9,5,6},10,7};
    Display(arr);
    //Append(&arr,10);
    //Insert(&arr,2,10);
    //printf("%d\n",Delete(&arr,0));
    //printf("%d\n",LinearSearch(arr,4));
    //printf("%d\n",ImproveLinearSearch(&arr,4));
    //printf("\n%d\n",IBinarySearch(arr,5));
    //printf("\n%d\n",RBinarySearch(arr.A,0,arr.length,5));

    // printf("\n%d\n",Get(arr,4));
    // printf("\n%d\n",Max(arr));
    // printf("\n%d\n",Min(arr));
    // printf("\n%d\n",Sum(arr));
    // printf("\n%f\n",Avg(arr));
    // Set(&arr,0,15);

    // InsertSort(&arr,12);
    // printf("\n%d \n",isSorted(arr));
    // Rearrange(&arr);

    struct Array arr1 ={{2,6,10,15,25},10,5};
    struct Array arr2 ={{3,4,7,18,20},10,5};
    struct Array *arr3;
    arr3 = Merge(&arr1,&arr2);
    Display(*arr3);
}