# ThingSpeak-y-ESP8266
Proyecto de medición continua de temperatura y análisis de tres días haciendo uso del sensor DHT11, la placa de desarrollo ESP8266 y la plataforma online ThingSpeak.

El proyecto involucra el uso de una placa de desarrollo NodeMCU ESP8266, esta hace uso de las librerias presentadas en el repositorio y se programa en el IDE de arduino.
En el IDE es necesario agregar el programador de la ESP8266, este se agrega en la seccion de File/Preferences/Additional Board Manager URL y en esa seccion se agrega el link siguiente:
"http://arduino.esp8266.com/stable/package_esp8266com_index.json"

Es necesario crear una cuenta en:
https://thingspeak.com

Posterior a esto se crea una tabla con un solo campo, y se extraer las claves de lectura/escritura y ID del canal para escribirlas en el codigo .ino y en el script .m

Las mediciones se realizaron por 3 dias seguidos, una medicion cada 10 minutos, por lo que hubieron 144 medciones al dia. 

