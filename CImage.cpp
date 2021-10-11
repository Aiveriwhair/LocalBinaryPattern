/*
*
* Codeur : William ISABELLE
* Ce programme a été réalisé dans le cadre de ma première année de prépa intégrée
* à Polytech Orléans.
* 
* Note : le code peut comporter des erreurs.
* 
*/

#include "CImage.h"
CImage::CImage()
{
	m_nb_Col = 0;
	m_nb_Ligne = 0;
	m_nb_valeurs = 0;
	m_tab = nullptr;
	Tab_binary = nullptr;
	Tab_Decimal = nullptr;
}

CImage::CImage(int ligne, int colonne)
{
	m_nb_Ligne = ligne; m_nb_Col = colonne;
	m_nb_valeurs = m_nb_Col * m_nb_Ligne;
	
	m_tab = new int* [m_nb_Ligne];
	for (int i = 0; i < m_nb_Ligne; i++)
	{
		m_tab[i] = new int[m_nb_Col];
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < m_nb_Ligne; i++)
	{
		for (int j = 0; j < m_nb_Col; j++)
		{
			m_tab[i][j] = rand() % (256);
		}
	}


	Tab_binary = new int* [m_nb_valeurs];
	for (int i = 0; i < m_nb_valeurs; i++)
	{
		Tab_binary[i] = new int[8];
	}

	Tab_Decimal = new int[m_nb_valeurs];
}

CImage::~CImage()
{
	delete[]m_tab;
}
void CImage::SaveLogs()
{
	ofstream fichier("logs", ios::out);
	for (int i = 0; i < m_nb_Ligne; i++)
	{
		for (int j = 0; j < m_nb_Col; j++)
		{
			
			fichier << m_tab[i][j] <<"    ";
		}
		fichier << endl;
	}
}
void CImage::Binary()
{
	for (int i = 0; i < m_nb_Ligne; i++)
	{
		for (int j = 0; j < m_nb_Col; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				switch (k)
				{
				case 0:
					if (i == 0 ||j==0){
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i-1][j-1]){
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else{
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 1:
					if (i == 0) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i - 1][j]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 2:
					if (i == 0 || j == m_nb_Col-1) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i - 1][j + 1]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 3:
					if (j == m_nb_Col-1) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i][j + 1]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 4:
					if (i == m_nb_Ligne-1 || j == m_nb_Col-1) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i + 1][j + 1]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 5:
					if (i == m_nb_Ligne-1) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i + 1][j]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 6:
					if (i == m_nb_Ligne-1 || j == 0) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i + 1][j - 1]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;

				case 7:
					if (j == 0) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else if (m_tab[i][j] > m_tab[i][j - 1]) {
						Tab_binary[i * m_nb_Col + j][k] = 0;
					}
					else {
						Tab_binary[i * m_nb_Col + j][k] = 1;
					}
					break;
				}
			}
		}
	}
}

void CImage::Conversion_Decimal()
{
	for (int i = 0; i < m_nb_valeurs; i++)
	{
		int decimal = 0;
		for (int j = 0; j < 8; j++)
		{
			if (Tab_binary[i][j])
			{
				decimal += pow(2, 7 - j);
			}
		}
		Tab_Decimal[i] = decimal;
	}
}
int* CImage::Histogramme()
{
	int* histogramme = new int[256];
	fill(histogramme, histogramme + 256, 0);
	for (int i = 0; i < m_nb_valeurs; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			if (Tab_Decimal[i] == j)
			{
				histogramme[j]++;
			}
		}
	}
	return histogramme;
}
void CImage::SaveHist(int *histo)
{
	ofstream fichier("logs.xls", ios::out);
	for (int i = 0; i < 256; i++)
	{
		fichier << histo[i];
		fichier << endl;
	}
}
void CImage::Decimal_Affiche()
{
	for (int i = 0; i < m_nb_valeurs; i++)
	{
		cout << Tab_Decimal[i];
		cout << endl;
	}
}
void CImage::Binary_Affiche()
{
	for (int i = 0; i < m_nb_valeurs; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << Tab_binary[i][j];
		}
		cout << endl;
	}
}
void CImage::Hist_Affiche(int* histo)
{
	for (int i = 0; i < 256; i++)
	{
		cout << "Nb occurence de " << i << " : " << histo[i];
		cout << endl;
	}
}




/*
tab[i][j];
   000000
   0xxxx0	i == 0			012		tab[i-1][j-1] tab[i-1][j] tab[i-1][j+1]
   0xxxx0	i == 1			7X3  	tab
   0xxxx0	i == nligne		654
   000000

j=	012ncol

	************		i*nb_col +j
*/
