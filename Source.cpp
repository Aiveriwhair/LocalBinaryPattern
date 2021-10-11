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
#include "CImage.h"
using namespace std;

int main()
{
	CImage Image1(3, 3);
	Image1.SaveLogs();
	Image1.Binary();
	Image1.Conversion_Decimal();
	Image1.SaveHist(Image1.Histogramme());

	Image1.Binary_Affiche();			//Vérification du fonctionnement des fonctions
	Image1.Decimal_Affiche();
	Image1.Hist_Affiche(Image1.Histogramme());
	return 0;
}
