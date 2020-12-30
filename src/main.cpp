#include <iostream>
#include "core.h"
#include "renderer.h"

// I just gave up writing decent code once I got to win checking, replaying, and spot checking.
// btw, if you are on anything other than linux, comment out "system("clear")"

char current_player = 'X';
int board_places = 0;

void PrintTicTacToeInfo(){
    std::cout << "          TIC-TAC-TOE" << std::endl;
    std::cout << "Player - 1 [X]    Player - 2 [O]";
    std::cout << std::endl;
}

void ResetGame(Board& board1, bool& stopchange, char& current_player, int& board_moves){
    board1.ClearBoard();
    system("clear");
    PrintTicTacToeInfo();
    RenderBoard(board1);
    current_player = 'X';
    stopchange = true;
    board_moves = 0;
}

int main(){
    system("clear");
    
    unsigned int nput;
    bool stopchange = false;
    
    Board* board = new Board;
    PrintTicTacToeInfo();
    RenderBoard(*board);
    
    bool running = true;
    
    while(running){
        GetUserInput(nput, current_player);
        
        system("clear");
        
        if(board->GetBoard()[nput-1] == 'X' || board->GetBoard()[nput-1] == 'O'){
            stopchange = true;
            std::cout << "A Mark Already Exists There!" << std::endl;
        }
        else{
            board->SetPosition(nput,current_player);
            board_places++;
        }
        PrintTicTacToeInfo();
        RenderBoard(*board);
        if(CheckForWin(*board, current_player)){
            std::cout << current_player << " WON!" << std::endl;
            if(!AskReplay()){
                running = false;
            }
            else{
                ResetGame(*board,stopchange,current_player, board_places);
            }
        }
        else{
            if(board_places==9){
                std::cout << "DRAW!" << std::endl;
                if(!AskReplay()){
                    running = false;
                }
                else{
                    ResetGame(*board,stopchange,current_player,board_places);
                }
            }
        }
        if(!stopchange){
            current_player = current_player=='X' ? 'O' : 'X';
        }
        stopchange = false;
    }
    
    delete board;
    
    std::cin.get();
}