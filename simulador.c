
#include <stdio.h>
#include "simulador.h"

void calcular_fase1(NaveArtemis *nave)
{
    if (nave == NULL) {
        return;
    }

    nave->tiempo_actual = 0.0;
    nave->altitud = 0.0;
    nave->velocidad = 0.0;
    nave->aceleracion = ACEL_FASE1;

    nave->altitud = nave->altitud
                  + nave->velocidad * TIEMPO_SRB
                  + (nave->aceleracion * TIEMPO_SRB * TIEMPO_SRB) / 2.0;

    nave->velocidad = nave->velocidad
                    + nave->aceleracion * TIEMPO_SRB;

    nave->tiempo_actual = TIEMPO_SRB;
}
