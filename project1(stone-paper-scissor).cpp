#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;

enum enChoice{stone=1,paper=2,scissors=3};

int ReadNumberOfRound() {
	int number;
	do {
		cout << "How many round 1 to 10 ?" << endl;
		cin >> number;
	} while (number < 1 || number>10);

	return number;
}

void ShowGameOverScreen() {
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t+++Game Over+++\n" << endl;
	cout<< "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t---------------------------[Game result]----------------------" << endl;
	
}

void ShowFinalResult(int number,int DrawTimes, int Player1Times, int computerTimes) {
	ShowGameOverScreen();
	cout << "\t\tGame Round :" << number<<endl;
	cout << "\t\tPlayer1 Won Time :" << Player1Times << endl;
	cout << "\t\tDraw Times :" << DrawTimes << endl;
	cout << "\t\t computer Winner Times:" << computerTimes << endl;
	cout <<endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	if (Player1Times == computerTimes) {
		cout << "\t\tNo Winner " << endl;

	}
	else if(Player1Times < computerTimes) {
		cout << "\t\tcomputer won" << endl;

	}
	else {
		cout << "\t\tplay1 won" << endl;
	}
}

enChoice ReadRandomOptions() {
     int  Randcom= rand() % 3 + 1;
	  return (enChoice) Randcom;
}

string ChoiceToString(enChoice choice) {
	switch (choice) {
	case stone:
		return "stone";
		
	case paper:
		return "paper";

	case scissors:
		return "scissors";

	default:
		return "unknown";

	}
}

void startGame(int number) {
	enChoice computerChoice;
	enChoice playerChoice;
	string  RoundWinner;
	int playerInput;
	int DrawTimes=0;
	int Player1Times = 0;
	int computerTimes = 0;

	
	for (int i = 1;i <= number;i++) {

		cout << "Round [" << i << "] begins :" << endl;


		do {
			cout << "you choise : [1]:stone,[2]:paper,[3]:scissors ?";
			cin >> playerInput;

		} while (playerInput < 1 || playerInput > 3);

		
		 playerChoice = (enChoice)playerInput;
		computerChoice = ReadRandomOptions();

		cout << "______________________Round[" << i << "]____________________________" << endl;
		cout << "\n\tPlayer1 choise: " << ChoiceToString(playerChoice) << endl;
		cout << "\tComputerChoise : " << ChoiceToString(computerChoice) << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << endl;
		if (playerChoice== computerChoice) {
			system("color E0");
			RoundWinner = "[No Winner]";
			DrawTimes++;
			

		}
		else if ((playerChoice == stone && computerChoice == scissors) || (playerChoice == paper && computerChoice == stone) || (playerChoice == scissors && computerChoice == paper))
		{
			
			system("color 2F");
			RoundWinner = "[player1won]";
			Player1Times++;
		}
		else {
			cout << "\a";
			system("color 4F ");
			RoundWinner = "[computer won]";
			computerTimes++;
		}

		cout << "\tRound Winner : " << RoundWinner << endl;
		cout << endl;

	}

	ShowFinalResult( number,  DrawTimes,  Player1Times, computerTimes);
	
}

char ResetScreen() {
	char yesno;
	cout << "Do you want to play again(y/n) ?" << endl;
	cin >> yesno;
	if (yesno == 'y' || yesno == 'Y'){
		system("color 07");
		system("cls");
	}
	return yesno;

	
}

int main()
{
	srand((unsigned)time(NULL));

	char answer;

	do {
		int number = ReadNumberOfRound();
		startGame(number);

		answer = ResetScreen();

	} while (answer == 'y'||answer=='Y');

	cout << "Game ended. Goodbye!" << endl;

	return 0;

}

