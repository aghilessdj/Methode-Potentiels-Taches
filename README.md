# Projet Gestion de la mémoire


## Présentation du Projet
Ce projet réaliser dans le cadre de l'UE "Gestion de la mémoire" et il consiste à Faire un système de gestion des tâches, pour cela on a utilisé la notions de la structure dynamique des données avec l'alocation et la libération de la mémoire à l'aide des listes génériques doublement chainé avec on a fait les graphes.


## L'utilité du projet
Ce projet consiste à lire les tâches (les jobs), leurs durés, et leurs tâches précédentes d'un fichier texte et les enregistrer à l'aide d'une structure dynamique dans un graphe, puis les trier selon leurs degré de dépendance, ensuite on calcule le rank des taches et elles les trie par rang croissant, puis supprimer les arcs inutiles et les afficher, puis calculer les dates au plus tôt, les dates au plus tard, les marges totales et les marges libres et afficher leurs résultat et enfin afficher le chemin critique. 


## Comment lancé l'application
Pour lancé l'application il suffit de appeler l'exécutable qui est dans le fichier bin et lui ajouter un fichier texte en paramétre (Le fichier text doit contenir les taches, leurs durés et leurs Préséance et terminer par 'NIL')
Si on modifie quelque chose dans le code on doit d'abord compiler avec la commande *Make all*


## modification apportées au canevas fourni

### Structurer le projet
Après qu'on a réxupérer le canevas, on a récupérer les fonction sur les listes et les éléments de liste du dernier tp (celui qui est sur les listes génériques doublement chainé) et on a ajouter la fonction *take_out()*
On a structuré le projet où les fichier *.c* dans le dossier *src* les fichier *.h* dans le dossier Include et on a ajouter le Makefile
On a ajouter les fonctions des jobs dans le fichier *job.c*

### Les fonction *partition()* et *find()*
On a écrit la fonction *partition()* qui divise une liste en deux en fonction d'une valeur pivt et on la testé dans le dernier tp 
En même temp on a écrit la fonction *find()* qui test la présence d'un job J dans une liste G et lui ajoute s'il n'est pas présent sinon elle supprime le job donnée en paramêtre et donner à J l'adress mémoire de ce Job qui est dans la liste

On fait des test sur le bon fonctionnement de ces deux fonction la fonctin *find()* avec la fonction *read_graph()* et *partition* avec *quick_sort()*
On note que les fonction *read_graph()* et *quick_sort()* ont été fourni dans le canevas

### Les fonction *ranking()*, *prune()*, *marges()*
La fonction *ranking()* sert à calculer le rang de chaque job dans une liste G et j'ai ajouter une fonction *max_rank()* qui retourne le plus grand valeur d'un rang dans une liste de jobs et après avoir calculer tout les rangs on trie la liste par ordre de rang croissant à l'aide de la fonction *quick_sort()*

La fonction *prune()* sert à supprimer les arc inutil dans une liste de jobs et on fait ça avec la vérification de la différence de rang entre les jobs si il est supérieur à 1 alors l'arc est inutil

La fonction *marges()* sert à calculer les dates au plus tôt, les dates au plus tard, les marges totales et libres et la partition au chemin critique pour chaque job dans la liste


## Développeurs de ce projet
Ce projet a été réaliser par *SAIDJ Aghiles* et *MOINIER Sacha* avec l'orientation du prof *PARIS Stephane*