#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string chooseWord();
void renderGame(string guessedWord, int badGuesscount);
char readAGuess();
bool contains(string secretWord, char guess);
string update(string guessedWord, string secretWord, char guess);

const int MAX_BAD_GUESS=7;

int main(){
	srand(time(0));
	string secretWord= chooseWord();
	string guessedWord = string(secretWord.length(),'-');
	int badGuessCount=0;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	do{
		renderGame (guessedWord, badGuessCount);
		char guess = readAGuess();
		
		if(contains(secretWord, guess)){
			guessedWord = update(guessedWord, secretWord, guess);
		}else badGuessCount++;
	}while (badGuessCount < MAX_BAD_GUESS && secretWord!=guessedWord);
	
	renderGame( guessedWord, badGuessCount);
	if(badGuessCount < MAX_BAD_GUESS){
		cout<<"Congratulations. You're win.";
	}else cout<<"You lost. The word is "<<secretWord;
}

const string WordList[]={
	"apple","bear","Iloveyou","computer","laptop","pentakill","language","school"
};

const int WORDcount = sizeof(WordList) / sizeof(string);

string chooseWord(){
	int random= rand() % WORDcount;
	return WordList[random];
}

const string FIGURE[] ={
	"  -------------------       \n"
	"    |                       \n"
	"    |                       \n"
	"    |                       \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	
	"  -------------------       \n"
	"    |             |         \n"
	"    |                       \n"
	"    |                       \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |                       \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |             |         \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |            /|         \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |            /|\\       \n"
	"    |                       \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |            /|\\       \n"
	"    |            /          \n"
	"    |     \n"
	"  -----   \n",
	"  -------------------       \n"
	"    |             |         \n"
	"    |             O         \n"
	"    |            /|\\       \n"
	"    |            / \\       \n"
	"    |     \n"
	"  -----   \n",
};

void renderGame(string guess, int badGuessCount){
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<FIGURE[badGuessCount]<<endl;
	SetConsoleTextAttribute(h,badGuessCount+ (1 + rand()%(13-1)));
	
	cout<<guess<<endl;
	
	cout<<"Number of wrong guesses:"<< badGuessCount<<endl;
	SetConsoleTextAttribute(h,10);
	SetConsoleTextAttribute(h+5,15);
}

char readAGuess(){
	char yourGuess;
	cout<<"Your guess is ";
	cin>>yourGuess;
	return yourGuess;
	
}

bool contains(string secretWord, char a){
	
	bool flag= secretWord.find_first_of(a)!= string::npos;
	return flag;
}

string update(string guessedWord, string secretWord, char guess){
	for(int i=0;i<secretWord.length();i++){
		if(secretWord[i]== guess){
			guessedWord[i]=guess;
		}
	}
	return guessedWord;
}





