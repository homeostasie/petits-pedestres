Quelques petites idées et remarques sur ce que tu m'as demandés.

En peu de temps : 10min.

1) Le côté statistique ne me semble pas le plus intéressant dans une optique de manipulation.

Pourquoi ?

- La première étape est souvent de compter le nombre de répétition des lettres... C'est long et pas particulièrement intéressant... 
    * On peut imaginer donner "le comptage" en même temps. 

- Il faut mieux que le texte à décoder soit un peu long si on veut que les statistiques deviennent pertinentes. Les messages courts ne marchent pas trop sauf à vraiment le choisir pour que ça marche, mais ça fait pipoté. 

- Même avec un texte un peu long... on reste dans le domaine des stats qui est un domaine qui fait toujours appel à de l'analyse et de l'interprétation. Notamment parce qu'en Fr, il y a des accents et que ça fout un peu la merde. Qu'il y a pas mal de biais... Si tu vouvois, des Z vont apparaître dans le texte. Pour autant, ça reste une question intéressante. 
    * En Fr, on trouve facilement les stats d'apparitions des lettres : https://www.apprendre-en-ligne.net/crypto/stat/francais.html
    * Le plus intéressant à mon avis est d'essayer un peu comme dans les mots croisés de faire des déductions notamment avec les bigrammes et les trigrammes. D'un point de vue "maths" on sort un peu de la méthode pour rentrer dans de la technique. Ça prends un peu plus de temps.


Sur ce thème, si tu veux aller un peu vite : https://www.dcode.fr/chiffre-cesar marche bien et te permet d'aller assez vite.
Soit sur du césar

Pour les codes avec des clés, c'est un peu plus touchy a expliquer : https://www.dcode.fr/chiffre-vigenere

2) Le côté informatique est je pense plus facile à faire découvrir dans un court laps de temps.
Je te file le pdf "pour enfants" que j'utilise.

pdf : de la page 8 à la page 16 de  : CS-unplugged-fr-1.pdf


- Tu peux le présenter de manière simple : Tu ne donnes que la page 16 avec le graphique et le tableau de correspondance. 
- Tu peux très facilement avec un tableur faire un autre message et une autre image si celles-ci sont trop enfantines.
- Tu peux expliquer plus ou moins rapidement mais en gros, c'est le principe du langage binaire.

    Chaque nombre peut s'écrire à l'aide des puissances de 2 : page 12 et 13 en commençant par 2^0.

    ex : 
    5  = 1 + 4 = 2^0 et 2^2 => la première et la troisième case en noire.
    14 = 2 + 4 + 8 = 2^1 + 2^2 + 2^3  => la deuxième, la troisième et la quatrième case en noire.

    Pour la première ligne du sapin, je note que les cases 0, 1 et 4 sont cochées : 

    ATTENTION :  ici il a été choisi de lire de droite à gauche.

    2^0 + 2^1 + 2^4 = 1 + 2 + 16 = 19 d'où la lettre S.
    
    Chaque nombre correspond à une lettre et donc chaque ligne de 5 pixel correspond à une lettre.

S'ils comprennent ça, ça peut aller vite pour décoder ce message qui est assez facile. 

Deux ouvertures possibles. 

- Le fait que c'est assez simple de coder un message dans une image... 
    * surtout si l'image est plus grande et qu'on a codé le message seulement dans une partie de l'image.
    * on peut imaginer un doc excel avec des nombres à la con et des couleurs plutôt random dedans. 

- C'est aussi comme ça qu'est stocker du texte dans un ordinateur.
    * les lettres ne sont pas côdées sur 26 mais sur 256. C'est le code ascii. 256 = 2^8. C'est pour ça qu'on parle d'un octet.
    * Un doc texte (notepad pas word) avec une seule lettre fait un octet. 
    * Un doc texte (notepad pas word) avec un millier de lettres fait un kilooctet. (environ parce qu'un kilooctet = 1024 octet mais surtout parce que lors de l'enregistrement les éditeurs de textes ont tendance à optimiser l'espace avec de la compression sur les répétitions., )












