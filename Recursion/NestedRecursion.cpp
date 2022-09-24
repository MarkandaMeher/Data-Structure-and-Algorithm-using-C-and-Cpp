#include<stdio.h>

int f1(int n){
    if (n>100)
    {
        return n-10;
    }
    return f1(f1(n+11));
}
int main(){
    int r;
    r = f1(99);
    printf("%d\n",r);
    return 0;
}