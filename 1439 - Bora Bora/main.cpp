/**
 * @autor Jose Junior
 * 1439 - Bora Bora
 * Runtime : 0.000s
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// Just to debug
const char cHeart[]         = "\xe2\x99\xa5";
const char cClub[]      	= "\xe2\x99\xa3";
const char cSpade[]         = "\xe2\x99\xa0";
const char cDiamond[]   	= "\xe2\x99\xa6";


using namespace std;

struct card
{
    short rank;
    char suit;

    card(): rank(0), suit(0){}

    // Just to debug
    void printCard()
    {
        if(rank > 0 && suit > 0)
        {
            const char* symbol = (suit == 'H') ? cHeart : (suit == 'C') ?  cClub : (suit == 'S') ? cSpade : cDiamond;
            cout << "[";
            if (rank > 1 && rank < 11){ cout << rank; }
            else if (rank == 1) {   cout << 'A'; }
            else if (rank == 11){   cout << 'J'; }
            else if (rank == 12){   cout << 'Q'; }
            else if (rank == 13){   cout << 'K'; }

            cout << symbol;
            cout << "]";
        }
    }

    bool isBlanc()
    {
        if(rank == 0 && suit == 0)
        {
            return true;
        }
        return false;
    }

    bool operator<(const card& card) const
    {
        if(this->rank == card.rank)
        {
            return suit < card.suit;
        }
        return this->rank < card.rank;
    }

    bool operator==(const card& card) const
    {
        if(this->rank == card.rank &&
                this->suit == card.suit)
        {
            return true;
        }
        return false;
    }
};

// Just to debug
void printDeck(vector<card> cards)
{
   for(vector<card>::iterator it = cards.begin(); it!=cards.end(); ++it)
   {
       it->printCard(); cout << " ";
   }
   cout << endl;
}

// Just to debug
void printDeck(list<card> cards)
{
   for(list<card>::iterator it = cards.begin(); it!=cards.end(); ++it)
   {
       it->printCard(); cout << " ";
   }
   cout << endl;
}


struct player
{
    list<card> clubs;
    list<card> diamonds;
    list<card> hearts;
    list<card> spades;

    bool isHandEmpty()
    {
        if(clubs.size() || diamonds.size() || hearts.size() || spades.size())
        {
            return false;
        }
        return true;
    }

    void addCard(card newCard)
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

    void DrawnCard(vector<card> *stack, int numberOfCards)
    {

        for(int i = 0 ; i < numberOfCards; i++)
        {
            card newCard  = stack->back();
            stack->pop_back();
            addCard(newCard);
        }
    }

    card findSameRank(short number, list<card> cards)
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
                cards->erase(it);
                break;
            }
        }
    }

    card DiscardCard(card topCard)
    {
        card discardedCard;
        if (topCard.suit == 'C' && clubs.size() > 0)
        {
            discardedCard = clubs.back();
            if(discardedCard.rank > topCard.rank)
            {
                clubs.pop_back();
                return discardedCard;
            }
        }
        else if (topCard.suit == 'D' && diamonds.size() > 0)
        {
            discardedCard = diamonds.back();
            if(discardedCard.rank > topCard.rank)
            {
                diamonds.pop_back();
                return discardedCard;
            }
        }
        else if (topCard.suit == 'H' && hearts.size() > 0)
        {
            discardedCard = hearts.back();
            if(discardedCard.rank > topCard.rank)
            {
                hearts.pop_back();
                return discardedCard;
            }
        }
        else if (topCard.suit == 'S' && spades.size() > 0)
        {
            discardedCard = spades.back();
            if(discardedCard.rank > topCard.rank)
            {
                spades.pop_back();
                return discardedCard;
            }
        }

        card findMe = findSameRank(topCard.rank, spades);
        if(findMe.rank == 0)
        {
            findMe = findSameRank(topCard.rank, hearts);
            if(findMe.rank == 0)
            {
                findMe = findSameRank(topCard.rank, diamonds);
                if(findMe.rank == 0)
                {
                    findMe = findSameRank(topCard.rank, clubs);
                }
            }
        }

        if(findMe.rank > discardedCard.rank)
        {
            discardedCard = findMe;
        }
        else if(findMe.rank == discardedCard.rank)
        {
            if(findMe.suit > discardedCard.suit)
            {
                discardedCard = findMe;
            }
        }

        if(discardedCard.suit > 0)
        {
            if(discardedCard.suit == 'D')     { remove( discardedCard.rank,&diamonds);}
            else if(discardedCard.suit == 'S'){ remove( discardedCard.rank,&spades  );}
            else if(discardedCard.suit == 'C'){ remove( discardedCard.rank,&clubs   );}
            else if(discardedCard.suit == 'H'){ remove( discardedCard.rank,&hearts  );}
        }

        return discardedCard;
    }

    // Just to debug
    void printHand()
    {
         cout << "|-------------------------------------------------------\\" << endl;
         cout << "|clubs    :";    printDeck(clubs);
         cout << "|diamonds :";    printDeck(diamonds);
         cout << "|hearts   :";    printDeck(hearts);
         cout << "|spades   :";    printDeck(spades);
         cout << "|-------------------------------------------------------/" << endl;
    }

};

inline int getNextPlayer(int player, int direction, int players)
{
    if(player == 1 && direction == -1)
    {
        player = players;
    }
    else if (player == players && direction == 1)
    {
        player = 1;
    }
    else
    {
        player += direction;
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

        player *playersList = new player[players+1];
        vector<card> discardPile;
        vector<card> stockPile;

        // reading cards for players
        for(int i = 1; i <= players; i++)
        {
            for(int j = 0; j < hand; j++)
            {
                card c;
                cin >> c.rank >> c.suit;
                playersList[i].addCard(c);
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

        int winnerPlayer    = 0;
        int directionOfPlay = (discardPile.back().rank == 12) ? -1 : 1; // in case of an initial queen the game starts with a c-cw;
        int currentPlayer   = 1;    //always start from the player 1
        bool discardedCard  = true; //count the first card in the discard pile as a discarded card action
        int round = 1;
        while (!winnerPlayer)
        {
            // First Action: see the last discarded card in my turn
            card discardTop = discardPile.back();

            if (discardedCard)
            {
                discardedCard = false;
                switch (discardTop.rank)
                {
                    case 1:  //Ace, draw one card and skip play
                        playersList[currentPlayer].DrawnCard(&stockPile, 1);
                        currentPlayer = getNextPlayer(currentPlayer, directionOfPlay, players);
                        continue;
                    case 7:  // 7, draw two card and skip play
                        playersList[currentPlayer].DrawnCard(&stockPile,2);
                        currentPlayer = getNextPlayer(currentPlayer, directionOfPlay, players);
                        continue;
                    case 11: // J, skip play
                        currentPlayer = getNextPlayer(currentPlayer, directionOfPlay, players);
                        continue;
                }
            }

            // Player see if he can discard a card;
            card discarded = playersList[currentPlayer].DiscardCard(discardTop);
            if (discarded.isBlanc())
            {
                // no card to discard, buy one more
                playersList[currentPlayer].DrawnCard(&stockPile, 1);
                discarded = playersList[currentPlayer].DiscardCard(discardTop);
            }

            if (!discarded.isBlanc())
            {
                discardPile.push_back(discarded);
                if(discarded.rank != 12)
                {
                    discardedCard = true;
                }
                else
                {
                    // is a Queen, change the direction
                    directionOfPlay *= -1;
                    discardedCard = false;
                }
            }

            //Test for winner!!!!;
            if(playersList[currentPlayer].isHandEmpty())
            {
                winnerPlayer = currentPlayer;
                cout << winnerPlayer << endl;
            }
            else
            {
                currentPlayer = getNextPlayer(currentPlayer, directionOfPlay, players);
            }

        }
    }
    return 0;
}
