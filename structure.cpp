#include<iostream>
#include<stdio.h>

using namespace std;

struct Rectangle {
    int length;
    int breath;
};

int main(){
    struct Rectangle r;
    r.length = 10,
    r.breath=6;
    cout<<"Area of rectangle = "<<r.length*r.breath;
    return 0;
}