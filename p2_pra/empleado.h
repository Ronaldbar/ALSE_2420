#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

typedef std::pair<int, float> HorasExtras; // (día, horas)

class Empleado {
    std::string _nombre;
    std::string _apellido;
    std::string _cedula;
    float _salario;
    std::list<HorasExtras> _horasExDia;

public:
    Empleado(const std::string& nombre, const std::string& apellido, 
        const unsigned int& cedula, float salario);

    Empleado();

    std::string nombre() const;
    void setNombre(const string &nombre);

    string apellido() const;
    void setApellido(const std::string &apellido);

    std::string cedula() const;
    void setCedula(const std::string &cedula);

    float salario() const;
    void setSalario(float salario);

    void agregarHorasExtras(int dia, float horas) ;

    float totalHorasExtras() const;

    bool ordenar();

    float calcularHE(float salario, float totalHorasExtras);

    static bool compararHE(const Empleado& a, const Empleado& b);

};

#endif
