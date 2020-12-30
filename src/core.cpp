// BASE LOGIC FILE

#include <iostream>
#include <string>
#include "core.h"

using String = std::string;

Board::Board() : m_board{'1','2','3','4','5','6','7','8','9'}{
    std::cout << "WELCOME TO TIC TAC TOE BY BPM! :)" << std::endl << std::endl;
}

Board::~Board(){
    std::cout << "Thanks For Playing!" << std::endl;
}

const char* Board::GetBoard() const{
    return m_board;
}

void Board::SetPosition(const int& position, char letter){
    int index = position - 1;
    m_board[index] = letter;
}

void Board::ClearBoard(){
    for(int i = 0; i<9; i++){
        m_board[i] = '1' + i;
    }
}

void GetUserInput(unsigned int& nput, char& current_player){
    while(true){
        nput = 0;
        std::cout << "(" << current_player << ") " << "Enter A Number 1-9: ";
        std::cin >> nput;
        std::cout << std::endl;
        if(nput>9 || nput<1){
            std::cout << "An Error Has Occured. Please Try Again." << std::endl;
        }
        else{
            break;
        }
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100,'\n');
        }
    }
}

int AskReplay(){
    char answer;
    std::cout << "Would you like to play again? ";
    std::cin >> answer;
    return (tolower(answer) == 'y');
}

void PrintBoard(Board& board1){
    const char* board_array = board1.GetBoard();
    for(int i = 0; i<9; i++){
        std::cout << board_array[i] << ", ";
    }
    std::cout << std::endl;
}

int CheckForWin(Board& board1, char cmark){
    // CREATE BETTER ALGO FOR TIC TAC TOE SOLVING
    
    const char* board_array = board1.GetBoard();
    
    return ((board_array[0]==cmark and board_array[1]==cmark and board_array[2]==cmark) ||
    (board_array[3]==cmark and board_array[4]==cmark and board_array[5]==cmark) ||
    (board_array[6]==cmark and board_array[7]==cmark and board_array[8]==cmark) ||

    (board_array[0]==cmark and board_array[3]==cmark and board_array[6]==cmark) ||
    (board_array[1]==cmark and board_array[4]==cmark and board_array[7]==cmark) ||
    (board_array[2]==cmark and board_array[5]==cmark and board_array[8]==cmark) ||

    (board_array[0]==cmark and board_array[4]==cmark and board_array[8]==cmark) ||
    (board_array[2]==cmark and board_array[4]==cmark and board_array[6]==cmark));
}