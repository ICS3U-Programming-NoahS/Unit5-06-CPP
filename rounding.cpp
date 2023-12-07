// Copyright (c) 2023 Noah Smith All rights reserved.
//
// Created by: Noah Smith
// Date: Dec. 4th, 2023
// This program asks the user for a number
// and a number of decimal places
// it then rounds that number and displays it
// with the proper amount of decimal places
#include <iostream>
#include <cmath>

void RoundDecimal(float &decNumFloat, int &numPlaces) {
    // Round number to correct amount of decimal places
    decNumFloat = decNumFloat * pow(10, numPlaces);
    decNumFloat = decNumFloat + 0.5;
    int decNumInt = int(decNumFloat);
    decNumFloat = decNumInt / pow(10, numPlaces);
}

int main() {
    // Declare variables
    std::string numStr, numPlacesStr;
    float numFloat;
    int numPlacesInt;

    // get number and number of decimal places from user
    std::cout << "Enter a number: ";
    std::cin >> numStr;
    std::cout << "Enter the number of decimal places: ";
    std::cin >> numPlacesStr;

    // Catch invalid input
    try {
        numFloat = std::stof(numStr);
        try {
            numPlacesInt = std::stoi(numPlacesStr);

            // If number of decimal places is less than 0
            if (numPlacesInt < 0) {
                std::cout << numPlacesInt;
                std::cout << " is not a valid number";
                std::cout << " of decimal places" << std::endl;
            } else {
                // Call function
                RoundDecimal(numFloat, numPlacesInt);

                // Display rounded number
                std::cout << numStr << " rounded to ";
                std::cout << numPlacesInt;
                std::cout << " decimal place(s) is " << numFloat << std::endl;
            }
        } catch (std::exception) {
            std::cout << numPlacesStr << " is not an integer." << std::endl;
        }
    } catch (std::exception) {
        std::cout << numStr << " is not a float." << std::endl;
    }
}
