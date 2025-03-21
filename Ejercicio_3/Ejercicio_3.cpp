#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

// Estructura para representar un nodo en la lista
struct node{
    int value;
    shared_ptr<node> next; // Puntero al siguiente nodo
};
// Estructura para representar la lista simplemente enlazada
struct list{
    shared_ptr<node> head;
    shared_ptr<node> tail;
    size_t size;
};
// Crea un nuevo nodo con un valor dado y retorna un shared_ptr
shared_ptr<node> create_node(int value){
    shared_ptr<node> new_node = make_shared<node>();
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}
// Crea una nueva lista vacía y retorna un shared_ptr
shared_ptr<list> create_list(){
    shared_ptr<list> new_list = make_shared<list>();
    new_list->head = nullptr;
    new_list->tail = nullptr;
    new_list->size = 0;
    return new_list;
}
// Inserta un nodo al inicio de la lista
void push_front(int value, shared_ptr<list>& my_list){ 
    shared_ptr<node> new_node = create_node(value);

    if (!my_list->head){ // Si la lista está vacía
        my_list->head= my_list->tail=new_node;
    }
    else{
        new_node->next=my_list->head;
        my_list->head=new_node;
    }
    my_list->size++;
}
// Inserta un nodo al final de la lista
void push_back(int value, shared_ptr<list>& my_list){
    shared_ptr<node> new_node = create_node(value);

    if (!my_list->head){// Si la lista está vacía
        my_list->head= my_list->tail=new_node;
    }
    else{
        my_list->tail->next=new_node;
        my_list->tail=new_node;
    }
    my_list->size++;
}
// Inserta un nodo en una posición específica de la lista
void insert(size_t position, int value, shared_ptr<list>& my_list){
    if(!my_list) return;

    if (position==0){// Si es la primera posición usa push_front
        push_front(value,my_list);
        return;
    }

    shared_ptr<node> new_node = create_node(value);
    shared_ptr<node> current = my_list->head;
    size_t current_index = 0;

    while(current && current_index < position - 1){// Avanza hasta la posición deseada o hasta que se termina la lista
        current = current->next;
        current_index++;
    }

    if(!current){ // Inserta al final si la posición está fuera de rango
        cout<< "Index out of list's range, inserting at the end."<<endl;
        push_back(value,my_list);
        return;
    }

    new_node->next=current->next; // Inserta el nuevo nodo en la posición correcta
    current->next=new_node;

    if(!new_node->next){ // Si el nodo se insertó al final, actualiza tail
        my_list->tail = new_node;
    }

    my_list->size++;
}
// Elimina un nodo en una posición específica de la lista
void erase(size_t position, shared_ptr<list>& my_list){
    if(!my_list || !my_list->head){
        cout<<"List is empty, there're no elements to remove."<<endl;
        return;
    }

    if (position==0){ // Caso si se elimina el primer nodo
        my_list->head=my_list->head->next;
        if(!my_list->head){ //caso si la lista se queda vacia
            my_list->tail = nullptr;
        }
        my_list->size--;
        return;
    }

    shared_ptr<node> current = my_list->head;
    shared_ptr<node> previous = nullptr;
    size_t current_index = 0;

    while(current->next && current_index < position){ //avanza hasta la posición indicada
        previous=current;
        current=current->next;
        current_index++;
    }

    if (current_index < position) { // Si la posición es mayor al tamaño de la lista
        cout << "Index out of list's range, removing its tail." << endl;
        if (previous) { // si hay un nodo anterior elimino el último nodo
            previous->next = nullptr;
            my_list->tail = previous;
        } else { 
            // si no hay nodo anterior, solo hay 1 elemento
            my_list->head = nullptr;
            my_list->tail = nullptr;
        }
        my_list->size--;
        return;
    }
    //Elimino el actual conectando el nodo anterior con el siguiente
    previous->next=current->next;
    if(!previous->next){ // Si se elimina el último nodo, actualiza tail
        my_list->tail=previous;
    }
    my_list->size--;
}
//Imprime la lista
void print_list(shared_ptr<list>& my_list){
    if(!my_list || !my_list->head){ //Si la lista está vacía
        cout<<"List is empty."<<endl;
        return;
    }
    shared_ptr<node> current = my_list->head;
    while(current){
        cout<<current->value;
        if (current->next){
            cout<<" -> ";
        }
        current=current->next;
    }
}

int main(){
    shared_ptr<list> list1=create_list();

    push_front(11, list1);
    push_front(10, list1);
    push_front(9, list1);

    cout<<"List after push_front(11), push_front(10), push_front(9): ";
    print_list(list1);
    cout<<endl;

    push_back(12, list1);
    push_back(13, list1);
    push_back(14, list1);

    cout<<"List after push_back(12), push_back(13), push_back(14): ";
    print_list(list1);
    cout<<endl;

    insert(3, 21, list1);
    insert(55, 1000, list1); //Position 55 is out of range, inserts the element at the end.

    cout<<"List after insert(3, 21), insert(55, 1000): ";
    print_list(list1);
    cout<<endl;

    erase(2, list1);
    erase(44, list1); //Position 44 is out of range, deletes the element at the end.
    erase(0, list1); //Deletes list's first node.

    cout<<"List after erase(2), erase(44), erase(0): ";
    print_list(list1);
    cout<<endl;

    return 0;
}
