#include <iostream>
#include "core.h"

void RenderBoard(Board& board1){
    const char* board_array = board1.GetBoard();
    for(int i = 0; i<3; i++){
        std::cout << "       " << "     |     |     " << std::endl;
        std::cout << "       " << "  " << board_array[0+(i*3)] << "  |  " << board_array[1+(i*3)] << "  |  " << board_array[2+(i*3)] << std::endl;
        std::cout << "       " << (!(i>1) ? "_____|_____|_____" : "     |     |    ") << std::endl;
    }
}