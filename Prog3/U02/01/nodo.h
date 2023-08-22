#ifndef NODO_H
#define NODO_H

template <class T> class Nodo {
private:
  T dato;
  Nodo<T> *siguiente; // no entiendo esta linea

public:
  Nodo();

  void setDato(T _dato);
  T getDato();

  void setSiguiente(Nodo<T> *_siguiente);
  Nodo<T> *getSiguiente();
};

template <class T> Nodo<T>::Nodo() {}

template <class T> Nodo<T> *Nodo<T>::getSiguiente() { return siguiente; }

template <class T> void Nodo<T>::setSiguiente(Nodo<T> *_siguiente) { siguiente = _siguiente; }

template <class T> T Nodo<T>::getDato() { return dato; }

template <class T> void Nodo<T>::setDato(T _dato) { dato = _dato; }

#endif // NODO_H
