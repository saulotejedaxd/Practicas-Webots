# Prácticas Webots

Repositorio con cuatro prácticas independientes de Webots. Cada práctica tiene su propio mundo y se incluyen los controladores fuente utilizados.

## Prácticas

1. **E-puck — usar un robot y girar una llanta — Tutorial 1 Webots**  
   Mundo: `worlds/01_epuck_rueda.wbt`  
   Controlador: `controllers/epuck_rueda/epuck_rueda.cpp`

2. **Diseñar carrito — Tutorial 6 Webots**  
   Mundo: `worlds/02_carrito.wbt`  
   Práctica enfocada al modelado del vehículo de cuatro ruedas.

3. **Helicóptero**  
   Mundo: `worlds/03_helicoptero.wbt`  
   Controlador: `controllers/helice_constante/helice_constante.cpp`

4. **Péndulo — PID Manual**  
   Mundo: `worlds/04_pendulo_pid.wbt`  
   Controlador: `controllers/pendulo_pid_manual/pendulo_pid_manual.cpp`

## Nota del péndulo

El mundo del péndulo utiliza `WorldInfo.basicTimeStep = 4 ms`. La barra tiene `boundingObject` y `Physics`, por lo que responde a gravedad. El controlador implementa el cálculo PID explícitamente a partir de la lectura del encoder y limita tanto la integral como la velocidad solicitada al motor.

## Estructura

```text
controllers/
  epuck_rueda/
  helice_constante/
  pendulo_pid_manual/
worlds/
  01_epuck_rueda.wbt
  02_carrito.wbt
  03_helicoptero.wbt
  04_pendulo_pid.wbt
```

No se incluyen ejecutables, carpetas `build`, capturas ni el historial `.git` del proyecto de origen; Webots los puede volver a generar localmente.
