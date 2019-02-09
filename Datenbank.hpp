#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Kunde.hpp"
/**
* \brief Header Datenbank
*
* Headerdatei Klasse Datenbank
* Include der Standartbibliothek, sowie des Datentyp vector, Eingabe und Ausgabe
* für Files.
* Die Datenbank beinhaltet einen Vektor von Kunden Elementen der Klasse
* Kunden.
* Methoden für die Handhabung der Datensätze, sowie das Lesen und Ausgeben
* in eine Textdatei "kunden.txt".
* @see Kunde*/
class Datenbank
  {
    private: /** Eigenschaften der Klasse Deklaration der Variablen **/
      std::vector<Kunde> Kunden;
    public:
      void neuerKunde(const Kunde& neu_K); /** @return fügt ein weiteres Element der Datenbank hinzu **/
      Kunde neuerEintrag(); /** @return anlegen des Kunden von Hand **/
      const Kunde& getKundeUeberKundennummer(int Kundennummer); /** @return Kunde **/
      const Kunde& getKundeUeberName(std::string Name);/** @return Kunde **/
      int getDatenbanksize();/** @return Anzahl der Kunden in Datenbank/Größe des Vectors **/
      void loescheEintrag(int Position);/** @return Entfernt Kunden **/
      void ladeFile(); /** @return lädt Kunden in Vector der Datenbank **/
      void speicherFile();/** @return Sichert Kunden der Datenbank in Textdatei **/
};
