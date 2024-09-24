// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo intermediario_ficheros.cc: fichero de definicion.
// Contiene la definicion de la clase que da nombre al fichero, siendo
// el objetivo de esta actuar como puente entre el fichero de entrada y 
// el fichero de salida, convirtiendo los datos del primero en los resultados
// requeridos por el opcode dado.
// Referencias: Hace uso de las demas clases creadas para este programa.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#include "intermediario_ficheros.h"
#include "funciones.h"

/*
 * @brief Constructor de la clase IntermediarioFicheros. Este abre los ficheros de entrada 
 * y salida y da valor al opcode. 
 *
 * @param fichero_entrada (nombre del fichero de entrada),
 *        fichero_salida (nombre del fichero de salida),
 *        opcode (indica la operación a realizar).
 */

IntermediarioFicheros::IntermediarioFicheros(std::string fichero_entrada, std::string fichero_salida, int opcode) : opcode_{opcode} {
  fichero_entrada_.open(fichero_entrada);
  fichero_salida_.open(fichero_salida);
}

/*
 * @breif Destructor de la clase IntermediarioFicheros, encargado de cerrar los ficheros de entrada 
 * y salida.
 *
 */

IntermediarioFicheros::~IntermediarioFicheros() {
  fichero_entrada_.close();
  fichero_salida_.close();
}

/**
  * @brief Metodo encargado de comprobar que los fichero han sido abiertos correctamente
  *
  */

bool IntermediarioFicheros::AbiertoCorrectamente() const {
  if (!fichero_entrada_.is_open() || !fichero_salida_.is_open()) {
    return false;
  }
  return true;
}

/*
 * @brief Esta metodod lee línea por línea el fichero de entrada y dependiendo del opcode 
 * realiza una "operación" específica sobre la cadena y/o alfabeto leídos en cada linea línea.
 * Operaciones disponibles dependiendo del valor del opcode:
 *    1.  Mostrar el alfabeto de cada linea.
 *    2.  Mostrar la longitud de cada cadena.
 *    3.  Mostrar la inversa de cada cadena.
 *    4.  Mostrar todos los prefijos posibles de cada cadena.
 *    5.  Mostrar todos los sufijos posibles de cada cadena.
 * En el caso de una linea tenga un formato no contemplado, escribe un mensaje de error en
 * el fichero de salida.
 */

void IntermediarioFicheros::RealizarOperacion() {
  std::string linea_fichero;
  while (std::getline(fichero_entrada_, linea_fichero)) {
    std::istringstream flujo_linea(linea_fichero);
    Cadena cadena_temp;
    Alfabeto alfabeto_temp;
    if (flujo_linea >> cadena_temp >> alfabeto_temp) {
      switch (opcode_) {
        case 1:
          fichero_salida_ << alfabeto_temp << std::endl;
          break; 
        case 2:
          fichero_salida_ << cadena_temp.LongitudCadena() << std::endl;
          break; 
        case 3:
          fichero_salida_ << cadena_temp.GenerarInversa() << std::endl;
          break; 
        case 4:
          fichero_salida_ << GenerarPrefijos(cadena_temp) << std::endl;
          break; 
        case 5:
          fichero_salida_ << GenerarSufijos(cadena_temp) << std::endl;
          break; 
        default:
          fichero_salida_ << "Una opcion no valida de operacion ha sido seleccionada, opcion = " << opcode_ << std::endl;
          break;  
      }
    } else {
      fichero_salida_ << "El contenido de esta linea era erroneo  en el fichero de entrada." << std::endl;
    }
  }
}