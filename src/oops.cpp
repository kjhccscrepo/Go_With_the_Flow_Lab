#include "oops.hpp"
inputValidator::inputValidator(const int &lowerBound, const int &upperBound, const std::string &prompt) {
    this->boundLo = lowerBound;
    this->boundHi = upperBound;
    this->prompt = prompt;
}
bool inputValidator::isInputInt(const std::string &input) {
    try {
        std::stoi(input);
    } catch (...) {
        return false;
    }
    return true;
}
bool inputValidator::isInputInBounds(const int &inputAsInt) const {
    if (inputAsInt >= this->boundLo && inputAsInt <= this->boundHi) {
        return true;
    }
    return false;
}
bool inputValidator::inBounds(const std::string &input) const {
    if (isInputInt(input)) {
        if (isInputInBounds(std::stoi(input))) {
            return true;
        }
        return false;
    }
    return false;
}
std::string inputValidator::generateOopsMsg() const {
    std::stringstream ss;
    ss << "Oops! Please enter a valid number between ";
    ss << this->boundLo << " and " << this->boundHi;
    ss << ".";
    return ss.str();
}
std::string inputValidator::generateYayMsg() const {
    return " is a valid input!\n";
}
int inputValidator::oops(std::string &inputString) {
    std::cout << this->prompt;
    std::cout << " Input:\t ";
    std::getline(std::cin, inputString);
    if (inBounds(inputString)) {
        // std::cout << inputString << generateYayMsg();
        return std::stoi(inputString);
    }
    std::cout << generateOopsMsg() << "\n";
    return (oops(inputString));
}