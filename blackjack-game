/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Alishaa Khoslaa
 * USC email: khoslaa@usc.edu
 ******************************************************************************/

//#includes
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
  //Initializing contents of array to numbers 0-51
  for (int m = 0; m < NUM_CARDS; m++) {
    cards[m]= m;
  }
  //Using Fisher-Yates / Durstenfeld shuffle algorithm
  for (int i = NUM_CARDS-1; i >= 1; i--) {
    int j = rand() % (i+1);
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/
  int num = id;
  //Prints card using card id by accessing corresponding
  //element of type[array]
  if (id >= 0 && id <=12) { //For suit H
    cout << type[num] << "-" << suit[0];
  }
  else if (id >= 13 && id <=25) { //For suit S
    num = id-13;
    cout << type[num] << "-" << suit[1];
  }
  else if (id >= 26 && id <=38) { //For suit D
    num = id-26;
    cout << type[num] << "-" << suit[2];
  }
  else { //For suit C
    num = id-39; 
    cout << type[num] << "-" << suit[3];
  }
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  //Gets value of card with associated id by accessing
  //elements of value[] array
  int n = id;
  while (n > 12) {
    n = n - 13;
  }
  int val = value[n];
  return val; 
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  //Loops through hand[] array to print each card in it
  //by calling printCard() function in each iteration
  for (int d = 0; d < numCards; d++) {
    int card_id = hand[d];
    printCard(card_id);
    cout << " ";
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  int totalscore = 0;
  int numaces = 0;
  for (int s = 0; s < numCards; s++) {
    totalscore += cardValue(hand[s]);
    if (cardValue(hand[s])==11) { //Checks if any cards are aces
      numaces++;
    }
  }
  //Loop for if player busts and aces are in hand
  //changes them to value of 1 instead of 11
  while (totalscore > 21 && numaces > 0) { 
    totalscore -=10;
    numaces--;
  }
  return totalscore;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  //Loop to keep game going while user types 'y' for yes
  char playagain = 'y';
  while (playagain == 'y') {
    //Shuffles cards[] and then deals first 2 cards each to player and dealer
    shuffle(cards);
    int cardsi = 0; //To keep track of what index in cards[] array should be accessed
    phand[0] = cards[cardsi];
    cardsi++;
    dhand[0] = cards[cardsi];
    cardsi++;
    phand[1] = cards[cardsi];
    cardsi++;
    dhand[1] = cards[cardsi];
    cardsi++;
    int p_numcards = 2; //To keep track of how many cards are currently in each hand
    int d_numcards = 2;
    
    //Prints initial hands of player and dealer
    cout << "Dealer: ? ";
    printCard(dhand[1]);
    cout << endl;
    cout << "Player: ";
    printHand(phand, p_numcards);
    
    //Sums or scores of each hand
    int psum = getBestScore(phand, p_numcards);
    int dsum = getBestScore(dhand, d_numcards);
 
    //Loop to ask user whether they want to hit or stay as long as 
    //their sum is under 21 and add cards to their hand accordingly
    char response = 'h';
    while (psum < 21 && response == 'h') {
      cout << "Type 'h' to hit and 's' to stay:" << endl;
      cin >> response;
      if (response == 'h') {
        phand[p_numcards] = cards[cardsi];
        p_numcards++;
        cardsi++;
        cout << "Player: ";
        printHand(phand, p_numcards);
        psum = getBestScore(phand, p_numcards);
       }
    }
    
    //Output for if player busts
    if (psum > 21) { 
      cout << "Player busts" << endl;
      cout << "Lose " << psum << " " << dsum << endl;
    }
    
    //Dealer plays since player did not bust
    else { 
      while (dsum < 17) { //Loop to add cards to dealer's hand while score < 17
         dhand[d_numcards] = cards[cardsi];
         d_numcards++;
         cardsi++;
         dsum = getBestScore(dhand, d_numcards);
      }
      cout << "Dealer: ";
      printHand(dhand, d_numcards);
      if (dsum > 21) { //Output if dealer busts
        cout << "Dealer busts" << endl;
        cout << "Win " << psum << " " << dsum << endl;
      }
      else { //Final outputs or game results with scores of p and d
        if (psum > dsum) {
          cout << "Win " << psum << " " << dsum << endl;
        }
        else if (psum == dsum) {
          cout << "Tie " << psum << " " << dsum << endl;
        }
        else {
          cout << "Lose " << psum << " " << dsum << endl;
        }
      }
    }
    
    //Prompting user to play again or stop playing
    cout << endl;
    cout << "Play again? [y/n]" << endl;
    cin >> playagain;   
  }
  return 0;
}
