#include "pch.h"
#include "card.h"



Card RandomizeCard() {

	Card card;
	int randVal = ((std::rand() % 13) + 1);
	int randCol = ((std::rand() % 4) + 1);
	card.value = randVal;
	card.color = randCol;
	return card;
}

bool isCardUnique(chosenCard* &head, Card randomized) {

	chosenCard* temp = head;
	while (temp) {
		if (temp->CantBeUsed.color == randomized.color && temp->CantBeUsed.value == randomized.value) {

			//RandomizeCard(temp2);
			//std::cout << "same!";
			return false;
		}
		temp = temp->next;
	}
	return true;
}

void addToGoodCard(chosenCard* &head, Card goodCard) {

	if (head == NULL) {
		chosenCard* temp = new chosenCard;
		temp->CantBeUsed = goodCard;
		temp->next = head;
		head = temp;
		return;
	}

	chosenCard* temp3 = new chosenCard;
	temp3->CantBeUsed = goodCard;
	temp3->next = head;
	head = temp3;

}

Card AssignCard(chosenCard* &head) {
	Card toReturn = head->CantBeUsed;
	chosenCard* temp = head;
	if (temp) {
		head = temp->next;
		delete temp;
	}
	return toReturn;
}

string ColorChanger(int color) {
	switch (color) {
	case 1: return " of hearts"; break;
	case 2: return " of spades"; break;
	case 3: return " of clubs"; break;
	case 4: return " of diamonds"; break;
	}
}

string ValueChanger(int value) {
	switch (value) {
	case 1: return "Ace"; break;
	case 2: return "Two"; break;
	case 3: return "Three"; break;
	case 4: return "Four"; break;
	case 5: return "Five"; break;
	case 6: return "Six"; break;
	case 7: return "Seven"; break;
	case 8: return "Eight"; break;
	case 9: return "Nine"; break;
	case 10: return "Ten"; break;
	case 11: return "Jack"; break;
	case 12: return "Queen"; break;
	case 13: return "King"; break;
	}
}

int MakingDecision(int ComputerBet) {
	int decision;

	
	cout << "1. Check	";
	cout << "2. Bet/Raise	";
	cout << "3. Pass	" << endl;
	//cout << "4. Call" << endl;
	cout << "Your turn: "; 
	cin >> decision;
	cout << endl;
	if (ComputerBet > 0 && decision == 1) {
		MakingDecision(ComputerBet);
	}

	if (decision == 1 || decision == 2 || decision == 3
		//|| decision == 4
	) return decision;
	else MakingDecision(ComputerBet);
}

void LogMoneyState(int PlayerMoney, int ComputerMoney, int pot) {
	cout << "Player Money: ";
	cout << PlayerMoney << endl;
	cout << "Computer Money: ";
	cout << ComputerMoney << endl;
	cout << endl;
	cout << "Pot: ";
	cout << pot << endl;
}

void LogHand(Card PlayerCard1, Card PlayerCard2) {
	ConsoleColorChanger("blue");
	cout << "Hand: " << endl;
	cout << ValueChanger(PlayerCard1.value) + ColorChanger(PlayerCard1.color) << endl;
	cout << ValueChanger(PlayerCard2.value) + ColorChanger(PlayerCard2.color);
	ConsoleColorChanger("white");
}

int Turn(int &pot, int decision, int &PlayerMoney, bool &turn) {

	int bet = 0;
	if (decision == 1) {

		turn = false;
		return bet;
	}
	else if (decision == 2) {
		turn = false;
		cout << "How Much?: ";
		cin >> bet;
		PlayerMoney -= bet;
		pot += bet;
		return bet;
	}
	else if (decision == 3) {
		turn = false;
		return -1;
	}
}

void Call(int Equalizer, int &pot, int &PlayerMoney) { // 
	PlayerMoney -= Equalizer;
	pot += Equalizer;
}

int ComputerTurn(int &pot, int &ComputerMoney, bool &turn, Card CompCard1, Card CompCard2, int round, int PlayerBet) {
	int bet = 0;

	int power = CompCard1.value + CompCard2.value;
	int decision = ((std::rand() % 10) + 1);

	if (round == 0) {
		if (PlayerBet == 0) { // Player checked
			if (CompCard1.value == 1 || CompCard2.value == 1 || power > 16) {  // good cards - Raise!
				if (decision > 7) {
					bet = 0.15 * ComputerMoney;
				}
				else {
					bet = 0.05 * ComputerMoney;
				}

				turn = true;
				pot += bet;
				ComputerMoney -= bet;
				return bet;
			}
			else {
				turn = true;
				return bet; // Check aswell
			}
		}
		else if (PlayerBet < ComputerMoney * 0.1) { // Player bet a little
			if (CompCard1.value == 1 || CompCard2.value == 1 || power > 16) { // goodCards
				if (decision > 7) { // Raise!
					bet = PlayerBet + 0.2 * ComputerMoney;
					turn = true;
					pot += bet;
					ComputerMoney -= bet;
					return bet;
				}
				else { // Call
					bet = PlayerBet;
					turn = true;
					pot += bet;
					ComputerMoney -= bet;
					return bet;
				}

			}
			else { // bad Card
				turn = true;
				return -1; // pass
			}
		}
		else { // PlayerBet much!
			if (CompCard1.value == 1 || CompCard2.value == 1 || power > 19) {
				bet = PlayerBet;
				turn = true;
				pot += bet;
				ComputerMoney -= bet;
				return bet; // Call
			}
			else {
				turn = true;
				return -1; // pass
			}
		}

		//turn = false;
		//return -10;
	}
	else if (round == 1) { // Flop
		if (PlayerBet == 0) {
			turn = true;
			return bet; // Check

		}
		else {
			bet = PlayerBet;
			turn = true;
			pot += bet;
			ComputerMoney -= bet;
			return bet; // Call

		}
	}
	else if (round == 2) { // Turn
		if (PlayerBet == 0) {
			turn = true;
			return bet;

		}
		else {
			bet = PlayerBet;
			turn = true;
			pot += bet;
			ComputerMoney -= bet;
			return bet; // Call

		}
	}
	else if (round == 3) { // river
		if (PlayerBet == 0) {
			turn = true;
			return bet;

		}
		else {
			bet = PlayerBet;
			turn = true;
			pot += bet;
			ComputerMoney -= bet;
			return bet; // Call
		}
	}
}

void ConsoleColorChanger(string color) {
	int chosenColor;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "RED" || color == "red" || color == "Red") {
		chosenColor = 0x0004; 
	}
	if (color == "BLUE" || color == "blue" || color == "Blue") {
		chosenColor = 0x0003; //cyan
	}
	if (color == "GREEN" || color == "green" || color == "Green") {
		chosenColor = 0x0002;// green
	}
	if (color == "WHITE" || color == "white" || color == "White") {
		chosenColor = 0x0007;   
	}
	if (color == "YELLOW" || color == "yellow" || color == "Yellow") {
		//chosenColor = 0x0005;  violet
		chosenColor = 0x0006;
	}
	SetConsoleTextAttribute(hOut, chosenColor);
}

void PrintRound(int round) {
	ConsoleColorChanger("yellow");
	if (round == 0) {
		cout << "PREFLOP: " << endl << endl;
	}
	if (round== 1) {
		cout << "FLOP: " << endl << endl;
	}
	if (round == 2) {
		cout << "TURN: " << endl << endl;
	}
	if (round == 3) {
		cout << "RIVER: " << endl << endl;
	}
	ConsoleColorChanger("white");

}