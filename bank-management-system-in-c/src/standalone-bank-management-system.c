#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
int i,j;
int main_exit;
void menu();
struct date
{
    int jour,mois,annee;
};
struct Client{

    char nom[60];
    int acc_no,age;
    char adresse[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt; // amount
    struct date dob; // date of birth
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

void fordelay(int j)// effet de retard
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void nouveaucompte()
{
    int choix;
    FILE *ptr;

    ptr=fopen("record.dat","w+");
    account_no:
    system("cls||clear");
    printf("\t\t\t********* AJOUT ***********");
    printf("\n\n\nEntrer la date d\'aujourd\'hui (jj/mm/aaaa):");
    scanf("%d/%d/%d",&add.deposit.jour,&add.deposit.mois,&add.deposit.annee);
    printf("\nEntrer le numero du compte:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Le numero entré est déja utilisé !");
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

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);

    fclose(ptr);
    printf("\nCompte créé avec succès!");
    add_invalid:
    printf("\n\n\n\t\tEntrer 1 pour afficher le menu principal et 0 pour quitter:");
    scanf("%d",&main_exit);
    system("cls||clear");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close(1);
    else
        {
            printf("\nInvalide!\a");
            goto add_invalid;
        }
}

void transact(void)
{   int choix,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Entrer le numero du compte bancaire du client :");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"A terme1")==0||strcmpi(add.acc_type,"A terme2")==0||strcmpi(add.acc_type,"A terme3")==0)
                {
                    printf("\a\a\a\n\nVOUS NE POUVEZ PAS DEPOSER OU RETIRER DE L'ARGENT DANS LES COMPTES A TERME!!!!!");
                    fordelay(1000000000);
                    system("cls||clear");
                    menu();

                }
                printf("\n\nVous voulez faire un(e))\n1.Depot d'argent'\n2.Retraite d'argent'?\n\nEntrer votre choix(1 pour le depot et 2 pour la retraite):");
                scanf("%d",&choix);
                if (choix==1)
                {
                    printf("Entrer le montant a deposer :DH ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);
                    printf("\n\nDepot avec success!");
                }
                else
                {
                    printf("Entrer le montant que vous voulez retirer :DH  ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);
                    printf("\n\nReatrait avec succes!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nCompte non trouvé !!");
       transact_Invalide:
      printf("\n\n\nEntrer 0 pour reesayer,1 pour revenir au menu principale et 2 pour Quitter:");
      scanf("%d",&main_exit);
      system("cls||clear");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close(1);
    else
    {
        printf("\nInvalide!");
        goto transact_Invalide;
    }

   }
   else
   {
       printf("\nEntrer 1 pour afficher le menu principal et 0 pour quitter:");
        scanf("%d",&main_exit);
        system("cls||clear");
        if (main_exit==1)
            menu();
        else
            close(1);
   }

}
void supprimer(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Entrer le numero du compte bancaire que vous voulez supprimer :");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);

        else
            {test++;
            printf("\nCompte supprimé avec succes !\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nCompte non trouvé!!\a\a\a");
            supprimer_Invalide:
              printf("\nEntrer 0 pour reesayer,1 pour revenir au menu principale et 2 pour Quitter:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close(0);
                else if(main_exit==0)
                    supprimer();
                else
                    {printf("\nInvalide!\a");
                    goto supprimer_Invalide;}
        }
    else
        {printf("\nEntrer 1 pour afficher le menu principal et 0 pour quitter:");
        scanf("%d",&main_exit);
        system("cls||clear");
        if (main_exit==1)
            menu();
        else
            close(0);
        }

}

void chercher(void)
{
    FILE *ptr;
    int test=0,rate;
    int choix;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Vous voulez faire la recherche par\n1.numero du compte\n2.nom\nEntrer votre choix:");
    scanf("%d",&choix);
    if (choix==1)
    {   printf("Entrer le numero du compte:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls||clear");
                test=1;

                printf("\nNumero du compte.:%d\nnom:%s \nDOB:%d/%d/%d \nAge:%d \nAdresse:%s \nCNI:%s \nNumero de telephone:%.0lf \nType Of Account:%s \nMontant depose:$ %.2f \nDate de Depot:%d/%d/%d\n\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);
            }
        }
    }
    else if (choix==2)
    {   printf("Enter the nom:");
        scanf("%s",&check.nom);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.nom,&add.dob.jour,&add.dob.mois,&add.dob.annee,&add.age,add.adresse,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.jour,&add.deposit.mois,&add.deposit.annee)!=EOF)
        {
            if(strcmpi(add.nom,check.nom)==0)
            {   system("cls||clear");
                test=1;
                printf("\nNumero de compte:%d\nnom:%s \nDOB:%d/%d/%d \nAge:%d \nAdresse:%s \nCNI:%s \nNumero de telephone:%.0lf \nType de compte:%s \nMontant depose:$%.2f \nDate de Depot%d/%d/%d\n\n",add.acc_no,add.nom,add.dob.jour,add.dob.mois,add.dob.annee,add.age,add.adresse,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.jour,add.deposit.mois,add.deposit.annee);
            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls||clear");
            printf("\ncompte no trouvé!!\a\a\a");
            chercher_Invalide:
              printf("\nEntrer 0 pour reesayer,1 pour revenir au menu principale et 2 pour quitter:");
              scanf("%d",&main_exit);
              system("cls||clear");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close(1);
                else if(main_exit==0)
                    chercher();
                else
                    {
                        system("cls||clear");
                        printf("\nInvalide!\a");
                        goto chercher_Invalide;}
        }
    else
        {printf("\nEntrer 1 pou aller au menu principale et 0 pour quitter:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls||clear");
            menu();
        }

        else
           {

             system("cls||clear");
            close(0);
            }

}
void menu(void)
{   int choix;
    system("cls||clear");
    system("color 2");
    printf("\n\n\t\t\tSYSTEME DE GESTION BANCAIRE");
    printf("\n\n\n\t*********** BIENVENU DANS LE MENU PRINCIPALE *************");
    printf("\n\n\t\t1.Creer un nouveau compte\n\t\t2.Voir les informations d'un compte\n\t\t3.Transactions\n\t\t4.Supprimer un compte\n\t\t5.Quitter\n\n\t\t Entrer votre choix :");
    scanf("%d",&choix);

    system("cls||clear");
    switch(choix)
    {
        case 1:nouveaucompte();
        break;
        case 2:chercher();
        break;
        case 3:transact();
        break;
        case 4:supprimer();
        break;
        case 5:close(0);
        break;
    }
}
int main()
{
    menu();
    return 0;
}
