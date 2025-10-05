#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    string firstName, lastName, department;
    double grossSalary, bonus, taxRate;
    double distancedTraveled, travelTime;
    int nummOfCoffeeCupSold;
    double coffeeCupCost;
    
    // Open input file
    inFile.open("inData.txt");
    
    // Error checking for input file
    if (!inFile) 
    { 
        cout << endl << "Error opening input file inData.txt." << endl; 
        system("pause");
        return -1;
    }
    
    // Open output file
    outFile.open("outData.txt");
    
    // Error checking for output file
    if (!outFile)
    {
        cout << endl << "Error opening output file outData.txt." << endl;
        inFile.close();
        system("pause");
        return -1;
    }
    
    // Read data from input file
    inFile >> firstName >> lastName >> department;
    inFile >> grossSalary >> bonus >> taxRate;
    inFile >> distancedTraveled >> travelTime;
    inFile >> nummOfCoffeeCupSold >> coffeeCupCost;
    
    // Process and write data to output file
    outFile << fixed << setprecision(2);
    outFile << "Name: " << firstName << " " << lastName << ", Department: " << department << endl;
    outFile << "Monthly Gross Salary: $" << grossSalary << ", Monthly Bonus: " << bonus << "%, Taxes: " << taxRate << "%" << endl;
    
    // Calculate paycheck (gross salary with bonus, minus taxes)
    double paycheck = grossSalary * (1 + bonus/100) * (1 - taxRate/100);
    outFile << "PayCheck: $" << paycheck << endl;
    
    outFile << "Distance Traveled: " << distancedTraveled << " miles, Traveling Time: " << travelTime << " hours" << endl;
    
    // Calculate average speed
    double averageSpeed = distancedTraveled / travelTime;
    outFile << "Average Speed: " << averageSpeed << " miles per hour" << endl;
    
    outFile << "Number of Coffee Cups Sold: " << nummOfCoffeeCupSold << ", Cost: $" << coffeeCupCost << " per cup" << endl;
    
    // Calculate sales amount
    double salesAmount = nummOfCoffeeCupSold * coffeeCupCost;
    outFile << "Sales Amount = $" << salesAmount << endl;
    
    // Close files
    inFile.close();
    outFile.close();
    
    cout << "Data processing completed successfully. Check outData.txt for results." << endl;
    system("pause");
    return 0;
}