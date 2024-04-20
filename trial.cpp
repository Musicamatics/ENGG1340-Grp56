#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <ctime>
#include <map>
#include <list>
#include <random>
using namespace std;
string ans_list[12];//NEVER USE GLOBAL VARIABLES!!!
int ans_ct; //SEE ABOVE
//void readandwriteFile(string fn);

bool loaddict(const string & file, map<int, string> & mydict){
    string word;
    //ifstream filed(file);
    ifstream filed{file};
    if (!filed.is_open()) {
        cout << "Error in file opening!" << endl;
        //ofstream file_writer(file);
        //exit(1);
        return false;
    }
    
    int num=0;
    if(filed.is_open()){
        while (getline(filed, word)){
            if(word.length() == 5){
                mydict[num] = word;
                num++;
            }
        }
    }

    cout << num << endl;
    filed.close();
    return true;
}
void toLowerCase(string & input){
    for (int i=0; i<5; i++){
        if (input[i] < 97){
            input[i] = input[i]+32;
        }
    }
}

string generateword(map<int, string> & mapdict){
    int N = mapdict.size()-1;
    int num = 0;
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<int> dist(1,N);
    num = dist(e2);
    return mapdict[num];
}



bool isValid(string input){
    if(input.length() > 5){
        return false;
    }
    for (int i=0;i<5;i++){
        if ((input[i]<97) || (input[i]>122)){
            return false;
        }
    }
    return true;
}

bool testingdoWordsMatch(string s1, string s2){
    if (s1 == s2){
        return true;
    }
    return false;
};
void testingfindGs(string s1,string s2, char chararr[], bool foundarr[]){
    for (int i=0; i<5; i++){
        if (s1[i] == s2[i]){
            chararr[i] = 'G';
            foundarr[i] = true;
        }
        else{
            chararr[i] = ' ';
            foundarr[i] = false;
        }
    }
};
void charprinting(char chararr[]){
    for (int i=0; i<5; i++){
        cout << chararr[i] << " ";
    }
    cout << endl;
}

void boolprinting( bool foundarr[]){
    for (int i=0; i<5; i++){
        cout << foundarr[i] << " ";
    }
    cout << endl;
}
void wordprinting( string line){
    for (int i=0; i<5; i++){
        cout << line[i] << " ";
    }
    cout << endl;
}
void testingfindYs(string s1,string s2, char chararr[], bool foundarr[]){
    for(int i=0; i<5; i++){
        for(int a=0; a<5; a++){
            if((s1[i] == s2[a]) && (chararr[i] != 'G')){
                chararr[i] = 'Y';
                foundarr[a] = true;
                for (int j=0; j<5; j++){
                    if((s2[a] == s2[j]) && (a > j)){
                        foundarr[a] = false;
                    }
                }            
            }
        }
    }
}
void testingfindYys(string s1,string s2, char chararr[], bool foundarr[]){
    for(int s=0; s<5; s++){
        for (int g=0; g<5; g++){
            if (((s1[s] == s1[g]) && (s!=g)) && ((chararr[s] == 'Y') && (chararr[g] == 'G'))){
                chararr[s] = ' ';
                cout << "remove y because g" << endl;
            }
            else if (((s1[s] == s1[g]) && (g > s)) && ((chararr[s] == 'Y') && (chararr[g] == 'Y'))){
                chararr[g] = ' ';
                cout << "remove y because y" << endl;
            }
        }
    }
};
int getSize(string fn){
return 0;
};
void readFile(string fn, string arr[], int num_words){

};
void playGame(int num_words, string arr[]){

};
string getWord(int num, string arr[]){
return 0;
};
bool startGuessing(string curr_word){
return 0;
};
//void printResults(string arr[]){
//    for (int i=0; i<sizeof(arr); i++){
//        system("Color 92");
//        cout << arr[i] << " " ;
//    }
//    cout << endl;
//};
bool checkWord(string guess, string curr_word);
bool doWordsMatch(string guess, string curr_word);
bool findGs(string guess, string curr_word,char ans[], bool found[]){
    int numgs = 0;
    for(int i=0; i<5; i++){
        if(ans[i] == 'G'){
            numgs++;
            found[i] = true;
        };
    }
    if(numgs == 5){return true;}
    return false;
};
void findYs(string guess, string curr_word,char ans[], bool found[]){
    int numys = 0;
    for(int i=0; i<5; i++){
        if(ans[i] == 'Y'){
            numys++;
            found[i] = true;
        };
    }
};
void reset_ans_list(){};


int main() {
    bool match;
    char chararr[5][5]; bool foundarr[5][5];

    for (int i=0; i<5; i++){
        for (int s=0; s<5; s++){
            chararr[i][s] = '\n';
            foundarr[i][s] = false;
        }
    }
    list <string> tries;
    string input, word;
    map<int, string> mydict;
    string filepath = "/usr/share/dict/words";
    bool b = loaddict(filepath, mydict);
    if (b){
        word = generateword(mydict);
        toLowerCase(word);
        cout << "word " << word << endl;
        }
    else {
        cout << "cannot add " << endl;
    }

    int num_of_tries = 6;
    int currentTry = 0, WORD_LENGTH=5;
    //while (currentTry < num_of_tries)
    while(currentTry < num_of_tries){
        do{
            cout << "Please enter your guess (word length must be " + to_string(WORD_LENGTH) + ") or type Q to quit: ";
            getline(cin, input);
            toLowerCase(input);
            if (input == "q"){
                cout << "Quit game" << endl;
                break;
            }
        
            if ((!isValid(input)) && (currentTry != 0)){
                cout << "Wrong format! Please enter your 5-letter word guess again: ";
            }
        }
        while (!isValid(input));
        
        if (input == "q"){
            break;
        }

        tries.push_back(input);
        testingfindGs(word, input, chararr[currentTry], foundarr[currentTry]);
        testingfindYs(word, input, chararr[currentTry], foundarr[currentTry]);
        wordprinting(word);
        wordprinting(input);
        charprinting(chararr[currentTry]);
        boolprinting(foundarr[currentTry]);
        currentTry++;

        if((num_of_tries - currentTry)==1){
            cout << "Would you like to play again? Please type Y to play again or type Q to quit:  " << endl;
            string input2;
            cin >> input2;
            if(input2 == "Y"){
                currentTry = 0;
                tries.clear();
            }
            else if(input2 == "Q"){
                break;
            }
        }
    }

    

    for (int i=0; i<tries.size(); i++){
        cout << tries.front() << ' ';
        tries.push_back(tries.front());
        tries.pop_front();
    }
    cout << endl;
    return 0;

}
