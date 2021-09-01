#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct atom_t {
	int mass_amount;
	int atom_amount;
	char *name;
} atom_t;

bool is_isotop(atom_t a, atom_t b);
bool is_isobar(atom_t a, atom_t b);
bool is_isoton(atom_t a, atom_t b);
unsigned int get_neutron(atom_t a);
char *input(char *text);

int main() {
	atom_t atom_a;
	atom_t atom_b;

	char *tmp; /* For user input */

	printf("- Atom 1 ------------------------\n");
	tmp = input("Nomor Massa\t: ");
	atom_a.mass_amount = atoi(tmp);
	free(tmp);
	tmp = input("Nama Unsur\t: ");
	atom_a.name = strdup(tmp);
	free(tmp);
	tmp = input("Nomor Atom\t: ");
	atom_a.atom_amount = atoi(tmp);
	free(tmp);

	printf("- Atom 2 ------------------------\n");
	tmp = input("Nomor Massa\t: ");
	atom_b.mass_amount = atoi(tmp);
	free(tmp);
	tmp = input("Nama Unsur\t: ");
	atom_b.name = strdup(tmp);
	free(tmp);
	tmp = input("Nomor Atom\t: ");
	atom_b.atom_amount = atoi(tmp);
	free(tmp);

	printf("\nHasil: ");

	if (is_isotop(atom_a, atom_b)) {
		printf("Isotop\n");
	} else if (is_isobar(atom_a, atom_b)) {
		printf("Isobar\n");
	} else if (is_isoton(atom_a, atom_b)) {
		printf("Isoton\n");
	} else {
		printf("Invalid.\n");
	}

	/* Free some memories */
	free(atom_a.name);
	free(atom_b.name);

	return 0;
}

bool is_isotop(atom_t a, atom_t b) {
	if (strcmp(a.name, b.name) != 0) return false;
	if (a.atom_amount != b.atom_amount) return false;
	if (a.mass_amount == b.mass_amount) return false;

	return true;
}

bool is_isobar(atom_t a, atom_t b) {
	if (strcmp(a.name, b.name) == 0) return false;
	if (a.mass_amount != b.mass_amount) return false;

	return true;
}

bool is_isoton(atom_t a, atom_t b) {
	if (strcmp(a.name, b.name) == 0) return false;

	return get_neutron(a) == get_neutron(b);
}

unsigned int get_neutron(atom_t a) {
	return a.mass_amount - a.atom_amount;
}

char *input(char *text) {
	char retval[7];
	memset(retval, 0, 7);

	printf("%s", text);
	if (fgets(retval, 7, stdin) == NULL) {
		printf("ERROR: Can't allocate memory");
		exit(1);
	}

	/* Remove newline */
	if (retval[5] == '\n') retval[5] = 0;

	return strdup(retval);
}
