// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo simbolo.h: fichero de declaracion.
// Contiene la declaracion de la clase simbolo, siendo esta la clase 
// mas basica que constituye la base de todas las demas creadas para
// este programa.
// Referencias: hace uso del tipo elemental char.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo {
 public:
  Simbolo(const char contenido_simbolo = ' ') : simbolo_{contenido_simbolo} {}
  char get_simbolo() const { return simbolo_;}

  friend std::ostream& operator<<(std::ostream& out, const Simbolo& simbolo);
  friend std::istream& operator>>(std::istream& in, Simbolo& simbolo);

  bool operator<(const Simbolo& simbolo_a_comparar) const;
  bool operator==(const Simbolo& simbolo_a_comparar) const;
  bool operator!=(const Simbolo& simbolo_a_comparar) const;
 private:
  char simbolo_;
};

#endif