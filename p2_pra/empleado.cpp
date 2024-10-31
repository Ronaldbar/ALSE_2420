#include "empleado.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Constructor
Empleado::Empleado()
    {
        _nombre = "";
        _apellido = "";
        _cedula = "";
        _salario = 0.0;
        _horasExDia.clear();
    }

float Empleado::salario() const
{
    return _salario;
}

void Empleado::setSalario(float salario)
{
    _salario = salario;
}

string Empleado::cedula() const
{
    return _cedula;
}

void Empleado::setCedula(const string &cedula)
{
    _cedula = cedula;
}

std::string Empleado::apellido() const
{
    return _apellido;
}

void Empleado::setApellido(const string &apellido)
{
    _apellido = apellido;
}

string Empleado::nombre() const
{
    return _nombre;
}

void Empleado::setNombre(const string &nombre)
{
    _nombre = nombre;
}

void Empleado::agregarHorasExtras(int dia, float horas) {
    HorasExtras a(dia, horas);
    _horasExDia.push_back(a);
    return;
}

bool Empleado::ordenar() {
    _horasExDia.sort();
    _horasExDia.reverse();
    return true;
}

float Empleado::totalHorasExtras() const {
    float total = 0;
    for (list<HorasExtras>::const_iterator it = _horasExDia.begin(); it != _horasExDia.end(); ++it) {
        total += it->second;
    }
    return total;
}

float Empleado::calcularHE(float salario, float totalHorasExtras) {
    float valorHE = 0;
    valorHE = (salario / 240) * totalHorasExtras;
    return valorHE;
}

bool Empleado::compararHE(const Empleado &a, const Empleado &b) {
    return a.totalHorasExtras() < b.totalHorasExtras();
}
