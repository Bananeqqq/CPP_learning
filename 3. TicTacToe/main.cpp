#include <iostream>
#include <conio.h>
#include <limits>

void board();
void resetBoard();
int checkWin();

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


int main() {
	int win{0};
    int player{1};
	int choice;
	char mark;
	bool playAgain{false};

	do{
		do{
			board();
			player = (player % 2) ? 1 : 2;
			mark = (player == 1) ? 'X' : 'O';
			std::cout << "\nPlayer " << player << " choose a square: ";
			std::cin >> choice;
			
			if (!std::cin){ //if input is not an integer
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			
			if (choice == 1 && square[1] == '1') square[1] = mark;
			else if(choice == 2 && square[2] == '2') square[2] = mark;
			else if(choice == 3 && square[3] == '3') square[3] = mark;
			else if(choice == 4 && square[4] == '4') square[4] = mark;
			else if(choice == 5 && square[5] == '5') square[5] = mark;
			else if(choice == 6 && square[6] == '6') square[6] = mark;
			else if(choice == 7 && square[7] == '7') square[7] = mark;
			else if(choice == 8 && square[8] == '8') square[8] = mark;
			else if(choice == 9 && square[9] == '9') square[9] = mark;
			else {
				//std::cout << "\nInvalid choice! Press enter to continue...";
				player--;
				//_getch();
			}

			win = checkWin();
			player++;
			
		}while(win==0);

		board();
		if (win == 1) {
			std::cout << "\n\tPlayer " << --player << " wins!" << std::endl;
		}
		else {
			std::cout << "\n\tIt's a tie!" << std::endl;
		}

		std::cout << "\n\tPlay again? (y/n): ";
		char answer;
		std::cin >> answer;
		if (answer == 'y') {
			resetBoard();
			playAgain = true;
		}
		else {
			playAgain = false;
		}

	}while(playAgain);
	return 0;
}


void board(){
	system("cls");
	std::cout << "\n\tTicTacToe \n";
	std::cout << "Player 1: X\tPlayer 2: O\n\n";

	std::cout << "\t" << square[1] << " | " << square[2] << " | " << square[3] << "\n";
	std::cout << "\t" << "---------\n";
	std::cout << "\t" << square[4] << " | " << square[5] << " | " << square[6] << "\n";
	std::cout << "\t" << "---------\n";
	std::cout << "\t" << square[7] << " | " << square[8] << " | " << square[9] << "\n";
}

void resetBoard(){
	for (int i = 1; i < 10; i++) {
		square[i] = i + '0';
	}
}

int checkWin(){ //0 game is in progress, 1 someone wins, 2 tie
	if (square[1] == square[2] && square[2] == square[3]){
		return 1;
	}
	else if (square[4] == square[5] && square[5] == square[6]){
		return 1;
	}
	else if (square[7] == square[8] && square[8] == square[9]){
		return 1;
	}
	else if (square[1] == square[4] && square[4] == square[7]){
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8]){
		return 1;
	}
	else if (square[3] == square[6] && square[6] == square[9]){
		return 1;
	}
	else if (square[1] == square[5] && square[5] == square[9]){
		return 1;
	}
	else if (square[3] == square[5] && square[5] == square[7]){
		return 1;
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
		return 2;
	}
	else{
		return 0;
	}
}
