
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//#include<unistd.h>
#include<conio.h>

int i,j;
int main_exit;
void menu();

struct date {
    int jour, mois, annee;
};

struct Client {
    char nom[60];
    int acc_no, age;
    char adresse[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, upd, check, rem, transaction;

void fordelay(int j) {
    int i,k;
    for(i=0;i<j;i++) k=i;
}

void nouveaucompte() {
    int choix;
    FILE *ptr;
    ptr=fopen("record.dat","w+");
account_no:
    system("cls||clear");
    printf("\t\t\t********* AJOUT ***********");
    printf("\n\n\nEntrer la date d'aujourd'hui (jj/mm/aaaa):");
    scanf("%d/%d/%d",&add.deposit.jour,&add.deposit.mois,&add.deposit.annee);
    printf("\nEntrer le numero du compte:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
           &add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,
           add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,
           &add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF) {
        if (check.acc_no==add.acc_no) {
            printf("Le numero entré est déja utilisé !");
            fordelay(1000000000);
            goto account_no;
        }
    }
    add.acc_no=check.acc_no;
    printf("\nEntrer votre nom complet:");
    scanf("%s",add.nom);
    printf("\nEntrer la date de naissance (jj/mm/aaaa):");
    scanf("%d/%d/%d",&add.dob.jour,&add.dob.mois,&add.dob.annee);
    printf("\nEntrer votre age:");
    scanf("%d",&add.age);
    printf("\nEntrer votre adresse:");
    scanf("%s",add.adresse);
    printf("\nEntrer le numero de votre carte d'identité:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEntrer le montant a deposer:DH ");
    scanf("%f",&add.amt);
    printf("\nType du compte:\n\t#Epargne\n\t#Courant\n\t#A terme1(pour 1 annee)\n\t#A terme2(pour 2 annees)\n\t#A terme3(pour 3 annees)\n\n\tEntrer ton choix:");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
        add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,
        add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,
        add.deposit.jour,add.deposit.mois,add.deposit.annee);
    fclose(ptr);
    printf("\nCompte créé avec succès!");
add_invalid:
    printf("\n\n\n\t\tEntrer 1 pour afficher le menu principal et 0 pour quitter:");
    scanf("%d",&main_exit);
    system("cls||clear");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        exit(0);
    else {
        printf("\nInvalide!\a");
        goto add_invalid;
    }
}

void menu(void) {
    int choix;
    system("cls||clear");
    system("color 2");
    printf("\n\n\t\t\tSYSTEME DE GESTION BANCAIRE");
    printf("\n\n\n\t*********** BIENVENU DANS LE MENU PRINCIPALE *************");
    printf("\n\n\t\t1.Creer un nouveau compte\n\t\t2.Voir les informations d'un compte\n\t\t3.Transactions\n\t\t4.Supprimer un compte\n\t\t5.Quitter\n\n\t\t Entrer votre choix :");
    scanf("%d",&choix);
    system("cls||clear");
    switch(choix) {
        case 1: nouveaucompte(); break;
        // case 2: chercher(); break;
        // case 3: transact(); break;
        // case 4: supprimer(); break;
        case 5: exit(0); break;
    }
}

int main() {
    menu();
    return 0;
}
