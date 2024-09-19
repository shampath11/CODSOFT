/********  TIC-TAC-TOE 
                    GAME
                                */
#include<iostream>
#include<string>
using namespace std;

string a[5][5];
string player1 = " X", player2 = " O";
int count1=0,count2=0,countm=0;
void makegrid();
int gameplay();
void printarray();
int playagain();
int* takeinput(string);
int check(string ,int ,int );
int row_check(string ,int );
int column_check(string ,int );
int primary_diagonal_check(string);
int secondary_diagonal_check(string);

int main(){
   

    int gameon=1;
    while(gameon == 1){
        gameon = gameplay();
    }
    


}

int gameplay(){
    int count = 0;
    //making 3*3 grid layout
    makegrid();

    cout<<"grid with positions:"<<endl;

    printarray();
    
    
    if(countm%2 == 1){
        string str = player1;
        player1 = player2;
        player2 = str;
    }
    else
    {
        player1 = " X", player2 = " O";
    }
    
    
    cout<<"player1: "<<player1<<endl;
    cout<<"player2: "<<player2<<endl;



    while(count<5){
        if(count == 4){
            int* position2 = takeinput(player1);
            int r = position2[0];
            int c = position2[1];
            if(check(player1,r,c)){
                if(playagain())
                    return 1;
                
            }
                
            cout<<"It's a draw"<<endl;
            countm++;
            cout<<"Matches played: "<<countm<<endl;
            cout<<"Matches won by player1: "<<count1<<endl;
            cout<<"Matches won by player2: "<<count2<<endl;
            if(playagain())
                return 1;
            else
                return 0;
        }
        else if(count >= 2){
            
            int* position = takeinput(player1);
            int r = position[0];
            int c = position[1];
            if(check(player1,r,c)){
                if(playagain())
                    return 1;
                else
                    return 0;
            }
            int* position1 = takeinput(player2);
            r = position1[0];
            c = position1[1];
            if(check(player2,r,c)){
                if(playagain())
                    return 1;
                else
                    return 0;
            }
            count++;
        }
        else{
            takeinput(player1);
            takeinput(player2);
            count++;
        }
        
    }
}


void makegrid(){
        int x = 0;
        string v;
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0||i==2||i==4){
                if(j==0||j==2||j==4){
                    x++;
                    v= " " + to_string(x) ;
                    a[i][j] = v;
                }   
                else
                    a[i][j] = " |";
            }
            else
                a[i][j] = "--";
        }
    }
}

void printarray(){
         for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
           cout<<a[i][j];
        }
        cout<<endl;
    }
}

int* takeinput(string player){
        int p,incorrect;
        static int r[2];
        int e,c;
        do
        {
            incorrect = 0;
            cout<<"Enter"<<player<<" position: ";
            cin>>p;
            switch (p)
            {
            case(1):
                if(a[0][0] == " X" || a[0][0] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }

                a[0][0] = player;
                e=0,c=0;
                break;
            case(2):
                if(a[0][2] == " X" || a[0][2] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }    

                a[0][2] = player;
                e=0,c=2;
                break;
            case(3):
                if(a[0][4] == " X" || a[0][4] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[0][4] = player;
                e=0,c=4;
                break;
            case(4):
                if(a[2][0] == " X" || a[2][0] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[2][0] = player;
                e=2,c=0;
                break;
            case(5):
                if(a[2][2] == " X" || a[2][2] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[2][2] = player;
                e=2,c=2;
                break;
            case(6):
                if(a[2][4] == " X" || a[2][4] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[2][4] = player;
                e=2,c=4;
                break;
            case(7):
                if(a[4][0] == " X" || a[4][0] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[4][0] = player;
                e=4,c=0;
                break;
            case(8):
                if(a[4][2] == " X" || a[4][2] == " O")
                {
                        cout<<"Entered occupied position"<<endl;
                        incorrect = 1;
                        break;
                }
                a[4][2] = player;
                e=4,c=2;
                break;    
            case(9):
                if(a[4][4] == " X" || a[4][4] == " O")
                {
                    cout<<"Entered occupied position"<<endl;
                    incorrect = 1;
                    break;
                }
                a[4][4] = player;
                e=4,c=4;
                break;
            default:
                cout<<"Enter valid position"<<endl;
                incorrect = 1;
                break;
            }
        } while (incorrect == 1);
        
        
        //printing the array
        printarray();

        r[0] = e;
        r[1] = c;
        return r;
    }

int check(string player,int r, int c){
    int sum = r+c;
    int count = 0;

    //row check
    if(row_check(player,r)) {
        return 1;
    }

    
    //column check
    else if (column_check(player,c))
    {
        return 1;
    }
    
    //diagonal check
    else if(sum % 4 == 0){
        
        //both
        if(r==2 && c==2){

            if(primary_diagonal_check(player)){
                return 1;
            }
            if(secondary_diagonal_check(player)){
                return 1;
            }  
            else{
                cout<<"Status: Ongoing"<<endl;
                return 0;
              }
        }

        //primary diagonal
        else if(r==c){
            if(primary_diagonal_check(player)){
                return 1;
            }
            else{
                 cout<<"Status: Ongoing"<<endl;
                 return 0;
            }
        }

        //secondary diagonal
        else if(r+c == 4)
        {
            if(secondary_diagonal_check(player)){
                return 1;
            }  
            else{
                cout<<"Status: Ongoing"<<endl;
                return 0;
            }        
        }
    }
    else{
        cout<<"Status: Ongoing"<<endl;
        return 0;
    }
        
    
}


int column_check(string player,int c){
    int count = 0;
    for(int i=0;i<5;i+=2){
        if(a[i][c] == player){
            count++;
        }
        else
            return 0;
        
        if (count == 3){
                        cout<<"Status: ";
                        if(player == player1){
                            cout<<"Player1 won the game.... :)"<<endl;
                            count1++,countm++;
                            
                        }
                        else{
                            cout<<"Player2 won the game.... :)"<<endl;
                            count2++,countm++;
                        }
                        cout<<"Matches played: "<<countm<<endl;
                        cout<<"Matches won by player1: "<<count1<<endl;
                        cout<<"Matches won by player2: "<<count2<<endl;
                        
                        return 1;
        }
                
    }
}

int row_check(string player, int r){
    int count = 0;
    for(int j =0;j<5;j+=2){
        if (a[r][j] == player)
            count++;
        else
            return 0;
        if (count == 3){
                        cout<<"Status: ";
                        if(player == player1){
                            cout<<"Player1 won the game.... :)"<<endl;
                            count1++,countm++;
                            
                        }
                        else{
                            cout<<"Player2 won the game.... :)"<<endl;
                            count2++,countm++;
                        }
                        cout<<"Matches played: "<<countm<<endl;
                        cout<<"Matches won by player1: "<<count1<<endl;
                        cout<<"Matches won by player2: "<<count2<<endl;
                        
                        return 1;
        }
    }
}

int primary_diagonal_check(string player){
    int count = 0;
    for(int i=0; i<5; i+=2){
                for(int j=0 ; j<5 ;j+=2){
                    if(i==j){
                        if (a[i][j] == player)
                            count++;
                        else
                            return 0;
                    }
                    if (count == 3){
                        cout<<"Status: ";
                        if(player == player1){
                            cout<<"Player1 won the game.... :)"<<endl;
                            count1++,countm++;
                            
                        }
                        else{
                            cout<<"Player2 won the game.... :)"<<endl;
                            count2++,countm++;
                        }
                        cout<<"Matches played: "<<countm<<endl;
                        cout<<"Matches won by player1: "<<count1<<endl;
                        cout<<"Matches won by player2: "<<count2<<endl;
                        
                        return 1;
                    }
                }
    }
}

int secondary_diagonal_check(string player){
    int count = 0;
        for(int i=0; i<5; i+=2){
                for(int j=0 ; j<5 ;j+=2){
                    if(i+j == 4){
                        if (a[i][j] == player)
                            count++;
                        else
                            return 0;
                    }
                    if (count == 3){
                        cout<<"Status: ";
                        if(player == player1){
                            cout<<"Player1 won the game.... :)"<<endl;
                            count1++,countm++;
                            
                        }
                        else{
                            cout<<"Player2 won the game.... :)"<<endl;
                            count2++,countm++;
                        }
                        cout<<"Matches played: "<<countm<<endl;
                        cout<<"Matches won by player1: "<<count1<<endl;
                        cout<<"Matches won by player2: "<<count2<<endl;
                        return 1;
                    }
                    
                }
        }
    
}


int playagain(){
    string x;
    int incorrect = 0;
    do
    {
        cout<<"Want to play again (Y/N): ";
        cin>>x;
        if(x=="N")
        return 0;
        else if(x=="Y")
        return 1;
        else{
        cout<<"Enter valid option.";
        incorrect = 1;
    }
        
    } while (incorrect == 1);
    
    
}
