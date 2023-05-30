
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;

//create a deck of cards
vector<string> deck;
vector<string> suits;
vector<string> ranks;
vector<int> values;
vector<string> playerHand;
vector<string> dealerHand;
vector<string> playerSplitHand;
vector<string> dealerSplitHand;
int playerMoney = 1000;
int currentBet;
int winnings;
int playerScore;
int dealerScore;
bool gameOver = false;
bool playerBust = false;
bool playersTurn = true;
bool dealersTurn = false;
bool blackjack = false;
bool hasPair = false;



//Here, we create a deck of cards and use push_back to add the cards to the deck
void createDeck()
{
	suits.push_back("Hearts");
	suits.push_back("Diamonds");
	suits.push_back("Clubs");
	suits.push_back("Spades");
	ranks.push_back("Ace");
	ranks.push_back("Two");
	ranks.push_back("Three");
	ranks.push_back("Four");
	ranks.push_back("Five");
	ranks.push_back("Six");
	ranks.push_back("Seven");
	ranks.push_back("Eight");
	ranks.push_back("Nine");
	ranks.push_back("Ten");
	ranks.push_back("Jack");
	ranks.push_back("Queen");
	ranks.push_back("King");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck.push_back(ranks[j] + " of " + suits[i]);

		}
	}
}

//Here, we shuffle the deck of cards
void shuffleDeck()
{
	srand(time(0));
	for (int i = 0; i < 52; i++)
	{
		int j = rand() % 52;
		string temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}
//Here, we clear the deck and the hands, and then recreate the deck and shuffle it
void deckCleanup()
{
	deck.clear();
	playerHand.clear();
	dealerHand.clear();
	playerSplitHand.clear();
	dealerSplitHand.clear();
	playerScore = 0;
	dealerScore = 0;
	currentBet = 0;
	winnings = 0;
	playerBust = false;
	createDeck();
	shuffleDeck();

}
//This is the function to ask if the player wants to play again or quit
void playAgain()
{
	char choice;
	cout << "Would you like to play BlackJack? (Y/N)" << endl;
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		deckCleanup();

	}
	else if (choice == 'N' || choice == 'n')
	{
		gameOver = true;
	}
	else
	{
		cout << "Invalid input. Please enter Y or N." << endl;
		playAgain();
	}
	cout << " " << endl;
}
//Here, we ask the player how much they want to bet, and then subtract that amount from their total money
void placeBet()
{
	cout << "You have " << playerMoney << " credits." << endl;
	cout << "How much would you like to bet?" << endl;
	cin >> currentBet;
	while (currentBet > playerMoney)
	{
		cout << "You don't have that much money. Please enter a valid bet." << endl;
		cin >> currentBet;
	}
	playerMoney -= currentBet;
	cout << "You have bet " << currentBet << " credits." << endl;
	cout << "You now have " << playerMoney << " credits." << endl;
	cout << " " << endl;
	dealersTurn = false;
}
//Here, we deal the cards from the beginning of the deck array, push the card into the playerHand vector, and then erase the card from the deck array
void dealCards()
{
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << " " << endl;
	cout << "You have been dealt a " << playerHand[0] << endl;
	dealerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "The dealer has been dealt a face down card" << endl;
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "You have been dealt a " << playerHand[1] << endl;
	dealerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "The dealer has been dealt a " << dealerHand[1] << endl;
	cout << " " << endl;
	playersTurn = true;

}
//Here, we deal the cards from the beginning of the deck array, push the card into the playerSplitHand vector, and then erase the card from the deck array
void clearCards()
{
	playerHand.clear();
	dealerHand.clear();
	playerSplitHand.clear();
	dealerSplitHand.clear();
	playerBust = false;
	blackjack = false;
}
//Player can double their bet and hit one more time
void doubleDown()
{
	while (currentBet > playerMoney)
	{
		cout << "You don't have that much money. Please enter a valid bet." << endl;
	}
	playerMoney -= currentBet;
	currentBet *= 2;
}
//Here, we calculate the winnings based on the curretBet, and then add the winnings to the playerMoney
void betWinnings()
{
	winnings = currentBet * 2;
	playerMoney += winnings;
	cout << "Congratulations! You've won " << currentBet << " credits!" << endl;
	cout << "You now have " << playerMoney << " credits." << endl;
	cout << " " << endl;
	playersTurn = false;
	dealersTurn = false;
}
//Here, we keep track of the score, checking the hand vector for strings that contain the rank of the card, and then adding the appropriate value to the score.
int getScore(vector<string> hand)
{
	int score = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].find("Two") != string::npos)
		{
			score += 2;
		}
		else if (hand[i].find("Three") != string::npos)
		{
			score += 3;
		}
		else if (hand[i].find("Four") != string::npos)
		{
			score += 4;
		}
		else if (hand[i].find("Five") != string::npos)
		{
			score += 5;
		}
		else if (hand[i].find("Six") != string::npos)
		{
			score += 6;
		}
		else if (hand[i].find("Seven") != string::npos)
		{
			score += 7;
		}
		else if (hand[i].find("Eight") != string::npos)
		{
			score += 8;
		}
		else if (hand[i].find("Nine") != string::npos)
		{
			score += 9;
		}
		else if (hand[i].find("Ten") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Jack") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Queen") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("King") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Ace") != string::npos)
		{
			//If the score is over 21, we want the Ace to be worth 1 instead of 11.
			score += 11;
			if (score > 21)
			{
				score -= 10;
			}
		}

	}
	return score;
}
//Here, we check for a winner by comparing the scores of the player and the dealer against the value of 21 and then against eachother.
void checkWinner()
{
	int playerScore = getScore(playerHand);
	int dealerScore = getScore(dealerHand);
	if (playerScore > 21)
	{
		cout << "You busted! Dealer wins!" << endl;
	}
	else if (dealerScore > 21)
	{
		cout << "Dealer busted! You win!" << endl;
	}
	else if (playerScore > dealerScore)
	{
		cout << "You win!" << endl;
	}
	else if (dealerScore > playerScore)
	{
		cout << "Dealer wins!" << endl;
	}
	else if (dealerScore == playerScore)
	{
		cout << "It's a tie!" << endl;
	}
}
//Player can choose to end their turn and let the dealer play
void stand()
{
	cout << "You stand." << endl;
	playersTurn = false;
	dealersTurn = true;
	return;
}
//Here, we allow the player to hit
void hit()
{
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your score: " << getScore(playerHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "You busted! Dealer wins!" << endl;
		cout << endl;
		playersTurn = false;
		dealersTurn = false;
		playerBust = true;
		return;
	}
	if (getScore(playerHand) == 21)
	{
		cout << "You have 21!" << endl;
		cout << endl;
		betWinnings();
		blackjack = true;
	}
	else
	{
		cout << "Would you like to hit(H) again or stand(S)?" << endl;
		char choice;
		cin >> choice;
		if (choice == 'H' || choice == 'h')
		{
			hit();
		}
		if (choice == 'S' || choice == 's')
		{
			stand();
			playersTurn = false;
		}
	}
}
//player can choose to end the round
void pass()
{
	cout << "You pass. The Dealer wins!" << endl;
	playerMoney -= currentBet;
	playersTurn = false;
	dealersTurn = false;
}
//Here, we allow the player to hit their second hand after a split
void hitSecond()
{
	playerSplitHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your second hand: " << endl;
	for (int i = 0; i < playerSplitHand.size(); i++)
	{
		cout << playerSplitHand[i] << endl;
	}
	cout << "Your second score: " << getScore(playerSplitHand) << endl;
	if (getScore(playerSplitHand) > 21)
	{
		cout << "Your second hand busted!" << endl;
	}
	else
	{
		char choice;
		cout << "Would you like to hit your second hand again? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitSecond();
		}
		else if (choice == 'N' || choice == 'n')
		{
			playersTurn = false;
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			hitSecond();
		}
	}
}
//Here, we allow the player to hit their first hand after a split
void hitFirst()
{
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your first hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your first score: " << getScore(playerHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "Your first hand busted!" << endl;
	}
	else
	{
		char choice;
		cout << "Would you like to hit your first hand again? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitFirst();
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "Would you like to hit your second hand? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				hitSecond();
			}
			else if (choice == 'N' || choice == 'n')
			{
				playersTurn = false;
			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
				hitFirst();
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			hitFirst();
		}
	}
}
//Here, we allow the player to split a pair on the first turn
void split()
{
	//Adding the second card to the second hand.
	playerSplitHand.push_back(playerHand[1]);
	//Removing the second card from the first hand and adding it to the second hand.
	playerHand.erase(playerHand.begin() + 1);
	//Adding a card to the first player hand.
	playerHand.push_back(deck[0]);
	//Removing the card from the deck.
	deck.erase(deck.begin());
	//Adding a card to the second player hand.
	playerSplitHand.push_back(deck[0]);
	//Removing the card from the deck.
	deck.erase(deck.begin());
	//Displaying the hands and scores.
	cout << "Your first hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your first score: " << getScore(playerHand) << endl;
	cout << "Your second hand: " << endl;
	for (int i = 0; i < playerSplitHand.size(); i++)
	{
		cout << playerSplitHand[i] << endl;
	}
	cout << "Your second score: " << getScore(playerSplitHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "Your first hand busted!" << endl;

	}
	if (getScore(playerSplitHand) > 21)
	{
		cout << "Your second hand busted!" << endl;
	}
	if (getScore(playerHand) > 21 && getScore(playerSplitHand) > 21)
	{
		cout << "Both hands busted! Dealer wins!" << endl;
		playersTurn = false;
		dealersTurn = false;
		playAgain();
	}
	else
	{
		char choice;
		cout << "Would you like to hit your first hand? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitFirst();
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "Would you like to hit your second hand? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				hitSecond();
			}
			else if (choice == 'N' || choice == 'n')
			{
				playersTurn = false;
			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
				split();
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			split();
		}
	}
}
//This is the UI function for the player's turn
void playerTurnMenu()
{
	//check if player has a pair and change hasPair to true if they do
	if (playerHand[0] == playerHand[1])
	{
		hasPair = true;
		cout << "You have a pair! Would you like to split? (Y/N)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			split();
		}
		if (choice == 'N' || choice == 'n')
		{
			hasPair = false;
			playerTurnMenu();
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			playerTurnMenu();
		}
	}
	char choice;
	cout << "Your score is: " << getScore(playerHand) << endl;
	cout << "Would you like to hit, stand, double down or pass? (H/S/D/X)" << endl;
	cin >> choice;
	if (choice == 'H' || choice == 'h')
	{
		hit();
	}
	else if (choice == 'S' || choice == 's')
	{
		stand();
	}
	else if (choice == 'D' || choice == 'd')
	{
		doubleDown();
	}
	else if (choice == 'X' || choice == 'x')
	{
		pass();
	}
	else
	{
		cout << "Invalid choice. Try again." << endl;
		playerTurnMenu();
	}
}
//Here, we allow the dealer to hit and calculate the end result
void dealerTurn()
{
	//Displaying the dealer's hand and score, using recursion to hit if necessary
	cout << "Dealer's hand: " << endl;
	for (int i = 0; i < dealerHand.size(); i++)
	{
		cout << dealerHand[i] << endl;
		cout << " " << endl;
	}
	cout << "Dealer's score: " << getScore(dealerHand) << endl;
	//If the dealer has less than 17, they must hit, if they have over 17, they must stand. If they bust, the player wins. If they don't, we compare scores
	if (getScore(dealerHand) < 17)
	{
		cout << "Dealer hits." << endl;
		cout << " " << endl;
		dealerHand.push_back(deck[0]);
		deck.erase(deck.begin());
		dealerTurn();
	}
	else if (getScore(dealerHand) > 21)
	{
		cout << "Dealer busted! You win!" << endl;
		betWinnings();
	}
	else
	{
		if (getScore(playerHand) > getScore(dealerHand))
		{
			cout << "You win!" << endl;
			betWinnings();

		}
		else if (getScore(playerHand) < getScore(dealerHand))
		{
			cout << "Dealer wins!" << endl;
			dealersTurn = false;
		}
		else
		{
			cout << "Push!" << endl;
			playerMoney += currentBet;
			dealersTurn = false;
		}
	}
}



//This is the main game loop, where we call all of our functions and run the game
int main()
{



	cout << "Welcome to Big Dante's BlackJack Emporium!" << endl;
	cout << "You have " << playerMoney << " credits." << endl;
	cout << "" << endl;

	while (gameOver == false || playerMoney <= 0)
	{

		playAgain();
		if (playerMoney <= 0)
		{
			cout << "Unfortunately you're out of money! Now get out of our establishment, you filthy peasant." << endl;
			break;
		}
		playersTurn = false;
		if (gameOver == false)
		{
			createDeck();
			shuffleDeck();
			placeBet();
			dealCards();
			while (playersTurn == true && playerBust == false)
			{
				playerTurnMenu();
			}
			while (playersTurn == false && playerBust == false && dealersTurn == true && blackjack == false)
			{
				dealerTurn();
				break;
			}
		}
	}
		{
			cout << "Thanks for playing!" << endl;
		}
        
		

	
	return 0;


}



