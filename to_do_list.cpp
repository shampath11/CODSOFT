/****** TO-DO 
            LIST 
                    */

#include<iostream>
#include<string>
using namespace std;

string a[100][3];
int task_no=0;
int row =0;

void choose_operation();
void view();
void add();
void del();

int main(){

    a[0][0]="Task_Number";
    a[0][1]=" | ";
    a[0][2]="List of Task";

    cout<<"1-> view task"<<endl;
    cout<<"2-> add task"<<endl;
    cout<<"3-> delete task"<<endl;
    cout<<"4-> exit"<<endl;
    choose_operation();

}

void choose_operation(){
    int x;
    cout<<"Enter the desired operation: ";
    cin>>x;
    switch (x)
    {
    case(1):
        view();
        break;
    case(2):
        add();
        break;
    case(3):
        del();
        break;
    case(4):
        exit(0);
        break;
    default:
        break;
    }
}

void add(){
    cout<<"Enter the task:";
    string task_name;
    cin.ignore();
    getline(cin ,task_name);
    task_no++,row++;
    a[task_no][0] = to_string(task_no);
    a[task_no][1] = " | ";
    a[task_no][2] = task_name;
    view();
    choose_operation();
}

void view(){

    for(int i=0;i<=row;i++){
        for(int j=0;j<3;j++){
           cout<<a[i][j];
        }
        cout<<endl;
    }
    choose_operation();
}

void del(){
    cout<<"Enter the task_no: ";
    int x;
    cin>>x;
    for(int i=x;i<row;i++){
        a[i][2] = a[i+1][2];
    }
    row--,task_no--;
    choose_operation();
}