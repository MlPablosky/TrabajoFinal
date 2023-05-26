#include <iostream>
#include <string>

/*CREADO POR : Pablo Murillo Lemus, Yeison Stiven Lozano, Luis Adrian Caicedo*/
using namespace std;

struct Atleta {
    string nombre;
    double tiempo1;
    double tiempo2;
    Atleta* left;
    Atleta* right;
};

Atleta* insertarAtleta(Atleta* root, string nombre, double tiempo1, double tiempo2) {
    if (root == NULL) {
        Atleta* nuevoAtleta = new Atleta;
        nuevoAtleta->nombre = nombre;
        nuevoAtleta->tiempo1 = tiempo1;
        nuevoAtleta->tiempo2 = tiempo2;
        nuevoAtleta->left = NULL;
        nuevoAtleta->right = NULL;
        return nuevoAtleta;
    }

    if (nombre < root->nombre) {
        root->left = insertarAtleta(root->left, nombre, tiempo1, tiempo2);
    } else {
        root->right = insertarAtleta(root->right, nombre, tiempo1, tiempo2);
    }

    return root;
}

void mostrarAtletas(Atleta* root) {
    if (root == NULL) {
        return;
    }
    mostrarAtletas(root->left);
    cout << root->nombre << ": " << root->tiempo1 << ", " << root->tiempo2 << endl;
    mostrarAtletas(root->right);
}

void mostrarPromediosAscendente(Atleta* root) {
    if (root == NULL) {
        return;
    }
    mostrarPromediosAscendente(root->left);
    double promedio = (root->tiempo1 + root->tiempo2) / 2.0;
    cout << root->nombre << ": " << promedio << endl;
    mostrarPromediosAscendente(root->right);
}

void liberarMemoria(Atleta* root) {
    if (root == NULL) {
        return;
    }
    liberarMemoria(root->left);
    liberarMemoria(root->right);
    delete root;
}

int main() {
    Atleta* root = NULL;
    int choice;

    do {
        cout << endl <<"---MENU DE REGISTRO DE ATLETAS---" << endl;
        cout << "1. Agregar atleta" << endl;
        cout << "2. Mostrar atletas (ordenados por nombre)" << endl;
        cout << "3. Mostrar promedios de tiempos (ascendente)" << endl;
        cout<<"4. Prticipantes del codigo" <<endl;
        cout << "5.. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                string nombre;
                double tiempo1, tiempo2;
                cout << "Ingrese el nombre del atleta: ";
                cin >> nombre;
                cout << "Ingrese el tiempo 1 para el atleta: ";
                cin >> tiempo1;
                cout << "Ingrese el tiempo 2 para el atleta: ";
                cin >> tiempo2;
                root = insertarAtleta(root, nombre, tiempo1, tiempo2);
                system("cls");
                break;
            }
            case 2:
                cout << endl << "Los datos de los atletas (ordenados por nombre) son:" << endl;
                mostrarAtletas(root);
                system("cls");
                break;
            case 3:
                cout << endl << "Los promedios de los tiempos (ascendente) son:" << endl;
                mostrarPromediosAscendente(root);
                system("cls");
                break;               
               
            case 5:
                liberarMemoria(root);
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
