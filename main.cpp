#include<iostream>
#include<string>
using namespace std;

int main(){
    int choice;
    int secret = 10;
    string winner ;

    cout<< "Welcome to the Game!\n"<<endl;

    cout<< "Please enter the name of 1st player: ";
    string name1;
    cin >> name1;

    cout<< "Please enter the name of 2nd player: ";
    string name2;
    cin >> name2;

    cout<<"\n Both players get 3 chances to guess a number between 0 and 20.\n";
    cout<<"Whoever guesses the number first is the WINNER!\n\n";

    for(int i=0; i<3; i++){
        cout<< name1 <<" (Stage "<<i+1<<") : Enter your guess: ";
        cin>>choice;

        if(choice == secret){
            winner = name1;
            break;
        } else {
            cout<<"Wrong guess!\n";
        }

        cout<< name2 <<" (Stage "<<i+1<<") : Enter your guess: ";
        cin>>choice;

        if(choice == secret){
            winner = name2;
            break;
        } else {
            cout<<"Wrong guess!\n";
        }

    }

    if(winner== name1 || winner==name2){
        cout<<"\n Congratulations "<<winner<<"! You guessed the number first and won the game!\n";
    }



    else {
        cout<<"\nNo one guessed the correct number. Game Over!\n";
    }

    return 0;
}
