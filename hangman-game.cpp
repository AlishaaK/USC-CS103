#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  int length = strlen(targetWord);
  for (int i = 0; i < length; i++) {
    word[i] = '*';
  }
  word[length] = '\0'; //set to null to make c-string
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (numTurns > 0 && wordGuessed == false ) {
    cout << "Current word: " << word << endl;
    cout << numTurns << " remain...Enter a letter to guess:" << endl;
    cin >> guess; 
    if(processGuess(word, targetWord, guess) == 0) { //if guess is wrong
      numTurns--;
    }
    if(strcmp(word, targetWord) == 0) { //if word is correctly guessed
      wordGuessed = true;
    }
  }

  // Print out end of game status
  if (wordGuessed) {
    cout << "The word was: " << word << ". You win!" << endl;
  }
  else if (numTurns == 0) {
    cout << "Too many turns...You lose!" << endl;
  }    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int count = 0; //to count occurrences of guess letter
  int len = strlen(targetWord);
  for (int j = 0; j < len; j++) {
    if (targetWord[j] == guess) {
      word[j] = guess;
      count++;
    }
  }
  return count;
}
