/*
NICOLLE RUIZ QUINTERO CODIGO: 8974036

ESTE PROGRAMA CREA 2 CLASES UNA QUE RECIBE EL EQUIPO CON LOS PUNTOS Y OTRA SOLO LOS EQUIPOS PARA DESPUES EN OTRA CLASE 
COMPARAR LOS NOMBRES Y ASIGNARLES SUS PUNTAJES Y DEMAS

EL PROGRAMA NO FUNCIONA BIEN, PERO PIENSO QUE EL PROGRAMA TIENE UNA COMPLEJIDAD CUADRADA YA QUE PODEMOS
ENCONTRAR VARIOS CICLOS ANIDADOS EN ESTE CODIGO.
*/

#include<iostream>
#include<string>    
#include<cstring>
#include<vector>
using namespace std;

class partido {
public:
    string nombre;
    int puntos;

    partido() {
        nombre = "";
        puntos = 0;
    }
    partido(string equipo) {
        nombre = equipo;
        puntos = 0;
    }

    partido(string equipos6, int puntaje) {
        nombre = equipos6;
        puntos = puntaje;
    }

};
class equipos {
public:
    string nombre;
    equipos() {
        nombre = "";
    }
    equipos(string equipo) {
        nombre = equipo;
    }
};
class juegos {
public:
    vector<partido> parti;
    vector<equipos> equipo5;int puntaje = 0;
    int goles = 0;
    int golesContra = 0;
    int partidosJuga = 0;
    void agregarJugador(partido m) {
        parti.push_back(m);
    }
    void agregarJuga(equipos z) {
        equipo5.push_back(z);
    }
    void jugar() {
        for (int i = 0; i < parti.size(); i++) {
            for (int j = 0; j < equipo5.size(); j++) {
                if (equipo5[j].nombre == parti[i].nombre) {
                    if (parti[i].puntos == parti[i + 1].puntos) {
                        puntaje += 1;
                        goles += parti[i].puntos;
                        golesContra += parti[i + 1].puntos;
                        partidosJuga += 1;
                    }
                    if (parti[i].puntos > parti[i + 1].puntos) {
                        puntaje += 3;
                        goles += parti[i].puntos;
                        golesContra += parti[i + 1].puntos;
                        partidosJuga += 1;
                    }
                    if (parti[i].puntos < parti[i + 1].puntos) {
                        puntaje += 0;
                        goles += parti[i+1].puntos;
                        golesContra += parti[i].puntos;
                        partidosJuga += 1;
                    }
                }
            }
        }
    }
};
int main() {
    juegos jugo;
    int jugadores;
    int partidos;
    char caracter;
    cin >> jugadores;
    cin >> partidos;
    while (jugadores != 0 && partidos != 0) {
        vector<string> equipo11;
        vector<string> equipos1;
        vector<int> puntaje4;
        vector<int> puntaje3;
        for(int i=0;i<jugadores;i++){
            string equipo12;
            cin>>equipo12;
            equipo11.push_back(equipo12);
        }
        equipos equipito(equipo11);
        jugo.agregarJuga(equipito);
        for (int j = 0; j < partidos; j++) {
            int puntajes1;
            int puntajes2;
            string equipo2;
            string equipo1;
            string caracter;
            cin >> equipo2;
            equipos1.push_back(equipo2);
            cin >> puntajes1;
            puntaje3.push_back(puntajes1);
            cin >> caracter;
            cin >> puntajes2;
            puntaje3.push_back(puntajes2);
            cin >> equipo1;
            equipos1.push_back(equipo1);
        }
        partido nomparti(equipos1,puntaje3);
        jugo.agregarJugador(nomparti);
    }
    return 0;
}