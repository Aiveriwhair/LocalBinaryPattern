/*
*
* Codeur : William ISABELLE
* Ce programme a �t� r�alis� dans le cadre de ma premi�re ann�e de pr�pa int�gr�e
* � Polytech Orl�ans.
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

	Image1.Binary_Affiche();			//V�rification du fonctionnement des fonctions
	Image1.Decimal_Affiche();
	Image1.Hist_Affiche(Image1.Histogramme());
	return 0;
}
