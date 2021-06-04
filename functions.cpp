#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> fullspaces;

void display( std::vector<char> character ){
    std::cout << character[6] << "|" << character[7] << "|" << character[8] <<"\n";
    std::cout << "-" << "-" << "-" << "-" << "-" <<"\n";
    std::cout << character[3] << "|" << character[4] << "|" << character[5] <<"\n";
    std::cout << "-" << "-" << "-" << "-" << "-" <<"\n";
    std::cout << character[0] << "|" << character[1] << "|" << character[2] <<"\n";
}
void Instructions(){
    fullspaces.push_back(0);
    std::cout << "Instructions:\n\n";
    std::cout << "For choosing where to mark, type the corresponding number\n";
    
    std::cout << "7,8,9\n";
    std::cout << "4,5,6\n";
    std::cout << "1,2,3\n";
}
bool CheckIfIsEmpty(int inp){
    
        for (int i = 0; i <9; i++)
        {
            if(fullspaces[i] == inp){
                return false;
            }
        }
        return true;
}
int GetInput(){
    
    int inp;
    std::cin >>inp;
    
    
    while (inp >9 || inp <0 || CheckIfIsEmpty(inp) == false)
    {
        std::cout << "Invalid Number, try again.\n";
        std::cin >>inp;
        
    }

    
    return inp; 
}

std::vector<char> AddToCharacter(int inputnum,bool isball,std::vector<char> character){
    
    if(isball){
        character[inputnum-1] = 'O';
        fullspaces.push_back(inputnum);
    }
    else{
        character[inputnum-1] = 'X';
        fullspaces.push_back(inputnum);
    }
    return character;
}
short int CheckWin(std::vector<char> cha){
    //Check if win
    std::vector<std::vector<int>> combinations = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {6,3,0},
        {7,4,1},
        {8,5,2},
        {0,4,8},
        {6,4,2},
    };

    for (int i = 0; i < combinations.size(); i++)
    {
        int combinquantO= 0;
        int combinquantX= 0;
        for (int a = 0; a < combinations[i].size(); a++)
        {
            
            if(cha[combinations[i][a]] == 'O'){
                combinquantO++;
                
            }
            else if(cha[combinations[i][a]] == 'X'){
                combinquantX++;
                
            }
            

        }
        
        if (combinquantO  == 3)
        {
            //opam alguem ganhou ai o
            return 1;
        }
        else if (combinquantX  == 3)
        {
            //opam alguem ganhou ai o
            return 2;
        }
    }


    int howmanyworemarked = 0;
    for (int i = 0; i < cha.size(); i++)
    {
        if(cha[i] != ' '){
            howmanyworemarked++;
        }   
    }
    if(howmanyworemarked >=9){
        return 3;
    }

    return 0;   
}