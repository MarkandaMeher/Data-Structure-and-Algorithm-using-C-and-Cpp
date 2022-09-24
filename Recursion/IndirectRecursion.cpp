#include<stdio.h>
void f2(int n);
void f1(int n){
    if(n>0){
        printf("%d ",n);
        f2(n-1);
    }
}
void f2(int n){
    if(n>1){
        printf("%d ",n);
        f1(n/2);
    }
}

int main(){
    f1(20);
}