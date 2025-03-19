#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

enum NivelSeveridad {
    DEBUG =1,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

void logMessage(const std::string& message, int SeverityLevel){

    std::ofstream file("logged_file.txt", std::ios::app); //abre el archivo en modo append
    if (file.is_open()){
        std::string Severity_Label;
        switch (SeverityLevel){
            case DEBUG: Severity_Label = "DEBUG"; break;
            case INFO: Severity_Label = "INFO"; break;
            case WARNING: Severity_Label = "WARNING"; break;
            case ERROR: Severity_Label = "ERROR"; break;
            case CRITICAL: Severity_Label = "CRITICAL"; break;
            default: Severity_Label = "LEVEL NOT LOGGED"; break;
        }
        file << "["<< Severity_Label<< "] " << message <<std::endl;
        file.close();
    }
    else{
        std::cerr <<"Error: Failed to open the file."<<std::endl;
    }
}

void logMessage(const std::string& message, const std::string& file_name, int line){
    std::ofstream file ("logged_file.txt", std::ios::app);
    if (file.is_open()){
        file << "[ERROR] File: "<< file_name << ", Line: "<<line<<", Error Type: " << message <<std::endl;
        file.close();
    }
    else{
       throw std::runtime_error("Failed to open the file.");
    }
}

void logMessage(const std::string& message, const std::string& username){
    std::ofstream file("logged_file.txt", std::ios::app);
    if (file.is_open()){
        file << "[SECURITY] Usuario: "<< username << ", Status: " << message <<std::endl;
        file.close();
    }
    else{
        std::cerr<<"Error: Failed to open the file." << std::endl;
    }
}
int main() {
    try {
        logMessage("Possible Segmentation Fault", 1);
        logMessage("Check", 2); 
        logMessage("Dangling Pointer", 3);
        logMessage("Dividing by Zero", 4);
        logMessage("Memory Leak", 5);
        logMessage("Diving by Zero", "Physics_Homework.pdf", 23);
        throw std::runtime_error("Mocked runtime error");
    }
    catch (const std::exception& e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
        logMessage(e.what(), "Physics_Homework.pdf", 23);
        std::cerr<<"Error has ocurred, closing program with code 1." <<std::endl;
        return 1;
    }
    return 0;
}
