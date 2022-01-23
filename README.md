# TP_CPlusPlus

## Enoncé

une plate-forme dédiée à la programmation informatique proposant aux
participants différents jeux sous forme de casse-tête ou de compétition
d’intelligence artificielle multi-joueurs. Des entreprises utilisent également
cette plateforme pour recruter des développeurs.
Chaque joueur devra programmer un bot qui affrontera ensuite les bots des
autres joueurs. La plate-forme se charge ensuite d’organiser les matchs et
gérer le classement. Les programmes ne disposent que de 100ms par tour pour
proposer une réponse.

## Présentation de CodeInGame

<a src="https://www.codingame.com/start">Lien vers le site</a>

# BroomStick

### Objectif monter dans le classement !

'''photo de la ligue

---

# Etape 1 Decouverte de l'IDE

photo de l'ide

photo du plateau

## liste des paramètre d'une entitée:

• int entity_id => id de l'entitée
• string entity_type => type d'entités (sorcier , balle , cogneur)

• int x => position sur l'abscisse x  
• int vx => vitesse sur l'ordonnée x

• int y => position sur l'ordonnée y
• int vy => vitesse sur l'ordonnée y

• int state => état de l'entité (0 'mort' sorti du jeu, 1 'vivant' présent sur le terrain)

---

# Etape 2 Définir les actions basiques

### Mouvement de base

les mouvements de base doivent être écrit dans le terminal du jeu.
pour donner une action on utilise la methode **play_action**

### Action de mouvement

#### bouger

```c++
// Se déplace vers la position x : 2000 et la position y:1000 sur le terrain à la vitesse 150
play_action("MOVE", 2000,1000,150);

void play_action(string verb, int x, int y, int parameter) {
        cout << verb << " " << x << " " << y << " " << parameter << endl;
    }
```

Les déplacements sont limités par la taille du terrain et la vitesse est limité à 150.

#### tirer
```c++
// Si on  possede une balle la tire dans la direction 
play_action("THROW", 16000, 3700, 500);
void play_action(string verb, int x, int y, int parameter) {
        cout << verb << " " << x << " " << y << " " << parameter << endl;
    }
```

#### lancer un sort

---

# Etape 3 Débloquer toutes les fonctionnalités

---

# Etape 4 Récupérer les données

---

# Etape 5 Algorythme génétique

## Principe de sélection naturel
