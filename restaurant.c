#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct plat{
    char name[20];
    int prix;
    struct plat *next;
}plat;

typedef struct boisson{
    char jusname[20];
    int prix;
    struct boisson *next;
}boisson;

typedef struct plat_demander{
    char plat[20];
    struct plat_demander *next;
}plat_demander;

typedef struct client{
    int code ;
    char nom[20];
    char prenom[20];
    int consommation;
    int numtable;
    plat_demander *plats_demandes;
    struct client *next;
}client;

plat* insertplatdebut(plat *L,char name[],int prix){
    plat *nouv=malloc(sizeof(plat));
    strcpy(nouv->name, name);
    nouv ->prix = prix;
    L = nouv;
    return(L);
}

client* inserclientdebut(client *P,int code,char nom[],char prenom[],int consommation,int numtable){
    client *nouv=malloc(sizeof(client));
    nouv ->code = code;
    strcpy(nouv->nom, nom);
    strcpy(nouv->prenom, prenom);
    nouv->consommation = consommation;
    nouv ->numtable = numtable;
    P = nouv;
    return(P);
}

plat* inserfinplat(plat *L,char name[],int prix){
    plat *nouv=malloc(sizeof(plat));
    strcpy(nouv->name, name);
    nouv ->prix = prix;
    nouv ->next = NULL;
    plat *tmp=L;
    if(L==NULL){return(nouv);};
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nouv;
    return(L);
}

boisson* inserfinboisson(boisson *A,char jusname[],int prix){
    boisson *nouv=malloc(sizeof(boisson));
    strcpy(nouv->jusname, jusname);
    nouv ->prix = prix;
    nouv ->next = NULL;
    boisson *tmp=A;
    if(A==NULL){return(nouv);};
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nouv;
    return(A);
}

client* inserfinclient(client *P,int code,char nom[],char prenom[],int consommation,int numtable){
    client *nouv=malloc(sizeof(client));
    nouv ->code = code;
    strcpy(nouv->nom, nom);
    strcpy(nouv->prenom, prenom);
    nouv ->consommation = consommation;
    nouv ->numtable = numtable;
    nouv ->next = NULL;
    client *tmp=P;
    if(P==NULL){return(nouv);};
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nouv;
    return(P);
}

plat_demander* inserfinplatdemander(plat_demander *C,char platprixname[]){
    plat_demander *nouv=malloc(sizeof(plat_demander));
    strcpy(nouv->plat, platprixname);
    nouv ->next = NULL;
    plat_demander *tmp=C;
    if(C==NULL){return(nouv);};
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nouv;
    return(C);
}

void afficheplate(plat *L){
    plat *tmp=L;
    printf("================================================\n");
    printf("|        Bienvenue au Solaire of Astora        |\n");
    printf("|              Menu du Restaurant              |\n");
    printf("|                   (plat)                     |\n");
    printf("================================================\n");
    printf("| %-20s | %-10s |\n", "Nom du plat", "Prix (dh)");
    printf("================================================\n");
    while(tmp!=NULL){
        printf("| %-20s | %-10d |\n", tmp->name, tmp->prix);
        tmp=tmp->next;
    }
    printf("================================================\n");
}

void afficheboisson(boisson *A){
    boisson *tmp=A;
    printf("================================================\n");
    printf("|        Bienvenue au Solaire of Astora        |\n");
    printf("|              Menu du Restaurant              |\n");
    printf("|                (boisson)                     |\n");
    printf("================================================\n");
    printf("| %-20s | %-10s |\n", "Nom du boisson", "Prix (dh)");
    printf("================================================\n");
    while(tmp!=NULL){
        printf("| %-20s | %-10d |\n", tmp->jusname, tmp->prix);
        tmp=tmp->next;
    }
    printf("================================================\n");
}


void afficheclient(client *P){
    client *tmp = P;

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s | %-15s | %-15s |\n", "Code", "Nom du client", "Prenom du client", "Consommation", "Numero de la table");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    while(tmp != NULL){
        printf("| %-20d | %-20s | %-20s | %-15d | %-15d |\n", tmp->code, tmp->nom, tmp->prenom, tmp->consommation, tmp->numtable);
        tmp = tmp->next;
    }

    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void afficheclient_plats(client *P, plat_demander *C) {
    client *tmp = P;
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-20s | %-40s |\n", "Code", "Nom", "Prenom", "Plats demandes");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    while (tmp != NULL) {
        printf("| %-10d | %-20s | %-20s |", tmp->code, tmp->nom, tmp->prenom);
        plat_demander *plats_tmp = tmp->plats_demandes;
        if (plats_tmp != NULL) {
            printf(" %s", plats_tmp->plat);
            plats_tmp = plats_tmp->next;
        }
        while (plats_tmp != NULL) {
            printf(", %s", plats_tmp->plat);
            plats_tmp = plats_tmp->next;
        }
        printf("\n");
        tmp = tmp->next;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

plat* rechercheplat(plat *L,char name[]){
    plat *tmp = L;
    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return NULL;
}

boisson* rechercheboisson(boisson *A,char jusname[]){
    boisson *tmp = A;
    while (tmp != NULL) {
        if (strcmp(tmp->jusname, jusname) == 0) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return NULL;
}

client* rechercheclient(client *P,int code){
    client *tmp = P;
    while (tmp != NULL) {
        if (tmp->code == code) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return NULL;
}

plat* suppocplat(plat* L, char name[]) {
    plat *tmp = L, *stmp;
    if (L == NULL) {
        printf("Liste de plats vide\n");
        return NULL;
    }
    if (strcmp(L->name, name) == 0) {
        L = L->next;
        free(tmp);
        return L;
    }
    stmp = tmp->next;
    while (stmp != NULL && strcmp(stmp->name, name) != 0) {
        tmp = stmp;
        stmp = stmp->next;
    }
    if (stmp != NULL) {
        tmp->next = stmp->next;
        free(stmp);
        return L;
    } else {
        printf("Plat n'existe pas\n");
        return L;
    }
}

boisson* suppocboisson(boisson* A, char jusname[]) {
    boisson *tmp = A, *stmp;
    if (A == NULL) {
        printf("Liste de plats vide\n");
        return NULL;
    }
    if (strcmp(A->jusname, jusname) == 0) {
        A = A->next;
        free(tmp);
        return A;
    }
    stmp = tmp->next;
    while (stmp != NULL && strcmp(stmp->jusname, jusname) != 0) {
        tmp = stmp;
        stmp = stmp->next;
    }
    if (stmp != NULL) {
        tmp->next = stmp->next;
        free(stmp);
        return A;
    } else {
        printf("Plat n'existe pas\n");
        return A;
    }
}

client* suppocclient(client* P, int code) {
    client *tmp = P, *stmp;
    if (P == NULL) {
        printf("Liste de clients vide\n");
        return NULL;
    }
    if (P->code==code) {
        P= P->next;
        free(tmp);
        return P;
    }
    stmp = tmp->next;
    while (stmp != NULL && stmp->code != code) {
        tmp = stmp;
        stmp = stmp->next;
    }
    if (stmp != NULL) {
        tmp->next = stmp->next;
        free(stmp);
        return P;
    } else {
        printf("client n'existe pas\n");
        return P;
    }
}


plat* modifieprixplat(plat *L,char name[],int prix){
    plat *tmp = L;
    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            tmp->prix = prix;
            return(L);
        }
        tmp = tmp->next;
    }
    return NULL;
}

boisson* modifieprixboisson(boisson *A,char jusname[],int prix){
    boisson *tmp = A;
    while (tmp != NULL) {
        if (strcmp(tmp->jusname, jusname) == 0) {
            tmp->prix = prix;
            return(A);
        }
        tmp = tmp->next;
    }
    return NULL;
}

int rechercheplatboisssonprix(plat *L,boisson *A,char platprixname[]){
    int consommation=0;
    plat *tmp = rechercheplat(L,platprixname);
    boisson *ptmp = rechercheboisson(A,platprixname);
    if(tmp == NULL && ptmp == NULL){
        printf("Ce plat/boison n'existe pas dans le menu.\n");
        sleep(3);
        system("clear");
    }else if(tmp!=NULL){
        consommation+=tmp->prix;
    }else if(ptmp!=NULL){
        consommation+=ptmp->prix;
    }
    return(consommation);
}

client *modifieconsomprix(client *P,int code,int total_consom){
    client *tmp = P;
    while (tmp != NULL) {
        if (tmp->code == code) {
            tmp->consommation = total_consom;
            return(P);
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    plat *L=NULL;
    client *P=NULL;
    plat_demander *C=NULL;
    boisson *A=NULL;
    int powproject;
    int nbrplat,prix,deletnameplatnbr,deletnameboissonnbr,addnamenbr,mdprixplatnbr,nbrplatdemander;
    int addclientnbr,code,consommation = 0,numtable,deletclientnbr,total_consom=0;
    int i,j,k,l,m,n,func_choix,vrf;
    char name[20];
    char jusname[20];
    char decision;
    char deletname[20];
    char platprixname[20];
    printf("\033[1;36m");
    printf("+==================================================================+\n");
    printf("\033[0m");
    printf("|              Bienvenue a l'interface du serveur !                |\n");
    printf("|               Cette interface est reservee pour :                |\n");
    printf("\033[1;32m");
    printf("|                   += ajouter des plats au menu                   |\n");
    printf("|                   += supprimer un ensemble de plats              |\n");
    printf("|                   += ajouter et supprimer des clients            |\n");
    printf("\033[0m");
    printf("+==================================================================+\n");
    printf("\033[1;31m");
    printf("|       !!!-> Actuellement, aucun plat n'existe dans le menu       |\n");
    printf("\033[0m");
    printf("|                                                                  |\n");
    printf("|-> Voulez-vous ajouter des plats au menu ou quitter l'interface ? |\n");
    printf("|                                                                  |\n");
    printf("\033[1;32m");
    printf("|            -> 1 pour ajouter au menu des plats                   |\n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("|            -> 2 pour ajouter au menu des boisson                 |\n");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("|            -> 3 pour quitter le program                          |\n");
    printf("\033[0m");
    printf("\033[1;36m");
    printf("+==================================================================+\n");
    printf("\033[0m");
    printf("\n \n decision : ");
    vrf = scanf("%d",&powproject);
    getchar();
    if(powproject==1){
        printf("donner le nombre de plat : ");
        scanf("%d",&nbrplat);
        getchar();
        system("cls");
        for (i = 0; i < nbrplat; i++) {
            printf("nom du plat : ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("prix du plat : ");
            scanf("%d", &prix);
            getchar();
            L = inserfinplat(L, name, prix);
            system("cls");
        }
    }else if(powproject==2){
        printf("donner le nombre de boisson : ");
        scanf("%d",&nbrplat);
        getchar();
        system("cls");
        for (i = 0; i < nbrplat; i++) {
            printf("nom du boisson : ");
            fgets(jusname, sizeof(jusname), stdin);
            jusname[strcspn(jusname, "\n")] = '\0';
            printf("prix du boisson : ");
            scanf("%d", &prix);
            getchar();
            A = inserfinboisson(A, jusname, prix);
            system("cls");
        }
    }else if(powproject==3){
        printf("\nfin du programe !");
        return(0);
    }else if(powproject >3 || powproject <1 || vrf == 0){
        printf("\n choix refuser !");
        return(0);
    }
    while(1){
        afficheplate(L);
        printf("\n");
        printf("\n");
        printf("====================================================================================================================\n");
        printf("####################################################################################################################\n");
        printf("====================================================================================================================\n");
        printf("\n");
        printf("\n");
        afficheboisson(A);
        printf("\n");
        printf("0-quitter le program ?\n");
        //fonction du menu plat
        printf("1-supprimer un plat du menu ?\n");
        printf("2-ajouter un plat au menu ?\n");
        printf("3-modifier le prix du plat ?\n");
        //fonction du menu boisson
        printf("4-supprimer un boisson du menu ?\n");
        printf("5-ajouter un boisson au menu ?\n");
        printf("6-modifier le prix d'un boisson ?\n");
        //fonction de la list client
        printf("7-ajouter un client ?\n");
        printf("8-supprimer un client ?\n");
        printf("9-afficher la list des clients ?\n");
        printf("10-ajouter les plats demander par les clients ?\n");
        printf("decision : ");
        vrf = scanf("%d",&func_choix);
        getchar();
        if(func_choix>10 || func_choix<0 || vrf == 0){
            printf("choix non valable \n");
            sleep(2);
            return (0);
        }
        if(func_choix == 0){
            system("cls");
            afficheplate(L);
            printf("\n \n");
            afficheclient(P);
            return(0);
//----------------------->fontionnement des fonction du menu plat :
        }else if(func_choix == 1){
            printf("\nvoulez vous vraimment supprimmer un plat ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y') {
                printf("\ncombient de plat voulez vous supprimer ? : ");
                scanf("%d",&deletnameplatnbr);
                getchar();
                for(j=0;j<deletnameplatnbr;j++){
                    printf("Donnez le nom du plat à supprimer : ");
                    fgets(deletname, sizeof(deletname), stdin);
                    deletname[strcspn(deletname, "\n")] = '\0';
                    if (rechercheplat(L, deletname) == NULL) {
                        printf("Ce plat n'existe pas dans le menu.\n");
                        sleep(3);
                        system("cls");
                    }else{
                        L = suppocplat(L, deletname);
                    }
                }
                system("cls");
            } else if (decision == 'n' || decision == 'N') {
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 2){  //la sequence ou le server demande d'ajouter un ou des plats
            printf("\nvoulez vous vraimment ajouter un plat au menu ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y'){
                printf("\ncombient de plat voulez vous ajouter ? : ");
                scanf("%d",&addnamenbr);
                getchar();
                for (k=0;k<addnamenbr;k++){
                    char name[20];
                    printf("Nom du plat : ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    if (rechercheplat(L, name) != NULL) {
                        printf("Ce plat existe deja dans le menu.\n");
                        sleep(3);
                        system("cls");
                    } else {
                        printf("Prix du plat : ");
                        scanf("%d", &prix);
                        getchar();
                        L = inserfinplat(L, name, prix);
                    }
                }
                system("cls");
            }else if (decision == 'n' || decision == 'N'){
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 3){
            printf("\nvoulez vous vraimment modifier le prix d'un plat ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y'){
                printf("\ncombient de plat voulez vous modifier leurs prix  ? : ");
                scanf("%d",&mdprixplatnbr);
                getchar();
                for (l=0;l<mdprixplatnbr;l++){
                    char name[20];
                    printf("Nom du plat : ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    if (rechercheplat(L, name) == NULL) {
                        printf("Ce plat n'existe pas dans le menu.\n");
                        sleep(3);
                        system("cls");
                    } else {
                        printf("nouveau Prix du plat : ");
                        scanf("%d", &prix);
                        getchar();
                        L = modifieprixplat(L, name, prix);
                    }
                }
                system("cls");
            }else if (decision == 'n' || decision == 'N'){
                system("cls");
            }else{
                system("cls");
            }
//----------------------->fontionnement des fonction du menu boisson :
        }else if(func_choix == 4){
            printf("\nvoulez vous vraimment supprimmer un boisson ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y') {
                printf("\ncombient de boisson voulez vous supprimer ? : ");
                scanf("%d",&deletnameboissonnbr);
                getchar();
                for(j=0;j<deletnameboissonnbr;j++){
                    printf("Donnez le nom du plat à supprimer : ");
                    fgets(deletname, sizeof(deletname), stdin);
                    deletname[strcspn(deletname, "\n")] = '\0';
                    if (rechercheboisson(A, deletname) == NULL) {
                        printf("Ce boisson n'existe pas dans le menu.\n");
                        sleep(3);
                        system("cls");
                    }else{
                        A = suppocboisson(A,deletname);
                    }
                }
                system("cls");
            } else if (decision == 'n' || decision == 'N') {
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 5){
            printf("\nvoulez vous vraimment ajouter un boisson au menu ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y'){
                printf("\ncombient de boisson voulez vous ajouter ? : ");
                scanf("%d",&addnamenbr);
                getchar();
                for (k=0;k<addnamenbr;k++){
                    printf("Nom du boisson : ");
                    fgets(jusname, sizeof(jusname), stdin);
                    jusname[strcspn(jusname, "\n")] = '\0';
                    if (rechercheboisson(A, jusname) != NULL) {
                        printf("Ce boisson existe deja dans le menu.\n");
                        sleep(3);
                       system("cls");
                    } else {
                        printf("Prix du boisson : ");
                        scanf("%d", &prix);
                        getchar();
                        A = inserfinboisson(A, jusname, prix);
                    }
                }
                system("cls");
            }else if (decision == 'n' || decision == 'N'){
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 6){
            printf("\nvoulez vous vraimment modifier le prix d'un boisson ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y'){
                printf("\ncombient de boisson voulez vous modifier leurs prix  ? : ");
                scanf("%d",&mdprixplatnbr);
                getchar();
                for (l=0;l<mdprixplatnbr;l++){
                    printf("Nom du boisson : ");
                    fgets(jusname, sizeof(jusname), stdin);
                    jusname[strcspn(jusname, "\n")] = '\0';
                    if (rechercheboisson(A, jusname) == NULL) {
                        printf("Ce boisson n'existe pas dans le menu.\n");
                        sleep(3);
                       system("cls");
                    } else {
                        printf("nouveau Prix du boisson : ");
                        scanf("%d", &prix);
                        getchar();
                        A = modifieprixboisson(A, jusname, prix);
                    }
                }
                system("cls");
            }else if (decision == 'n' || decision == 'N'){
                system("cls");
            }else{
                system("cls");
            }

//----------------------->fontionnement des fonction de lalist client :
        }else if(func_choix == 7){
            printf("\nvoulez vous vraimment ajouter un client ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y') {
                printf("\ncombient de client voulez vous ajouter ? : ");
                scanf("%d",&addclientnbr);
                getchar();
                for (m=0;m<addclientnbr;m++){
                    char nom[20];
                    char prenom[20];
                    printf("le code du client : ");
                    scanf("%d",&code);
                    getchar();
                    if (rechercheclient(P, code) != NULL) {
                        printf("Ce client existe deja dans la list.\n");
                        sleep(3);
                        system("cls");
                    } else {
                        printf("Nom du client : ");
                        fgets(nom, sizeof(nom), stdin);
                        nom[strcspn(nom, "\n")] = '\0';
                        printf("Prenom du client : ");
                        fgets(prenom, sizeof(prenom), stdin);
                        prenom[strcspn(prenom, "\n")] = '\0';
                        printf("le numero de table du client : ");
                        scanf("%d",&numtable);
                        getchar();
                        P = inserfinclient(P, code, nom, prenom, consommation, numtable);
                    }
                }
                system("cls");
                afficheclient(P);
                printf("\n");
                printf("Press Enter to continue...");
                fflush(stdout);
                getchar();
                system("cls");
            } else if (decision == 'n' || decision == 'N') {
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 8){
            printf("\nvoulez vous vraimment supprimer un client ? (y/n) : ");
            scanf("%c",&decision);
            getchar();
            if (decision == 'y' || decision == 'Y') {
                printf("\ncombient de client voulez vous supprimer ? : ");
                scanf("%d",&deletclientnbr);
                getchar();
                for (n=0;n<deletclientnbr;n++){
                    printf("le code du client : ");
                    scanf("%d",&code);
                    getchar();
                    if (rechercheclient(P, code) == NULL) {
                        printf("Ce client n'existe pas dans la list.\n");
                        sleep(3);
                        system("cls");
                    } else {
                        P=suppocclient(P,code);
                    }
                }
                system("cls");
                afficheclient(P);
                printf("\n");
                printf("Press Enter to continue...");
                fflush(stdout);
                getchar();
                system("cls");
            } else if (decision == 'n' || decision == 'N') {
                system("cls");
            }else{
                system("cls");
            }
        }else if(func_choix == 9){
            system("cls");
            printf("list des clients actuelle : \n");
            afficheclient(P);
            printf("\n \n  ");
            getchar();
            printf("====================================================================================================================\n");
            printf("####################################################################################################################\n");
            printf("====================================================================================================================\n");
            printf("\n \n ");
            getchar();
        }else if(func_choix == 10){
            printf("\nVoulez-vous vraiment ajouter les plats demandes par un client ? (y/n) : ");
            scanf("%c", &decision);
            getchar();
            if (decision == 'y' || decision == 'Y') {
                printf("\nCombien de plats sont demandes par le client ? : ");
                scanf("%d", &nbrplatdemander);
                getchar();
                printf("Entrez le code du client pour qui ce plat est demande : ");
                scanf("%d", &code);
                getchar();
                client *client_tmp = rechercheclient(P,code);
                if (client_tmp == NULL) {
                    printf("Ce client n'existe pas.\n");
                    sleep(3);
                    system("cls");
                }else {
                    for (j = 0; j < nbrplatdemander; j++){
                        printf("Donnez le nom du plat/boisson demande : ");
                        fgets(platprixname, sizeof(platprixname), stdin);
                        platprixname[strcspn(platprixname, "\n")] = '\0';
                        client_tmp->plats_demandes = inserfinplatdemander(client_tmp->plats_demandes, platprixname);
                        total_consom += rechercheplatboisssonprix(L, A, platprixname);
                        modifieconsomprix(P, code, total_consom);
                    }
                }
                system("cls");
                afficheclient_plats(P, C);
                printf("\n");
                printf("Press Enter to continue...");
                fflush(stdout);
                getchar();
                system("cls");
            } else if (decision == 'n' || decision == 'N') {
                system("cls");
    		}else{
                system("cls");
            }
        }
    }
    return 0;
}
