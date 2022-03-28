// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Vigenere Cipher.cpp
// Author and ID and Group:karem hassane hamed / 20210293/ Group A

#include <iostream>
#include <string>
using namespace std;

int c = 0, ascii_word; // Define a global variables
string word, key;      // Define a global variables
void Encrypt()         // Define function for Encrypt
{
    cout << "please enter massage :";
    getline(cin >> ws, word);
    while (word.length() > 80)      // check word length
    {
        cout << "the message is too long! your limit is 80 char";
        cout << "please enter massage: ";
        getline(cin, word);
    }

    for (int i = 0; i < word.length(); i++) // check  all letter in word is upper
    {
        word[i] = toupper(word[i]);
    }

    cout << "please enter your key: ";
    getline(cin, key);
    while (key.length() > 8) // check key length
    {
        cout << "the key is too long! your limit is 8 leters";
        cout << "please enter key: ";
        getline(cin, key);
    }

    for (int i = 0; i < key.length(); i++) // check  all letter in key is upper
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (int(word[i]) == 32) //  check if the word have space continue
        {
            cout << ' ';
            c++;
            continue;
        }

        if (!isalpha(word[i])) // check if word isnt alphabetic
        {
            cout << (word[i]);
            continue;
        }

        ascii_word = int(word[i]) + int(key[c]); // do operation for encrypt

        ascii_word = ascii_word % 26;
        ascii_word += 65;

        c++;
        if (c == key.length()) // check if c ==  key lenght repeat c = 0
        {

            c = 0;
        }

        cout << (char)ascii_word;
    }
}

void Decrypt()  // Define function for decrypt
{
    cout << "please enter massage :";
    getline(cin >> ws, word);
    while (word.length() > 80)      // check word length
    {
        cout << "the message is too long! your limit is 80 char";
        cout << "please enter massage:";
        getline(cin, word);
    }

    for (int i = 0; i < word.length(); i++)         // check  all letter in word is upper
    {
        word[i] = toupper(word[i]);
    }

    cout << "please enter your key:";
    getline(cin, key);
    while (key.length() > 8)         // check key length
    {   
        cout << "the key is too long! your limit is 8 leters";
        cout << "please enter key: ";
        getline(cin, key);
    }

    for (int i = 0; i < key.length(); i++)  // check  all letter in key is upper
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (int(word[i]) == 32) //  check if the word have space continue
        {
            cout << ' ';
            c++;
            continue;
        }

        if (!isalpha(word[i]))  // check if word isnt alphabetic
        {
            cout << (word[i]);
            continue;
        }
        // do operation for decryption
        ascii_word = int(word[i]) - int(key[c]);

        if (ascii_word < 0)
        {

            ascii_word = ascii_word + 26 + 65;
        }

        else
        {

            ascii_word += 65;
        }

        c++;
        if (c == key.length())
        {

            c = 0;
        }

        cout << (char)ascii_word;
    }
}

int main()
{
    int op;  
    //  ask user to choose encryption or decryption 
    cout << "please enter operation: \n";
    cout << "enter the operation(1:encryption or 2:decryption): ";
    cin >> op;
    while (op != 1 && op != 2) // Check if the user entered the wrong number
    {
        cout << "please enter valid operation! \n";
        cout << "enter the operation(1:encryption or 2:decryption):\n ";
        cout << "choose(1,2): ";
        cin >> op;
    }

    if (op == 1)
    {

        Encrypt();
    }
    else if (op == 2)
    {

        Decrypt();
    }

    return 0;
}
