// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenier´ıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Cadenas y lenguajes
// Autor: Javier Acosta Portocarrero
// Correo: alu0101660769@ull.edu.es
// Fecha: 21/09/2024
// Archivo funciones.h: fichero de declaracion.
// Contiene la declaracion de todas las funciones externas
// a las demas clases usadas por el programa, en el fichero de definicion
// se encuentran mas detalles sobre estas.
// Referencias: Hace uso de la lenguaje y la clase cadena.
// Enlaces de interes
//
// Historial de revisiones
// 21/09/2024 - Creacion (primera version) del codigo

#ifndef FUNCIONES
#define FUNCIONES

#include "lenguaje.h"

void MostrarErrorDeEntrada();
void MostrarMensajeDeAyuda();

Lenguaje GenerarSufijos(const Cadena& cadena_original);
Lenguaje GenerarPrefijos(const Cadena& cadena_original);

#endif