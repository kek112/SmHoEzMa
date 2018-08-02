# Smarthome Easymaker (SmHoEzMa)
Created by:
- Tobias Rieß
- Karl-Erik Kley
- Martin Lesser

## *Mobile Computing 1 Projekt*
Dieses Projekt ist die Belegarbeit für das Fach Mobile Computing 1. 
Der Smarthome Easymaker oder kurz SmHoEzMa dient zur Ansteuerung und Bedienung verschiedener Smarthome Geräte welche sich im Netzwerk befinden. Als Hauptfunktionen werden das Anlegen verschiedener Geräte, eine Homecoming Funktion sowie die Ansteuerung der einzelnen Geräte Ansicht betrachtet. 
Das Projekt wurde in Qt/C++ umgesetzt mit teilweise dem Aufsatz QML, sowie Java für einen Emulator und ASP.Net für einen anderen. 

### Installation/Start Fremdsoftware
Um eine realistische Herangehensweise zu simulieren gab es die ursprüngliche Planung das tatsächlich Smarthome Geräte organisiert werden. Diese Idee wurde aber schnell verworfen da es deutlich geschickter ist entsprechende Emulatoren für besagte Geräte bereitzustellen, welche die gleiche Funktionalität bereitstellen. Zum einen wurde ein ausgezeichneter Emulator für die Philips Hue Lampen gefunden und aus Mangel existierender Alternativen wurde ein eigener für 2 Sensoren auf BAsis von ASP.Net entwickelt. 

#### Philips Hue Emulator

Es wird die externe Software von https://steveyo.github.io/Hue-Emulator/ genutzt. 
Dieses Repository wird einfach runtergeladen und der darin enthaltene Emulator wird gestartet. 
Die Version V0.8 wurde in unserer App verwendet und war zu dem Entwicklungszeitpunkt die aktuellste Version.
Nach dem Start der Software sollte dieses Bild angezeigt werden:

![Emulator Startup](/images/Emulator_UI.PNG)

In dieser Ansicht muss nur oben auf Start gedrückt werden um den Server zu starten. 
In diesem Emulator können noch zusätzliche Lampen hinzugefügt werden. In unserem Beispiel haben wir eine Lux Lampe erstellt. 

![Emulator-Lampen](/images/EmulatorPNG.PNG)

Danach ist der Link(Links auf dem Bild) über die IP-Adresse des Rechners ansprechbar. 
Die genauen REST-Abfragen lassen sich mit in dem Repository welches verlinkt wurde finden. 

#### Temperatur/Luftfeuchtigkeit Emulator 
Da es sonst wenig bis keine laufenden Alternativen für andere Smarthome Devices gab, wir aber noch mindestens eine andere Art der Ansteuerung haben wollten, musste eine Alternative entwickelt werden. 

Dieses wurde in Form einer schnellen Umsetzung auf der Basis von ASP.Net gemacht. Letztendlich bietet diese Lösung nur die Funktionalität um Temperatur und Luftfeuchtigkeitswerte zu erzeugen. 
In dieser Version werden die Werte noch zufällig zwischen 2 Grenzwerten wiedergegeben. Im Grunde wird dadurch eine weitere REST-Schnittstelle erzeugt welche wir abrufen können. 

ASP.Net läuft in unserer Version über den IIS Express welcher in VS integriert ist. Soll dieser ohne den IIS Express von Visual Studio laufen so kann man sich auch einen separaten IIS installieren und darin die Datein platzieren. 

Nach dem Start können darüber also auch REST-Requests durchgeführt werden welche wie folgt aussehen. 

![Emulator-ASP.Net](/images/ASPnet.PNG)

Als Empfehlung für den IIS Express ist es zu raten das eine Erweiterung installiert wird damit die IP-Adresse von außen ansprechbar ist, da ansonsten die Schnittstelle nur Lokal läuft und in einen vollwertigen IIS integriert werden muss. 

### Kurze Zusammenfassung
1. Hue-Emulator starten
    1. Software starten
    1. Emulator über Start in der oberen Leiste starten 
2. ASP.Net Emulator starten
    2. Dateien in IIS legen und Start
    2. IIS Express über Visual Studio starten mit Erweiterung für Netzwerkweite Kommunikation 
3. SmHoEzMa starten 


### Bedienung von SmHoEzMa 


Der Startbildschirm von SmHoEzMa ist die Liste der eingespeicherten Geräte. Sollte man die App noch nicht gestartet haben so kann man anfangen und die Geräte über das Plus hinzuzufügen. 

#####HIER BILD VON STARTSEITE ohne Gerät EINFÜGEN
![SmHoEzMa-Startmenü](/images/.PNG)

Möchte man ein neues Gerät hinzufügen so sollte man dessen IP Adresse kennen. Diese trägt man mit einem Namen der eigenen Wahl ein und lässt es hinzufügen. Dann mit einem Dropdown wird die Geräteklasse ausgewählt. Diese ist wichtig um zu wissen wie das Geräte später angesteuert werden muss. 

#####HIER BILD VON GERÄT HINZUFÜGEN EINFÜGEN
![SmHoEzMa-Gerät hinzufügen](/images/.PNG)

Nachdem das entsprechende Gerät in der Liste aufgenommen wurde können verschiedene Funktionen ausgeführt werden. Je nach Gerätemodel werden andere Möglichkeiten der Ansteuerung dargestellt. So bietet ein Sensor nur die Abfrage des Wertes und eine Philips Hue bietet die Einstellung der Helligkeit, der Sättigung und des Farbwertes. 

#####HIER BILD VON STARTSEITE mit philips hue EINFÜGEN
![SmHoEzMa-Startmenü2](/images/.PNG)

Werden nun die Einstellung eines hinzugefügten Gerätes ausgewählt so kommt man in ein Menü welches die Möglichkeit bietet eine Homecoming Funktion einzustellen. Diese ermöglicht es die Geräte spezifisch anzusteuern sobald sich das Telefon in deren Nähe befindet. 

#####HIER BILD VON GERÄTe EInstellungen EINFÜGEN
![SmHoEzMa-Geräte Einstellung](/images/.PNG)

Wählt man das Hamburgermenü im Startbildschirm aus so werden verschiedene Funktionen sichtbar wie den Sleepmode oder die Einstellung für die App. 
Der Sleepmode ermöglicht es alle Geräte anzusteuern und diese auszuschalten, sofern diese damit ansprechbar sind. 
Die Auswahl Einstellung aus dem Startmenü ermöglicht es bisher Benachrichtigungen an- oder abzuschalten. 

 
### Zukunftsausblicke von SmHoEzMa

Als Erweiterung und als Ausblick auf Mobile Computing 2 wurden schon einige Überlegungen angestellt um die bisherige App zu verbessern. 

Zum einen wird das Grundprinzip der Ansteuerung der Geräte komplett über eine REST Schnittstelle geschehen. Somit muss nicht immer jedes Gerät für sich hinzugefügt werden, sondern nur noch der Server welcher die Verfügbaren Smartdevices kommuniziert. Dies ermöglicht es sämtlichen Netzwerkaufwand auf ein externes Gerät zu schieben und nur noch die Daten abzurufen, wenn diese gebraucht werden. 

Daraus ergibt es sich auch das die Logik innerhalb vom SmHoEzMa verändert werden muss damit die entsprechenden Antworten übersetzt werden können. 
Außerdem bedeutet das eine Entwicklung eines Entsprechend komplexen Backend welche neuen Überlegungen benötigt um eine verbesserte Funktionalität zu bieten. Damit verbunden existiert auch die Idee das dieser Server kleinere Sensoren ansteuert die tatsächliche Werte liefern kann und nicht wie bisher zufällig Werte generiert.

Als andere Planung ist es vorgesehen, dass die gesamte GUI auf QML umgestellt wird. Diese bietet im Vergleich zu den bisherigen Qt Widgets mehr Komfort im Bereich der Android Entwicklung da die Widgets an sich eher für den Desktop Gebrauch ausgelegt sind. 

Es sind auch kleinere Funktionalitäten geplant wie die Anzeige von Graphen für bisherige Verläufe oder teilautomatische Ansteuerungen unter bestimmten Voraussetzungen.
