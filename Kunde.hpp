#pragma once

#include <iostream>
#include <string>
/**
* \brief Header Kunden
*
* Headerdatei Klasse Kunden
* Include der Standartbibliothek, sowie des Datentyp String.
* Ein Datensatz innerhalb der Datenbank Kunde
* besteht aus einem Eintrag Firmenname, Name, Vorname, Jahresumsatz
* und Kundennummer.
* Die Klasse beinhaltet zwei Konstruktoren, einen für einen Aufruf ohne Argumente
* und einen weiteren der für jeden übergebenen Wert einen Bezug der Eigenschaften
* unter private herstellt. Die Datentypen string für Firmenname, Name, Vorname,
* sowie double für den Jahresumsatz und integer für die Kundennummer.
* @see Datenbank */
class Kunde
{
  private:  /** Eigenschaften der Klasse Deklaration der Variablen **/
    std::string   Firmenname;
    std::string   Name;
    std::string   Vorname;
    double        Jahresumsatz;
    int           Kundennummer;
  public:
    Kunde(); /** Konstruktor ohne Argument **/
    Kunde(const std::string& neu_FN, const std::string& neu_NM,
      const std::string& neu_VN, const double& neu_JU, const int& neu_KN); /** Konstruktor zur Erstellung eines einzelnen Kunden **/
    std::string getFirmenname(); /** @return string Firmenname **/
    std::string getName(); /** @return string Name **/
    std::string getVorname(); /** @return string Vorname **/
    double getJahresumsatz(); /** @return double Jahresumsatz **/
    int getKundennummer();/** @return integer Kundennummer **/
    void setJahresumsatz(double neu_JU); /** @return Zuweisung des Jahresumsatz zu einem Kunden **/
    void getRabatt(const Kunde&); /** @return Wert Rabatt **/
    friend std::ostream& operator << (std::ostream& output, const Kunde& rhs); /** friend Deklarattion zur Nutzung des Schiebeoperators **/
    friend std::istream& operator >> (std::istream& input, Kunde& rhs); /** friend Deklaration zur Nutzung des Schiebeoperators **/
};
