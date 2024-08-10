#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate symptoms randomly
void generateSymptoms(bool symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        symptoms[i] = rand() % 2 == 0;  // Assign true or false randomly
    }
}

// Function to check the type of illness
std::string checkIllness(bool symptoms[]) {
    // Implement basic logic to check the type of illness based on symptoms
    // This is a simplified example, and you may need to refine it based on your requirements.
    if (symptoms[0] && symptoms[1] && symptoms[2]) {
        return "COVID-19";
    } else if (symptoms[0] || symptoms[1] || symptoms[5]) {
        return "Cold";
    } else if (symptoms[0] || symptoms[1] || symptoms[4]) {
        return "Flu";
    } else {
        return "Other illness";
    }
}

int main() {

    std::cout << "Welcome to Symptoms Checker" << std::endl;\
    

    // Guide for symptoms
    std::cout << "Guide: * Common + Sometimes/Rarely - NO" << std::endl;
    std::cout <<"==============================================================" << std::endl;
    std::cout << "Symptoms | COVID-19 | Cold | Flu |" << std:: endl;
    std::cout <<"==============================================================" << std::endl;
    std::cout << "Fever | * | + | * |" << std::endl;
    std::cout << "Cough | * | + | * |" << std::endl;
    std::cout << "Shortness of Breath | * | - | - |" << std::endl;
	std::cout << "Runny Nose | + | * | + |" << std::endl;
	std::cout << "Headaches | + | + | * |" << std::endl;
	std::cout << "Sneezing | - | * | - |" << std::endl;
	std::cout << "Fatigue | + | + | * |" << std::endl;

    // Array to store symptoms
    bool symptoms[7];

    // Input the number of patients
    int numPatients;
    std::cout << "Enter the number of patients? ";
    std::cin >> numPatients;

    int covidCount = 0, coldCount = 0, fluCount = 0, otherCount = 0;

    // Generate symptoms and classify patients
    for (int i = 0; i < numPatients; ++i) {
        generateSymptoms(symptoms, 7);

        // Check the type of illness
        std::string illness = checkIllness(symptoms);

        // Count patients based on illness
        if (illness == "COVID-19") {
            ++covidCount;
        } else if (illness == "Cold") {
            ++coldCount;
        } else if (illness == "Flu") {
            ++fluCount;
        } else {
            ++otherCount;
        }
    }

    // Output the final report
    std::cout << "Symptoms Checker...." << std::endl;
    std::cout << covidCount << " patients have symptoms of COVID-19" << std::endl;
    std::cout << coldCount << " patients have symptoms of Cold" << std::endl;
    std::cout << fluCount << " patients have symptoms of Flu" << std::endl;
    std::cout << otherCount << " patients may have some other illness" << std::endl;

    // Calculate and output the percentage of each illness
    double totalPatients = static_cast<double>(numPatients);
    double covidPercentage = (covidCount / totalPatients) * 100.0;
    double coldPercentage = (coldCount / totalPatients) * 100.0;
    double fluPercentage = (fluCount / totalPatients) * 100.0;
    double otherPercentage = (otherCount / totalPatients) * 100.0;

    std::cout << "========================================" << std::endl;
    std::cout << "Percentage of each illness:" << std::endl;
    std::cout << "COVID-19: " << covidPercentage << "%" << std::endl;
    std::cout << "Cold: " << coldPercentage << "%" << std::endl;
    std::cout << "Flu: " << fluPercentage << "%" << std::endl;
    std::cout << "Other illness:" << otherPercentage << "%" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}