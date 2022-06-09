#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
 
 
 
int getTheSequenceOf_A_Letter(char letter) {
    if(int(letter) > 64 && int(letter) < 91){
        return int(letter) - 65;
    }
    else if (int(letter) > 96 && int(letter) < 123) {
        return int(letter) - 97;
    }
    else {
        cout << "This is not letter (special character).";
        return 0;
    }
}
 
 
 
int main(void) {
 
    char englishSmallLetters[26];
    for (int i = 0; i < 26; i++) {
        englishSmallLetters[i] = char(97 + i);
    }
 
    char englishCapitalLetters[26];
    for (int i = 0; i < 26; i++) {
        englishCapitalLetters[i] = char(65 + i);
    }
 
    string word;
    do {
        cout << "Enter a word (from 5 letters only): ";
        cin >> word;
    } while (word.length() > 5 || word.length() < 5);
 
    srand(time(0));
    int randomNumber = rand() % 50;
    if (randomNumber == 0) {
        randomNumber++;
    }
 
    for (int i = 0; i < 5; i++) {
        if(int(word[i]) > 96 && int(word[i]) < 123){
        if (getTheSequenceOf_A_Letter(word[i]) + randomNumber > 25) {
            word[i] = englishSmallLetters[getTheSequenceOf_A_Letter(word[i]) + randomNumber - 26];
        }
        else {
            word[i] = englishSmallLetters[getTheSequenceOf_A_Letter(word[i]) + randomNumber];
        }
 
        }
        else if (int(word[i]) > 64 && int(word[i]) < 91) {
            if (getTheSequenceOf_A_Letter(word[i]) + randomNumber > 25) {
                word[i] = englishCapitalLetters[getTheSequenceOf_A_Letter(word[i]) + randomNumber - 26];
            }
            else {
                word[i] = englishCapitalLetters[getTheSequenceOf_A_Letter(word[i]) + randomNumber];
            }
        }
    }
 
    cout << word << endl;
 
 
 
    return 0;
}
