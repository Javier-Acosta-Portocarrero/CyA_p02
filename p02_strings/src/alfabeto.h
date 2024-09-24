// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo alfabeto.h: fichero de declaracion.
// Contiene la declaracion de la clase alfabeto, usada
// como un conjunto de simbolos.
// Referencias: Hace uso de la clase simbolo y usa como estructura de datos 
// los set, pues consiguen imitar muy bien el comportamiento de los conjuntos, 
// pues ambos no permiten elementos repetidos.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <set>
#include "simbolo.h"
#include "cadena.h"

class Alfabeto {
 public:
  Alfabeto() {}

  Alfabeto(const Cadena& cadena_auxiliar);

  std::set<Simbolo> get_alfabeto() const { return alfabeto_;}

  void InsertarSimbolo(const Simbolo& simobolo_a_agregar);

  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);
  friend std::istream& operator>>(std::istream& in, Alfabeto& alfabeto);

 private:
  std::set<Simbolo> alfabeto_;
};

#endif