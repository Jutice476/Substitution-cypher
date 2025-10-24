#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string to_upper(string n);
int key_alpha_check(string n);
int key_duplicate_check(string n);
string encryption(string n, string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26 || key_alpha_check(argv[1]) == 'y' ||
             key_duplicate_check(to_upper(argv[1])) == 'y')
    {
        printf("Key must contain 26 letters, different from each other\n");
        return 1;
    }
    else
    {
        string word = get_string("plaintext: ");
        printf("ciphertext: %s\n", encryption(word, argv[1]));
        return 0;
    }
}

// turns the key to uppercase
string to_upper(string n)
{
    for (int i = 0, l = strlen(n); i < l; i++)
    {
        n[i] = toupper(n[i]);
    }
    return n;
}

// checks whether the key consists of the alphabetic letters only
int key_alpha_check(string n)
{
    int error = 0;
    for (int i = 0, l = strlen(n); i < l; i++)
    {
        if (isalpha(n[i]))
        {
            i += 0;
        }
        else
        {
            error++;
            break;
        }
    }
    if (error > 0)
    {
        return 'y';
    }
    else
    {
        return 0;
    }
}

// checks if there are duplicate letters in the key
int key_duplicate_check(string n)
{
    int error = 0;
    // a loop for a whole word
    for (int i = 0, l = strlen(n); i < l; i++)
    {
        // a loop for each letter comparing to each other letter
        for (int j = 0; j < l; j++)
        {
            if (n[i] == n[j])
            {
                if (i == j)
                {
                    i += 0;
                }
                else
                {
                    error++;
                    break;
                }
            }
            else
            {
                j += 0;
            }
        }
    }
    if (error > 0)
    {
        return 'y';
    }
    else
    {
        return 0;
    }
}

// encrypts the word
string encryption(string n, string s)
{
    for (int i = 0, l = strlen(n); i < l; i++)
    {
        // using place variable, I can easily connect word's letters to the needed key letters
        int place = 0;
        if (isupper(n[i]))
        {
            place = n[i] - 65;
            n[i] = toupper(s[place]);
        }
        else if (islower(n[i]))
        {
            place = n[i] - 97;
            n[i] = tolower(s[place]);
        }
    }
    // return the encrypted word
    return n;
}
