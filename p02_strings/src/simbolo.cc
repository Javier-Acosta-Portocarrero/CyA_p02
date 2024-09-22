// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo simbolo.cc: fichero de definicion.
// Contiene la definicion de la clase simbolo, siendo esta la clase 
// mas basica que constituye la base de todas las demas creadas para
// este programa.
// Referencias: hace uso del tipo elemental char.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include "simbolo.h"
#include <iostream>


/*
 * Sobrecarga del operador de salida "<<" de la clase Simbolo, este imprime 
 * el caracter ASCII que representa el simbolo.
 *
 * @param out (flujo de salida).
          simbolo (simbolo a imprimir).
 * @return out (flujo de salida con el símbolo impreso).
 */

std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo) {
  out << simbolo.simbolo_;
  return out;
}

/*
 * Sobrecarga del operador de entrada ">>" de la  clase Simbolo, el cual posibilita 
 * dar valor a un obejto Simbolo a traves de un flujo de entrada
 *
 * @param in (flujo de entrada) 
          simbolo (referencia al objeto Simbolo a modificar).
 * @return in (el flujo de entrada ya modificado.)
 */

std::istream& operator>>(std::istream& in, Simbolo& simbolo) {
  in >> simbolo.simbolo_;
  return in;
}

/*
 * Sobrecarga del operador de desigualdad menor "<"" de la clase Simbolo, este posibilita comparar dos objetos de tipo
 * Simbolo, siendo el factor diferenciador el valor ASCII del caracter que los compone.
 *
 * @param simbolo_a_comparar (referencia al simbolo con el que se comparará el objeto original).
 * @return true si el símbolo actual es menor que el símbolo a comparar y false si no.
 */

bool Simbolo::operator<(const Simbolo& simbolo_a_comparar) const {
  return (static_cast<int>(get_simbolo()) < static_cast<int>(simbolo_a_comparar.get_simbolo()));
}

/*
 * Sobrecarga del operador de comparacion de la clase Simbolo, este posibilita diferenciar
 * si dos simbolos son iguales o no.
 *
 * @param simbolo_a_comparar (referencia al simbolo con el que se comparará el objeto original).
 * @return true si ambos simbolos son iguales y false si no.
 */

bool Simbolo::operator==(const Simbolo& simbolo_a_comparar) const {
  return (static_cast<int>(simbolo_) == static_cast<int>(simbolo_a_comparar.get_simbolo()));
}

/*
 * Sobrecarga del operador de comparacion de la clase Simbolo, este posibilita diferenciar
 * si dos simbolos son iguales o no.
 *
 * @param simbolo_a_comparar (referencia al simbolo con el que se comparará el objeto original).
 * @return true si ambos simbolos no son iguales y false si si.
 */

bool Simbolo::operator!=(const Simbolo& simbolo_a_comparar) const {
  return (static_cast<int>(simbolo_) != static_cast<int>(simbolo_a_comparar.get_simbolo()));
}