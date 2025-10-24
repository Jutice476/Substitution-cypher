# Substitution-cypher
A C program that **encrypts** every letter of the plain text by another letter from the **key**. The key consists of 26 unique letters (no duplicates) each representing certain letter in the alphabet. For example, here I got a key: NQXPOMAFTRHLZGECYJIUWSKDVB, which is only known to me and my friend. Using this key I change all the letters in my message: Hello! -> Fonne! and send it to my friend, who is using the key decrypts my message. Thus, only those who know the key are able to decyipher the message.  

## Contents
This time, I have added 2 new libraries to make the coding easier, which are **ctype.h** and **string.h**. I used ctype.h for its **isalpha**, **isupper**, **islower**, **toupper**, and **tolower** functions. I used string.h for its **strlen** function. Of course, I could have written these functions manualy, by myself, but I decided that its better to start using more libraries (like professional coders), and save my time for the overall logic and algorithm. 

There are 5 functions in my program: **to_upper**, **key_alpha_check**, **key_duplicate_check**, **encryption**, and **main**.
1) **to_upper** function uses a for loop to turn every letter of the key to uppercase. it is needed to make the key letters uniform, so the **key_duplicate_check** function would be able to find out duplicates even if they are of different cases. 
2) **key_alpha_check** function uses a loop to check every letter of the key, whether its a letter or not. If its not, the program ends. It is needed to evade having other symbols instead of the letters.
3) **key_duplicate_check** function checks if there are any duplicates inside the key, which would distort the encryption.
4) **encryption** function is the main character of this program. It changes the plain text's letters to their corresponding letters in the key, thus encrypting the whole word. Inside the for loop, depending on the letter's case, using the knowledge that a word is basically an array of characters, I correspond each plain text's letter to the letter in the key.
5) **main** function combines all the above functions together. First, it checks if there are more than 2 command line arguments. Then, it calls  **key_alpha_check** and **key_duplicate_check** to ensure that the key consists of 26 unique letters only. After that, the main calls for the **encryption** function and prints out the encrypted word.   

## How it works
1. The program takes a command line argument as an input for the key.
2. It checks if there are any errors, like: more than two command line arguments(./substitution and the key), numbers or duplicates in the key.
3. If no errors are found, it takes user input for a plain text.
4. This plain text, alongside the key, is passed to the encryption function, where the word is encrypted.
5. The program prints out the encrypted word.

## Example runs

./substitution NQXPOMAFTRHLZGECYJIUWSKDVB 
plaintext: Hello!
ciphertext: Fonne!

./substitution 123
Key must contain 26 letters, different from each other

./substitution
Usage: ./substitution key

## What could be done better
1) In the key_alpha_check, due to misunderstanding, I decided to enlarge the program by unnecesary conditions. I could simply return 'y' inside the loop after finding a non-alphabetic character, instead of checking the whole key after that. The same for the key_duplicate_check.
2) In the encryption, I could have put the place variable inside the for declaration, like i, so it would not be declared every iteration. 
There are more things for sure, but these are the most important ones in my opinion.

## Reflection
This program is more complex than the previous one. It uses the command line arguments, arrays, deeper understanding of loops, conditions, and functions. 
Comparing to the previous credit program, here I decided to add comments inside the code, so it would be easier to understand. Also, I started to return 0s for success and positive integers for failure. So, there are definitely improvements in my coding skills.  
Overall, I like this program a lot and I believe that coding it, allowed me to deepen my understanding of C language, as well as CS in general. 
