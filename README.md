# README #
Este repositorio muestra la implementacion de la metodologia de Test Driven Development en un ejemplo simple: El desarrollo de un contolador de 16 leds mapeados en memoria. El ejemplo es una adaptacion a ceedling de ejemplo desarrollado en el libro *Pragmatic Test Driven Development for Embedded C* de James W. Genning

### Requisitos ###

* Maneja 16 LEDs de dos estados (encendido y apagado).
* Se puede cambiar el estado de un LED sin afectar a los otros.
* Se puede cambiar el estado de todos los LEDs en una sola operaciÃ³n.
* Se puede recuperar el estado actual de un LED.
* Al iniciar el procesador no hay estado conocido de los LEDs, estos deben ser apagados por software.
* Los LEDs estan mapeados en una palabra de 16 bits, en memoria, en una direcciÃ³n a determinar.
* Para encender el led se debe escribir un â€œ1â€ en el bit y para apagarlo se debe * escribir un â€œ0â€.
* El led 1 corresponde al bit menos significativo y el led 16 al bit mas significativo.
