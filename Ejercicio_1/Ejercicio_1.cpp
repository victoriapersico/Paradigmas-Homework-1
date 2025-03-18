#include <iostream>
using namespace std;
//no hace falta que haga un liberar memoria?
int** create_matrix(int n){

    int** array = new int *[n];
    for (int i=0; i<n; i++){
        array[i]=new int [n];
    }
    return array;
}

void assign_value(int** array, int n){
    int value = 1;
    for(int i=0; i<n*n; i++){
        int row = i/n;
        int column = i%n;
        array[row][column]=value++;
    }
}

void print_values_decreasing_way(int **array, int n){

    for(int i = n*n-1; i>=0; i--){
        int row =i/n;
        int column= i%n;
        cout << "Matrix["<<row<<"]["<<column<<"] = "<<array[row][column]<<endl;
    }

}

void free_matrix(int ** array, int n){

    for(int i =0; i<n;i++){
        delete [] array[i];
    }
    delete [] array;
}

int main(){
    int n;
    cout <<"Insert a positive integer:";
    cin >> n;
    if (n>1){
        int**matrix = create_matrix(n);
        assign_value(matrix,n);
        print_values_decreasing_way(matrix, n);
        free_matrix(matrix,n);
    }
    else{
        cout<<"The number must be a positive integer.\n";
    }
    return 0;
}