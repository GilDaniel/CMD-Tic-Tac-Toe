#include <iostream>
#include <vector>
#include "headers.h"

std::vector<char> character = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

bool isBallTurn = true;
bool won = false;

int main(){
    
    std::cout <<"The new CMD Tick Tack Toe\n\n";
    
    display(character);
    Instructions();
    
    
    

    while(!won){
        
        if(isBallTurn){
            std::cout << "It's the 'O' turn.\n";
            character = AddToCharacter(GetInput(),isBallTurn,character);
            display(character);
             
        }
        else{
            std::cout << "It's the 'X' turn.\n";
            character = AddToCharacter(GetInput(),isBallTurn,character);
            display(character);
             
        }
        short int result = CheckWin(character);
        
        switch (result)
        {
        case 1:
            std::cout <<"\nO won !!!\n\n\n";
            won = true;
            break;
        case 2:
            std::cout <<"\nX won !!!\n\n\n";
            won = true;
            break;
        case 3:
            std::cout <<"\nTIE !!!\n\n\n";
            won = true;
            break;
        default:
            won = false;
            break;    
        }
        
        isBallTurn = !isBallTurn;
    }
    
    
    int keepopen;
    std::cin >> keepopen;
}