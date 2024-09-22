// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo funciones.cc: fichero de definicion.
// Contiene la definicion de todas las funciones externas
// a las demas clases usadas por el programa, abajo se encuentran
// mas detalles sobre estas.
// Referencias: Hace uso de la lenguaje y la clase cadena.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include "funciones.h"
#include <iostream>

/*
 * Esta función muestra un mensaje de error cuando el usuario no proporciona
 * la entrada correcta a través de la línea de comandos. Además, indica como obtener
 * ayuda sobre el uso del programa.
 *
 * @return No devuelve ningún valor.
 */

void MostrarErrorDeEntrada() {
  std::cout << "Modo de empleo: ./p02_strings ficheroentrada.txt ficherosalida.txt opcode  ." << std::endl 
            << "Pruebe  ./p02_strings --help para mas informacion" << std::endl;;
}

/*
 * Esta función muestra un mensaje de ayuda que describe que parametros se deben 
 * poner para la ejecución del programa y el significado de los distintos opcode.
 *
 * @return No devuelve ningún valor.
 */

void MostrarMensajeDeAyuda() {
  std::cout << "Por linea de comandos se debe incluir el nombre del ejecutable seguido por el nombre del"
            <<  " fichero de entrada y el fichero de salida, y, por ultimo, la operacion que se realizara"  
            <<  " (1 para mostrar los alfabetos, 2 para mostrar la longitud de las cadenas, 3 para mostrar" 
            <<  " la inversa de la cadenas, 4 para mostrar los prefijos y 5 para mostrar los sufijos)." << std::endl;
}

/*
 * Esta función genera todos los sufijos posibles de una cadena dada. Siendo estos
 * cualquier subcadena de la original cuyo ultimo simbolo sea el ultimo de la cadena original.
 * Los sufijos generados se almacenan en un lenguaje para facilitar su impresion.
 *
 * @param cadena_original (la cadena a partir de la cual se generaran los sufijos).
 * @return conjunto_sufijos (objeto de tipo Lenguaje que contiene todos los sufijos de la cadena original)
 */

Lenguaje GenerarSufijos(const Cadena& cadena_original) {
  Lenguaje conjunto_sufijos;
  conjunto_sufijos.InsertarCadena(Cadena());
  int longitud_cadena{cadena_original.LongitudCadena()};
  for (int i{longitud_cadena - 1}; i >= 0; i--) {
    Cadena cadena_auxiliar;
    for (int j{i}; j < longitud_cadena; j++) {
      cadena_auxiliar.ConcatenarSimbolo(cadena_original.DevolverPosicion(j));
    }
    conjunto_sufijos.InsertarCadena(cadena_auxiliar);
  }
  return conjunto_sufijos;
}

/*
 * Esta función genera todos los prefijos posibles de una cadena dada. Siendo estos
 * cualquier subcadena de la original cuyo primer simbolo sea el primero de la cadena original.
 * Los prefijos generados se almacenan en un lenguaje para facilitar su impresion.
 *
 * @param cadena_original (la cadena a partir de la cual se generaran los prefijos).
 * @return conjunto prefijos (objeto de tipo Lenguaje que contiene todos los prefijos de la cadena original)
 */

Lenguaje GenerarPrefijos(const Cadena& cadena_original) {
  Lenguaje conjunto_prefijos;
  conjunto_prefijos.InsertarCadena(Cadena());
  int longitud_cadena{cadena_original.LongitudCadena()};
  for (int i{0}; i < longitud_cadena; i++) {
    Cadena cadena_auxiliar;
    for (int j{0}; j <= i; j++) {
      cadena_auxiliar.ConcatenarSimbolo(cadena_original.DevolverPosicion(j));
    }
    conjunto_prefijos.InsertarCadena(cadena_auxiliar);
  }
  return conjunto_prefijos;
}