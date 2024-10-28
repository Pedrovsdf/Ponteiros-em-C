#include <stdio.h>

struct Registro_Nascimento
{
	int Dia;
	int Mes;
	int Ano;
};

struct Registro_Alunos
{
	char Nome[100];
	float Notas[3];
	struct Registro_Nascimento Data;
	float mediaind;
};

struct Media_Turmas{
	float mediatotal;
	struct Registro_Alunos Aluno[2][3];
}
Turma[2];


int main(){
	int i=0, j=0;
	
	printf("\n---------- Cadastro de alunos ----------\n\n");
	
	for(j=0; j<2; j++){
		for(i=0; i<3; i++){
		printf("\nInsira o nome do aluno %d da turma %d: ", i+1, j+1);
		scanf("%s", &Turma->Aluno[j][i].Nome);
		
		printf("Digite as 3 notas do aluno(a) %d da turma %d:\n", i+1, j+1);
		scanf("%f", &Turma->Aluno[j][i].Notas[0]);
		scanf("%f", &Turma->Aluno[j][i].Notas[1]);
		scanf("%f", &Turma->Aluno[j][i].Notas[2]);
		
		Turma->Aluno[j][i].mediaind = (Turma->Aluno[j][i].Notas[0] + Turma->Aluno[j][i].Notas[1] + Turma->Aluno[j][i].Notas[2])/3;
		Turma[j].mediatotal = Turma->Aluno[j][i].mediaind + Turma[j].mediatotal;
	
		printf("Digite a data de nascimento da do aluno(a) %d da turma %d, composto por dia, mes e ano:\n", i+1, j+1);
		scanf("%d", &Turma->Aluno[j][i].Data.Dia);
		scanf("%d", &Turma->Aluno[j][i].Data.Mes);
		scanf("%d", &Turma->Aluno[j][i].Data.Ano);
		}
	}
	
	for(j=0; j<2; j++){
		Turma[j].mediatotal = Turma[j].mediatotal/5;
	}
	
	printf("\n---------- Leitura dos dados ----------\n\n");
	
	for(j=0; j<2; j++){
		printf("A media total da turma %d eh: %.2f\n", j+1, Turma[j].mediatotal);
	}
	
	for(j=0; j<2; j++){
		printf("--Turma %d--", j+1);
		for(i=0; i<3; i++){
			if(Turma->Aluno[j][i].mediaind >= Turma[j].mediatotal){
				printf("\nAluno(a): %s\nEsta acima da media, com media: %.2f\nSua data de nascimento eh: %d/%d/%d\nSuas notas sao: %.2f, %.2f e %.2f\n", Turma->Aluno[j][i].Nome, Turma->Aluno[j][i].mediaind, Turma->Aluno[j][i].Data.Dia, Turma->Aluno[j][i].Data.Mes, Turma->Aluno[j][i].Data.Ano, Turma->Aluno[j][i].Notas[0], Turma->Aluno[j][i].Notas[1], Turma->Aluno[j][i].Notas[2]);
			}
		}
	}
	
	return 0;
}
