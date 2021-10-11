# LocalBinaryPattern

Le Local Binary Pattern (LBP) ou motifs binaires locaux consiste à calculer pour chaque pixel d'une image une valeur de LBP en fonction de la luminance des voisins de ce dernier. Cette méthode est utilisée pour la vision par ordinateur est souvent associée à des réseaux de neuronnes pour la reconnaissance facilale, la détection d'objets ou encore la recconnaissance de textures.
Ce programme est un exemple d'implémentation de local binary pattern utilisant des matrices de valeurs aléatoires pour simuler des images.

Note : il se peut que le code comporte des erreurs. De plus, le code ne respecte par certaine notions fondamentales de la programmation orientée objet.

Codé par William ISABELLE.
Ce programme a été réalisé dans le cadre de ma première année de prépa intégrée
à Polytech Orléans.


*Description :

- Constructeurs : 
Le programme comprend 2 constructeurs dont 1 par défaut. Le constructeur par paramètres prend respectivememt comme paramètres la hauteur et la largeur de l'image que l'on souhaite générer aléatoirement.

- Fonctions : 
  - SaveLogs() :
  Permet de sauvegarder dans un fichier texte les valeurs des pixels généré aléatoirement.
  - Binary() :
  Permet de récupérer le code LBP de chaque pixel sous forme d'octet en binaire. Ces derniers sont gardés en mémoire dans un tableau membre de la classe CImage.
  - Conversion_Decimal() :
  Permet la conversion en valeurs décimal des octets précédemment calculés.
  - SaveHist(int* histogramme) :
  Sauvegarde de l'histogramme généré dans un fichier excel.
  - Binary_Affiche() :
  Affiche dans la console les octets binaires obtenus.
  - Decimal_Affiche() :
  Affiche dans la console les nombres obtenus via la conversion des octets binaires.
  - Hist_Affiche(int* histogramme) :
  Affiche dans la console l'histogramme des valeurs obtenues précédemment.






* 
