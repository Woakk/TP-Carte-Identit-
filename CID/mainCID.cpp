#include <stdio.h>
#include <string>
#include <string.h>

#define TAILLE 255

typedef struct birth {
	int n_day = 1;
	int n_month = 1;
	int n_year = 1;
}birth;

typedef struct address {
	char* str_street;
	int n_postal = 0;
	char* str_town;
}address;

typedef enum class gender { M, Mme }civ;

typedef struct carteid {
	int n_id;
	civ E_civ = {};
	char* str_surname;
	char* str_name;
	birth* t_date;
	address* t_address;
}carteid;

void Date(birth* t_date);
void Adresse(address* t_address);
void Genre(civ* E_civ);
void CID(carteid* t_carteid);
void Affichage(birth* t_date, address* t_address, civ* E_civ, carteid* t_carteid);

int main() {

	birth* t_date;
	t_date = nullptr;
	t_date = (birth*)malloc(TAILLE * sizeof(birth));
	address* t_address;
	t_address = (address*)malloc(TAILLE * sizeof(address));
	carteid* t_carteid;
	t_carteid = nullptr;
	t_carteid = (carteid*)malloc(TAILLE * sizeof(carteid));
	civ* E_civ;
	E_civ = (civ*)malloc(TAILLE * sizeof(civ));
	E_civ = nullptr;



	Date(t_date);
	Adresse(t_address);
	CID(t_carteid);
	Genre(E_civ);
	Affichage(t_date, t_address, E_civ, t_carteid);

	return 0;
}

void Date(birth* t_date) {
	int n_day = 0;
	int n_month = 0;
	int n_year = 0;
	int i = 0;
	do {
		printf_s("Quel est le jour de votre naissance ? \n");
		scanf_s("%d", &n_day);
		if (n_day <= 0) {
			printf_s("Quel est le jour de votre naissance ? \n");
			scanf_s("%d", &n_day);
		}
		printf_s("Quel est le mois de votre naissance ? \n");
		scanf_s("%d", &n_month);
		if (n_month <= 0) {
			printf_s("Quel est le mois de votre naissance ? \n");
			scanf_s("%d", &n_month);
		}
		printf_s("Quelle est l'année de votre naissance ? \n");
		scanf_s("%d", &n_year);
		if (n_year <= 0) {
			printf_s("Quelle est l'année de votre naissance ? \n");
			scanf_s("%d", &n_year);
		}
		t_date[i].n_day = n_day;
		t_date[i].n_month = n_month;
		t_date[i].n_year = n_year;
		i++;
	} while (i != 1);
};

void Adresse(address* t_address) {
	address str_ok;
	int n_postal = 0;
	for (int i = 0; i < 1; i++) {
		printf_s("Quel est le nom de votre rue ? \n");
		str_ok.str_street = (char*)malloc(TAILLE * sizeof(char));
		if (str_ok.str_street != nullptr) {
			scanf_s("%s", str_ok.str_street, TAILLE);
		}
		printf_s("Quel est votre code postal ? \n");
		scanf_s("%d", &n_postal);
		printf_s("Quel est le nom de votre ville ? \n");
		str_ok.str_town = (char*)malloc(TAILLE * sizeof(char));
		if (str_ok.str_town != nullptr) {
			scanf_s("%s", str_ok.str_town, TAILLE);
		}
		t_address[i].str_street = str_ok.str_street;
		t_address[i].n_postal = n_postal;
		t_address[i].str_town = str_ok.str_town;
		i++;
	}
};

carteid ok;
int n_id = 0;
int i = 0;

void CID(carteid* t_cid) {
	for (i; i < 1; i++) {
		printf_s("Quel est votre ID ? \n");
		scanf_s("%d", &n_id);
		printf_s("Quel est votre Nom? \n");
		ok.str_surname = (char*)malloc(TAILLE * sizeof(char));
		if (ok.str_surname != nullptr) {
			scanf_s("%s", ok.str_surname, TAILLE);
		}
		printf_s("Quel est votre Prenom? \n");
		ok.str_name = (char*)malloc(TAILLE * sizeof(char));
		if (ok.str_name != nullptr) {
			scanf_s("%s", ok.str_name, TAILLE);
		}
		t_cid[i].str_surname = ok.str_surname;
		t_cid[i].str_name = ok.str_name;
		t_cid[i].n_id = n_id;
		i++;
	}
};
void Affichage(birth* t_birth, address* t_address, civ* E_civ, carteid* t_cid) {
	printf_s(" %d", E_civ);
	printf_s("Votre Nom:%s / votre Prenom:%s / votre ID:%d \n", t_cid->str_surname, t_cid->str_name, t_cid->n_id);
	printf_s("Date de naissance:%d/%d/%d \n", t_birth->n_day, t_birth->n_month, t_birth->n_year);
	printf_s("Rue:%s / Adresse:%d / Ville:%s \n", t_address->str_street, t_address->n_postal, t_address->str_town);
};