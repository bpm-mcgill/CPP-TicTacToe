#pragma once
#include <iostream>

class Board{
private:
    char m_board[9];
public:
    Board();
    ~Board();
    const char* GetBoard() const;
    void SetPosition(const int& position, char letter);
    void ClearBoard();
};

void PrintBoard(Board& board1);
void GetUserInput(unsigned int& nput, char& current_player);
int CheckForWin(Board& board1, char cmark);
int AskReplay();