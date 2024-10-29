#include <iostream>
#include <string>
#include <cctype>

#include "transformChar.hpp"


std::string transformChar (const char in_char){ 


    /*transliterates the input text: all letters are turned into uppercase 
    and all numbers are spelt out into their english words and turned to uppercase.

    Non alpha-numeric characters are ignored.

    const char in_char: a line of characters
    std::string input_text: a string that the transformed text is stored in and this is the return of the function
    
    */
   
    std::string input_text;

    // Uppercase alphabetic characters
    if (std::isalpha(in_char)) {
        input_text += std::toupper(in_char);
        return input_text;
    }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            input_text += "ZERO";
            break;
        case '1':
            input_text += "ONE";
            break;
        case '2':
            input_text += "TWO";
            break;
        case '3':
            input_text += "THREE";
            break;
        case '4':
            input_text += "FOUR";
            break;
        case '5':
            input_text += "FIVE";
            break;
        case '6':
            input_text += "SIX";
            break;
        case '7':
            input_text += "SEVEN";
            break;
        case '8':
            input_text += "EIGHT";
            break;
        case '9':
            input_text += "NINE";
            break;
    }

    // If the character isn't alphabetic or numeric, DONT add it

    return input_text;
    

} 