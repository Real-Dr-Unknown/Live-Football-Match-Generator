#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to shift letters and digits
string shiftWord(const string& word, int shiftBy) {
    string shiftedWord = word;
    for (char& ch : shiftedWord) {
        if (isalpha(ch)) { // Check if character is a letter
            char base = islower(ch) ? 'a' : 'A'; // Determine if lowercase or uppercase
            ch = (ch - base + shiftBy) % 26 + base;
        }
        else if (isdigit(ch)) { // Check if character is a digit
            ch = (ch - '0' + shiftBy) % 10 + '0'; // Shift digits
        }
    }
    return shiftedWord;
}

// Function to unshift letters and digits
string unshiftWord(const string& word, int shiftBy) {
    string unshiftedWord = word;
    for (char& ch : unshiftedWord) {
        if (isalpha(ch)) { // Check if character is a letter
            char base = islower(ch) ? 'a' : 'A'; // Determine if lowercase or uppercase
            ch = (ch - base - shiftBy + 26) % 26 + base; // Ensure positive result with +26
        }
        else if (isdigit(ch)) { // Check if character is a digit
            ch = (ch - '0' - shiftBy + 10) % 10 + '0'; // Unshift digits
        }
    }
    return unshiftedWord;
}

// Main function
int main() {
    string word;
    int shiftBy = 3;
    string referer;

    // Accept input from the user
    cout << "Enter a word: ";
    cin >> word;

    cout << "Enter the Referer (Ankit, Suraj, HoneyPie, Kapil, Romeo): ";
    cin >> referer;

    // Shift and unshift the word
    string shifted = shiftWord(word, shiftBy);
    string unshifted = unshiftWord(shifted, shiftBy);

    // Display the results
    cout << "Original Word: " << word << endl;
    cout << "Shifted Word: " << shifted << endl;
    cout << "Unshifted Word: " << unshifted << endl;
    cout << "https://live-match-a5p.pages.dev/?referer=" << referer << "&match=" << shifted << endl;

    return 0;
}
