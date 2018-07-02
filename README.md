# Smarthome Easymaker (SmHoEzMa)
Created by:
- Tobias Rieß
- Karl-Erik Kley
- Martin Lesser

## *Mobile Computing 1 Projekt*
Dieses Projekt ist die Belegarbeit für das Fach Mobile Computing 1. 
Der Smarthome Easymaker oder kurz SmHoEzMa dient zur Ansteuerung und Bedienung verschiedener Smarthome Geräte welche sich im Netzwerk befinden. Als Hauptfunktionen werden das Anlegen verschiedener Geräte, eine Homecoming Funktion sowie die Ansteuerung der einzelnen Geräte ansich betrachtet. 
Das Projekt wurde in Qt/C++ umgesetzt mit teilweise dem Aufsatz QML, sowie Java für einen EMulator und ASP.Net für einen adneren. 

### Installation/Start Fremdsoftware
Um eine realistische Herangehensweise zu simulieren gab es die ursprüngliche Planung das tatsächlich Smarthome Geräte organisiert werden. Diese Idee wurde aber schnell verworfen da es deutlisch geschickter ist entsprechnde Emulatoren für besagte Geräte berietzustellen, welche die gleiche Funktionalität bereitstellen. Zum einen wurde ein ausgezeichneter Emulator für die Philips Hue Lampen gefunden und aus Mangel exististierender Alternativen wurde ein eigener für 2 Sensoren auf BAsis von ASP.Net entwicklet. 

#### Philips Hue Emulator

Es wird die externe Software von https://steveyo.github.io/Hue-Emulator/ genutzt. 
Dieses Repository wird einfach runtergeladen und der darin enthaltene Emulator wird gestartet. 
Die Version V0.8 wurde in unserer App verwendet und war zu dem Entwicklungszeitpnkt die aktuellste Version.
Nach dem Start der Software sollte dieses Bild angezeigt werden:

![Emulator Startup](/images/Emulator_UI.PNG)

In dieser Ansicht muss nur oben auf Start gedrückt werden um den Server zum laufen zu bekommen. 
In diesem Emulator können noch zusätzliche Lampen hinzugefügt werden. In unserem Beispiel haben wir eine Lux Lampe erstellt. 

![Emulator-Lampen](/images/EmulatorPNG.PNG)

Danach ist der Link(Links auf dem Bild) über die IP-Addresse des Rechners ansprechbar. 
Die genauen REST-Abragen lassen sich mit in dem Repository welches verlinkt wurde finden. 

#### Temperatur/Luftfeuchtigkeits Emulator 
Da es sonst wenig bis keine laufenden Alternativen für andere Smarthome Devices gab, wir aber noch mindestens eine andere Art der Ansteuerung haben wollten, musste eine Alternative entwickelt werden. 

Dieses wurde in Form einer schnellen Umsetzung auf der Basis von ASP.Net gemacht. Letzendlich bietet diese Lösung nur die Funktionalität um Temperatur und Luftfeuchtigkeitswerte zu erzeugen. 
In dieser Version werden die Werte noch zufällig zwischen 2 Grenzwerten wiedergegeben. Im Grunde wird dadurch eine weitere REST-SChnittstelle erzeugt welche wir abrufen können. 

ASP.Net läuft in unserer Version über den IIS Express welcher in VS integriert ist. Soll dieser ohne den IIS Express von Visual Studio laufen so kann man sich auch einen separaten IIS installieren und darin die Datein platzieren. 

Nach dem Start können darüber also auch REST-Requests durchgeführt werden welche wie folgt aussehen. 

![Emulator-ASP.Net](/images/ASPnet.PNG)

Als Empfehlung für den IIS Express ist es zu raten das eine Erweiterung installiert wird damit die IP-Adresse von außen ansprechbar ist, da ansonsten die Schnittstelle nur Lokal läuft und in einen vollwertigen IIS integriert werden muss. 

### Kurzzumsammenfassung
1. Hue-Emulator starten
    1.1 Software starten
    1.2 Emulator über Start in der oberen Leiste starten 
2. ASP.Net Emulator starten
    2.1 Datein in IIS legen und start
    2.2 IIS Express über Visual Studio starten mit Erweiterung für Netzwerkweite Kommunikation 
3. SmHoEzMa starten 


### Bedienung von SmHoEzMa 

:clap: :100: :100: :100: :100:
