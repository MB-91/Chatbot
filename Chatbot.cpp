#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>  // Added for transform()
#include <limits>     // Added for numeric_limits
#include <cmath>      // Added for fmod()
#include <stdexcept>  

using namespace std;


// Function prototypes
void chat();
void calculator();
void stopwatch();
void saveToFile(const string& text);
void showSavedData();
void clearChatHistory();
string getRandomJoke();

int main() {
    srand(time(0)); // Seed for random joke

    int choice;
    string input;

    do {
        cout << "\n=== Chatbot Main Menu ===\n";
        cout << "1. Chat\n";
        cout << "2. Calculator\n";
        cout << "3. View Saved Conversations\n";
        cout << "4. Stopwatch\n";
        cout << "5. Exit\n";
        cout << "6. Clear Chat History\n";
        cout << "Enter your choice: ";
        getline(cin, input);

        stringstream ss(input);
        if (!(ss >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }

        switch(choice) {
            case 1: chat(); break;
            case 2: calculator(); break;
            case 3: showSavedData(); break;
            case 4: stopwatch(); break;
            case 5: cout << "Goodbye!\n"; break;
            case 6: clearChatHistory(); break;
        }
    } while(choice != 5);

    return 0;
}

// ===================== Chat Function =====================
void chat() {
    string userInput;
    cout << "You can type 'bye' to end the chat or 'help' to see options.\n";
    do {
        cout << "\nYou: ";
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        saveToFile("User: " + userInput);

        
        if (userInput == "hi" || userInput == "hello" || userInput == "hey" || userInput == "greetings") {
            cout << "Bot: Hello there! How can I assist you today?\n";
            cout << "     You can ask me about my functions, tell me a joke, or try the calculator!\n";
            saveToFile("Bot: Hello there! How can I assist you today?");
        }
        else if (userInput == "salam" || userInput == "assalam u alaikum" || userInput == "as-salam alaykum") {
            cout << "Bot: Wa Alaikum Assalam! How can I help you today?\n";
            cout << "     I can tell jokes, perform calculations, or just chat!\n";
            saveToFile("Bot: Wa Alaikum Assalam! How can I help you today?");
        }
        
        else if (userInput.find("how are you") != string::npos) {
            cout << "Bot: I'm just a program, but I'm functioning well! How about you?\n";
            cout << "     Are you enjoying our conversation so far?\n";
            saveToFile("Bot: I'm just a program, but I'm functioning well! How about you?");
        }
        else if (userInput == "who are you?" || userInput == "what are you?" || userInput == "introduce yourself") {
            cout << "Bot: I'm your personal chatbot assistant created with C++.\n";
            cout << "     My capabilities include conversation, jokes, calculations, and time tracking!\n";
            saveToFile("Bot: I'm your personal chatbot assistant. My purpose is to help you!");
        }
        
        else if (userInput == "joke" || userInput == "tell me a joke" || userInput == "make me laugh" || 
                userInput == "say something funny") {
            string joke = getRandomJoke();
            cout << "Bot: " << joke << endl;
            cout << "     Would you like to hear another one? Just ask!\n";
            saveToFile("Bot: " + joke);
        }
        
        else if (userInput == "help" || userInput == "options" || userInput == "what can you do") {
            cout << "Bot: I can respond to these commands:\n";
            cout << "------------------------------------\n";
            cout << "- Greetings: hi, hello, hey, greetings, salam\n";
            cout << "- Personal: who are you, what are you, how are you\n";
            cout << "- Entertainment: joke, tell me a joke, make me laugh\n";
            cout << "- Utilities: time (coming soon), calculator (from main menu)\n";
            cout << "- System: help, options, bye, exit\n";
            cout << "------------------------------------\n";
            cout << "You can also try casual conversation!\n";
            saveToFile("Bot: Showed detailed help options");
        }
        
        else if (userInput.find("thank") != string::npos || userInput == "thanks" || userInput == "thank you") {
            cout << "Bot: You're very welcome! It's my pleasure to assist you.\n";
            cout << "     Don't hesitate to ask if you need anything else!\n";
            saveToFile("Bot: You're very welcome! Is there anything else I can help with?");
        }
        
        else if (userInput.find("time") != string::npos || userInput.find("clock") != string::npos) {
            cout << "Bot: I can't tell time yet, but that feature is coming in version 2.0!\n";
            cout << "     For now, you can use the stopwatch from the main menu.\n";
            saveToFile("Bot: I can't tell time yet, but that's a great feature to add!");
        }
        
        else if (userInput.find("calculate") != string::npos || userInput.find("math") != string::npos) {
            cout << "Bot: I can help with calculations! Here's how:\n";
            cout << "     1. Return to the main menu (type 'bye' first)\n";
            cout << "     2. Select option 2 for the calculator\n";
            cout << "     3. I'll handle +, -, *, / operations with precision!\n";
            saveToFile("Bot: Directed user to calculator function");
        }
        
        else if (userInput.find("stopwatch") != string::npos || userInput.find("timer") != string::npos) {
            cout << "Bot: My stopwatch feature can measure elapsed time precisely!\n";
            cout << "     To use it:\n";
            cout << "     1. End this chat (type 'bye')\n";
            cout << "     2. Choose option 4 from the main menu\n";
            cout << "     3. Press Enter to start/stop timing\n";
            saveToFile("Bot: Directed user to stopwatch function");
        }
        
        else if (userInput.find("feature") != string::npos || userInput.find("update") != string::npos) {
            cout << "Bot: Future versions might include:\n";
            cout << "     - Weather information\n";
            cout << "     - Reminder system\n";
            cout << "     - Multiple language support\n";
            cout << "     - And much more!\n";
            saveToFile("Bot: Discussed future features");
        }
        
        else if (userInput == "bye" || userInput == "goodbye" || userInput == "exit" || userInput == "see you") {
            cout << "Bot: Goodbye! It was wonderful chatting with you.\n";
            cout << "     Remember you can always come back to continue our conversation!\n";
            saveToFile("Bot: Goodbye! Have a great day!");
        }
        
        else {
            cout << "Bot: I'm still learning. Maybe try one of these:\n";
            cout << "     - Ask about my functions ('help')\n";
            cout << "     - Request a joke\n";
            cout << "     - Ask who created me\n";
            cout << "     - Or say hello in different ways!\n";
            saveToFile("Bot: Suggested alternatives for unrecognized input");
        }
    } while(userInput != "bye" && userInput != "goodbye" && userInput != "exit" && userInput != "see you");
}

// ===================== Calculator Function =====================
void calculator() {
    char choice;
    do {
        double num1, num2;
        char op;
        bool validInput = false;

        // Input validation loop
        while (!validInput) {
            cout << "\nEnter first number: ";
            if (cin >> num1) {
                validInput = true;
            } else {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            }
        }

        validInput = false;
        while (!validInput) {
            cout << "Enter operator (+ - * /): ";
            cin >> op;
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                validInput = true;
            } else {
                cout << "Invalid operator! Please use +, -, *, or /\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        validInput = false;
        while (!validInput) {
            cout << "Enter second number: ";
            if (cin >> num2) {
                validInput = true;
            } else {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Perform calculation
        switch(op) {
            case '+': 
                cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl; 
                break;
            case '-': 
                cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl; 
                break;
            case '*': 
                cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl; 
                break;
            case '/': 
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                    if (fmod(num1, num2) != 0) { // Check for remainder
                        cout << "Remainder: " << fmod(num1, num2) << endl;
                    }
                }
                else {
                    cout << "Error: Cannot divide by zero.\n";
                }
                break;
        }

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Ask if user wants to continue
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (tolower(choice) == 'y');
}
// ===================== Stopwatch Function =====================
void stopwatch() {
    cout << "Press ENTER to start/stop\n";

    // Wait for the first ENTER to start
    cin.ignore();
    auto start = chrono::high_resolution_clock::now();
    cout << "Stopwatch running... Press ENTER to stop\n";

    // Wait for the second ENTER to stop
    cin.ignore();
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration
    double elapsed = chrono::duration<double>(end - start).count();
    cout << "Time: " << elapsed << " seconds\n";
}

// ===================== Joke Generator Function =====================
string getRandomJoke() {
    string jokes[] = {
        // Programming Jokes
        "Why do programmers prefer dark mode? Because light attracts bugs!",
        "Why did the programmer quit his job? Because he didn't get arrays.",
        "How many programmers does it take to change a light bulb? None, that's a hardware problem!",
        "Why do Java developers wear glasses? Because they can't C#!",
        "Why was the JavaScript developer sad? Because he didn't know how to 'null' his feelings.",
        "Why don't programmers like nature? It has too many bugs.",
        
        // Tech Jokes
        "Why did the computer go to the doctor? Because it had a virus!",
        "Why did the smartphone go to therapy? It had too many hang-ups!",
        "Why was the Wi-Fi feeling lonely? Because it couldn't find any connection.",
        "Why did the robot go on a diet? It had too many bytes!",
        "Why did the tablet break up with the smartphone? It needed more space.",
        "Why don't computers take naps? Because they have no 'sleep' function!",
        
        // Science Jokes
        "Why don't scientists trust atoms? Because they make up everything!",
        "Did you hear about the chemist who was reading a book about helium? He couldn't put it down!",
        "Why can't you trust an atom? They make up everything!",
        "What did the biologist wear to impress their date? Designer genes!",
        "Why did the physics teacher break up with the biology teacher? There was no chemistry.",
        "Why was the math book sad? Because it had too many problems.",
        
        // Animal Jokes
        "What do you call a fish with no eyes? Fsh!",
        "Why don't elephants use computers? They're afraid of the mouse!",
        "What do you get when you cross a snowman and a dog? Frostbite!",
        "Why did the cow win the award? Because it was outstanding in its field!",
        "What do you call a bear with no teeth? A gummy bear!",
        "Why did the chicken join a band? Because it had the drumsticks!",
        
        // Food Jokes
        "Why did the tomato turn red? Because it saw the salad dressing!",
        "What do you call cheese that isn't yours? Nacho cheese!",
        "Why did the cookie go to the doctor? Because it was feeling crummy!",
        "What did the grape say when it got stepped on? Nothing, it just let out a little wine!",
        "Why don't eggs tell jokes? They'd crack each other up!",
        "Why was the belt arrested? For holding up a pair of pants!"
    };
    
    // Initialize random seed
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    
    int randomIndex = rand() % 30;  // Now selects from 30 jokes
    return jokes[randomIndex];
}
// ===================== Save Chat to File =====================
void saveToFile(const string& text) {
    ofstream file("conversation.txt", ios::app);
    if (file.is_open()) {
        file << text << endl;
        file.close();
    } else {
        cout << "Error saving conversation.\n";
    }
}

// ===================== Show Saved Conversations =====================
void showSavedData() {
    const string filename = "conversation.txt";
    ifstream file(filename);
    
    // Check if file exists and is open
    if (!file.is_open()) {
        cerr << "Error: Could not find or open the conversation file.\n";
        return;
    }

    // Check if file is empty
    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        cout << "No conversations saved yet.\n";
        file.close();
        return;
    }
    file.seekg(0, ios::beg);

    // Display with better formatting
    cout << "\n=== Saved Conversations ===\n";
    cout << "--------------------------\n";
    
    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        lineCount++;
        
        // Add timestamp detection and special formatting
        if (line.find("===") != string::npos) {
            cout << "\n\033[1;36m"; // Cyan color for timestamps (if supported)
        }
        
        cout << line << endl;
        
        if (line.find("===") != string::npos) {
            cout << "\033[0m"; // Reset color
            cout << "--------------------------\n";
        }
    }
    file.close();

    // Show statistics
    cout << "\nTotal conversation entries: " << lineCount/2 << endl;
    cout << "File: " << filename << endl;
    
    // Add option to clear history
    char choice;
    cout << "\nWould you like to clear the conversation history? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (tolower(choice) == 'y') {
        ofstream clearFile(filename, ios::trunc);
        clearFile.close();
        cout << "Conversation history cleared successfully.\n";
    }
}
// ===================== Clear Chat History =====================
void clearChatHistory() {
    const string filename = "conversation.txt";
    
    // First check if file exists and has content
    ifstream checkFile(filename);
    if (!checkFile.is_open()) {
        cout << "No chat history exists to clear.\n";
        return;
    }
    
    checkFile.seekg(0, ios::end);
    if (checkFile.tellg() == 0) {
        cout << "Chat history is already empty.\n";
        checkFile.close();
        return;
    }
    checkFile.close();

    // Get user confirmation
    char choice;
    cout << "\nWARNING: This will permanently delete all chat history.\n";
    cout << "Are you sure you want to continue? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tolower(choice) != 'y') {
        cout << "Chat history preservation cancelled.\n";
        return;
    }

    // Clear the file with better error handling
    ofstream file(filename, ios::trunc);
    if (!file) {
        cout << "Error clearing chat history: Failed to open file\n";
        return;
    }
    
    file.close();
    
    // Verify the file is now empty
    ifstream verify(filename);
    verify.seekg(0, ios::end);
    bool success = (verify.tellg() == 0);
    verify.close();

    if (success) {
        cout << "Chat history cleared successfully.\n";
        time_t now = time(0);
        cout << "Cleared at: " << ctime(&now);
    } else {
        cout << "Error clearing chat history: Verification failed\n";
    }
}
