#include <iostream>
#include <string>

using namespace std;

bool checkBrackets(string sentence){
    int length = sentence.length();
    bool validSentence = false;

    if(length > 1){
        int counter = 0;
        int i;
        bool openBracket = false;

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

    else{
        if(sentence[0] == '(' || sentence[0] == ')')
            validSentence = false;
        else
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