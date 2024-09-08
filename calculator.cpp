#include<iostream>
using namespace std;

float calculate(float num1, float num2, char op){
    if(op=='+') return num1+num2;
    else if(op=='-') return num1-num2;
    else if(op=='*') return num1*num2;
    else if(op=='/') return num1/num2;
    else{
        cout<<"Invalid Operator!!"<<endl;
        return -1;
    }
}

int main(){
    float num1,num2;
    char op;

    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    cout<<"Enter the operator(+,-,*,/): ";
    cin>>op;

    float ans=calculate(num1,num2,op);
    cout<<num1<<op<<num2<<"="<<ans<<endl;
    return 0;
}
