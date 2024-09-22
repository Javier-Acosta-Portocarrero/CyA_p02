// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo cadena.cc: fichero de definicion.
// Contiene la definicion de la clase cadena, la cual emula
// una secuencia de simbolos y esta basada en un vector de estos.
// Referencias: Hace uso de la clase simbolo y la clase vector.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include "simbolo.h"
#include "cadena.h"

/*
 * Constructor de la clase Cadena que forma una secuencia de símbolos a 
 * partir de una cadena de caracteres. Por cada carácter de la cadena de 
 * entrada se crea un objeto Simbolo y se añade a un vector.
 *
 * @param cadena_cruda (cadena de caracteres a partir de la cual se crea
 *        la secuencia de símbolos).
 */

Cadena::Cadena(std::string cadena_cruda) {
  for (int i{0}; i < static_cast<int>(cadena_cruda.length()); ++i) {
    cadena_.emplace_back(Simbolo(cadena_cruda[i]));
  }
}

/*
 * Sobrecarga del operador salida "<<"", el cual permite la impresión de un
 * objeto Cadena en un flujo de salida. Si la cadena está vacía, imprime '&' el simbolo
 * específico que representa a la cadena vacia, constante definida por "CADENA_VACIA", 
 * de lo contrario imprime los símbolos que contiene.
 *
 * @param out (flujo de salida en el cual se imprimirá la cadena).
 * @param cadena (el objeto Cadena que se imprimirá).
 * @return out (flujo de salida modificado con el contenido de la cadena).
 */

std::ostream& operator<<(std::ostream& out, const Cadena& cadena) {
  if (cadena.LongitudCadena() == 0) {
    out << CADENA_VACIA;
  } else {
    for (Simbolo simbolo_aux : cadena.cadena_) {
      out << simbolo_aux;
    }
  }
  return out;
}

/*
 * Sobrecarga del operador de entrada ">>""", permitiendo este leer una Cadena desde 
 * un flujo de entrada. Los caracteres leídos son convertidos en símbolos y 
 * almacenados en el vector que compone la clase Cadena.
 *
 * @param in (flujo de entrada desde el cual se leerá la cadena).
 * @param cadena (el objeto Cadena que será modificado con los símbolos 
 *        leídos del flujo de entrada).
 * @return in (flujo de entrada modificado).
 */

std::istream& operator>>(std::istream& in, Cadena& cadena) {
  std::string input_auxiliar;
  in >> input_auxiliar; 
  cadena.cadena_.clear();  // Sirve para limpiar la cadena actual
  for (char caracter_auxiliar : input_auxiliar) {
    cadena.cadena_.emplace_back(Simbolo(caracter_auxiliar));
  }
  return in;
}

/*
 * Sobrecarga del operador menor "<"", cuyo finalidad es la de comparar dos objetos de la 
 * clase Cadena. La comparación se realiza en base a la longitud de estas.
 *
 * @param cadena_a_comparar (la cadena con la que se realizará la comparación).
 * @return true si la cadena actual es menor que la cadena_a_comparar y
 *         false en el caso contrario.
 */

bool Cadena::operator<(const Cadena& cadena_a_comparar) const {
  if (LongitudCadena() != cadena_a_comparar.LongitudCadena()) {
    return LongitudCadena() < cadena_a_comparar.LongitudCadena();
  } else  {
    for (int i{0}; i < LongitudCadena(); i++) {
      if (DevolverPosicion(i) != cadena_a_comparar.DevolverPosicion(i)) {
        return DevolverPosicion(i) < cadena_a_comparar.DevolverPosicion(i);
      }
    }
  }
  return false;
}

/*
 * Metodo que devuelve el símbolo que está en una posición específica 
 * de la cadena. 
 *
 * @param posicion (la posición del símbolo que se quiere devolver).
 * @return el símbolo que está en la posición especificada.
 */

Simbolo Cadena::DevolverPosicion(int posicion) const {
  return cadena_[posicion];
}

/*
 * Metodo que permite concatenar un símbolo al final de la cadena.
 *
 * @param simbolo_a_concatenar (el símbolo que se concatenara a la cadena).
 */

void Cadena::ConcatenarSimbolo(const Simbolo& simbolo_a_concatenar) {
  cadena_.emplace_back(simbolo_a_concatenar);
}

/*
 * Metodo que devuelve la longitud de la cadena (es decir, la cantidad de 
 * símbolos que contiene).
 *
 * @return la cantidad de símbolos presentes en la cadena.
 */

int Cadena::LongitudCadena() const {
  return cadena_.size();
}

/*
 * Meotodo que genera y devuelve  inversa de la cadena desde la que se llama. 
 * La inversa se obtiene invirtiendo el orden de los símbolos 
 * de la cadena original.
 *
 * @return un objeto Cadena que representa la cadena original invertida.
 */

Cadena Cadena::GenerarInversa() const {
  Cadena cadena_inversa;
  int longitud_cadena_original{LongitudCadena()};
  for (int i{longitud_cadena_original - 1}; i >= 0; i--) {
    cadena_inversa.ConcatenarSimbolo(DevolverPosicion(i));
  }
  return cadena_inversa;
}
