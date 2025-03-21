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

void logMessage(const string& message, int SeverityLevel){

    ofstream file("logged_file.txt", ios::app); //abre el archivo en modo append
    if (file.is_open()){
        string Severity_Label;
        switch (SeverityLevel){
            case DEBUG: Severity_Label = "DEBUG"; break;
            case INFO: Severity_Label = "INFO"; break;
            case WARNING: Severity_Label = "WARNING"; break;
            case ERROR: Severity_Label = "ERROR"; break;
            case CRITICAL: Severity_Label = "CRITICAL"; break;
            default: Severity_Label = "LEVEL NOT LOGGED"; break;
        }
        file << "["<< Severity_Label<< "] " << message <<endl;
        file.close();
    }
    else{
        cerr <<"Error: Failed to open the file."<<endl;
    }
}

void logMessage(const string& message, const string& file_name, int line){
    ofstream file ("logged_file.txt", ios::app);
    if (file.is_open()){
        file << "[ERROR] File: "<< file_name << ", Line: "<<line<<", Error Type: " << message <<endl;
        file.close();
    }
    else{
       throw runtime_error("Failed to open the file.");
    }
}

void logMessage(const string& message, const string& username){
    ofstream file("logged_file.txt", ios::app);
    if (file.is_open()){
        file << "[SECURITY] Usuario: "<< username << ", Status: " << message <<endl;
        file.close();
    }
    else{
        cerr<<"Error: Failed to open the file." << endl;
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
        throw runtime_error("Mocked runtime error");
    }
    catch (const exception& e){
        cerr << "Exception caught: " << e.what() << endl;
        logMessage(e.what(), "Mocked_Runtime_Error.pdf", 13);
        cerr<<"After mocked runtime error has ocurred, closing program with code 1." <<endl;
        return 1;
    }
    return 0;
}
