#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

#include "runCaesarCipher.hpp"


std::string runCaesarCipher( const std::string& inputText, 
    const size_t key, 
    const bool encrypt){

    /* This function will take the capitalised text and apply the Caesar cipher with the specified key to the text to encrypt/decrypt it
    
    const std::string& inputText: the capitalised text to be encrypted/decrypted
    const size_t key: the key, a number used to define the shift in the aplhabet used by the Caesar cipher to encrypt/decrypt the text
    const bool encrypt: the boolean indicating whather the user wants to encrypt or decryt the input text
    
    */

   // create the alphabet container and output string
   std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   std::string cipherOutputText{""};

   // Loop over the input text
   for 

   // For each character find the corresponding position in the alphabet

   // get the index in the alphabet list of the letter

   // Apply the shift (+ve or -ve depending on the encrypt/decrypt)
   // to the position, handling correctly potential wrap-around.

   // add the key to the index

   // Determine the new character and add it to the output string

   // get the letter from the alphabet string in the shifted index place
   // Do this for all characters in the string

   // After the loop, return the output string
   return cipherOutputText;

}

