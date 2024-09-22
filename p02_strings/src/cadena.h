// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo cadena.h: fichero de declaracion.
// Contiene la declaracion de la clase cadena, la cual emula
// una secuencia de simbolos y esta basada en un vector de estos.
// Referencias: Hace uso de la clase simbolo y la clase vector.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream> 

#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include "simbolo.h"

const std::string CADENA_VACIA = "&";  // Usado en el operador de salida si longitud = 0

class Cadena {
 public:
  Cadena(std::string cadena_cruda = "");

  std::vector<Simbolo> get_cadena() const { return cadena_;}
  int LongitudCadena() const;

  Simbolo DevolverPosicion(int posicion) const;

  void ConcatenarSimbolo(const Simbolo& simbolo_a_concatenar);

  Cadena GenerarInversa() const;

  friend std::ostream& operator<<(std::ostream& out, const Cadena& cadena);
  friend std::istream& operator>>(std::istream& in, Cadena& cadena);
  bool operator<(const Cadena& cadena_a_comparar) const;  // Usado por la clase set en lenguaje y alfabeto para que pueda mantener la lista ordenada

 private:
  std::vector<Simbolo> cadena_;
};

#endif