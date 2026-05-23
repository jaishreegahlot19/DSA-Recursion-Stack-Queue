#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
public:
    int STACK[10];
};
class StackOperation : public Stack
{
public:
    int TOP,MaxSize;
    StackOperation()
    {
        TOP = -1 ;
        cout<<"Enter Size of Stack -- ";
        cin>>MaxSize;
    }
    int Push()
    {
        system("cls");
        cout<<"Push in Stack Module \n\n";
        int DATA , PushStatus=0;
        cout<<"Enter Data - ";
        cin>>DATA;
        if(TOP == MaxSize-1){
            cout<<"Stack is Overflow...\n\n";
            return 0;
        }
        if(TOP == -1){
            TOP = 0;
            STACK[TOP] = DATA;
            PushStatus = 1 ;
        }
        else {
            TOP = TOP + 1;
            STACK[TOP] = DATA;
            PushStatus = 1;
        }
        if(PushStatus == 1)
            cout<<"\n\nData Successfully Inserted/Pushed..\n\n";
    }
    int Pop()
    {
        system("cls");
        cout<<"Pop From Stack Module \n\n";
        if(TOP== -1){
            cout<<"Stack is Underflow...\n\n";
            return 0;
        }
        STACK[TOP]=0;
        TOP = TOP - 1 ;
        cout<<"Data Deleted Successfully...\n\n";
    }
    int Peek()
    {
        cout<<"Peek Stack Module\n\n";
        if(TOP == -1){
            cout<<"Stack is Empty..\n\n";
            return 0;
        }
        else {
            for(int i = TOP ; i >= 0 ; i--){
                cout<<STACK[i]<<" -> ";
            }
            cout<<"\n\n";
        }

    }
    void MainMenu()
    {
        system("cls");
        cout<<"\tStack Operation -- \n\n";
        cout<<"1.Push..\n";
        cout<<"2.Pop..\n";
        cout<<"3.Peek..\n";
        cout<<"4.Exit..\n";
        cout<<"Choose any one of these..\n\n";
        char c = getch();
        if(c == '1'){
            Push();
        }else if (c == '2'){
            Pop();
        }else if (c == '3'){
            Peek();
        } else if (c == '4'){
            exit(0);
        }
        cout<<"Do you want to continue press 1 else any key...\n";
        c = getch();
        if(c == '1'){
            MainMenu();
        }
    }
};
int main()
{
    StackOperation S;
    S.MainMenu();
}
