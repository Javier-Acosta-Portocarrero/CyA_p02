// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases alfabeto, 
// lenguaje, cadena, simbolo e intermediario_ficheros, para asi conseguir
// simular todos los objetivos propuestos en la practica
// Referencias: Hace uso de la clase IntermediarioFicheros.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include <iostream>
#include "intermediario_ficheros.h"
#include "funciones.h"

int main(int argc, char *argv[]) {
  // Lenguaje lenguaje_prueba;
  // std::cin >> lenguaje_prueba;
  // std::cout << lenguaje_prueba << std::endl;;
  if (argc != 4 && argc != 2) {
    MostrarErrorDeEntrada();
    return 1;
  } else if (argc == 2) {
    if (std::string(argv[1]) == "--help") {
      MostrarMensajeDeAyuda();
      return 0;
    } else {
      MostrarErrorDeEntrada();
      return 1;
    }
  }
  IntermediarioFicheros intermediario_programa(argv[1], argv[2], atoi(argv[3]));
  if (!intermediario_programa.AbiertoCorrectamente()) {
    std::cerr << "Alguno de los ficheros no se ha podido abrir correctamente." 
              << std::endl << "Finalizando programa" << std::endl;
    return 1;
  }
  intermediario_programa.RealizarOperacion();
  return 0;
}