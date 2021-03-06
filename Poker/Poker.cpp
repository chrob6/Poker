
#include "pch.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include "card.h"



int main()
{

	int money, Entry, PlayerMoney, ComputerMoney, pot, decision, PlayerBet, ComputerBet, round, oneortwo;
	Card *TableCard = new Card[5];
	Card PlayerCard1, PlayerCard2, ComputerCard1, ComputerCard2;
	bool turn = true;
	chosenCard * head = NULL;
	srand(time(NULL));
	
	ConsoleColorChanger("red");
	cout << "Welcome to Blackjack Poker by Marcin Chrobak" << endl;
	Sleep(2000);
	//cout << "Let's lose some money! How much?: " << endl;
	//cin >> money;
	money = 1000; // for tests

	Entry = 0.05 * money;
	PlayerMoney = money;
	ComputerMoney = money;

	while (1) {


		for (int i = 0; i < 9; i++) { // in future 7 will be amounts of players
			Card temp = RandomizeCard();

			if (head == NULL) {
				addToGoodCard(head, temp);
			}
			else {
				if (isCardUnique(head, temp)) addToGoodCard(head, temp);
				else i--;
			}
		}

		ConsoleColorChanger("White");

		pot = 2 * Entry;
		PlayerMoney -= Entry;
		ComputerMoney -= Entry;

		PlayerCard1 = AssignCard(head);
		PlayerCard2 = AssignCard(head);
		ComputerCard1 = AssignCard(head);
		ComputerCard2 = AssignCard(head);


		
		round = 0;
		PrintRound(round);

		LogMoneyState(PlayerMoney, ComputerMoney, pot);
		LogHand(PlayerCard1, PlayerCard2);
		cout << endl << endl;

		ComputerBet = -2;
		PlayerBet = -2;

		do {

			
			if (turn) {
				decision = MakingDecision(ComputerBet);

				PlayerBet = Turn(pot, decision, PlayerMoney, turn);
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
				Sleep(2000);
			}


			if (PlayerBet == -1) {
				ComputerMoney += pot;
				break;
			}

			if (turn == false) {
				ComputerBet = ComputerTurn(pot, ComputerMoney, turn, ComputerCard1, ComputerCard2, round, PlayerBet);
				cout << "Computer bet: ";
				cout << ComputerBet << endl << endl << endl;
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
			}

			if (ComputerBet == -1) {
				PlayerMoney += pot;
				break;
			}

		} while (PlayerBet != ComputerBet);


		cout << endl << endl;

		round++;
		PrintRound(round);
		

		ConsoleColorChanger("blue");
		for (int i = 0; i < 5; i++) {
			TableCard[i] = AssignCard(head);
			if (i < 3)
				cout << ValueChanger(TableCard[i].value) + ColorChanger(TableCard[i].color) << endl;
		}
		cout << endl;
		ConsoleColorChanger("white");

		LogMoneyState(PlayerMoney, ComputerMoney, pot);
		LogHand(PlayerCard1, PlayerCard2);
		cout << endl << endl;
		

		do {
			if (turn) {
				decision = MakingDecision(ComputerBet);

				PlayerBet = Turn(pot, decision, PlayerMoney, turn);
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
				Sleep(2000);
			}


			if (PlayerBet == -1) {
				ComputerMoney += pot;
				break;
			}

			if (turn == false) {
				ComputerBet = ComputerTurn(pot, ComputerMoney, turn, ComputerCard1, ComputerCard2, round, PlayerBet);
				cout << "Computer bet: ";
				cout << ComputerBet << endl << endl << endl;
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
			}

			if (ComputerBet == -1) {
				PlayerMoney += pot;
				break;
			}

		} while (PlayerBet != ComputerBet);

		round++;
		PrintRound(round);
		ConsoleColorChanger("blue");
		
		for (int i = 0; i < 4; i++) {
			cout << ValueChanger(TableCard[i].value) + ColorChanger(TableCard[i].color) << endl;
		}
		cout << endl;
		ConsoleColorChanger("white");

		LogMoneyState(PlayerMoney, ComputerMoney, pot);
		LogHand(PlayerCard1, PlayerCard2);
		cout << endl << endl;
		

		do {
			if (turn) {
				decision = MakingDecision(ComputerBet);
				PlayerBet = Turn(pot, decision, PlayerMoney, turn);
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
				Sleep(2000);
			}


			if (PlayerBet == -1) {
				ComputerMoney += pot;
				break;
			}

			if (turn == false) {
				ComputerBet = ComputerTurn(pot, ComputerMoney, turn, ComputerCard1, ComputerCard2, round, PlayerBet);
				cout << "Computer bet: ";
				cout << ComputerBet << endl << endl << endl;
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
			}

			if (ComputerBet == -1) {
				PlayerMoney += pot;
				break;
			}

		} while (PlayerBet != ComputerBet);

		round++;
		PrintRound(round);

		ConsoleColorChanger("blue");
		for (int i = 0; i < 5; i++) {
			cout << ValueChanger(TableCard[i].value) + ColorChanger(TableCard[i].color) << endl;
		}
		cout << endl;
		ConsoleColorChanger("white");



		LogMoneyState(PlayerMoney, ComputerMoney, pot);
		LogHand(PlayerCard1, PlayerCard2);
		cout << endl << endl;

		do {
			if (turn) {
				decision = MakingDecision(ComputerBet);
				PlayerBet = Turn(pot, decision, PlayerMoney, turn);
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
				Sleep(2000);
			}


			if (PlayerBet == -1) {
				ComputerMoney += pot;
				break;
			}

			if (turn == false) {
				ComputerBet = ComputerTurn(pot, ComputerMoney, turn, ComputerCard1, ComputerCard2, round, PlayerBet);
				cout << "Computer bet: ";
				cout << ComputerBet << endl << endl << endl;
				LogMoneyState(PlayerMoney, ComputerMoney, pot);
			}

			if (ComputerBet == -1) {
				PlayerMoney += pot;
				break;
			}

		} while (PlayerBet != ComputerBet);
		
		ConsoleColorChanger("blue");
		cout << endl << "WHO WIN?" << endl;
		for (int i = 0; i < 5; i++) {
			cout << ValueChanger(TableCard[i].value) + ColorChanger(TableCard[i].color) << endl;
		}
		ConsoleColorChanger("white");
		
		cout << endl << "1. Player: " << endl;
		LogHand(PlayerCard1, PlayerCard2);
		cout << endl << endl << "2. Computer " << endl;
		LogHand(ComputerCard1, ComputerCard2);
		cout << endl;
		cin >> oneortwo; // very complicated to write all the edge cases so player choose the winner DO NOT CHEAT!

		
		if (oneortwo == 1) {
			cout << endl << "player win the round!";
			PlayerMoney += pot;
			pot = 0;
		}
		else if (oneortwo == 2) {
			cout << endl << "computer win the round!";
			ComputerMoney += pot;
			pot = 0;
		}
		cout << endl;
		cout << "=================";
		cout << endl << endl;
		Sleep(2000);
		system("CLS");

		
		if (PlayerMoney <= 0) {
			cout << "COMPUTER WIN THE GAME!";
			break;
		}

		if (ComputerMoney <= 0) {
			cout << "PLAYER WIN THE GAME!";
			break;
		}
	}

	cin.get();

}


