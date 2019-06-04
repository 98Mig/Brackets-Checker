#include <iostream>
#include <string>

using namespace std;

bool checkBrackets(string sentence){
    int length = sentence.length();
    bool validSentence = false;
    int counterBrackets = 0;
    int j = 0;
    for(j = 0; j < length; j++){
        if(sentence[j] == '(' || sentence[j] == ')')
            counterBrackets++;
    }
    
    if(counterBrackets % 2 == 0){
        int counter = 0;
        int i;
        bool openBracket = false;
        int counterBrackets = 0;

        for(i = 0; i < length; i++){
            if(sentence[i] == '(' && !openBracket){
                counter++;
                openBracket = true;
            }
            else if(sentence[i] == ')' && openBracket){
                counter--;
                openBracket = false;
            }
        }

        if(counter == 0 && !openBracket)
            validSentence = true;

    }

    return validSentence;

}

int main(){

    string userInput;
    bool sentenceValid = false;
    cout << "Please enter a sentence: " << endl;

    cin >> userInput;

    sentenceValid = checkBrackets(userInput);

    if(sentenceValid)
        cout << "Your sentence is valid!" << endl;
    else
        cout << "Your sentence isn't valid! Please correct it!" << endl;

    return 0;

}