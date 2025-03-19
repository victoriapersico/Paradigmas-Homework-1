#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//BORRAR TESTS

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

// int main() {
//     logMessage("tiene que decir debug", 1);
//     logMessage("tiene que decir warning.", 3); 
//     logMessage("Tiene que decir error", 4); 
// }
