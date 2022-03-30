// Simple tic-tac-toe with minimax
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>    // std::max
#include <time.h>      // import time  
using namespace std;

// function declaration
void makemove();
int min(int depth, int alpha, int beta);
int max(int depth, int alpha, int beta);
int terminalEvaluation();
bool timeup();
/*
void AIMove();
int alphaBetaPruning(int depth, int alpha, int beta, bool maxPlayer);
*/
int check4winner();
void checkGameOver();
void getamove();
void setup();
void printboard();

// declare global variables
int minValue = -2147483648;
int maxValue = 2147483647;
int b[8][8], maxdepth=5, alpha = minValue, beta = maxValue;
char letter[8] = {'A', 'B',  'C',  'D',  'E',  'F',  'G',  'H'};
clock_t startTime;

int main ()
{   
    int start = 0;
    cout << "WELCOME TO THE GAME OF TIC TAC TOE\n" << endl;
    cout << "Human Move(Your move) = O" << endl;
    cout << "Computer(AI) Move = X" << endl;
    cout << endl;
    
    while(true){
        cout << "Do you want to start first?[1:yes 2:no] ";
        cin >> start;
        if(start == 1 || start == 2)
            break;
        else
            cout << "Invalid!" << endl;
    }
    
    setup();
    printboard();
    for (;;){  
        
        if(start == 1){
            // human starts first
            getamove();
            checkGameOver();
//            AIMove();

            makemove();
            checkGameOver();
        }
            
        else{
 //           AIMove();
            makemove();
            checkGameOver();
            getamove();
            checkGameOver();
        }
    } 
    
}

void printboard()
{ 
    // display the board
    cout << "  ";
    for(int x = 0; x < 8; x++)
        cout << x + 1 << " ";
    cout << endl;
    
    for(int i = 0; i < 8; i++){
        cout << letter[i] << " ";
        for(int j = 0; j < 8; j++){
            if(b[i][j] == 0)
                cout << "- ";
            if(b[i][j] == 1) 
                cout << "X ";
            if(b[i][j] == 2)
                cout << "O ";
        }
        cout << endl;
    }

}

void setup()
{ 
    // make the board with blank spaces
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) 
            b[i][j]=0; 
    }
}

void getamove()
{ 
    // get the human move
    string move;
    int row,col;
    bool rowValid = false, colValid = false;
    
    while(true){
        cout << "Enter your move[a letter + col number]: ";
        cin >> move;
        
        if(move.length() == 2){
            // check letter[row]
            for(int i = 0; i < 8; i++){
                if(toupper(move[0]) == letter[i]){
                    row = i;
                    rowValid = true;
                }
            }
        
            
            // check number[column]
            for(int j = 1; j < 9; j++){
                if(move[1] == '0' + j){
                    col = j - 1;
                    colValid = true;
                }
            }
      
            
            if(rowValid&&colValid){
                if(b[row][col] == 1 || b[row][col] == 2)
                    cout << "The move has already being taken!" << endl;
                else
                    break;
            }
            
            
        }
            
        cout << "Invalid Input" << endl;
        
        
    }
    
    b[row][col]=2;
}

/*

void AIMove()
{ 
    int bestScore=minValue, bestRow = 0, bestCol = 0;
    int score = 0, depth = maxdepth;
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){ 
            if (b[i][j]==0){ 
                b[i][j]= 1; // make move on board
                score = alphaBetaPruning(depth - 1, alpha, beta, true);
                b[i][j]= 0; // undo move
                
                if (score > bestScore) { 
                    bestRow = i;
                    bestCol = j;
                    bestScore = score; 
                }
            } 
        } 
        
    }
    
    cout << "my move is " << letter[bestRow] << bestCol + 1 << endl;
    b[bestRow][bestCol]=1;
}

int alphaBetaPruning(int depth, int alpha, int beta, bool maxPlayer){
    int score;
    if(depth == 0 || check4winner() != 0)
        return check4winner();
        
    if(maxPlayer){
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){ 
                if (b[i][j]==0){ 
                    b[i][j]= 1; // make move on board
                    score = alphaBetaPruning(depth - 1, alpha, beta, false);
                    b[i][j]= 0; // undo move
                    alpha = max(alpha,score);
                    if(beta >= alpha)
                        break;
                } 
            } 
        }
        return alpha;
    }
    
    else{
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){ 
                if (b[i][j]==0){ 
                    b[i][j]= 1; // make move on board
                    score = alphaBetaPruning(depth-1, alpha, beta, true);
                    b[i][j]= 0; // undo move
                    beta = min(beta,score);
                    if(beta <= alpha)
                        break;
                } 
            } 
        }
        return beta;
    }
    
}
*/


bool timeup(){
    // return true if the time past 5 seconds
    if(((float)( clock() - startTime ) / CLOCKS_PER_SEC) > 5)
        return true;
    return false;
}


void makemove()
{ 
    startTime = clock (); // start time
    // AI makes a move
    int best=minValue,depth=maxdepth,score,mi,mj;
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){ 
            if (b[i][j]==0){ 
                b[i][j]=1; // make move on board
                score = min(depth-1,alpha,beta);
                
                if (score > best) { 
                    mi=i; 
                    mj=j; 
                    best=score; 
                }
                
                b[i][j]=0; // undo move
                if(timeup())
                    break;
            } 
        } 
        
    }
    
    cout << "my move is " << letter[mi] << mj + 1 << endl;
    b[mi][mj]=1;
}


int min(int depth, int alpha, int beta)
{ 
    // minimum in minimax algorithm with alpha and beta pruning
    int score;
        
    if (check4winner() != 0) 
        return (check4winner());
 
    if (depth == 0) 
        return 0;
    for (int i=0; i<8; i++){ 
        for (int j=0; j<8; j++){ 
            if (b[i][j]==0){ 
                b[i][j]=2; // make move on board
                score = max(depth-1,alpha,beta);
                b[i][j]=0; // undo move
                beta = min(beta,score);
                if(alpha >= beta)
                    break;
                
            } 
        } 
    }
    return beta;
}

int max(int depth,int alpha, int beta)
{ 
    // maximum in minimax algorithm with alpha and beta pruning
    int score;
        
    if (check4winner() != 0) 
        return (check4winner());
        
    if(timeup())
        return (check4winner());
        
    if (depth == 0) 
        return 0;
    for (int i=0; i<8; i++){ 
        for (int j=0; j<8; j++){ 
            if (b[i][j]==0){ 
                b[i][j]=1; // make move on board
                score = min(depth-1,alpha,beta);
                b[i][j]=0; // undo move
                alpha = max(alpha,score);
                if(alpha >= beta)
                    break;
                    
            } 
        } 
    }
    return alpha;
}

int terminalEvaluation(){
  
    // non-terminal evalution function
    return 0;
    
}
    
int check4winner()
{   
    // check any row has a winner
    for (int i=0; i<8; i++){
        for (int j=0; j<5; j++){
            if(b[i][j] == 1 && b[i][j+1] == 1 && b[i][j+2] == 1 && b[i][j+3] == 1)
                return 5000; // computer wins
                
            if(b[i][j] == 2 && b[i][j+1] == 2 && b[i][j+2] == 2 && b[i][j+3] == 2)
                return -5000; // human wins
        }
    }
   
   // check any col has a winner
    for (int j=0; j<8; j++){
        for (int i=0; i<5; i++){
            if(b[i][j] == 1 && b[i+1][j] == 1 && b[i+2][j] == 1 && b[i+3][j] == 1)
                return 5000; // computer wins
                
            if(b[i][j] == 2 && b[i+1][j] == 2 && b[i+2][j] == 2 && b[i+3][j] == 2)
                return -5000; // human wins
        }
    }
    
    // check if the board is still empty
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            if(b[i][j] == 0)
                return 0;
                
        }
    }
    
    
    
    return 1; // if there is no winner with a full board, return draw 
}
    

void checkGameOver()
{ 
    printboard();
    if (check4winner() == -5000){ 
        cout << "You win" << endl; 
        exit(0);
    }
        
    if (check4winner() == 5000){
        cout << "Computer wins"   << endl;
        exit(0);
    }
    
    if (check4winner() == 1){
        cout << "Draw" << endl;
        exit(0);
    }
    
}



