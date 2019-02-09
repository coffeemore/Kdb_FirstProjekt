#include "Kunde.hpp"
#include "Datenbank.hpp"
/**
* \brief Hauptprogramm
*
* Einbinden der Klassen Kunden und Datenbank.
* Erzeugen einses Vectors vom Typ Datenbank mit beinhalteten Kunden.
* Globale Variable für die Nutzereingabe um Menu zu bedienen.
* Ausgabe auf der Kommandozeile eines Hauptmenüs, über eine while Schleife
* die als Abbruchbedingung die userEingabe "v" zum verlassen des Programms
* beinhaltet. Switchcase Anweisungen innerhalb der Schleife, um dem Nutzer
* Wahlmöglichkeiten anzubieten.
* @see Kunde
* @see Datenbank*/
char userEingabe;

int main()
{
  Datenbank db;
  /**
  *  Hauptmenue While Schleife
  * Hauptmenue wird ausgegeben nach != v jedem ausgeführten case.
  * Abbruchbedingung "v" schließt das Programm.
  * @param erwaratet char Nutzerentscheidung
  * @return gibt Hauptmenue aus*/
while (userEingabe != 'v')
{
  std::cout <<'\n';
  std::cout << "Hauptmenue" << std::endl;
  std::cout << "[l]ade Datenbank, " <<  "[s]peichern der Datenbank, "<< '\n'
  << "[n]euer Kunde, " << "[e]ntferne Kunde, " << "setze [j]ahresumsatz uebr Kundennummer, "
  << "[f]inde Kunden, "<< '\n'
  << "Programm [v]erlassen" << std::endl;
  std::cout <<'\n';
  std::cout << "Auswahl" << '\n';
  std::cout << "> ";
  std::cin >> userEingabe;
  /**
  *  Switchcase
  * Durch Beelgung der userEingabe Variable wird case gewählt
  * @param j Jahresumsatz setzen
  * @param l Datenbank laden
  * @param f Kunden finden
  * @param s Datenbank speichern
  * @param n Kunden anlegen
  * @param e löschen
  * @return führt case aus */
  switch (userEingabe)
  {
    case 'j':
    {
      /**
      *  Case 1
      * Jahresumsatz wird vom Nutzer eingegeben.
      * Zuvor Eingabe einer gültigen Kundennummer.
      * @param k Kunde entspricht Kunden in Datenbank mit Kundennummer
      * @return gibt Hauptmenue aus*/
      int kdnr;
      std::cout << "Bitte Kundennummer eingeben: " << std::endl;
      std::cout << "> ";
      std::cin >> kdnr;
      Kunde k = db.getKundeUeberKundennummer(kdnr);
      std::cout << "Bitte Jahresumsatz eingeben des Kunden: " << std::endl;
      std::cout << "> ";
      double jum;
      std::cin >> jum;
      k.setJahresumsatz(jum);
      db.getKundeUeberKundennummer(kdnr);
    }
    break;
    /**
    *  Case 2
    * Einlesen der Daten in Datenbank.
    * @return Kundenelmente mit Werten aus Datei
    * @return Anzahl Kundenelment in Vector*/
    case 'l':
    std::cout << "Datenbank lädt..." << std::endl;
    db.ladeFile();
    std::cout << db.getDatenbanksize() << " Kunde(n) in Datenbank geladen." <<std::endl;
    break;

    /**
    *  Case 3
    * Kunden finden in Datenbank.
    * Zuvor wird auswahl über If Anweisung geprüft.
    * @return Kundenelment*/
    case 'f':
    std::cout << "Kunden finden ueber [n]ame oder [k]undennummer? " << std::endl;
    std::cout << "> ";
    char auswahl;
    std::cin >> auswahl;
    /**
    *  Finden über Kundennummer
    * Nutzereingabe und Datenabgleich
    * Nach erfolgreicher Suche besteht die Möglichkeit, sich die Rabattkategorie
    * des Kunden anzusehen über erneute switch case anweisung.
    * @param y ja
    * @param n nein
    * @return Kundenelment
    * @return Kundenelment mit übereinstimmender Kundennummer
    * @return Rabatt des Kunden */
    if (auswahl == 'k')
      {
        int kdnr;
        std::cout << "Bitte Kundennummer eingeben: " << std::endl;
        std::cout << "> ";
        std::cin >> kdnr;
        Kunde k = db.getKundeUeberKundennummer(kdnr);
        std::cout << "Rabattkategorie anzeigen? (y/n)" << std::endl;
        std::cout << "> ";
        char wahl;
        std::cin >> wahl;
        switch (wahl)
          {
          case 'y':
          k.getRabatt(k);
          break;
          case 'n':
          std::cout << "...zurueck zum Hauptmenue." << std::endl;
          break;
          }
      }
      /**
      *  Finden über Namen
      * Nutzereingabe und Datenabgleich
      * Nach erfolgreicher Suche besteht die Möglichkeit, sich die Rabattkategorie
      * des Kunden anzusehen über erneute switch case anweisung.
      * @param y ja
      * @param n nein
      * @return Kundenelment
      * @return Kundenelment mit übereinstimmender Kundennummer
      * @return Rabatt des Kunden  */
    if (auswahl == 'n')
    {
      std::string name;
      std::cout << "Bitte Kunden (Nach)name eingeben: " << std::endl;
      std::cout << "> ";
      std::cin >> name;
      Kunde k = db.getKundeUeberName(name);
      std::cout << "Rabattkategorie anzeigen? (y/n)" << std::endl;
      std::cout << "> ";
      char wahl;
      std::cin >> wahl;
      switch (wahl)
        {
        case 'y':
        k.getRabatt(k);
        break;
        case 'n':
        std::cout << "...zurueck zum Hauptmenue." << std::endl;
        break;
        }
    }
    break;
    /**
    *  Case 4
    * Auslesen der Datenbank.
    * @return Anzahl Kundenelment in Vector
    * @return "kunden.txt"*/
    case 's':
    std::cout << "Datenbank speichern..." << std::endl;
    std::cout << db.getDatenbanksize() << " Kunde(n) gespeichert." <<std::endl;
    db.speicherFile();
    break;
    /**
    *  Case 5
    * Anlegen eines Kunden von Hand
    * Kundenelment wird in den Vector von Kunden übergeben
    * Angaben für alle Datenelemente von Kunde.
    * @return fügt ein weiteres Element der Datenbank hinzu */
    case 'n':
    db.neuerKunde(db.neuerEintrag());
    break;

    /**
    *  Case 6
    * Löschen eines Kunden über Datenbankposition
    * @param Position des zu löschenden Elements
    * @pre Eintrag in Datenbank muss bekannt sein
    * @return Entfernt Kundenelment */
    case 'e':
    {
      int x;
      std::cout << "Aktuell: " << db.getDatenbanksize() << " Kunde(n) in Datenbank gespeichert." << std::endl;
      std::cout << "Zum Entfernen: Position des Kunden in Datenbank eingeben." << std::endl;
      std::cin >> x;
      db.loescheEintrag(x);
      break;
    }
  }
}
  std::cout << "Programm wird geschlossen." << '\n';
  return 0;
}
