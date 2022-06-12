/*
Name: Hajer Qara
Date: 6/12/2022
File Name: ShippingCalculator
Section: ITCS 2530 V0801 2021SS - C++ Programming 1

ShippingCalculator.cpp:
Write a Item Shipping Calculator program that does the following:

Prompt and retrieve the following input from the user (through the console):
    1) Item name
    2) Is the item fragile (add in $2.00 if the item is fragile)
    3) The order total (without shipping)
    4) The destination to which the item will be shipped (USA, Canada, Australia)
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm> 
#include <fstream>

using namespace std;

//Constant Varaiables
const double WARRANTY_COST = 2.00;
const string ERROR_MESSAGE = "Invalid entry, exiting";
const string OUTPUTFILE = "Order.txt";

int main()
{
    //Declared Variables
    ofstream outputData;
    string programMessage;
    int messageLength;
    string itemName;
    string isFragile;
    double totalShipping;
    double shippingCost;
    double orderTotal;
    string destination;

    //Allows all data to output to file Order.txt
    //The ofstream varaible is used to output data with that varaible name 
    //into the file within the OUTPUTFILE varaible
    outputData.open(OUTPUTFILE); 

    totalShipping = 0.00; // Initializes total shipping for later use

    // The message at the top users will see when accessing the program
    programMessage = "   ITCS 2530 - Programming Assignment for week #3   ";
    messageLength = static_cast<int>(programMessage.length()); // calculates how many characters in the message

    //Prints out asterisk border and welcoming message to users to console
    cout << setfill('*') << setw(messageLength) << "*" << endl;
    cout << programMessage << endl;
    cout << setfill('*') << setw(messageLength) << "*" << endl;

    //Prints out asterisk border and welcoming message to users to Order.txt file
    outputData << setfill('*') << setw(messageLength) << "*" << endl;
    outputData << programMessage << endl;
    outputData << setfill('*') << setw(messageLength) << "*" << endl;

    //Prompts the users to enter name of item to the console 
    cout << endl << "Please enter the name of item (no spaces)" << setw(12) << right << setfill('.') << ":";
    cin >> itemName;

    //Prints out prompt and users entry of the items name to Order.txt 
    outputData << endl << "Please enter the name of item (no spaces)" << setw(12) << right << setfill('.') << ":";
    outputData << itemName << endl;

    //Prompts the user whether item is fragile to the console 
    cout << "Is the item fragile? (y=yes/n=no)" << setw(20) << right << ":";
    cin >> isFragile;

    //Outputs users response to whether item is fragile to Order.txt file 
    outputData << "Is the item fragile? (y=yes/n=no)" << setw(20) << right << ":";
    outputData << isFragile << endl;

    // Uses an conditional statment to determine if additional costs of protection is needed for fragile items
    // Also accounts for if the user entered a specific case or an incorrect value
    if (isFragile == "y" || isFragile == "Y")  //checks for upper or lower case 
    {
        // adds extra $2.00 if fragile
        totalShipping = totalShipping + WARRANTY_COST;
    } 
    else if (isFragile == "n" || isFragile == "N") //checks for upper or lower case
    {
        // keeps total shipping the same if not fragile
        totalShipping = totalShipping;
    } 
    else
    {
        cout << endl << ERROR_MESSAGE << endl;
        outputData << endl << ERROR_MESSAGE << endl;
        system("pause");
        return 1; // This will force the console to exit 
    }

    // Prompts the user to enter the order total to the console
    cout << "Please enter your order total" << setw(24) << right << fixed << setprecision(2) << ":";
    cin >> orderTotal;

    // Prints out the users inputted data for the order total to Order.txt file
    outputData << "Please enter your order total" << setw(24) << right << fixed << setprecision(2) << ":";
    outputData << orderTotal << endl;

    //Prompts the user to enter the destination to ship to, to the console
    cout << "Please enter destination. (usa/can/aus/mars)" << setw(14) << right << ":";
    cin >> destination;

    //Prints out the destination selected by the user to Order.txt file
    outputData << "Please enter destination. (usa/can/aus/mars)" << setw(14) << right << ":";
    outputData << destination << endl;
 
    if (destination == "usa" || destination == "can" || destination == "aus" || destination == "mars") {
        //Left empty if one of the options was selected to skip to the code below 
    }
    else {
        cout << endl << ERROR_MESSAGE << endl;
        outputData << endl << ERROR_MESSAGE << endl;
        system("pause");
        return 1; // This will force the console to exit 
    }
   
    //Changes item name input into all caps 
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);

    // Reiterates the information the user provided earlier for the item name
    outputData << endl <<"Your item is" << setw(40) << right << itemName << endl;
    cout << endl << "Your item is" << setw(40) << right << itemName << endl;


    // Uses nested if structure to determine shipping costs based on the order total users entered perviously
    if (orderTotal <= 50.00) {
        if (destination == "usa") {
            shippingCost = 6.00;
        }
        else if (destination == "can") {
            shippingCost = 8.00;
        }
        else if (destination == "aus") {
            shippingCost = 10.00; 
        }
        else {
            shippingCost = 20.00; // If usa or can or aus not entered the default destination is mars
        }
    }
    else if (orderTotal <= 100.00 && orderTotal >= 50.01) {
        if (destination == "usa") {
            shippingCost = 9.00;
        }
        else if (destination == "can") {
            shippingCost = 12.00;
        }
        else if (destination == "aus") {
            shippingCost = 14.00;
        }
        else {
            shippingCost = 50.00;
        }
    }
    else if (orderTotal <= 150.00 && orderTotal >= 100.01) {
        if (destination == "usa") {
            shippingCost = 12.00;
        }
        else if (destination == "can") {
            shippingCost = 15.00;
        }
        else if (destination == "aus") {
            shippingCost = 17.00;
        }
        else {
            shippingCost = 80.00;
        }
    }
    else {
        shippingCost = 0.00; // If the users enters higher than 150 the shipping is free
    }

    // Adds the additional shipping costs to the total shipping 
    // Currently only has the cost of shipping and if there is any added shipping based on if it is fragile
    totalShipping = totalShipping + shippingCost;

    //Prints out total shipping costs 
    outputData << "Your shipping cost is" << setw(23) << right << fixed << setprecision(2);
    outputData << "$" << totalShipping << endl;

    cout << "Your shipping cost is" << setw(23) << right << fixed << setprecision(2);
    cout << "$" << totalShipping << endl;

    //Changes destination so that it is in all caps 
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    //Prints out destination the user inputed earlier
    outputData << "Your are shipping to" << setw(26) << right << destination << endl;
    cout << "Your are shipping to" << setw(26) << right << destination << endl;

    //Adds order total to totalshipping to calculate final cost for everything 
    totalShipping = totalShipping + orderTotal;

    // Prints out the final shipping costs
    outputData << "Your total shipping costs are" << setw(15) << right << fixed << setprecision(2);
    outputData << "$" << totalShipping << endl;

    cout << "Your total shipping costs are" << setw(15) << right << fixed << setprecision(2);
    cout << "$" << totalShipping << endl;

    //Thank you message to greet users for their business 
    outputData << endl << setw(53) << setfill('-') << "Thank You!" << endl;
    cout << endl << setw(53) << setfill('-') << "Thank You!" << endl;

    outputData << endl;
    cout << endl; 

    system("pause");
    return 0;
}

////////////////////////////////////////////////////////////////
// CODE THAT I TRIED BUT DID NOT END UP IN THE FINAL PROGRAM //
/*
* 
// This didn't print out the full user input to the order file
//If a person typed more than one character it would cut off the phrase in order.txt
char isFragile 

//Didn't properly format the prompts into columns
    cout << "Please enter the name of item (no spaces)...........:";
    cout << "Is the item fragile? (y=yes/n=no)..........:";
    cout << "Please enter your order total..........:";
    cout  << "Please enter destination. (usa/can/aus).........:";

// Kept outputting the error message no matter what was written
//Incorrect logic when comparing the different statements 
// Didn't like the long statements comparing the countriess
    if (destination != "usa" || destination != "can" || destination != "aus") {
        cout << endl << errorMessage << endl;
        system("pause");
        return 1;
    }

*/