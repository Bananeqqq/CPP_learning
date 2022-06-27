#include <iostream>
#include <conio.h>
#include <limits>
#include <stdlib.h>
#include <string>


void cinCheck();
void board();
void resetBoard();
int checkWin();
void playW_bot();
void playW_friend();
void squareCheck(int& player);
int bot_squareCheck();
bool playWithBot{false};

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int win{0};

int choice; //player's move
char mark;	//player's mark
int steps{0};


int main() {

	bool playAgain{false};
	int playW_choice{0};

	do{	
		std::cout << "Hey, wanna play with a bot, or with a friend?\n";
		std::cout << "1. With a friend\n"; 	//press 1
		std::cout << "2. With a bot\n";		//press 2
		std::cout << "Your choice: ";
		std::cin >> playW_choice;
		
		if (playW_choice == 1) {
			playWithBot = false;
			playW_friend();
		}
		else if (playW_choice == 2) {
			playWithBot = true;
			playW_bot();
		}
		else {
			std::cout << "Invalid input.\n";
			cinCheck();
		}


		std::cout << "\n\tPlay again? (y/n): ";
		char answer;
		std::cin >> answer;
		if (answer == 'y') {
			resetBoard();
			playAgain = true;
		}else playAgain = false;
		
	}while(playAgain);
	return 0;
}

void board(){
	system("cls");
	std::cout << "\n\tTicTacToe \n";

	if (playWithBot) std::cout << "   Bot: X\tPlayer: O\n\n";
	else std::cout << "Player 1: X\tPlayer 2: O\n\n";
	
	
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
	system("cls");
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

void playW_bot(){
	
	// int player{1}; 
	int player = std::rand() % 2 + 1;	// 1 for bot, 2 for player
	std::string player_name;
	do{
		board();
		player = (player % 2) ? 1 : 2;
		mark = (player == 1) ? 'X' : 'O'; //player's mark is X, bot's mark is O
		player_name = (player == 1) ? "Bot" : "Player";


		if (player_name == "Bot"){

			choice = bot_squareCheck();
			squareCheck(player); 

		}else{

			std::cout << "\nChoose a square: ";
			std::cin >> choice;
			cinCheck();
			squareCheck(player);
			steps++;
		}
	}while(win == 0);

	board();
	--player;
	player = (player % 2) ? 1 : 2;
	player_name = (player == 1) ? "Bot" : "Player";

	if (win == 1) std::cout << "\n\t" << player_name << " wins!" << std::endl;
	else std::cout << "\n\tIt's a tie!" << std::endl;
}

int bot_squareCheck(){ //stupid, but simple for smaller boards
	if (steps >= 2){
		if (square[1] == 'O' && square[2] == 'O' && square[3] == '3') return 3;
		else if (square[4] == 'O' && square[5] == 'O' && square[6] == '6') return 6;
		else if (square[7] == 'O' && square[8] == 'O' && square[9] == '9') return 9;
		else if (square[1] == 'O' && square[4] == 'O' && square[7] == '7') return 7;
		else if (square[2] == 'O' && square[5] == 'O' && square[8] == '8') return 8;
		else if (square[3] == 'O' && square[6] == 'O' && square[9] == '9') return 9;
		else if (square[1] == 'O' && square[5] == 'O' && square[9] == '9') return 9;
		else if (square[3] == 'O' && square[5] == 'O' && square[7] == '7') return 7;

		else if (square[1] == 'O' && square[2] == '2' && square[3] == 'O') return 2;
		else if (square[4] == 'O' && square[5] == '5' && square[6] == 'O') return 5;
		else if (square[7] == 'O' && square[8] == '8' && square[9] == 'O') return 8;
		else if (square[1] == 'O' && square[4] == '4' && square[7] == 'O') return 4;
		else if (square[2] == 'O' && square[5] == '5' && square[8] == 'O') return 5;
		else if (square[3] == 'O' && square[6] == '6' && square[9] == 'O') return 6;
		else if (square[1] == 'O' && square[5] == '5' && square[9] == 'O') return 5;
		else if (square[3] == 'O' && square[5] == '5' && square[7] == 'O') return 5;
		
		else if (square[1] == '1' && square[2] == 'O' && square[3] == 'O') return 1;
		else if (square[4] == '4' && square[5] == 'O' && square[6] == 'O') return 4;
		else if (square[7] == '7' && square[8] == 'O' && square[9] == 'O') return 7;
		else if (square[1] == '1' && square[4] == 'O' && square[7] == 'O') return 1;
		else if (square[2] == '2' && square[5] == 'O' && square[8] == 'O') return 2;
		else if (square[3] == '3' && square[6] == 'O' && square[9] == 'O') return 3;
		else if (square[1] == '1' && square[5] == 'O' && square[9] == 'O') return 1;
		else if (square[3] == '3' && square[5] == 'O' && square[7] == 'O') return 3;
		else {
			bool isnum = true;
			int n{0};
			do{
				n = std::rand() % 57 + 49;
				char num = n;
				if (num == square[n-48]){
					isnum = false;	
				}
				
			}while(isnum);
			
			return n-48;
		}
	}
	else {
		bool isnum = true;
		int n{0};
		do{
			n = std::rand() % 57 + 49;
			char num = n;
			if (num == square[n-48]){
				isnum = false;	
			}

		}while(isnum);
			
		return n-48;
	}
}


void playW_friend(){
	int player = std::rand() % 2 + 1;

	do{
		board();
		player = (player % 2) ? 1 : 2;
		mark = (player == 1) ? 'X' : 'O';
		std::cout << "\nPlayer " << player << " choose a square: ";
		std::cin >> choice;
		
		cinCheck();

		squareCheck(player);

	}while(win==0);

	board();
	if (win == 1) std::cout << "\n\tPlayer " << --player << " wins!" << std::endl;
	else std::cout << "\n\tIt's a tie!" << std::endl;
}

void squareCheck(int& player){

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
	
}

void cinCheck(){
	if (!std::cin){ //if input is not an integer
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
}
