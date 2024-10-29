#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

#include "ProcessCommandLine.hpp"



bool ProcessCommandLine(
    const std::vector<std::string>& args, 
    bool& helpRequested, 
    bool& versionRequested,
    std::string& inputFileName,
    std::string& outputFileName,
    size_t& key,
    bool& encrypt){

    /* This function processes the command line arguments given when running the script

    const std::vector<std::string>& args: a vector containing the arguments given on the command line
    bool& helpRequested: a boolean , indicating that help has been requested
    bool& versionRequested: a boolean, indciating if the version has been requested
    std::string& inputFileName: a string that will be the name of the input file containing the text for encryption/decryption.
    std::string& outputFileName: a string that will be the name of the file the encrypted/decrypted text will be outputted to.

    Returns:
    A boolean to signify if the processing of the command line arguments has been sucessful.
    
    */

    bool processStatus{true};


    // a variable containing the number of arguments given
    const std::size_t nargs{args.size()};

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nargs; ++i) {

        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
            break;

        } else if (args[i] == "--version") {
            versionRequested = true;
            break;

        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nargs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // 
                processStatus = false;
                break;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
                
            }

        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nargs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // 
                processStatus = false;
                break;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
                
            }
        

        } else if (args[i] == "-k"){
            // Handle the key option
            // Next element is the key unless "-k" is the last argument
            if (i == nargs -1 ){
                std::cerr << "[error] -k requires a key argument"
                          << std::endl;
                
                processStatus = false;
                break;
            } else {
                // we have a key so assign the value and advance past it
                // we want the key as an unsigned long so we need to convert it from a string
                key = std::stoul(args[i + 1], nullptr, 10);
                ++i;

            }


        } else if (args[i] == "encrypt"){
            // Handle the encrypt/decrypt option
            // set encrypt variable to true
            encrypt = true;
        
        } else if (args[i] == "decrypt"){
            // Handle the encrypt/decrypt option
            // set encrypt variable to false
            encrypt = false;
        
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            processStatus = false;
            break;
        }

    }

    // need to return a boolean variable to indicate that the processing of the command line arguments was successful.
    // Not sure if this should always be true or i should have other things in the code.
    return processStatus;
    
    // not sure it's working exactly as it should - ideally, if -i or -o are the last arguments and an input and output file 
    // arent given, the program should just stop there and stop you from entering text in a the command line.
    // Only if you don't use the -i or -o options should it let you input text from the command line and then spit it out to the command line.
}
