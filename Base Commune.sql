DROP TABLE Choisir;
DROP TABLE Service;
DROP TABLE Comptabilite;
DROP TABLE Servir;
DROP TABLE Client;
DROP TABLE Manipuler;
DROP TABLE Employe;
DROP TABLE Fournir;
DROP TABLE Produits;
DROP TABLE Fournisseurs;
CREATE TABLE Fournisseurs(
Code_F NUMBER ,
Localisation VARCHAR2(50 char) ,
Num_tel NUMBER UNIQUE,
Type_P VARCHAR2(50 char),
Prix FLOAT,
CONSTRAINT Fournisseurs_pk PRIMARY KEY(Code_F)
);
CREATE TABLE Produits(
Code_abar VARCHAR2(13 ) ,
Nom VARCHAR2(50 char) ,
Type_P VARCHAR2(50 char) ,
Quantite int,
Prix FLOAT,
CONSTRAINT Produits_pk PRIMARY KEY(Code_abar)
);
CREATE TABLE Fournir(
Produit VARCHAR2(13),
Fournisseur NUMBER,
CONSTRAINT Fournir_Produit_fk Foreign KEY(Produit) REFERENCES Produits(Code_abar),
CONSTRAINT Fournir_Fournisseur_fk Foreign KEY(Fournisseur) REFERENCES Fournisseurs(Code_F),
CONSTRAINT Fournir_Produit_Fournissuer_pk Primary key(Produit,Fournisseur)

);
CREATE TABLE Employe(
CIN NUMBER,
Num_tel NUMBER UNIQUE,
Nom VARCHAR2 (50 char),
Prenom VARCHAR2 (50 char),
Adresse VARCHAR2(50 char),
Role VARCHAR2(50 char),
CONSTRAINT Employe_pk PRIMARY KEY(CIN)
);
CREATE TABLE Manipuler(
Prod VARCHAR2(13 ),
Emp NUMBER,
CONSTRAINT Manipuler_Produit_fk Foreign KEY(Prod) REFERENCES Produits(Code_abar),
CONSTRAINT Manipuler_Employe_fk Foreign KEY(Emp) REFERENCES Employe(CIN),
CONSTRAINT Manipuler_Prod_Fmp_pk Primary key(Prod,Emp)
);
CREATE TABLE Client(
Code_C NUMBER,
Num_tel NUMBER UNIQUE,
Nom VARCHAR2 (50 char),
Prenom VARCHAR2 (50 char),
Adresse_Mail VARCHAR2(50 char),
Date_RDV DATE,
S_Attribue NUMBER,
CONSTRAINT Client_pk PRIMARY KEY(Code_C)
);
CREATE TABLE Servir(
Cli NUMBER,
Emp NUMBER,
CONSTRAINT Servir_Client_fk Foreign KEY(Cli) REFERENCES Client(Code_C),
CONSTRAINT Servir_Employe_fk Foreign KEY(Emp) REFERENCES Employe(CIN),
CONSTRAINT Servir_Cli_Emp_pk Primary KEY(Cli,Emp)
);
CREATE TABLE Comptabilite(
Code_Fact NUMBER,
Categorie VARCHAR2(50 char),
Date_Paiement DATE,
Somme FLOAT,
Descriptions VARCHAR2(50 char),
CIN_Tresorier NUMBER,
CONSTRAINT Comptabilite_pk PRIMARY KEY(Code_Fact),
CONSTRAINT Comptabilite_Employe_fk Foreign KEY(CIN_Tresorier) REFERENCES Employe(CIN)
);
CREATE TABLE Service(
Code_S NUMBER,
Type_S VARCHAR2(50 char),
Descriptions VARCHAR2(50 char),
Prix FLOAT,
CONSTRAINT Service_pk PRIMARY KEY(Code_S)
);
CREATE TABLE Choisir(
Serv NUMBER,
Cli NUMBER,
CONSTRAINT Choisir_Client_fk Foreign KEY(Cli) REFERENCES Client(Code_C),
CONSTRAINT Choisir_Service_fk Foreign KEY(Serv) REFERENCES Service(Code_S),
CONSTRAINT Choisir_Service_Client_pk Primary KEY(Serv,Cli)
);