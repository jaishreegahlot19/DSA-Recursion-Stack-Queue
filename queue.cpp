#include<iostream>
#include<conio.h>
using namespace std;
class Queue
{
public:
    int QUEUE[10];
};
class QueueOperation : public Queue
{
public:
    int Front,Rear,MaxSize;
    QueueOperation()
    {
        Front = Rear = -1 ;
        cout<<"Enter Size of Queue -- ";
        cin>>MaxSize;
    }
    int Push()
    {
        system("cls");
        cout<<"Push Operation Module \n\n";
        int DATA , PushStatus=0;
        cout<<"Enter Data - ";
        cin>>DATA;
        if(Front == 0 && Rear == MaxSize-1){
            cout<<"Queue is Overflow...\n\n";
            return 0;
        }
        if(Front == -1 && Rear == -1){
            Front = Rear = 0;
            QUEUE[Rear] = DATA;
            PushStatus = 1 ;
        }
        else if (Rear == MaxSize-1 && Front!= 0){
            for(int i = Front ; i < Rear ; i++){
                QUEUE[i-1] = QUEUE[i];
            }
            Front = Front -1 ;
            QUEUE[Rear] = DATA;
            PushStatus = 1;
        }
        else {
            Rear = Rear + 1;
            QUEUE[Rear] = DATA;
            PushStatus = 1;
        }
        if(PushStatus == 1)
            cout<<"\n\nData Successfully Inserted/Pushed..\n\n";
    }
    int Pop()
    {
        system("cls");
        cout<<"Pop From Queue Module \n\n";
        if(Front == -1 && Rear == -1){
            cout<<"Queue is Underflow...\n\n";
            return 0;
        }
        if(Front == Rear){
            QUEUE[Front] = 0;
            Front = Rear = -1;
        }
        else {
            QUEUE[Front]= 0;
            Front = Front + 1;
        }
        cout<<"Data Deleted Successfully...\n\n";
    }
    int Peek()
    {
        cout<<"Peek Module \n\n";
        if(Front == -1){
            cout<<"Queue is Empty..\n\n";
            return 0;
        }
        else {
            for(int i = Front ; i <= Rear ; i++){
                cout<<QUEUE[i]<<" -> ";
            }
            cout<<"\n\n";
        }

    }
    void MainMenu()
    {
        system("cls");
        cout<<"\tQueue Operation -- \n\n";
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
    QueueOperation Q;
    Q.MainMenu();
}
