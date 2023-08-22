#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include <iostream>
#include <optional>

template <class T> class Lista {
private:
  Nodo<T> *inicio;

public:
  Lista();
  ~Lista();
  Lista(const Lista<T> &li);

  bool esVacia();
  int getTamanio();

  void insertar(int posicion, T dato);
  void insertarPrimero(T dato);
  void insertarUltimo(T dato);

  void eliminar(int posicion);
  void reemplazar(int posicion, T dato);
  void vaciar();

  void fnInvierte();
  void insertAfter2(T oldValue, T newValue);

  T getDato(int posicion);

  void imprimir();
};

template <class T> Lista<T>::Lista() { inicio = nullptr; }

template <class T> Lista<T>::~Lista() {
  vaciar();
  delete inicio;
}

template <class T> Lista<T>::Lista(const Lista<T> &li) { inicio = li.inicio; }

/* ~~ */

template <class T> bool Lista<T>::esVacia() { return inicio == nullptr; }

template <class T> int Lista<T>::getTamanio() {
  Nodo<T> *aux = inicio;
  int tam = 0;

  while (aux != nullptr) {
    tam++;
    aux = aux->getSiguiente();
  }

  return tam;
}

/* ~~ */

template <class T> void Lista<T>::insertar(int posicion, T dato) {

  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);

  if (posicion == 0) {
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }

  Nodo<T> *aux = inicio;
  int posicionActual = 0;

  while ((aux != nullptr) && (posicionActual != posicion - 1)) {
    aux = aux->getSiguiente();
    posicionActual++;
  }

  if (aux == nullptr) {
    throw 400;
  }

  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

template <class T> void Lista<T>::insertarPrimero(T dato) {

  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  nuevo->setSiguiente(inicio);
  inicio = nuevo;
}

template <class T> void Lista<T>::insertarUltimo(T dato) {

  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->setDato(dato);
  Nodo<T> *aux = inicio;

  if (aux == nullptr) {
    nuevo->setSiguiente(nullptr);
    inicio = nuevo;
    return;
  }

  while (aux->getSiguiente() != nullptr) {
    aux = aux->getSiguiente();
  }

  nuevo->setSiguiente(nullptr);
  aux->setSiguiente(nuevo);
}

/* ~~ */

template <class T> void Lista<T>::eliminar(int posicion) {
  Nodo<T> *aux = inicio, *aBorrar;
  int posicionActual = 0;

  if (posicion == 0) {
    inicio = inicio->getSiguiente();
    delete aux;
    return;
  }

  while ((aux != nullptr) && (posicionActual != posicion - 1)) {
    aux = aux->getSiguiente();
    posicionActual++;
  }

  if (aux == nullptr) {
    throw 400;
  }

  aBorrar = aux->getSiguiente();

  aux->setSiguiente(aBorrar->getSiguiente());
  delete aBorrar;
}

template <class T> void Lista<T>::reemplazar(int posicion, T dato) {

  Nodo<T> *aux = inicio;
  int posicionActual = 0;

  while ((aux != nullptr) && (posicionActual != posicion)) {
    aux = aux->getSiguiente();
    posicionActual++;
  }

  if (aux == nullptr) {
    throw 400;
  }

  aux->setDato(dato);
}

template <class T> void Lista<T>::vaciar() {
  Nodo<T> *aux = inicio, *aBorrar;

  while (aux != nullptr) {
    aBorrar = aux;
    aux = aux->getSiguiente();
    delete aBorrar;
  }

  inicio = nullptr;
}

template <class T> T Lista<T>::getDato(int posicion) {

  Nodo<T> *aux = inicio;
  int posicionActual = 0;

  while ((aux != nullptr) && (posicionActual != posicion)) {
    aux = aux->getSiguiente();
    posicionActual++;
  }

  if (aux == nullptr) {
    throw 400;
  }

  return aux->getDato();
}

template <class T> void Lista<T>::fnInvierte() {

  Nodo<T> *anterior = nullptr, *aux = inicio, *siguiente = inicio;
  /*aux es anterior, aux1 es auxSiguiente y aux2 es auxiliar*/

  if (inicio == nullptr) {
    return;
  }

  siguiente = siguiente->getSiguiente();

  while (siguiente) {
    aux->setSiguiente(anterior);
    anterior = aux;
    aux = siguiente;
    siguiente = siguiente->getSiguiente();
  }
  aux->setSiguiente(anterior);
  inicio = aux;
}

template <class T> void Lista<T>::insertAfter2(T oldValue, T newValue) {
  Nodo<T> *aux = inicio;
  int contOldValue = 0;

  while (aux != nullptr) {
    if (aux->getDato() == oldValue) {
      ++contOldValue;
    }
    if (contOldValue == 2) {
      break;
    }
    aux = aux->getSiguiente();
  }

  if (aux == nullptr) {
    throw 404;
  }

  Nodo<T> nuevo = new Nodo<T>;
  nuevo->setDato(newValue);
  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

template <class T> void Lista<T>::imprimir() {
  Nodo<T> *aux = inicio;
  while (aux != nullptr) {
    std::cout << aux->getDato() << "->";
    aux = aux->getSiguiente();
  }
  std::cout << "NULL" << std::endl;
}

#endif // Lista_H
