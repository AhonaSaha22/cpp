#include <iostream>
#include <string>
#include <vector>
using namespace std;
   double calculate() {
     double a,b  ;
      char c;

    cout<<"Enter math expression ( e.g., 5 + 3): ";
    cin>>a >> c>> b;
    cin.ignore(1000, '\n');

    if(c== '+') return a + b;
    else if(c == '-') return a - b;
    else if(c== '*') return a * b;
    else if(c== '/') return (b != 0) ? a / b : 0;
    else return 0;
}
int main() {
    string input, name;
    vector<string> history;
    bool hasName = false;

    cout << "Welcome to Mini Chatbot!\n";
cout << "\n-- Menu!!\n";
    cout << "1. Greet\n2. Set Name\n3. Chat\n4. Math\n5. Show History\n6. Exit\n";

    while (true) {
        cout << "\nChoose option: ";
        getline(cin, input);

        if(input == "1") {
            cout << "Chatbot: Hello! Nice to meet you \n";
            history.push_back("Greeted user");
        }
        else if(input == "2") {
            cout << "Chatbot: What is your name? ";
            getline(cin, name);
            cout << "Chatbot: Nice to meet you,"<< name << "!\n";
            hasName= true;

            history.push_back("Set name: " + name);
        }
        else if(input == "3") {
            cout << "Chatbot: Say something: ";
            getline(cin, input);
            if(input == "how are you") cout << "Chatbot: I'm doing great! \n";
            else if(input == "what is my name") {

                if(hasName)
                    cout << "Chatbot: Your name is " << name << "\n";

                else cout << "Chatbot: I don't know your name yet \n";
            }
            else


                cout<<"Chatbot:Sorry, I don't understand \n";

            history.push_back("Chat: " +input);
        }
        else if(input == "4") {
            double result = calculate();
            cout << "Chatbot: Result = " <<result << "\n";
            history.push_back("Math calculation done");
        }
        else if(input == "5") {
            cout << "Chatbot: Chat History:\n";
            for(int i = 0; i < history.size(); i++)
                cout << i+1<< ". " << history[i] << "\n";
        }
        else if(input== "6") {
            cout<< "Chatbot: Goodbye! \n";

            break;
        }
        else {
            cout<<"Chatbot: Invalid option \n";
        }
    }

    return 0;
}
