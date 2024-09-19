/******** SIMPLE 
         CALCULATOR 
                    */

#include<iostream>
using namespace std;

int main(){
    int operation,x,y;

    //getting the choice of operation
    cout<<"ENTER 1->Addition 2->Subtraction 3->Multiplication 4->Division \n";
    cin>>operation;

    //getting the value of operands
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"Enter the value of y: ";
    cin>>y;

    //Performing the choosen operation and printing the result
    switch (operation)
    {
    case (1):
       cout<<"Answer: "<<x+y;
        break;
    case(2):
       cout<<"Answer: "<<x-y;
        break;
    case(3):
       cout<<"Answer: "<<x*y;
        break;
    case(4):
       cout<<"Answer: "<<x/y;
        break;
    
    default:
        cout<<"Invalid choice";
        break;
    }
}