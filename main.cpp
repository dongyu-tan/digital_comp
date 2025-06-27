#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    double devicePowerWatts;
    double hoursPerDay;
    double costPerKWH;
    double carbonEmissionsPerKWH;

    double dailyKWH;
    double monthlyKWH;
    double annualKWH;

    double dailyCost;
    double monthlyCost;
    double annualCost;

    double annualCarbonFootprint;

    double reductionPercentage;
    double reducedAnnualKWH;
    double reducedAnnualCost;
    double reducedAnnualCarbonFootprint;

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "    Welcome to the Eco-Smart Home Helper!    " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Let's find out how much energy your gadgets use and " << std::endl;
    std::cout << "how you can save money and help our planet!    " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl << std::endl;

    auto getValidatedInput = [](const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail() || value < 0) {
                std::cout << "Oops! That's not a valid number. Please enter a positive number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                return value;
            }
        }
    };

    devicePowerWatts = getValidatedInput("First, tell us: How much power does your device use in Watts?\n"
                                         "  (e.g., A light bulb might be 60W, a phone charger 5W, a TV 100W): ");

    hoursPerDay = getValidatedInput("Next, roughly how many hours do you use it per day?\n"
                                    "  (e.g., If you use it for half a day, enter 12): ");

    costPerKWH = getValidatedInput("What's the cost of electricity per unit (kilowatt-hour or kWh) in your area?\n"
                                   "  (e.g., If it's RM0.15 per kWh, just enter 0.15): ");

    carbonEmissionsPerKWH = getValidatedInput("Finally, what are the average carbon emissions for electricity in your region?\n"
                                              "  (e.g., A common value is 0.5 kg CO2 per kWh. Enter 0.5 if unsure): ");

    double devicePowerKW = devicePowerWatts / 1000.0;

    dailyKWH = devicePowerKW * hoursPerDay;
    monthlyKWH = dailyKWH * 30.44;
    annualKWH = dailyKWH * 365.0;

    dailyCost = dailyKWH * costPerKWH;
    monthlyCost = monthlyKWH * costPerKWH;
    annualCost = annualKWH * costPerKWH;

    annualCarbonFootprint = annualKWH * carbonEmissionsPerKWH;

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "           Your Device's Energy Footprint               " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Daily energy use: " << dailyKWH << " kWh" << std::endl;
    std::cout << "Monthly energy use: " << monthlyKWH << " kWh" << std::endl;
    std::cout << "Annual energy use: " << annualKWH << " kWh" << std::endl << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Estimated Daily Cost: RM" << dailyCost << std::endl;
    std::cout << "Estimated Monthly Cost: RM" << monthlyCost << std::endl;
    std::cout << "Estimated Annual Cost: RM" << annualCost << std::endl << std::endl;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Estimated Annual Carbon Emissions: " << annualCarbonFootprint << " kg of CO2" << std::endl;
    std::cout << "(That's like planting " << std::fixed << std::setprecision(1) << annualCarbonFootprint / 20.0 << " small trees!)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "            Smart Living: Let's Save Energy!            " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Want to see how much you could save by using this device less?" << std::endl;
    std::cout << "Enter a percentage (from 0 to 100) you think you could reduce usage:\n"
                 "  (e.g., enter 20 for a 20% reduction): ";
    
    reductionPercentage = -1;
    while (reductionPercentage < 0 || reductionPercentage > 100 || std::cin.fail()) {
        std::cin >> reductionPercentage;
        if (std::cin.fail()) {
            std::cout << "Oops! That's not a valid number. Please enter a percentage between 0 and 100." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (reductionPercentage < 0 || reductionPercentage > 100) {
            std::cout << "Invalid percentage! Please enter a number between 0 and 100." << std::endl;
        }
    }

    reducedAnnualKWH = annualKWH * (1 - (reductionPercentage / 100.0));
    reducedAnnualCost = annualCost * (1 - (reductionPercentage / 100.0));
    reducedAnnualCarbonFootprint = annualCarbonFootprint * (1 - (reductionPercentage / 100.0));

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "  Awesome! Here's the impact of " << std::fixed << std::setprecision(0) << reductionPercentage << "% less usage!" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "New Annual Energy Use: " << reducedAnnualKWH << " kWh" << std::endl;
    std::cout << "Energy YOU Saved Annually: " << annualKWH - reducedAnnualKWH << " kWh" << std::endl << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "New Annual Cost: RM" << reducedAnnualCost << std::endl;
    std::cout << "Money YOU Saved Annually: RM" << annualCost - reducedAnnualCost << std::endl << std::endl;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "New Annual Carbon Emissions: " << reducedAnnualCarbonFootprint << " kg CO2" << std::endl;
    std::cout << "Carbon Footprint YOU Reduced Annually: " << annualCarbonFootprint - reducedAnnualCarbonFootprint << " kg CO2" << std::endl;
    std::cout << "(Every 20kg CO2 saved is like planting one tree! )" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl << std::endl;

    std::cout << "Thank you for using the Eco-Smart Home Helper!" << std::endl;
    std::cout << "Remember: Every small change helps build a greener, smarter city!" << std::endl;

    return 0;
}