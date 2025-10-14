#pragma once
#include <string>
#include <iostream>
#include <sstream>
class inputValidator {
private:
    std::string prompt;
    bool valid_or_invalid{};
    int boundLo;
    int boundHi;
public:
    inputValidator(const int &upperBound, const int &lowerBound, const std::string &prompt);
    static bool isInputInt(const std::string &input);
    bool isInputInBounds(const int &inputAsInt) const;
    bool inBounds(const std::string &input) const;
    std::string generateOopsMsg() const;
    std::string generateYayMsg() const;
    int oops(std::string &inputString);
};