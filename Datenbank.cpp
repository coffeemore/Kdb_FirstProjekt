#include "Datenbank.hpp"
/**
* \brief Klasse Datenbank
*
* Implementation Klasse Datenbank
* Die Datenbank basiert auf einm Vector von Kunden. Methoden zum
* Anlegen, Suchen und Entfernen von Datensätze wurden implemenitert, sowie
* Methoden zum Lesen und Ausgeben in eine Textdatei "kunden.txt".
* @see Kunden */
/**
*  Methode neuer Kunden
* Kundenelment wird in den Vector von Kunden übergeben
* @param Referenz auf Objekt vom Typ Kunde
* @pre Vorhandensein eines Kundenelment
* @return fügt ein weiteres Element der Datenbank hinzu */
void Datenbank::neuerKunde(const Kunde& neu_K)
{
  Kunden.push_back(neu_K);
}
/**
*  Methode neuer Eintrag
* Kundenelment wird durch Nutzereingabe erzeugt.
* Angaben für alle Datenelemente von Kunde.
* @return Kundenelment mit eingegebenen Werten*/
Kunde Datenbank::neuerEintrag()
{
  std::string FN, NM, VN;
  double JU;
  int KN;
  std::cout << "Firmenname eingeben:" << std::endl;
  std::cin >> FN;
  std::cout << "Name eingeben:" << std::endl;
  std::cin >> NM;
  std::cout << "Vorname eingeben:" << std::endl;
  std::cin >> VN;
  std::cout << "Jahresumsatz eingeben:" << std::endl;
  std::cin >> JU;
  std::cout << "Kundennummer eingeben:" << std::endl;
  std::cin >> KN;
  Kunde Eingabe( FN, NM, VN, JU, KN);
  return Eingabe;
}
/**
*  Methode Finden eines Kunden über Kundennummer
* Zeilenweises durchsuchen des Vectors, Abgleich Nutzereingabe und
* Eintrag in Datenbank.
* Sollten zwei Kunden mit der selben Kundennummer im Vector enthalten sein
* führt dies zum Fehler des Programms.
* Verantwortlich für Ausgabe eines Warnings" warning: control may reach
* end of non-void function [-Wreturn-type]", liegt sicher an fehlendem
* "return" innerhalb letzter Klammer der Methode.
* @param Angabe einer gültigen Kundennummer
* @pre Vector darf nicht leer sein
* @return Kundenelment mit übereinstimmender Kundennummer*/
const Kunde& Datenbank::getKundeUeberKundennummer(int Kundennummer)
{
  for (int i = 0; i < Kunden.size(); i++)
    if (Kunden.at(i).getKundennummer() == Kundennummer)
    {
      std::cout <<'\n';
      std::cout << "Kunde gefunden: " << Kunden.at(i) << std::endl;
      return Kunden.at(i);
    }
    std::cout << "Kunde nicht gefunden..." << std::endl;
}
/**
*  Methode Finden eines Kunden über Namen
* Zeilenweises durchsuchen des Vectors, Abgleich Nutzereingabe und
* Eintrag in Datenbank.
* Bei fehlhafter Eingabe des Nutzers wird Kunde nicht gefunden. Wird nur
* ein Leerzeichen eingeben führt dies ebenfalls zu fehlhaftem Verhalten.
* Verantwortlich für Ausgabe eines Warnings" warning: control may reach
* end of non-void function [-Wreturn-type]", liegt sicher ebenfalls
* an fehlendem "return" innerhalb letzter Klammer der Methode. Ich
* wusste allerdings nicht, wie ich dies beheben konnte.
* @param Angabe eines gültigen Namens
* @pre Vector darf nicht leer sein
* @return Kundenelment mit übereinstimmendem Kundennamen*/
const Kunde& Datenbank::getKundeUeberName(std::string Name)
{
  for (int i = 0; i < Kunden.size(); i++)
    if (Kunden.at(i).getName() == Name)
    {
      std::cout <<'\n';
      std::cout << "Kunde gefunden: " << Kunden.at(i) << std::endl;
      return Kunden.at(i);
    }
    std::cout << "Kunde nicht gefunden..." << std::endl;
}
/**
*  Methode Elemente in Datenbank
* @return Anzahl Kundenelment in Vector*/
int Datenbank::getDatenbanksize()
{
  return Kunden.size();
}
/**
*  Methode Elemente aus Datenbank entfernen
* @param Position des zu löschenden Elements
* @pre Eintrag in Datenbank muss bekannt sein
* @return Entfernt Kundenelment*/
void Datenbank::loescheEintrag(int Position)
{
  Kunden.erase (Kunden.begin()+Position);
}
/**
*  Methode Einlesen der Daten
* Abfrage ob File geöffnet ist.
* Zeilenweises durchgehen der Datei "kunden.txt".
* Erstellen eines Kundenelments pro Zeile.
* Über If Bedingung wird die auf Komma-Zeichen geprüft und
* ggf. durch ein Leerzeichen ersetzt, um evtl. auftretende
* Fehler zu umgehen.
* Pro Zeile wird ein Kunde in Variable k erstellt und bekommt
* den Inhalt des zeilenpuffers übergeben. k wird anschließend
* über Methode neuer Kunden in Vector geschrieben.
* Schließen der Kundendatei.
* @param i Schrittweite von 1
* @pre ließt Zeilenweise, ohne Leerzeile zwischen Einträgen
* @return Kundenelmente mit Werten aus Datei*/
void Datenbank::ladeFile()
{
  std::ifstream Kundendatei("kunden.txt", std::ios::in);
  if (Kundendatei.is_open())
  {
    std::string zeile;
    while (getline(Kundendatei, zeile))
    {
      for(int i = 0; i < zeile.size(); i++)
      {
        if (zeile [i] == ',')
        {
          zeile [i] = ' ';
        }
      }
    Kunde k;
    std::stringstream zeilenpuffer(zeile);
    zeilenpuffer >> k;
    neuerKunde(k);
    }
    Kundendatei.close();
  }
}
/**
*  Methode Schreiben in Textdatei
* Abfrage ob File geöffnet ist.
* Zeilenweises durchgehen der Datenbank und Schreiben der Information
* in Textdatei.
* Schließen der Kundendatei.
* Fehler beim Ausgeben der Datei treten auf, sobald sich in der Datenbank
* leere Einträge befinden, die durch den Konstruktor Aufruf Kunde() zwei
* Nullen enthalten. Außerdem wird die Datei jedesmal neu geschrieben und
* wuchs exponentiell bei einigen Tests. Die Textdatei müsste eigentlich
* jedesmal neu unter einem anderen Namen gespeichert werden oder die vorhergehende
* Datei müsste zuvor entfernt werden.
* @param i Schrittweite von 1
* @return schreibt Kundenelmente mit Werten aus Datenbank */
void Datenbank::speicherFile() //Methode zum Speichern der Datenbank
{
  std::ofstream Kundendatei("kunden.txt", std::ios::out);
  if (Kundendatei.is_open())
  {
    for (size_t i = 0; i < Kunden.size(); i++)
    {
      Kundendatei << Kunden[i] << std::endl;
    }
  }
  Kundendatei.close();
}
