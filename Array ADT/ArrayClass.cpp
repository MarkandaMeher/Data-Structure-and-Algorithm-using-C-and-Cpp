#include<iostream>
using namespace std;
class Array{
    private:
    int *A;
    int size;
    int lenth;
    public:
    Array(){
        size = 10;
        A = new int[10];
        lenth=0;
    }
    Array(int sz){
        size=sz;
        lenth=0;
        A = new int[size];
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Insert(int index,int x);
    int Delete(int index);
};
void Array :: Display(){
    //cout<<"I am in Display Fun";
    for(int i=0;i<lenth;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void Array::Insert(int index,int x){
    if(index>=0 && index<=lenth){
        for(int i =lenth-1;i>=index;i--)
        A[i+1]=A[i];
        A[index]=x;
        lenth++;
    }
}
int Array::Delete(int index){
    int x =0;
    if(index >=0 && index<lenth){
        x = A[index];
        for(int i = index;i<lenth-1;i++){
            A[i]=A[i+1];
        }
        lenth--;
    }
    return x;
}

 main(){

    Array arr(10);
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);
    arr.Insert(3,16);
    //cout<<100000;
    arr.Display();
}