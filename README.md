# Projet Gestion de la mémoire


## Présentation du Projet
Ce projet réalisé dans le cadre de l'UE "Gestion de la mémoire" et consiste à Faire un système de gestion des tâches, pour cela, on a utilisé la notions de la structure dynamique des données avec l'allocation et la libération de la mémoire à l'aide des listes génériques doublement chainées (nous avons utilisé la notion de grahe).


## L'utilité du projet
Ce projet consiste à lire les tâches (les jobs), leurs durée, et leurs tâches précédentes d'un fichier texte et les enregistrer à l'aide d'une structure dynamique dans un graphe, puis les trier selon leur degré de dépendance, ensuite on calcule le rang des taches et on les trie par rang croissant, puis supprimer les arcs inutiles et les afficher, puis calculer les dates au plus tôt, les dates au plus tard, les marges totales et les marges libres et afficher leurs résultats et enfin afficher le chemin critique. 


## Comment lancer l'application
Pour lancer l'application il suffit d'appeler l'exécutable qui est dans le fichier bin et de lui fournir un fichier texte en paramètre (Le fichier texte doit contenir les tâches, leur durée et leurs Précédance et se terminer par 'NIL')
Si on modifie quelque chose dans le code, il faut d'abord compiler avec la commande *Make all*


## Modifications apportées au canevas fourni

### Structuration du projet
Après avoir réxupérer le canevas, on a repris les fonctions sur les listes et les éléments de liste du dernier TP (celui qui est sur les listes génériques doublement chainées) et on a ajouté la fonction *take_out()*
On a structuré le projet en plaçant les fichiers *.c* dans le dossier *src* et les fichiers *.h* dans le dossier *Include* et on a ajouté le Makefile
On a ajouté les fonctions des jobs dans le fichier *job.c*

### Les fonctions *partition()* et *find()*
On a écrit la fonction *partition()* qui divise une liste en deux en fonction d'une valeur pivot et on la testé dans le dernier TP.
En même temps on a écrit la fonction *find()* qui teste la présence d'un job J dans une liste G et l'ajoute s'il n'est pas présent sinon elle supprime le job donné en paramètre et donne à J l'adresse mémoire de ce Job qui est dans la liste

On a fait des testa sur le bon fonctionnement de ces deux fonctions la fonctin *find()* avec la fonction *read_graph()* et *partition* avec *quick_sort()*
On note que les fonctions *read_graph()* et *quick_sort()* ont été fournies dans le canevas

### Les fonction *ranking()*, *prune()*, *marges()*
La fonction *ranking()* sert à calculer le rang de chaque job dans une liste G et j'ai ajouté une fonction *max_rank()* qui retourne la plus grande valeur d'un rang dans une liste de jobs et après avoir calculé tous les rangs on trie la liste par ordre de rang croissant à l'aide de la fonction *quick_sort()*

La fonction *prune()* sert à supprimer les arc inutiles dans une liste de jobs et on fait ça en vérifiant si la différence de rang entre les jobs est supérieur à 1 (dans ce cas l'arc est inutile)

La fonction *marges()* sert à calculer les dates au plus tôt, les dates au plus tard, les marges totales et libres et à identifier le chemin critique pour chaque job dans la liste


## Expliquation de quelques Algorithme

### Algorithme de trie rapide

1 - Si la liste contient 0 ou 1 élément donc elle est déjà trier (cas de base)
2 - Prend le premier élément de la liste comme *pivot* et on met à jour la liste pour contenir les élément après le pivot
3 - On crée deux nouvelles listes 
    3.1 - *val_inf_pivot* qui vas contenir les éléments de la liste inférieures au pivot
    3.1 - *val_sup_pivot* qui vas contenir les éléments de la liste suppérieures au pivot
        Cette étape faite à l'aide de la fonction partition
4 - On ssupprime les élément de la liste L mais son supprimer les jobs et la liste
5 - Si la *val_inf_pivot* est vide alors on ajoute le pivot dans la liste L (Le pivot est la plus petite valeur)
    Sinon (*val_inf_pivot* n'est pas vide) on trie récursivement cette liste puis on ajoute le pivot en queue de cette partie
6 - Si *val_sup_pivot* n'est pas vide Alors on la trie récursivement puis on l'attache à la suite du pivot




## Développeurs de ce projet
Ce projet a été réalisé par *SAIDJ Aghiles* et *MOINIER Sacha* avec l'orientation du professeur *PARIS Stephane*