// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo intermediario_ficheros.h: fichero de declaracion.
// Contiene la declaracion de la clase que da nombre al fichero, siendo
// el objetivo de esta actuar como puente entre el fichero de entrada y 
// el fichero de salida, convirtiendo los datos del primero en los resultados
// requeridos por el opcode dado.
// Referencias: Hace uso de las demas clases creadas para este programa.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#ifndef INTERMEDIARIO_FICHEROS_H
#define INTERMEDIARIO_FICHEROS_H

#include <fstream>
#include <cstdlib>
#include <sstream>
#include "lenguaje.h"
#include "alfabeto.h"

class IntermediarioFicheros {
 public:
  IntermediarioFicheros(std::string fichero_entrada = "fichero_entrada.txt", std::string fichero_salida = "fichero_salida.txt", int opcode = 1); 

  ~IntermediarioFicheros();

  void RealizarOperacion(); 
 private:
  std::ifstream fichero_entrada_;
  std::ofstream fichero_salida_;
  int opcode_;
};

#endif