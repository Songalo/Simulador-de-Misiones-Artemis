#ifndef SIMULADOR_H
#define SIMULADOR_H

// 1. CONSTANTES FÍSICAS 
#define ACEL_GRAV 9.80       // m/s^2 (Gravedad terrestre)
#define ACEL_FASE1 20.0         // m/s^2 (Aceleración con SRB)
#define TIEMPO_SRB 120.0        // s (Tiempo de desacople de los SRB)
#define ACEL_FASE2 12.5         // m/s^2 (Aceleración del núcleo principal)
#define ALTURA_OBJETIVO 160000.0 // m (160 km de altitud donde se apagan motores)

// CONFIGURACION DE MISION PERSONALIZADA
typedef struct {
    double acel_fase1;
    double acel_fase2;
    double altura_objetivo;
} ConfiguracionMision;

// 2. DEFINICIÓN DE ESTRUCTURA PARA ORGANIZAR DATOS DE LA NAVE
typedef struct {
    double tiempo_actual;   // Segundos transcurridos
    double altitud;         // Metros recorridos (y)
    double velocidad;       // m/s
    double aceleracion;     // m/s^2 actual
} NaveArtemis;

// 3. PROTOTIPOS DE FUNCIONES

// FUNCIONES DE LA PARTE FÍSICA
void calcular_fase1(NaveArtemis *nave, const ConfiguracionMision *config);
void calcular_fase2(NaveArtemis *nave, const ConfiguracionMision *config);
void simular_caida_libre(NaveArtemis *nave, const ConfiguracionMision *config);

// FUNCIONES DE INTERFAZ Y REPORTES
void mostrar_reporte_final(NaveArtemis nave, const ConfiguracionMision *config);

#endif