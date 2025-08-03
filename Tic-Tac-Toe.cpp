#include <iostream>
#include <ctime>
using namespace std;

void drawboard(char *spaces);
void playerturn(char *space ,char player);
void computurturn(char *space, char comp);
bool winner(char *spaces,char player, char comp);
bool tie(char *spaces);

int main(){
    char spaces[9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
    char player ='X';
    char computer = 'O';
    bool running =true;
    drawboard(spaces);
    while(running){
        playerturn(spaces,player);
        drawboard(spaces);
        if(winner(spaces,player,computer)){
            running=false;
            break;
        }
        else if(tie(spaces)){
            running = false;
            break;
        }
        computurturn(spaces,computer);
        drawboard(spaces);
        if(winner(spaces,player,computer)){
           running=false;
             break;
        }
        else if(tie(spaces)){
            running = false;
            break;
        }
    }
}

void drawboard(char *spaces){
    cout<<"      |    |      "<<"\n";
    cout<<"   "<<spaces[0] << "  |  "<<spaces[1] <<" |  " <<spaces[2] << " "<<"\n";  
    cout<<"______|____|______"<<"\n";
    cout<<"      |    |      "<<"\n";
    cout<<"   "<<spaces[3] << "  |  "<<spaces[4] <<" |  " <<spaces[5] << " "<<"\n";  
    cout<<"______|____|______"<<"\n";
    cout<<"      |    |      "<<"\n";
    cout<<"   "<<spaces[6] << "  |  "<<spaces[7] <<" |  " <<spaces[8] << " "<<"\n";  
    cout<<"      |    |"<<"\n";
}

void playerturn(char *spaces, char player){
    int index;
    do{
        cout<<"Enter a spot to place between index (1-9): ";
        cin>>index;
        index--;
        if(spaces[index]==' '){
            spaces[index] =player;
            break;
        }
    }while(!index>0 || !index<8);
}

void computurturn(char *space, char comp){
    srand(time(NULL));
    int index;
    
    while(true){
        index =rand()%9;
        if(space[index]==' '){
            space[index] =comp;
            break;
        }
    }
}

bool winner(char *spaces,char player, char comp){
    if((spaces[0] != ' ' ) && (spaces[0]==spaces[1]) && (spaces[1]==spaces[2]) ){
        spaces[0] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[3] != ' ' ) && (spaces[3]==spaces[4]) && (spaces[4]==spaces[5]) ){
        spaces[3] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[6] != ' ' ) && (spaces[6]==spaces[7]) && (spaces[7]==spaces[8]) ){
        spaces[6] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[0] != ' ' ) && (spaces[0]==spaces[3]) && (spaces[3]==spaces[6]) ){
        spaces[0] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[1] != ' ' ) && (spaces[2]==spaces[4]) && (spaces[4]==spaces[6]) ){
        spaces[1] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[0] != ' ' ) && (spaces[0]==spaces[4]) && (spaces[4]==spaces[8]) ){
        spaces[0] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[2] != ' ' ) && (spaces[2]==spaces[4]) && (spaces[4]==spaces[8]) ){
        spaces[2] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else if((spaces[2] != ' ' ) && (spaces[2]==spaces[5]) && (spaces[5]==spaces[8]) ){
        spaces[2] ==player ? cout<<"You Won! \n" : cout<<"You Lost!!!! \n";
    }
    else{
        return false;
    }

    return true;
}

bool tie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    cout<<"It's a Tie!!!!!!!!!!!!!!\n";
    return true;
}