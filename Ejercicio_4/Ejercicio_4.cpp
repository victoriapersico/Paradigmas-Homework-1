#include <iostream>
#include <chrono>

using namespace std;

// SECTION A: Recursive comparison using char*
// Compara dos cadenas de caracteres recursivamente usando punteros.
bool recursive_comparison(const char* s1, const char* s2) {
   if (*s1 == '\0' && *s2 == '\0') { //Si las 2 cadenas terminan, devuelve True
       return true;
   }
   if (*s1 != *s2) { //Las cadenas son diferentes si algún caracter es distinto
       return false;
   }
   return recursive_comparison(s1 + 1, s2 + 1); // Avanzamos punteros recursivamente
}


// SECTION C: Compile-time comparison using constexpr
constexpr bool compile_time_comparison(const char s1[], const char s2[], size_t index = 0) {
   if (s1[index] == '\0' && s2[index] == '\0') { //Caso base cuando las 2 cadenas terminan
       return true;
   }
   if (s1[index] != s2[index]) { //Las cadenas son diferentes si algún caracter es distinto
       return false;
   }
   return compile_time_comparison(s1, s2, index + 1); //Llama recursivamente avanzando en el índice
}


int main() {
   // SECTION B: Measuring execution time with chrono
   cout << "Inciso B:\n" << endl;


   const char* text1 = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
   const char* text2 = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
   const char* text3 = "NASAs newest astrophysics observatory, SPHEREx, is on its way to study the origins of our universe and the history of galaxies, and to search for the ingredients of life in our galaxy. Short for Spectro-Photometer for the History of the Universe, Epoch of Reionization and Ices Explorer, SPHEREx lifted off at 8:10 p.m. PDT on March 11 aboard a SpaceX Falcon 9 rocket from Space Launch Complex 4 East at Vandenberg Space Force Base in California.";


   auto startTime = chrono::high_resolution_clock::now();
   bool answer = recursive_comparison(text1, text2);
   auto endTime = chrono::high_resolution_clock::now();
   auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);


   cout << "Are text1 and text2 the same text? " << (answer ? "Yes" : "No") << endl;
   cout << "Recursive comparison took: " << elapsedTime.count() << " nanoseconds.\n" << endl;


   auto startTime2 = chrono::high_resolution_clock::now();
   bool answer2 = recursive_comparison(text1, text3);
   auto endTime2 = chrono::high_resolution_clock::now();
   auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);


   cout << "Are text1 and text3 the same text? " << (answer2 ? "Yes" : "No") << endl;
   cout << "Recursive comparison took: " << elapsedTime2.count() << " nanoseconds.\n" << endl;


   // SECTION C: Compile-time comparison
   cout << "Inciso C:\n" << endl;
   constexpr const char text4[] = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
   constexpr const char text5[] = "In sociology, Emile Durkheim defined social facts as ways of acting, thinking, and feeling that exist outside of individuals but exert control over them, shaping their behavior and social reality. These are external, coercive, and independent of individual manifestations.";
   constexpr const char text6[] = "NASAs newest astrophysics observatory, SPHEREx, is on its way to study the origins of our universe and the history of galaxies, and to search for the ingredients of life in our galaxy. Short for Spectro-Photometer for the History of the Universe, Epoch of Reionization and Ices Explorer, SPHEREx lifted off at 8:10 p.m. PDT on March 11 aboard a SpaceX Falcon 9 rocket from Space Launch Complex 4 East at Vandenberg Space Force Base in California.";


   constexpr bool answer3 = compile_time_comparison(text4, text5); // Evaluated at compile-time
   constexpr bool answer4 = compile_time_comparison(text4, text6);


   auto startTimeCompile = chrono::high_resolution_clock::now();
   bool answerRuntime1 = compile_time_comparison(text4, text5);
   auto endTimeCompile = chrono::high_resolution_clock::now();
   auto elapsedTimeCompile = chrono::duration_cast<chrono::nanoseconds>(endTimeCompile - startTimeCompile);


   auto startTimeCompile2 = chrono::high_resolution_clock::now();
   bool answerRuntime2 = compile_time_comparison(text4, text6);
   auto endTimeCompile2 = chrono::high_resolution_clock::now();
   auto elapsedTimeCompile2 = chrono::duration_cast<chrono::nanoseconds>(endTimeCompile2 - startTimeCompile2);


   // Results
   cout << "Are text4 and text5 the same text?" << endl;
   cout << "Execution-time answer: " << (answer3 ? "Yes" : "No") << endl;
   cout << "Compile-time answer: " << (answerRuntime1 ? "Yes" : "No") << endl;
   cout << "Runtime: " << elapsedTimeCompile.count() << " nanoseconds.\n" << endl;


   cout << "Are text4 and text6 the same text?" << endl;
   cout << "Execution-time answer: " << (answer4 ? "Yes" : "No") << endl;
   cout << "Compile-time answer: " << (answerRuntime2 ? "Yes" : "No") << endl;
   cout << "Runtime: " << elapsedTimeCompile2.count() << " nanoseconds.\n" << endl;

   //Comentarios Finales:

   // A: Usar std::string y substr() es el tipo más lento porque copia en memoria una nueva cadena por cada llamada de la función recursiva. Usar std::string e índices para recorrer la cadena sin hacer copias es más rápida. Pero la mejor opción es char* porque compara cada caracter usando punteros en memoria, en vez de copiar la cadena. 
   // C: Conclusión: Comparar los textos en tiempo de compilación, con constexpr, es más eficiente que compararlos en tiempo de ejecución porque el compilador lo resuelve antes que el programa se ejecute. Para cuando sea el tiempo de ejecución, la comparación ya está pre-evaluada y no toma tanto tiempo en ejecutarse. La versión en tiempo de ejecución necesita recorrer los caracteres uno por uno en memoria.
   
   return 0;
}
