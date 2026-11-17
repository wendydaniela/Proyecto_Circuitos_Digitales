# Sistema de Detección de Obstáculos para Personas con Discapacidad Visual basado en Arduino

Sistema embebido portátil de bajo costo diseñado para asistir a personas con discapacidad visual en la detección de obstáculos cercanos mediante retroalimentación auditiva progresiva[cite: 1].

## Descripción del Proyecto
Este proyecto implementa una solución tecnológica asistiva basada en hardware libre[cite: 1, 2]. Utiliza un sensor ultrasónico HC-SR04 para medir la distancia a los objetos del entorno y procesa la información mediante una placa Arduino Uno, traduciéndola en alertas sonoras intermitentes o continuas a través de un buzzer piezoeléctrico[cite: 1, 2, 3].

## Problemática Abordada
Las personas con discapacidad visual enfrentan barreras en su movilidad cotidiana, especialmente ante obstáculos situados a media altura (como mesas, puertas abiertas u objetos suspendidos) que el bastón blanco tradicional no siempre detecta a tiempo, incrementando el riesgo de colisiones[cite: 1]. Este sistema ofrece una alternativa accesible, económica y de respuesta en tiempo real que aporta mayor autonomía y seguridad al usuario[cite: 1, 2].

## Lista de Componentes
* **Placa Arduino Uno** (Microcontrolador ATmega328P)[cite: 2, 3]
* **Sensor ultrasónico HC-SR04** (Medición de distancia por eco a 40 kHz)[cite: 2, 3]
* **Buzzer piezoeléctrico** (Actuador de alertas auditivas)[cite: 2, 3]
* **Protoboard** (Base para el montaje del circuito)[cite: 3]
* **Cables tipo jumper** (Conexiones entre componentes y placa)[cite: 3]
* **Cable USB tipo A-B** (Alimentación y carga de programa)[cite: 2, 3]

## Diagrama de Conexiones

| Componente | Pin del Componente | Pin en Arduino Uno |
| :--- | :--- | :--- |
| Sensor HC-SR04 | VCC | 5V |
| Sensor HC-SR04 | TRIG | Pin Digital 12[cite: 3] |
| Sensor HC-SR04 | ECHO | Pin Digital 13[cite: 3] |
| Sensor HC-SR04 | GND | GND |
| Buzzer | Positivo (+) | Pin Digital 8[cite: 3] |
| Buzzer | Negativo (-) | GND |

## Instrucciones de Uso

1. Clonar o descargar este repositorio en el equipo local.
2. Abrir el archivo `.ino` en el entorno de desarrollo **Arduino IDE**.
3. Conectar la placa **Arduino Uno** al computador mediante el cable USB[cite: 2, 3].
4. Seleccionar la placa correspondiente en **Herramientas > Placa > Arduino Uno** y asignar el puerto COM activo.
5. Compilar y cargar el código en la placa mediante el botón **Subir**.
6. Abrir el **Monitor Serie** a `9600 baudios` para supervisar las mediciones de distancia en tiempo real[cite: 3].

### Comportamiento del Sistema por Rangos
* **Mayor a 50 cm:** El sistema permanece en silencio (estado de reposo)[cite: 4, 5].
* **Entre 15 cm y 50 cm:** Alerta auditiva intermitente lenta cuya frecuencia aumenta a medida que disminuye la distancia[cite: 4, 5].
* **Entre 3 cm y 15 cm:** Alerta auditiva intermitente rápida[cite: 5].
* **Menor o igual a 3 cm:** Alerta sonora continua a 3500 Hz indicando proximidad crítica[cite: 4, 5].

## Video Demostrativo
El funcionamiento en tiempo real del prototipo físico se encuentra documentado en el siguiente enlace:
https://youtu.be/pRIVPsAHXRo?feature=shared

## Integrantes
* Lindarys Fragozo
* Wendy Suárez
* Daniel Pérez
* Laura Sofia Barrera

* Universidad de San Buenaventura - Bogotá | Ingeniería Multimedia[cite: 1]
