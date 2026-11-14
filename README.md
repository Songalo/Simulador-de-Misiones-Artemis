# 🚀 Simulador de Misiones Artemis - Situación 1: Ascenso y Propulsión con el SLS

## Video de explicación en Youtube : https://www.youtube.com/watch?v=0j4-OfGHe0U

--------------------------------------------------------------------------

## 1. Integrantes - Legajo y Comisión / Grupo
* Colman, Fiorella Soledad - 30699
* Tabernero, Francisco Ariel - 30155
* López, Aldana Ailín - 29189
* Gomez, Bruno Leopoldo Agustín - 25743
* Gallardo Coronel Gonzalo - 30432
* **Comisión C / Grupo N°: 22**

---

## 2. Descripción del Proyecto y Escenario Asignado

El proyecto consiste en el desarrollo de un simulador interactivo por consola basado en la **Situación Problemática 1: Ascenso y Propulsión con el SLS (MRUV y Desprendimiento)** de la misión Artemis.

El escenario representa el ascenso de la nave Orion impulsada por el cohete Space Launch System (SLS), partiendo del reposo desde la plataforma de lanzamiento, con velocidad y altura iniciales iguales a cero.

La simulación se divide en dos fases:

- **Primera fase – Ascenso y desprendimiento de los SRB:** la nave asciende con una aceleración constante de 20 m/s² durante 120 segundos, impulsada por los motores principales y los dos cohetes de combustible sólido (SRB). Al finalizar este período, los propulsores sólidos se desprenden.
- **Segunda fase – Propulsión del motor principal:** luego del desprendimiento, el motor principal continúa acelerando la nave a 12,5 m/s² hasta alcanzar una altura de 160.000 metros, momento en el que los motores se apagan.

Para los cálculos se considera que la nave parte del reposo, que no existe resistencia del aire y que la aceleración de la gravedad terrestre es de 9,80 m/s².

Además, el escenario contempla una posible falla de motores al alcanzar la altura objetivo. En ese caso, se calcula la altura máxima que puede alcanzar la nave por inercia antes de comenzar a descender.

El simulador permite analizar las velocidades, alturas y aceleraciones alcanzadas durante las distintas etapas del ascenso, así como los resultados de una eventual falla de motores. También permite realizar configuraciones personalizadas modificando determinados parámetros de la misión.

## 3. Funcionamiento del Simulador

Al iniciar el programa, se presenta un menú que permite seleccionar entre realizar la misión oficial, utilizando los valores establecidos en la consigna, o configurar una misión personalizada.

En la misión personalizada, el usuario puede modificar las aceleraciones de ambas fases y la altura objetivo, mientras que el tiempo de la primera fase y la gravedad se mantienen constantes.

Una vez seleccionada la configuración, se accede al menú de simulación, que permite:

- Ejecutar la primera fase de ascenso durante 120 segundos y calcular la velocidad y altura alcanzadas al momento del desprendimiento de los SRB.
- Ejecutar la segunda fase de propulsión hasta alcanzar la altura objetivo establecida. El simulador calcula la velocidad final y el tiempo necesario para llegar a dicha altura, que puede variar según los parámetros seleccionados.
- Simular una falla de motores y calcular la altura máxima que alcanza la nave por inercia.
- Consultar un reporte final con los principales resultados obtenidos durante la simulación, incluyendo la aceleración máxima expresada como múltiplo de la gravedad terrestre.
- Finalizar la ejecución del programa.

El sistema también incorpora validaciones de los datos ingresados para evitar valores incorrectos y mantener las condiciones necesarias para realizar los cálculos.


## 4. Instrucciones de Compilación y Ejecución

El proyecto incluye un **Makefile** para automatizar el proceso de compilación mediante el compilador `gcc`

### Pasos para compilar y ejecutar:

1. Clonar el repositorio y posicionarse en la carpeta raíz:
   ```bash
   git clone https://github.com/Songalo/Simulador-de-Misiones-Artemis.git
   cd Simulador-de-Misiones-Artemis
2. Instalar el componente necesario desde PowerShell para que Makefile funcione:
   ```bash
   winget install ezwinports.make
3. Compilar el programa utilizando el Makefile. Para utilizarlo se debe ejecutar:
   ```PowerShell
   make
4. Ejecutar el simulador generado.
   ```bash
   simulador_artemis.exe
5. Si se desea limpiar los archivos compilados se puede utilizar el comando:
   ```bash
   make clean

## 5. Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizaron distintas herramientas de Inteligencia Artificial como apoyo para comprender conceptos, resolver dudas y facilitar distintas etapas del trabajo.

Entre sus principales usos se encuentran:

- Comprender la utilidad de los archivos de cabecera `.h` y cómo se utilizan dentro de la estructura del programa.
- Recibir asistencia en el diseño de las estructuras de datos necesarias para el simulador.
- Comprender el funcionamiento de las funciones y los fragmentos de código desarrollados por los integrantes, facilitando el intercambio de conocimientos dentro del grupo.
- Consultar sobre la aplicación de fórmulas físicas y cálculos de MRUV, velocidad, altura y caída libre.
- Recibir orientación para incorporar una opción de misión personalizada, manteniendo los valores originales de la misión oficial.
- Obtener explicaciones sobre las validaciones de datos y las posibles pruebas para comprobar el funcionamiento del programa.
- Recibir orientación sobre la función y configuración del Makefile, así como sobre el uso de GCC y los comandos necesarios para compilar y ejecutar el proyecto.

Aclaración importante: Las respuestas, sugerencias y explicaciones proporcionadas por las herramientas utilizadas fueron tomadas como material de consulta y apoyo. Los integrantes revisaron la información antes de aplicarla, contrastaron los conceptos y cálculos con el material de estudio y realizaron pruebas para comprobar el correcto funcionamiento del programa.
