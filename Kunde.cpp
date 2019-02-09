#include "Kunde.hpp"
/**
* \brief  Klasse Kunden
*
* Implementation Klasse Kunden
* Konstruktoren für den Aufruf ohne Argument und den Aufruf mit den Datentypen
* string, double und integer.
* Jeweils eine einzelne Methode die die entsprechenden Werte der einzelnen
* Datenelemente von Kunde zurückgeben.
* Methode um den Jahresumsatz eines einzelnen Kunden einzugeben.
* Weitere Methode die jedem Kunden in Anhängigkeit seines Jahresumsatz eine
* Rabattkategorie zuordnet.
* Überladungen der Ein- und Ausgabeoperatoren.
* @see Datenbank */
/**
*  Konstruktor ohne Argument
* Implementation Konstruktor der Klasse Kunde ohne Argument
* @pre keine Argumentübergabe
* @return Initalisierung des Jahresumsatz und der Kundennummer mit 0 */
Kunde::Kunde()
{
  Jahresumsatz = {0};
  Kundennummer = {0};
}
/**
*  Konstruktor
* Implementation Konstruktor der Klasse Kunde, sowie die Zuweisung zu
* den Eigenschaften der Klasse.
* @pre Angaben zu Firma und Person, sowie Jahresumsatz und Kundennummer
* @return Kunde mit allen Datenelementen */
Kunde::Kunde(const std::string& neu_FN, const std::string& neu_NM,
  const std::string& neu_VN, const double& neu_JU, const int& neu_KN)
{
  Firmenname = neu_FN;
  Name = neu_NM;
  Vorname = neu_VN;
  Jahresumsatz = neu_JU;
  Kundennummer = neu_KN;
}
/**
*  Methode Firmenname
* @return string Firmenname des Kunden */
std::string Kunde::getFirmenname()
{
  return Firmenname;
}
/**
*  Methode Name
* @return string Name des Kunden */
std::string Kunde::getName()
{
  return Name;
}
/**
*  Methode Vorname
* @return string Vornahme des Kunden */
std::string Kunde::getVorname()
{
  return Vorname;
}
/**
*  Methode Jahresumsatz
* @return double Jahresumsatz des Kunden */
double Kunde::getJahresumsatz()
{
  return Jahresumsatz;
}
/**
*  Methode Kundennummer
* @return integer Kundennummer des Kunden */
int Kunde::getKundennummer()
{
  return Kundennummer;
}
/**
*  Methode zum setzen des Jahresumsatz
* Zeiger auf eigene Klasse um den Jahresumsatz
* innerhalb eines Kunden auf den Übergebenen double Wert zu
* setzen.
* "Diese Methode konnte ich nicht richtig implementieren, sie tut nicht was sie soll.
* Andere Möglichkeiten über "Jahresumsatz = übergebener Wert" funktionierten
* ebenfalls nicht." */
void Kunde::setJahresumsatz( double neu_JU)
{
  this -> Jahresumsatz = neu_JU;
}
/**
*  Methode zur Zuordnung eines gewährten Rabatts
* Rabatt ist abhängig von Jahresumsatz in fünf Kategorien unterteilt.
* weniger als 10000 Euro ohne Rabatt, 10000-20000 Euro 1%,
* 20000 bis 40000 Euro 2%, 40000 Euro bis 100000 Euro 4 % und mehr als
* 100000 10% Rabatt.
* @param Objekt vom Typ Kunde muss übergeben werden
* @pre es muss ein Jahresumsatz gesetzt sein
* @return Zuordnung einer Rabattkategorie des Kunden */
void Kunde::getRabatt(const Kunde&)
{
 if (Jahresumsatz < 10000)
 {
   std::cout << "Kein Rabatt für diesen Kunden. Jahresumsatz unter 1000 EUR" << std::endl;
 }
 else if (Jahresumsatz >= 10000 && Jahresumsatz < 20000)
 {
   std::cout << "Kunde wird 1 Prozent Rabatt gewährt!" << std::endl;
 }
 else if (Jahresumsatz >= 20000 && Jahresumsatz < 40000)
 {
   std::cout << "Kunde wird 2 Prozent Rabatt gewährt!" << std::endl;
 }
 else if (Jahresumsatz >= 40000 && Jahresumsatz < 100000)
 {
   std::cout << "Kunde wird 4 Prozent Rabatt gewährt!" << std::endl;
 }
 else if (Jahresumsatz < 100000)
 {
   std::cout << "Kunde wird 10 Prozent Rabatt gewährt!" << std::endl;
 }
 else
 {
   std::cout << "Kunde wird 10 Prozent Rabatt gewährt!" << std::endl;
 }
}
/**
*  Funktion Operator <<
* Überladen des Operator << für die Ausgabe von Datenelementen durch Funktion
* mit Zugriff auf Klasse Kunde
* @param Datenelemente vom Typ Kunde muss übergeben werden
* @return Inhalte der Klasse als standart Ausgabe Wert mit
* jeweils Leezeichen getrennt. */
std::ostream& operator << (std::ostream& output, const Kunde& rhs)
{
  output << rhs.Firmenname << " " << rhs.Name << " " << rhs.Vorname << " " << rhs.Jahresumsatz << " " << rhs.Kundennummer << std::endl;
  return output;
};
/**
*  Funktion Operator >>
* Überladen des Operator >> für die Eingabe von Datenelementen durch Funktion
* mit Zugriff auf Klasse Kunde
* @param Datenelemente vom Typ Kunde muss ausgegeben werden
* @return Inhalte der Klasse als standart Ausgabe Wert mit
* jeweils Leezeichen getrennt. */
std::istream& operator >> (std::istream& input, Kunde& rhs)
{
  input >> rhs.Firmenname >> rhs.Name >> rhs.Vorname >> rhs.Jahresumsatz >> rhs.Kundennummer;
  return input;
};
