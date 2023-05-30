#pragma once



vector<string> deck;
vector<string> suits;
vector<string> ranks;
vector<int> values;
vector<string> playerHand;
vector<string> dealerHand;
vector<string> playerSplitHand;
vector<string> dealerSplitHand;


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
	srand(time_t(0));
	for (int i = 0; i < 52; i++)
	{
		int j = rand() % 52;
		string temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

//Here, we deal the cards from the beginning of the deck array, push the card into the playerHand vector, and then erase the card from the deck array.
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

}

void clearCards()
{
	playerHand.clear();
	dealerHand.clear();
	playerSplitHand.clear();
	dealerSplitHand.clear();
}