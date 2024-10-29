#include <cctype> // for the isalpha function
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "transformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaesarCipher.hpp"




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// Main /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    //const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    size_t key{0};
    // initialise as true (encrypt) to start with
    bool encrypt{true};


    
    const bool cmdLineStatus{ProcessCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, encrypt)};

    if (!cmdLineStatus){
        return 1;
    }

       

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>] [-k <key>] [encypt/decrypt]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -k int(key)      Provide an integer number as the cipher key for encypting/decrypting the input text\n\n"
            << "  bool\n\n"
            << "  (encypt/decrypt) Provide a boolean [True/False] to indicate encyption or decryption of the input text\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
    std::string cipherOutputText;

    // Read in user input from file if we have one
    if (!inputFile.empty()) {

        std::ifstream in_file {inputFile};
        

        // Only reading in if its good to read

        // if the istream didn't work
        if (!in_file.good()) {
            
            // print error message
            std::cerr << "[error] Failed to create istream on file " << inputFile << " and read" << std::endl;
            return 1;
        }


        // Assuming it did work, take each caharcter from the inut file an add it to the inputChar string
        while (in_file >> inputChar){
            inputText += transformChar(inputChar);

        }
       
        

        
    } else {
        // Take input from the command line if an input file was not given
        // loop over each character from user input
        while (std::cin >> inputChar) {
        
            // transform the input string into a suitable form for input into cipher
            inputText += transformChar(inputChar);
            } 

    }

    // Take the transliterated text and apply the cipher to it to encrypt/decrypt it.
    cipherOutputText = runCaesarCipher(inputText, key, encrypt);

    

    // Write the transliterated text to the output file
    if (!outputFile.empty()) {
        // open the file and check its ok to be used to write to
        std::ofstream out_file {outputFile};

        // Only writing if it's good to write

        if (!out_file.good()){
            // print error message
            std::cerr << "[error] Failed to create ostream on " << outputFile << " and write" << std::endl;
            return 1;
        } 
    
        // Assuming the file is good to write to, print the transformed text to the output file
        out_file << inputText << std::endl;
    


    // print to command line if no output file was given
    } else {

        std::cout << inputText << std::endl;

    }

    // Need to call the Ceasar Cipher function to take the key and the encrypt/decrypt boolean and apply the cipher to the input text.


    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}



