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
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Display(arr);
    //Append(&arr,10);
    //Insert(&arr,2,10);
    //printf("%d\n",Delete(&arr,0));
    //printf("%d\n",LinearSearch(arr,4));
    //printf("%d\n",ImproveLinearSearch(&arr,4));
    //printf("\n%d\n",IBinarySearch(arr,5));
    //printf("\n%d\n",RBinarySearch(arr.A,0,arr.length,5));

    printf("\n%d\n",Get(arr,4));
    printf("\n%d\n",Max(arr));
    printf("\n%d\n",Min(arr));
    printf("\n%d\n",Sum(arr));
    printf("\n%f\n",Avg(arr));
    Set(&arr,0,15);

    Display(arr);
}