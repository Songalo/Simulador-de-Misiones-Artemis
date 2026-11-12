#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int leerEntero(const char *mensaje, int min, int max);
float leerFlotante(const char *mensaje, float min, float max);
void mostrarMensajeAmable(const char *mensaje);
void mostrarAlerta(const char *mensaje);
void pausarConsola(void);

#endif
