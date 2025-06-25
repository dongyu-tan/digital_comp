#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
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

	// Welcome Message
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "✨ Welcome to the Eco-Smart Home Helper! ✨" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Let's find out how much energy your gadgets use and " << std::endl;
	std::cout << "how you can save money and help our planet! 🌍" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl
						<< std::endl;

	// Helper function for robust input
	auto getValidatedInput = [](const std::string &prompt)
	{
		double value;
		while (true)
		{
			std::cout << prompt;
			std::cin >> value;
			if (std::cin.fail() || value < 0)
			{
				std::cout << "Oops! That's not a valid number. Please enter a positive number." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				return value;
			}
		}
	};

	// Collect User Input
	devicePowerWatts = getValidatedInput("First, tell us: How much power does your device use in Watts?\n"
																			 "  (e.g., A light bulb might be 60W, a phone charger 5W, a TV 100W): ");

	hoursPerDay = getValidatedInput("Next, roughly how many hours do you use it per day?\n"
																	"  (e.g., If you use it for half a day, enter 12): ");

	costPerKWH = getValidatedInput("What's the cost of electricity per unit (kilowatt-hour or kWh) in your area?\n"
																 "  (e.g., If it's $0.15 per kWh, just enter 0.15): ");

	carbonEmissionsPerKWH = getValidatedInput("Finally, what are the average carbon emissions for electricity in your region?\n"
																						"  (e.g., A common value is 0.5 kg CO2 per kWh. Enter 0.5 if unsure): ");

	double devicePowerKW = devicePowerWatts / 1000.0;

	dailyKWH = devicePowerKW * hoursPerDay;
	monthlyKWH = dailyKWH * 30.44; // Assuming 30.44 days/month average
	annualKWH = dailyKWH * 365.0;

	dailyCost = dailyKWH * costPerKWH;
	monthlyCost = monthlyKWH * costPerKWH;
	annualCost = annualKWH * costPerKWH;

	annualCarbonFootprint = annualKWH * carbonEmissionsPerKWH;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "         📊 Your Device's Energy Footprint 📊          " << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << std::fixed << std::setprecision(3); // Set precision for KWH/Carbon
	std::cout << "✨ Daily energy use: " << dailyKWH << " kWh" << std::endl;
	std::cout << "✨ Monthly energy use: " << monthlyKWH << " kWh" << std::endl;
	std::cout << "✨ Annual energy use: " << annualKWH << " kWh" << std::endl
						<< std::endl;

	std::cout << std::fixed << std::setprecision(2); // Set precision for currency
	std::cout << "💰 Estimated Daily Cost: $" << dailyCost << std::endl;
	std::cout << "💰 Estimated Monthly Cost: $" << monthlyCost << std::endl;
	std::cout << "💰 Estimated Annual Cost: $" << annualCost << std::endl
						<< std::endl;

	std::cout << std::fixed << std::setprecision(3); // Reset precision for carbon
	std::cout << "🌳 Estimated Annual Carbon Emissions: " << annualCarbonFootprint << " kg of CO2" << std::endl;
	std::cout << "(That's like planting " << std::fixed << std::setprecision(1) << annualCarbonFootprint / 20.0 << " small trees! 🌲)" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl
						<< std::endl;

	return 0;
}