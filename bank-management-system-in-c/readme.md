
# Gestion de Comptes Bancaires en Langage C

## Description du Projet
Ce projet consiste en une application de gestion de comptes bancaires développée en langage C. Elle permet aux utilisateurs de créer, consulter, modifier et supprimer des comptes bancaires, ainsi que d'effectuer des transactions (dépôts et retraits). Les données sont stockées dans un fichier binaire (`record.dat`) pour une gestion sécurisée et efficace.

## Fonctionnalités
- **Création de compte** : Enregistrement des informations client (nom, numéro de compte, solde initial, etc.).
- **Consultation de compte** : Affichage des détails d'un compte existant.
- **Transactions** : Dépôt et retrait d'argent sur un compte.
- **Suppression de compte** : Effacement d'un compte du système.
- **Menu intuitif** : Interface simple pour naviguer entre les fonctionnalités.

## Structure du Code
- **Structures de données** :
  - `struct date` : Pour gérer les dates (naissance, dépôt, retrait).
  - `struct Client` : Pour stocker les informations clients.
- **Fonctions principales** :
  - `nouveaucompte()` : Crée un nouveau compte.
  - `chercher()` : Recherche un compte par numéro ou nom.
  - `transact()` : Gère les transactions (dépôt/retrait).
  - `supprimer()` : Supprime un compte.
  - `menu()` : Affiche le menu principal.

## Comment Utiliser
1. **Compilation** :
   ```bash
   gcc ./src/standalone-bank-management-system.c -o standalone-bank-management-system
   ```
2. **Exécution** :
   ```bash
   ./src/standalone-bank-management-system.c
   ```

3. **Navigation** :
   Suivez les instructions du menu pour effectuer les opérations souhaitées.

## Exemple de Sortie
```
******** BIENVENU DANS LE MENU PRINCIPALE *********

1. Créer un nouveau compte
2. Voir les informations d'un compte
3. Transactions
4. Supprimer un compte
5. Quitter

Entrer votre choix : 1
```

## Fichiers Inclus
- `standalone-bank-management-system.c` : Code source du projet.
- `record.dat` : Fichier binaire pour stocker les données des comptes.

## Auteur
GARHOUM Hafid
Année Universitaire : 2022-2023

## Licence
Ce projet est open-source et disponible pour des fins éducatives.
