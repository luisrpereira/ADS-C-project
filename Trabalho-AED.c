#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#
// MENU
void menu() {
	printf("**************************** [ REGISTO DE PACIENTES ] ******************************\n");
	printf("*                                                                                  *\n");
	printf("* \t\t1. Inserir um novo paciente                                        *\n");
	printf("* \t\t2. Listar pacientes                                                *\n");
	printf("* \t\t3. Alterar dados de um paciente                                    *\n");
	printf("* \t\t4. Pesquisar paciente por número de Utente de Saúde                *\n");
	printf("* \t\t5. Pesquisar paciente pelo primeiro nome                           *\n");
	printf("* \t\t6. Remover um paciente                                             *\n");
	printf("* \t\t0. SAIR                                                            *\n");
	printf("*                                                                           	   *\n");
	printf("*                            $ Informática Médica $                                *\n");
	printf("**************************** $ IPCA-EST 2017-2018 $ ********************************\n");
}
// ESTRUTURA PACIENTE 
typedef struct {
	int num_ut;
	char nome[100];
	char data_nasc[100];
	int num_if;
	int num_ss;
	char morada[100];
} PACIENTE;



// CASE 1 - INSERIR PACIENTES
int ins_paciente(PACIENTE N[], int n_pacientes) {
	int i = n_pacientes, n_utente = 0, aux = 0, k = 0;
	char opcao;
	FILE *listagem;
	do {
		system("cls");
		printf("[INSERIR NOVO PACIENTE]\n\n");
		do {
			printf("\tIntroduza o número de utente do paciente:");
			scanf("%i", &n_utente);
			fflush(stdin);
			if (i != 0) {
				for (k = 0; k <= i; k++) {
					if (n_utente == N[k].num_ut) {
						printf("O número de utente que introduziu já se encontra atribuído a um paciente, por favor tente novamente\n");
						aux = 1;
						break;
					}
					else aux = 0;
				}
			}
		} while (aux == 1);
		N[i].num_ut = n_utente;
		printf("\tIntroduza o nome do paciente:");
		gets(N[i].nome);
		strupr(N[i].nome);
		printf("\tIntroduza a data de nascimento do paciente:");
		gets(N[i].data_nasc);
		strupr(N[i].data_nasc);
		printf("\tIntroduza o número de identificação fiscal do paciente:");
		scanf("%i", &N[i].num_if);
		printf("\tIntroduza o número da segurança social do paciente:");
		scanf("%i", &N[i].num_ss);
		fflush(stdin);
		printf("\tIntroduza a morada do paciente:");
		gets(N[i].morada);
		strupr(N[i].morada);
		
		//Escrever info no ficheiro
		listagem = fopen("Lista Pacientes.txt", "a");
		if (listagem != NULL) {
			fprintf(listagem, "%i\n%s\n%s\n%i\n%i\n\%s\n", N[i].num_ut, N[i].nome, N[i].data_nasc, N[i].num_if, N[i].num_ss, N[i].morada);
		}
		fclose(listagem);
		i++;
		printf("\n\tDeseja introduzir mais um paciente? (s/n) :");
		scanf("%c", &opcao);
		fflush(stdin);
	} while (opcao == 's');
	printf("\n\n\t\t*Pacientes inseridos com sucesso*\n");
	system("pause > nul");
	system("cls");
	return i;
}

// CASE 2 - LISTAR PACIENTES
void listar_paciente(PACIENTE N[], int n_pacientes) {
	system("cls");
	int i;
	if (n_pacientes == 0) {
		printf("Ainda não foram introduzidos pacientes\n");
		printf("\n*Pressione uma tecla qualquer para voltar ao menu*\n");
		system("pause > nul");
		system("cls");
	}
	else {
		printf("[PACIENTES REGISTADOS]\n");
		for (i = 0; i<n_pacientes; i++) {
			printf("\nPaciente número: %i\n", N[i].num_ut);
			printf("\tNome: %s\n", N[i].nome);
			printf("\tData de nascimentos: %s\n", N[i].data_nasc);
			printf("\tNúmero de identificação fiscal: %i\n", N[i].num_if);
			printf("\tNúmero da segurança social: %i\n", N[i].num_ss);
			printf("\tMorada: %s\n", N[i].morada);
		}
		printf("\nPacientes registados: %i\n", n_pacientes);
		printf("\n\n\t\t*Listagem completa*\n");
		system("pause > nul");
		system("cls");
	}
}

//CASE 3 - ALTERAR DADOS DE UM PACIENTE 
void alterar_dados(PACIENTE N[], int n_pacientes) {
	int n_utente = 0, i = 0, aux = 0, opcao = 0, aux2 = 0, aux3 = 0, k = 0;
	char opcao2, opcao3;
	FILE *listagem;
	system("cls");
	if (n_pacientes == 0) {
		system("cls");
		printf("Ainda não foram introduzidos pacientes\n");
		printf("\n*Pressione uma tecla qualquer para voltar ao menu*\n");
		system("pause > nul");
		system("cls");
	}
	else {
		do {
			if (opcao3 == 's' && aux == 1) system("cls");
			aux = 0;
			printf("[ALTERAR DADOS DE UM PACIENTE]\n\n");
			printf("\tIntroduza o número de utente do paciente que deseja alterar dados:");
			scanf("%i", &n_utente);
			fflush(stdin);
			for (i = 0; i<n_pacientes; i++) {
				if (n_utente == N[i].num_ut) {
					system("cls");
					aux = 1;
					do {
						system("cls");
						printf("[ALTERAR DADOS DE UM PACIENTE]\n\n");
						printf("\n\t1-Paciente número: %i\n\t2-Nome: %s\n\t3-Data de nascimento: %s\n\t4-Número de identificação fiscal: %i\n\t5-Número da segurança social: %i\n\t6-Morada: %s\n", N[i].num_ut, N[i].nome, N[i].data_nasc, N[i].num_if, N[i].num_ss, N[i].morada);
						if (aux2 == 1)printf("\n\t\tCampo inválido, por favor tente novamente");
						aux2 = 0;
						printf("\n\tIntroduza o número do campo que deseja alterar:");
						scanf("%i", &opcao);
						fflush(stdin);
						switch (opcao) {
						case 1: do {
							aux3 = 0;
							printf("\n\tNúmero de utente atual: %i\n\tInsira novo número:", N[i].num_ut);
							scanf("%i", &n_utente);
							fflush(stdin);
							for (k = 0; k<n_pacientes; k++) {
								if (n_utente == N[k].num_ut) {
									printf("\n\tO número de utente que introduziu já se encontra atribuído a um paciente, por favor tente novamente\n");
									aux3 = 1;
								}
							}
							if (aux3 == 0) N[i].num_ut = n_utente;
						} while (aux3 == 1);
						break;
						case 2: printf("\n\t\tNome atual: %s\n\t\tInsira o novo nome:", N[i].nome);
							gets(N[i].nome);
							strupr(N[i].nome);
							break;
						case 3: printf("\n\t\tData de nascimento atual: %s\n\t\tInsira a nova data:", N[i].data_nasc);
							gets(N[i].data_nasc);
							strupr(N[i].data_nasc);
							break;
						case 4:	printf("\n\t\tNúmero de identificação fiscal atual: %i\n\t\tInsira o novo número:", N[i].num_if);
							scanf("%i", &N[i].num_if);
							fflush(stdin);
							break;
						case 5:	printf("\n\t\tNúmero da segurança social atual: %i\n\t\tInsira o novo número:", N[i].num_ss);
							scanf("%i", &N[i].num_ss);
							fflush(stdin);
							break;
						case 6:	printf("\n\t\tMorada atual: %s\n\t\tInsira a nova morada:", N[i].morada);
							gets(N[i].morada);
							strupr(N[i].morada);
							break;
						default:aux2 = 1;
							break;
						}
						if (aux2 == 0) {
							printf("\n\tDeseja alterar mais um campo? (s/n)");
							scanf("%c", &opcao2);
							fflush(stdin);
						}
					} while (opcao2 == 's' || aux2 == 1);
				}
			}
			if (aux == 0) {
				system("cls");
				printf("O número de utente introduzido não se encontra registado, por favor tente novamente\n\n");
			}
			if (aux2 == 0 && aux != 0) {
				printf("\n\tDeseja alterar dados de outro paciente? (s/n):");
				scanf("%c", &opcao3);
				fflush(stdin);
			}
		} while (aux != 1 || opcao3 == 's');
		
		//Substituir o ficheiro com a nova info
		listagem = fopen("Lista Pacientes.txt", "w"); 
		if (listagem != NULL) {
			for (i = 0; i<n_pacientes; i++) {
				fprintf(listagem, "%i\n%s\n%s\n%i\n%i\n\%s\n", N[i].num_ut, N[i].nome, N[i].data_nasc, N[i].num_if, N[i].num_ss, N[i].morada);
			}
			fclose(listagem);
		}
		printf("\n\t\t*Alteração executada com sucesso*");
		system("pause > nul");
		system("cls");
	}
}

//CASE 4 - PROCURAR PACIENTE PELO NÚMERO DE UTENTE
void procurar_num(PACIENTE N[], int n_pacientes) {
	int n_utente, i, aux = 0;
	char opcao;
	system("cls");
	if (n_pacientes == 0) {
		printf("Ainda não foram introduzidos pacientes\n");
		printf("\n*Pressione uma tecla qualquer para voltar ao menu*\n");
		system("pause > nul");
		system("cls");
	}
	else {
		do {
			if (opcao == 's' && aux != 0) system("cls");
			printf("[PROCURAR PACIENTE PELO NÚMERO DE UTENTE]\n\n");
			aux = 0;
			printf("\n\tIntroduza o número de utente do paciente que deseja procurar:");
			scanf("%i", &n_utente);
			fflush(stdin);
			for (i = 0; i<n_pacientes; i++) {
				if (n_utente == N[i].num_ut) {
					system("cls");
					printf("\nPaciente número: %i\n", N[i].num_ut);
					printf("\tNome: %s\n", N[i].nome);
					printf("\tData de nascimentos: %s\n", N[i].data_nasc);
					printf("\tNúmero de identificação fiscal: %i\n", N[i].num_if);
					printf("\tNúmero da segurança social: %i\n", N[i].num_ss);
					printf("\tMorada: %s\n", N[i].morada);
					aux = 1;
					fflush(stdin);
				}
			}
			if (aux == 0) {
				system("cls");
				printf("\n\tO número de utente inserido não se encontra registado, por favor tente novamente\n\n");
			}
			if (aux == 1) {
				printf("\nDeseja procurar outro paciente? (s/n):");
				scanf("%c", &opcao);
				fflush(stdin);
			}
		} while (aux == 0 || opcao == 's');
		printf("\n\t\t*PACIENTES ENCONTRADOS COM SUCESSO*");
		system("pause > nul");
		system("cls");
	}
}


//CASE 5 - PROCURAR PELO PRIMEIRO NOME
void procurar_nome(PACIENTE N[], int n_pacientes) {
	int i = 0, k, cont = 0, aux;
	char  nome[200], opcao;
	system("cls");
	if (n_pacientes == 0) {
		printf("Ainda não foram introduzidos pacientes\n");
		printf("\n*Pressione uma tecla qualquer para voltar ao menu*\n");
		system("pause > nul");
		system("cls");
	}
	else {
		do {
			if (opcao == 's' && aux != 0) system("cls");
			printf("[PROCURAR PACIENTE PELO PRIMEIRO NOME]\n\n");
			aux = 0;
			printf("\n\tIntroduza o nome que pretende procurar?");
			gets(nome);
			strupr(nome);
			if (strlen(nome) == 0) {
				system("cls");
				printf("\n\t\tNome inválido, por favor tente novamente\n");
			}
			else {
				for (i = 0; i<n_pacientes; i++) {
					cont = 0;
					for (k = 0; k<strlen(nome); k++) {
						if (N[i].nome[k] == nome[k]) {
							cont++;
						}
					}
					if (cont == strlen(nome)) {
						printf("\nPaciente número: %i\n", N[i].num_ut);
						printf("\tNome: %s\n", N[i].nome);
						printf("\tData de nascimentos: %s\n", N[i].data_nasc);
						printf("\tNúmero de identificação fiscal: %i\n", N[i].num_if);
						printf("\tNúmero da segurança social: %i\n", N[i].num_ss);
						printf("\tMorada: %s\n", N[i].morada);
						aux = 1;
					}
				}
				if (aux == 0) {
					system("cls");
					printf("\n\tNão foram encontrados paciente com esse nome, por favor tente novamente\n\n");
				}
				if (aux == 1) {
					printf("\nDeseja procurar outro paciente? (s/n):");
					scanf("%c", &opcao);
					fflush(stdin);
				}
			}
		} while (aux == 0 || opcao == 's');
		printf("\n\t\t*PACIENTES ENCONTRADOS COM SUCESSO*");
		system("pause > nul");
		system("cls");
	}
}

//CASE 6 - REMOVER PACIENTE 
int remover_paciente(PACIENTE N[], int n_pacientes) {
	int n_utente, i = 0, c = 0, aux = 0, aux2 = 0;
	char opcao;
	FILE *listagem;
	system("cls");
	if (n_pacientes == 0) {
		printf("Ainda não foram introduzidos pacientes\n");
		printf("\n*Pressione uma tecla qualquer para voltar ao menu*\n");
		system("pause > nul");
		system("cls");
	}
	else {
		do {
			aux = 0;
			printf("[REMOVER UM PACIENTE]\n");
			printf("\n\tIntrouduza o número de utente do paciente que deseja remover:");
			scanf("%i", &n_utente);
			fflush(stdin);
			for (i = 0; i<n_pacientes; i++) {
				if (n_utente == N[i].num_ut) {
					aux = 1;
					system("cls");
					printf("[REMOVER UM PACIENTE]\n");
					printf("\nPaciente número: %i\n", N[i].num_ut);
					printf("\tNome: %s\n", N[i].nome);
					printf("\tData de nascimentos: %s\n", N[i].data_nasc);
					printf("\tNúmero de identificação fiscal: %i\n", N[i].num_if);
					printf("\tNúmero da segurança social: %i\n", N[i].num_ss);
					printf("\tMorada: %s\n", N[i].morada);
					printf("\n\t Tem a certeza que deseja remover este paciente? (s/n):");
					scanf("%c", &opcao);
					fflush(stdin);
					if (opcao == 's') {
						for (c = i; c<n_pacientes; c++) {
							N[c] = N[c + 1];
						}
						n_pacientes--;
						aux2 = 1;
					}
				}
			}
			if (aux == 0)	printf("\n\tO número de utente inserido não se encontra registado, por favor tente novamente:");
		} while (aux == 0);
		if (aux2 == 1) {
			printf("\n\t\t*PACIENTE REMOVIDO COM SUCESSO*");
			
			//Substituir o ficheiro com a nova informação
			
			listagem = fopen("Lista Pacientes.txt", "w"); //mudar modo 
			if (listagem != NULL) {
				for (i = 0; i<n_pacientes; i++) {
					fprintf(listagem, "%i\n%s\n%s\n%i\n%i\n\%s\n", N[i].num_ut, N[i].nome, N[i].data_nasc, N[i].num_if, N[i].num_ss, N[i].morada);
				}
				fclose(listagem);
			}
		}
		if (aux2 == 0) printf("\n\t\t*O PACIENTE NÃO FOI REMOVIDO");
		system("pause > nul");
		system("cls");
	}
	return n_pacientes;
}


//LER DO FICHEIRO

int read_file(PACIENTE N[], int n_pacientes) {
	FILE *listagem;
	int i = 0;
	listagem = fopen("Lista Pacientes.txt", "r");
	while (fscanf(listagem, "%d\n", &N[i].num_ut) != EOF) {
		fgets(N[i].nome, 100, listagem);
		N[i].nome[strlen(N[i].nome) - 1] = 0;
		fgets(N[i].data_nasc, 100, listagem);
		N[i].data_nasc[strlen(N[i].data_nasc) - 1] = 0;
		fscanf(listagem, "%i\n", &N[i].num_if);
		fscanf(listagem, "%i\n", &N[i].num_ss);
		fgets(N[i].morada, 100, listagem);
		N[i].morada[strlen(N[i].morada) - 1] = 0;
		i++;
	}
	fclose(listagem);
	return i;
}

//CRIAR FICHEIRO 

void criar_file() {
	FILE *listagem;
	listagem = fopen("Lista Pacientes.txt", "a");
	fclose(listagem);
}




int main() {
	int n_pacientes = 0, opcao;
	PACIENTE N[100];

	setlocale(LC_ALL, "Portuguese");

	criar_file();
	n_pacientes = read_file(N, n_pacientes);

	while (opcao != 0) {
		menu();
		printf("---->Introduza a opção:");
		scanf("%i", &opcao);
		fflush(stdin);
		switch (opcao) {
		case 1:	n_pacientes = ins_paciente(N, n_pacientes);
			break;
		case 2: listar_paciente(N, n_pacientes);
			break;
		case 3: alterar_dados(N, n_pacientes);
			break;
		case 4: procurar_num(N, n_pacientes);
			break;
		case 5: procurar_nome(N, n_pacientes);
			break;
		case 6: n_pacientes = remover_paciente(N, n_pacientes);
			break;
		case 0: printf("A sair...\n");
			system("pause");
			break;
		default:
			printf("\n\t\t*OPÇÃO INVÁLIDA, PRESSIONE UMA TECLA QUALQUER PARA TENTAR NOVAMENTE*\n");
			system("pause > nul");
			system("cls");
			break;
		}
	}
	return 0;
}
