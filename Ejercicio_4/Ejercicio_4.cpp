#include <iostream>
#include <chrono>

using namespace std;

// SECTION A: Recursive comparison using char*: 
bool recursive_comparison(const char* s1, const char* s2){

    if (*s1== '\0' && *s2=='\0'){
        return true;
    }

    if (*s1 != *s2){
        return false;
    }

    return recursive_comparison(s1+1, s2+1); // en el llamado recursivo avanzo punteros
}

// SECTION C: Modifying the code to use constexpr for compile-time evaluation.

constexpr bool compile_time_comparison(const char* s1, const char* s2){

    if (*s1== '\0' && *s2=='\0'){
        return true;
    }

    if (*s1 != *s2){
        return false;
    }

    return compile_time_comparison(s1+1, s2+1);
}

int main(){

    // SECTION B: Measuring executing time with chrono:
    cout<<"Inciso B:\n"<<endl;

    const char* text1 = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
    const char* text2 = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
    const char* text3 = "NASAs newest astrophysics observatory, SPHEREx, is on its way to study the origins of our universe and the history of galaxies, and to search for the ingredients of life in our galaxy. Short for Spectro-Photometer for the History of the Universe, Epoch of Reionization and Ices Explorer, SPHEREx lifted off at 8:10 p.m. PDT on March 11 aboard a SpaceX Falcon 9 rocket from Space Launch Complex 4 East at Vandenberg Space Force Base in California.";
    
    auto startTime = std::chrono::high_resolution_clock::now();
    bool answer = recursive_comparison(text1, text2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout<<"Are text1 and text2 the same text? "<< (answer ? "Yes" : "No") <<std::endl;
    std::cout << "My recursive_comparison took: "<< elapsedTime.count() << " nanoseconds to tell."<< std::endl;

    auto startTime2 = std::chrono::high_resolution_clock::now();
    bool answer2 = recursive_comparison(text1, text3);
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);
    std::cout<<"Are text1 and text3 the same text? "<< (answer2 ? "Yes" : "No") <<std::endl;
    std::cout << "My recursive_comparison took: "<< elapsedTime2.count() << " nanoseconds to tell."<< std::endl;

    // SECTION C: Measuring comparison time in executing time:
    cout<<"\nInciso C:\n"<<endl;
    constexpr const char text4[] = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
    constexpr const char text5[] = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
    constexpr const char text6[] = "NASAs newest astrophysics observatory, SPHEREx, is on its way to study the origins of our universe and the history of galaxies, and to search for the ingredients of life in our galaxy. Short for Spectro-Photometer for the History of the Universe, Epoch of Reionization and Ices Explorer, SPHEREx lifted off at 8:10 p.m. PDT on March 11 aboard a SpaceX Falcon 9 rocket from Space Launch Complex 4 East at Vandenberg Space Force Base in California.";
    
    constexpr bool answer3 = compile_time_comparison(text4, text5); //evaluated in compilation-time
    constexpr bool answer4 = compile_time_comparison(text4, text6);

    auto start_Time = std::chrono::high_resolution_clock::now();
    bool answer_3 = compile_time_comparison(text4, text5); //evaluated in execution-time
    auto end_Time = std::chrono::high_resolution_clock::now();
    auto elapsed_Time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_Time - start_Time);

    auto start_Time2 = std::chrono::high_resolution_clock::now();
    bool answer_4 = compile_time_comparison(text4, text6);
    auto end_Time2 = std::chrono::high_resolution_clock::now();
    auto elapsed_Time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_Time2 - start_Time2);
    //Me falta mostrar resultados inciso C
    return 0;
}