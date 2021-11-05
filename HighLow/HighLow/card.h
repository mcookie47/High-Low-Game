#include <iostream>
#include <ctime>

using namespace std;
class Card {
	private:
		int rank;
		int suit;

	public:
		Card() {
			srand(time(NULL));
			rank = (1 + (std::rand() % (int)(13)));
			suit = (1 + (std::rand() % (int)(4)));
		}

		int get_rank() {
			return rank;
		}

		string get_rank_string() {
			if (rank == 1) return "Ace";
			if (rank == 2) return "Two";
			if (rank == 3) return "Three";
			if (rank == 4) return "Four";
			if (rank == 5) return "Five";
			if (rank == 6) return "Six";
			if (rank == 7) return "Seven";
			if (rank == 8) return "Eight";
			if (rank == 9) return "Nine";
			if (rank == 10) return "Ten";
			if (rank == 11) return "Jack";
			if (rank == 12) return "Queen";
			if (rank == 13) return "King";
			else return "Error";
		}

		int get_suit() {
			return suit;
		}

		string get_suit_string() {
			if (suit == 1) return "Diamonds";
			if (suit == 2) return "Hearts";
			if (suit == 3) return "Spades";
			if (suit == 4) return "Clubs";
			else return "Error";
		}
};
