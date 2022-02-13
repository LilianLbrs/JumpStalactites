# Présentation :
JumpStalactites est un jeu type Platformer en 2D qui utilise SDL2 pour l'affichage graphique.
Ce jeu est développé par Anthony Gonzalez, Alexandre Azouri et Lilian Labrosse dans le cadre de l'Unité d'Enseignement LIFAP4 (Université Lyon 1).

# Vidéo de présentation :
![](Blockudoku-presentation.gif)

# Description des fichiers :

    - bin : contient les executables (JumpStalactites.exe en version graphique et JumpStalactites_txt.exe pour la version texte) et les librairies nécessaires à l'execution
    - data : contient les données du jeu (les sprites et la map en format texte)
    - doc : contient la documentation doxygen ainsi que son fichier de configuration
    - extern : contient les librairies SDL2 (classique, image, mixer, font)
    - obj : contient les fichiers objets pour la compilation
    - src : contient les fichiers sources, core pour la base du jeu, txt pour l'affichage texte et sdl2 pour l'affichage graphique
    - Makefile : Règles de compilation pour la version graphique
    - Makefile_txt : Règles de compilation pour la version texte
    - README.md : ce fichier

# Compilation :

- Pour compiler la version graphique il suffit d'utiliser la commande make à la source du fichier. Cela va créer l'éxecutable dans le dossier bin.
- Pour compiler la version texte il faut executer la commande `make -f Makefile_txt`
