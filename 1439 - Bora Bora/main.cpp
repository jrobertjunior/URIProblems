#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct card
{
    short   rank;
    char    suit;
    card()
    {
        rank = 0;
        suit = 0;
    }

    bool isBlanc()
    {
        if(rank == 0 && suit == 0)
        {
            return true;
        }
        return false;
    }

    bool operator<(const card& c) const
    {
        if(this->rank == c.rank)
        {
            return suit < c.suit;
        }
        return this->rank < c.rank;
    }

    bool operator==(const card& c) const
    {
        if(this->rank == c.rank &&
                this->suit == c.suit)
        {
            return true;
        }
        return false;
    }

};

struct player
{
    list<card> clubs;
    list<card> diamonds;
    list<card> hearts;
    list<card> spades;

    inline bool isEmpty()
    {
        if(clubs.size() || diamonds.size() || hearts.size() || spades.size())
        {
            return false;
        }
        return true;
    }

    inline void DrawnCard(card newCard)
    {

        if (newCard.suit == 'C')
        {
            clubs.push_back(newCard);
            clubs.sort();
        }
        else if (newCard.suit == 'D')
        {
            diamonds.push_back(newCard);
            diamonds.sort();
        }
        else if (newCard.suit == 'H')
        {
            hearts.push_back(newCard);
            hearts.sort();
        }
        else if (newCard.suit == 'S')
        {
            spades.push_back(newCard);
            spades.sort();
        }
    }

    inline card topNumber(short number, list<card> cards)
    {
        card ret;
        for(list<card>::iterator it = cards.begin(); it!=cards.end(); ++it)
        {
            if(it->rank == number)
            {
                return *it;
            }
        }
        return ret;
    }

    void remove(short number,  list<card> *cards)
    {
        for(list<card>::iterator it = cards->begin(); it!=cards->end(); ++it)
        {
            if(it->rank == number)
            {
                cards->remove(*it);
                break;
            }
        }
    }

    card DiscardCard(card topCard)
    {
        card tempCard;
        if (topCard.suit == 'C' && clubs.size() > 0)
        {
            tempCard = clubs.back();
            if(tempCard.rank > topCard.rank)
            {
                clubs.pop_back();
                return tempCard;
            }
        }
        else if (topCard.suit == 'D' && diamonds.size() > 0)
        {
            tempCard = diamonds.back();
            if(tempCard.rank > topCard.rank)
            {
                diamonds.pop_back();
                return tempCard;
            }
        }
        else if (topCard.suit == 'H' && hearts.size() > 0)
        {
            tempCard = hearts.back();
            if(tempCard.rank > topCard.rank)
            {
                hearts.pop_back();
                return tempCard;
            }
        }
        else if (topCard.suit == 'S' && spades.size() > 0)
        {
            tempCard = spades.back();
            if(tempCard.rank > topCard.rank)
            {
                spades.pop_back();
                return tempCard;
            }
        }

        card findMe = topNumber(topCard.rank, spades);
        if(findMe.rank == 0)
        {
            findMe = topNumber(topCard.rank, hearts);
            if(findMe.rank == 0)
            {
                findMe = topNumber(topCard.rank, diamonds);
                if(findMe.rank == 0)
                {
                    findMe = topNumber(topCard.rank, clubs);
                }
            }
        }

        if(findMe.rank > tempCard.rank)
        {
        	tempCard = findMe;
        }
        else if(findMe.rank == tempCard.rank)
        {
        	if(findMe.suit > tempCard.suit)
        	{
        		tempCard = findMe;
        	}
        }

        if(tempCard.suit > 0)
        {
        	remove(tempCard.rank,
        			(tempCard.suit == 'D') ? &diamonds :
        					(tempCard.suit == 'S') ? &spades :
        							(tempCard.suit == 'C') ? &clubs : &hearts
					);
        }


        return tempCard;
    }
};

void printDeck(list<card> cards)
{
   for(list<card>::iterator it = cards.begin(); it!=cards.end(); ++it)
   {
	   cout << "[" << it->rank << "] ";
   }
}

void printDeck(vector<card> cards)
{
   for(vector<card>::iterator it = cards.begin(); it!=cards.end(); ++it)
   {
	   cout << "[" << it->rank << "] ";
   }
}

inline int getNextPlayer(int player, int nextPlayer, int players)
{
    if(player == 0 && nextPlayer == -1)
    {
        player = players-1;
    }
    else if (player == players-1 && nextPlayer == 1)
    {
        player = 0;
    }
    else
    {
        player += nextPlayer;
    }
    return player;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int players, hand, deck;


    while(cin >> players)
    {
        if (players == 0)
        {
            break;
        }
        cin >> hand >> deck;

        player *playersList = new player[players];
        vector<card> discardPile;
        vector<card> stockPile;

        // reading cards for players
        for(int i = 0; i < players; i++)
        {
            for(int j = 0; j < hand; j++)
            {
                card c;
                cin >> c.rank >> c.suit;
                playersList[i].DrawnCard(c);
            }
        }
        card c;
        cin >> c.rank >> c.suit;
        discardPile.push_back(c);

        // reading rest of cards;
        for(int j = 0; j < deck - (players*hand + 1); j++)
        {
            card c;
            cin >> c.rank >> c.suit;
            stockPile.push_back(c);
        }

        reverse(stockPile.begin(),stockPile.end());
        int winner = 0;
        int player = 0;
        int nextPlayer = 1;
        bool discaded = true;
        while(!winner)
        {
//        	cout << "--------------------------------------------------------------------" << endl;
//        	cout << "current player:: " << player << endl;
//        	cout << "current top [" << discardPile.back().rank << "|" << discardPile.back().suit << "]" << endl;
//        	cout << "deck: "; printDeck(stockPile); cout << endl;
////        	for(int pp = 0; pp < players; pp++)
////        	{
//        		//cout << "p: " << pp << endl;
//        		cout << "clubs: \t"; printDeck(playersList[player].clubs); cout << endl;
//        		cout << "diamonds: \t"; printDeck(playersList[player].diamonds); cout << endl;
//        		cout << "spades: \t"; printDeck(playersList[player].spades); cout << endl;
//        		cout << "hearts: \t"; printDeck(playersList[player].hearts); cout << endl;
//        		cout << endl;
////        	}
//        	cout << "--------------------------------------------------------------------" << endl;
            if(discaded)
            {
                card discardTop = discardPile.back();
                discaded = false;

                if(discardTop.rank == 12)
                {
                    nextPlayer *= -1;
                }
                else if (discardTop.rank == 7)
                {
                    playersList[player].DrawnCard(stockPile.back());
                    stockPile.pop_back();

                    playersList[player].DrawnCard(stockPile.back());
                    stockPile.pop_back();

                    player = getNextPlayer(player, nextPlayer, players);
                    continue;
                }
                else if (discardTop.rank == 1)
                {
                    playersList[player].DrawnCard(stockPile.back());
                    stockPile.pop_back();
                    player = getNextPlayer(player, nextPlayer, players);
                    continue;

                }
                else if (discardTop.rank == 11)
                {
                    player = getNextPlayer(player, nextPlayer, players);
                    continue;
                }
            }


            card discarded = playersList[player].DiscardCard(discardPile.back());

            if ( discarded.rank != 0)
            {
                discardPile.push_back(discarded);
                if(discarded.rank != 12)
                {
                	discaded = true;
                }
                else
                {
                	discaded = false;
                	nextPlayer *= -1;
                }
            }
            else
            {
                playersList[player].DrawnCard(stockPile.back());
                stockPile.pop_back();
                card discarded = playersList[player].DiscardCard(discardPile.back());
                if ( discarded.rank != 0)
                {
                    discardPile.push_back(discarded);
                    if(discarded.rank != 12)
					{
						discaded = true;
					}
					else
					{
						discaded = false;
						nextPlayer = -1;
					}
                }
            }


            if (playersList[player].isEmpty())
            {
                winner = player+1;
            }
            else
            {
                player = getNextPlayer(player, nextPlayer, players);
            }
        }
        cout << winner << endl;
    }
}
