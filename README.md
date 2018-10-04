#Analyser LL

L'analyser LL est un programme permettant de générer un tableau d'analyse à
partir d'une grammaire, d'un fichier texte formaté. Il génère un
fichier binaire exploitable par un programme C.

Cette Analyser LL est accompagné d'une libraire permettant de travailler avec
les fichier binaires ```.all``` ainsi générés, directement depuis un projet C.


##Installation

Pour installer l'analyser LL, il suffit de lancer les commandes ci-dessous

```
git clone  https://CallMarl@bitbucket.org/CallMarl/analyser_ll.git
cd analyser_ll | sh ./init.sh
make analyser_ll

```

##Usage

Pour compiler un fichier de grammaire, il suffit de lancer la commande
ci-dessous :

```
./analyser_ll path/to/grammar.gmr path/to/grammar.all

```

Le fichier de grammaire doit porté l'extension ``.gmr``, le fichier binaire
générer par l'analyseur LL porte l'extension ``.all``.

##La grammaire

Afin de rédiger un fichier de grammaire, il suffit de respecter ces quelques
règles de formatage:

####Les blocks

Un fichier de grammaire ``.gmr`` est composé de deux bloques délimitant les
variables terminales, des règles de grammaire. Le délimiteur utilisé est le
terme ``%%``.

```
%%

déclaration des variable terminales

%%

déclaration des règles

%%
```

####Déclaration des terminaux

Les terminaux doivent se trouver dans le premier block du fichier de grammaire,
les terminaux corresponde à une énumération de termes distinct les un des autres
et distinct des règles de grammaire. Les terminaux sont séparés par des
espaces.

sur plusieurs lignes:
```
%%

nbr
somme
produit
moins

%%
```

sur un seul ligne:
```
%%

nbr somme produit moins

%%
```

####Déclaration des règles

Les règles doivent se trouver dans le segon block du fichier de grammaire,
les règles doivent toutes posséder un nom distinct les une des autres. Afin
de rédiger une règle, il suffit d'utiliser la syntaxe suivante:

```
%%

EXP :: nbr somme nbr;

%%
```

Il est d'usage de nommer une règle en Majuscule, et les terminaux en minuscules.
On dis que ``EXP`` dérive en ``nbr somme nbr``. Là où les dérivations sont
marquées par le terme ``::`` et les règles se terminent par un ``;``.

```
%%

EXP :: nbr somme nbr
    :: nbr product nbr

%%
```

Les règles peuvent également s'appeler récursivement:

```
%%

OPE :: EXP

EXP :: nbr somme nbr
    :: nbr product nbr

%%
```

####Termes réservés

  * ``%%`` : Délimiteurs pour un bloque
  * ``::`` : Règles de dérivation
  * ``ε`` : Caractere null

####Exemple

```
%%

nbr somme produit moins ( )

%%

SUM :: PRODUCT SUM_NEXT

SUM_NEXT :: ε
         :: somme SUM

PRODUCT :: EXRP PRODUCT_NEXT

PRODUCT_NEXT :: ε
             :: produit PRODUCT

EXRP :: ( SUM )
	 :: NUMBER

NUMBER :: nbr
	   :: moins nbr

%%
```

##Librairie

######Bientôt

##Liens

https://fr.wikipedia.org/wiki/Grammaire_formelle
https://fr.wikipedia.org/wiki/Symboles_terminaux_et_non_terminaux
https://fr.wikipedia.org/wiki/Grammaire_non_contextuelle
https://fr.wikipedia.org/wiki/Analyse_LL
https://github.com/DmitrySoshnikov/syntax/blob/master/examples/calc.ll1
