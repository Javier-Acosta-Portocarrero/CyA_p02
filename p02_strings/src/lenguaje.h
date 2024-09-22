// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo lenguaje.h: fichero de declaracion.
// Contiene la declaracion de la clase lenguaje, emulando esta a un conjunto 
// de cadenas.
// Referencias: Hace uso de la clase cadena que a su vez hace uso de la clase simbolo. 
// Además hace uso de la estructura de datos set para almacenar las cadenas, pues encaja .
// muy con la definicion de conjunto que no permite elementos repetidos.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream> 

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <set>
#include "cadena.h"

class Lenguaje {
 public:
  Lenguaje() {}

  std::set<Cadena> get_lenguaje() const { return lenguaje_;}

  void InsertarCadena(const Cadena& cadena_a_agregar);

  friend std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);

 private:
  std::set<Cadena> lenguaje_;
};

#endif