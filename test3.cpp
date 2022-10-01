#include<iostream>

using namespace std;

class node{
    public:
        int coef;
        int grado;
        node* next;
    public:
        node(int _coef, int _grado){
            coef = _coef;
            grado = _grado;
            next = nullptr;
        }
};

class polinomio{
    private:
        node* head;

    public:
        polinomio():head{nullptr}{}

        // agregar elementos al inicio de la lista
        void insert(int coef, int grado){
            if(!head){
                head = new node(coef, grado);
            }
            else {
                node* newNode = new node(coef, grado);
                newNode->next = head;
                head = newNode;
                newNode->coef = coef;
                newNode->grado = grado;
            }
        }

        // agregar elementos al final de la lista
        void push_back(int coef, int grado){
            if(!head){
                head = new node(coef, grado);
            }else{
                node* tmp = head;
                for(; tmp -> next; tmp = tmp -> next);
                tmp ->next = new node(coef, grado);
                //tmp->coef = coef;
                //tmp->grado = grado;
            }
        }

        void add(int coef, int grado){
            if(!head){
                head = new node(coef, grado);
            }
            else{
                node* newNode = new node(coef, grado);
                //newNode->grado = grado;

                if(newNode->grado > grado){
                    insert(coef, grado);
                }
                else if(newNode->grado < grado){
                    push_back(coef, grado);
                }
                else{

                }
                //newNode->next = head;
                //head = newNode;
                //newNode->coef = coef;
                //newNode->grado = grado;
            }
        }

        void print(){
            node* x = this->head;
            while(x != nullptr){
                cout << x->coef << "x" << x->grado << " -> ";
                x = x->next;
            }
            cout << "\n";
        }


/*
        // Metodo insert    set () 
        void insertOrdered(int coef, int grado){
            node* tmp = new node(coef, grado);
            tmp -> grado = grado;
            tmp -> next = nullptr;
            
            if(this -> head == nullptr || grado < this -> head -> grado){
                tmp = tmp-> next; // 2 -> 5       <       //  5
                this -> head = tmp;
            }
            else{
                node* aux = this -> head;
                while(aux -> next != nullptr && aux -> next -> grado < grado){
                    aux = aux -> next;
                }
                if(aux -> next == nullptr){
                    aux = tmp->next;
                }
                else if(aux -> next ->grado >= grado){
                    tmp = aux -> next-> next; 
                    aux = tmp ->next;
                }
            }     
        }
*/

        
};

int main(){
    polinomio n;
    
    cout << "Insertar al inicio: " << endl;
    n.insert(-1,0);
    n.insert(3,2);
    n.insert(3,4);
    n.insert(-19,5);
    n.insert(8,7);
    cout << "Lista: " << endl;
    n.print();

  
    cout << "Insertar en orden: " << endl;
    n.add(8,7);
    n.add(3,8);
    n.add(4,5);

    //n.insertOrdered(8,7);
    //n.insertOrdered(3,8);
    //n.insertOrdered(4,5);
    cout << "Lista: " << endl;
    n.print();
    

    return 0;
}