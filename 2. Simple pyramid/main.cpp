#include<iostream>

int main(){

    int height = 1;
    int width = 1;
    char symbol;

    
    std::cout << "Height: ";
    std::cin >> height;
    

    std::cout << "Enter symbol: ";
    std::cin >> symbol;
    std::cout << "\n";


    for (int h = 0; h < height; ++h){
        for (int j = 0; j <= h; ++j){
            std::cout << symbol;
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (int h = 0; h < height; ++h){
        for (int j = height-h; j >= 1; --j){
            std::cout << symbol;
        }
        std::cout << "\n";
    }

    std::cout << "\n";


    int num_of_symbols{1};
    int spaces = height - 1;
    for (int h = 0; h < height; ++h){

        for (int j = spaces; j >= 0; --j){ //spaces in front of the first symbol
            std::cout << " ";
        }

        for (int i = 0; i < num_of_symbols; ++i){ //symbols after the spaces
            std::cout << symbol;
        }

       std::cout << "\n";
       spaces = (spaces == 0) ? 0 : --spaces;
       num_of_symbols += 2;
    }
    

    std::cout << "\n";
    num_of_symbols = 2*height-1;
    spaces = 0;
    for (int h = 0; h < height; ++h){

        for (int j = spaces; j >= 0; --j){ //spaces in front of the first symbol
            std::cout << " ";
        }

        for (int i = 0; i < num_of_symbols; ++i){ //symbols after the spaces
            std::cout << symbol;
        }

       std::cout << "\n";
       spaces = (spaces == height) ? height : ++spaces;
       num_of_symbols -= 2;
    }

    /*

    ....*....
    ...***....
    ..*****....
    .*******....
    *********
    
    */


    return 0;
}
