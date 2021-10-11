/*
*
* Codeur : William ISABELLE
* Ce programme a été réalisé dans le cadre de ma première année de prépa intégrée
* à Polytech Orléans.
* 
* Note : le code peut comporter des erreurs.
* 
*/

#include<iostream>
#include<time.h>
#include<fstream>
#include<math.h>
using namespace std;

#pragma once
class CImage
{
	int** m_tab;
	int m_nb_Ligne;
	int m_nb_Col;
	int m_nb_valeurs;
	int** Tab_binary;
	int* Tab_Decimal;
public:
	CImage();
	CImage(int ligne, int colonne);
	~CImage();
	void SaveLogs();
	void Binary();
	void Conversion_Decimal();
	int* Histogramme();
	void SaveHist(int *histo);


	void Decimal_Affiche();
	void Binary_Affiche();
	void Hist_Affiche(int* histo);
};

