#include<iostream>
//#include<conio.h>
using namespace std;

int input()
{
    int num;
    cout<<"\nEnter a number : ";
    cin>>num;
    return num;
}

int Factorial(int n)
{
    if(n > 1)
        return n * Factorial(n - 1);
    else
        return 1;
}

int Fibonacci(int n)
{
    if(n==1||n==2)
        return n-1;
    else
        return(Fibonacci(n-1)+Fibonacci(n-2));
}

void menu()
{
    cout<<"\nChoose an option :\n";
    cout<<"\n1.Factorial";
    cout<<"\n2.Fibonacci";
    cout<<"\n0.Exit\n\n";
    int ch;
    cin>>ch;
    int num,result;
    switch(ch)
    {
        case 1: num=input();
                result=Factorial(num);
                cout<<"\nThe factorial of "<<num<<" is "<<result<<endl;
                break;
        case 2: num=input();
                cout<<"\nFirst "<<num<<" terms of the fibonnaci series are ";
                for(int i=1;i<=num;i++)
                    cout<<"\t"<<Fibonacci(i);
                cout<<endl;
                break;
        case 0: exit(0);
        default:cout<<"\nInvalid choice";
    }
}

int main()
{
    menu();
    //getch();
    return 0;
}
