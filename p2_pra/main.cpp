#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "empleado.h"

using namespace std;

void cargarArchivo( char* file, vector<Empleado> &trabajadores ){
  string nombre, apellido;
  unsigned int cedula;
  double salario;
  int dia;
  float horas;
  string   texto;
  stringstream ss;
  
  ifstream archivo( file );
  if( archivo.is_open() ){
    while( !archivo.eof() && getline( archivo, texto)){
      ss.clear();
      ss << texto ; 
      ss >> nombre >> apellido >> cedula >> salario;
      Empleado e( nombre, apellido, cedula, salario );
      while( ss >> dia >> horas ){
        e.agregarHorasExtras( dia, horas );
      }
      trabajadores.push_back( e );
    }
    archivo.close();
  }
}

int main(int argc, char**argv){
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nombreArchivo>" << endl;
        return 1;
    }

    vector<Empleado> _trabajadores;

    cargarArchivo(argv[1], _trabajadores); // carga bien
    size_t tam = _trabajadores.size();
    cout << "Número de trabajadores: " << tam << endl;

    // Calcula el valor a pagar por horas extras de cada trabajador 
    // y mostrar el valor mensual y el valor de las horas extras en un 
    // arreglo tabular
    // Empleado (Nombre y apellido) | Salario mensual | Horas extras | Total a pagar
    cout << "Empleado (Nombre y apellido) | Salario mensual | Horas extras | Total a pagar" << endl;
    for (const auto& trabajador : _trabajadores) {
        float salarioMensual = trabajador.salario();
        float totalHorasExtras = trabajador.totalHorasExtras();
        float valorHorasExtras = trabajador.calcularHE(totalHorasExtras, salarioMensual);
        float totalAPagar = salarioMensual + valorHorasExtras;
        cout << trabajador.nombre() << " " << trabajador.apellido() << " | " 
             << salarioMensual << " | " << totalHorasExtras << " | " << totalAPagar << endl;
    }

    // Encontrar y reportar el empleado con mayor número de horas extras
    auto maxHorasExtras = max_element(_trabajadores.begin(), _trabajadores.end(), 
        [](const Empleado& a, const Empleado& b) {
            return a.totalHorasExtras() < b.totalHorasExtras();
        });
    if (maxHorasExtras != _trabajadores.end()) {
        cout << "Empleado con mayor número de horas extras: " 
             << maxHorasExtras->nombre() << " " << maxHorasExtras->apellido() << endl;
    }

    // Encontrar y reportar el empleado con menor número de horas extras
    auto minHorasExtras = min_element(_trabajadores.begin(), _trabajadores.end(), 
        [](const Empleado& a, const Empleado& b) {
            return a.totalHorasExtras() < b.totalHorasExtras();
        });
    if (minHorasExtras != _trabajadores.end()) {
        cout << "Empleado con menor número de horas extras: " 
             << minHorasExtras->nombre() << " " << minHorasExtras->apellido() << endl;
    }

    // Encontrar y reportar el día con mayor número de horas extras
    vector<float> horasPorDia(7, 0); // Asumiendo que hay 7 días en la semana
    for (const auto& trabajador : _trabajadores) {
        for (const auto& horas : trabajador.horasExtras()) {
            horasPorDia[horas.first] += horas.second;
        }
    }
    auto maxDia = max_element(horasPorDia.begin(), horasPorDia.end());
    if (maxDia != horasPorDia.end()) {
        cout << "Día con mayor número de horas extras: " << distance(horasPorDia.begin(), maxDia) << endl;
    }

    return 0;
}
