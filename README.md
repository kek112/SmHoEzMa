# Smarthome Easymaker (SmHoEzMa)
Created by:
- Tobias Rieß
- Karl-Erik Kley
- Martin Lesser

*Mobile Computing 1 Project*

uses external Software from https://steveyo.github.io/Hue-Emulator/ 
Just download this tool and start the 0.8.jar for starting the emulator.
Now there should be displayed some bulbs which are controlled by the Bridge.
The Bridge itself is amenable by an REST-API. The exact Documentation is readable from the link above. 

Also i had to develop an interface by myself because other manufactures dont distribute emulators. 
With the Hue emulator as example i created an own REST-API which delivers different values for temperature and humidity. 

1. Starten des Java Hue Emulators v0.8
2. Starten der Rest API mittels IIS Express über VS oder Daten direkt in IIS Verzeichnis kopieren und damit starten
3. App starten, Geräte ansteuen