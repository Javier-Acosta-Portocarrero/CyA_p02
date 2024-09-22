// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo lenguaje.cc: fichero de definicion.
// Contiene la definicion de la clase lenguaje, emulando esta a un conjunto 
// de cadenas.
// Referencias: Hace uso de la clase cadena que a su vez hace uso de la clase simbolo. 
// Además hace uso de la estructura de datos set para almacenar las cadenas, pues encaja .
// muy con la definicion de conjunto que no permite elementos repetidos.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include "lenguaje.h"


/*
 * Metodo que inserta una cadena nueva en el lenguaje. 
 *
 * @param cadena_a_agregar (cadena a ser agregada al lenguaje).
 */

void Lenguaje::InsertarCadena(const Cadena& cadena_a_agregar) {
   lenguaje_.insert(cadena_a_agregar);
}


/*
 * Sobrecarga del operador de salida "<<"" para la clase Lenguaje que imprime el 
 * conjunto de cadenas pertenecientes al lenguaje, siendo estas imprimidas 
 * separadas por comas y entre llaves para respetar la representacion de un conjunto.
 *
 * @param out (flujo de salida).
 *        lenguaje (lenguaje a imprimir).
 * @return out (el flujo de salida modificado).
 */

std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje) {
  out << '{'; 
  int contador_aux{0};
  for (Cadena cadena_auxiliar : lenguaje.get_lenguaje()) {
    if (contador_aux > 0) {
      out << ", ";   
    }
    out << cadena_auxiliar;
    contador_aux++;
  }
  out << '}';
  return out;
}
