// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo alfabeto.cc: fichero de definicion.
// Contiene la definicion de la clase alfabeto, usada
// como un conjunto de simbolos.
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include "alfabeto.h"

/*
 * Constructor de la clase Alfabeto que crea un alfabeto a partir de una cadena
 * dada. Para cada símbolo en la cadena, este constructor lo añade al alfabeto,
 * almacenando los símbolos en un conjunto.
 *
 * @param cadena_auxiliar (objeto de la clase Cadena a partir del cual se
 *        generará el alfabeto).
 */
 
Alfabeto::Alfabeto(const Cadena& cadena_auxiliar) {
  for (int i{0}; i < cadena_auxiliar.LongitudCadena(); ++i) {
    InsertarSimbolo(Simbolo(cadena_auxiliar.DevolverPosicion(i)));
  }  
}

/*
 * Esta función permite insertar un símbolo nuevo en el alfabeto. 
 *
 * @param simobolo_a_agregar (el símbolo que se va a añadir al alfabeto).
 */

void Alfabeto::InsertarSimbolo(const Simbolo& simobolo_a_agregar) {
  alfabeto_.insert(simobolo_a_agregar);
} 

std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  int contador_aux{0};
  out << '{';
  for (Simbolo simbolo_aux : alfabeto.get_alfabeto()) {
    if (contador_aux > 0) {
      out << ", ";
    }
    out << simbolo_aux;
    contador_aux++;
  }
  out << '}';
  return out;
}

/*
 * Sobrecarga del operador de salida <<, que  permite la salida en
 * formato de texto de un alfabeto. El formato es el de un conjunto, con los
 * símbolos separados por comas y encerrados entre llaves.
 *
 * @param out (flujo de salida en el que se imprimirá el alfabeto).
 * @param alfabeto (el objeto de la clase Alfabeto que se imprimirá).
 * @return out (flujo de salida modificado con el contenido del alfabeto).
 */

std::istream& operator>>(std::istream& in, Alfabeto& alfabeto) {
  std::string input_auxiliar;
  in >> input_auxiliar; 
  alfabeto.alfabeto_.clear();  
  for (char caracter_auxiliar : input_auxiliar) {
    alfabeto.alfabeto_.insert(Simbolo(caracter_auxiliar));
  }
  return in;
}
