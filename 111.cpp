
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct Sotr // ���������
{
	char fio[64]; // ���
	char date[16]; // ���� ��������
	char dolg[32]; // ���������
	double okl; // �����
};

struct List // ������
{
	Sotr sotr; // ��� ����
	List *pNext; // ��������� �� ��������� �������
};

// ������� ���������� �������� � ������ ������
void addFirst(List *& pF, // ��������� �� ������ ������
			  List* p) // ��������� �� ����������� �������
{
	p->pNext=pF;
	pF=p;
}
// �������� �������� �� ������ ������
List * delFirst(List *&pF) // ������� ���������� ��������� �� ��������� �������
{
	if (pF==0) return 0;
	List *p=pF;
	pF=pF->pNext;
	return p;

}
// ���������� �������� ����� ��������
bool add(List *&pF, List * pZad, List *p)	
{
	// ������� ���������� true ��� ���������� ���������� � false � ������ ������
	if (pZad==pF) // ������� ����� ������
	{
		p->pNext=pF;
		pF=p;
		return true;
	}

		List *pPred=pF; // ��������� �� ���������� ������� ����� pZad
		while(pPred->pNext!=pZad && pPred->pNext)
			pPred=pPred->pNext;
		if (pPred->pNext==0) return false; // �������� pZad ��� � ������
		p->pNext=pZad;
		pPred->pNext=p;
		return true;
}
// �������� ������ �������� p �� ������
List * del(List*& pF, List *p) // ������� ���������� ��������� �� ��������� �������
{
	if (pF==0) return 0;
	if (pF==p) // ������� ������ �������
	{
		pF=pF->pNext;
		return p;
	}
	else
	{
		List *pPred=pF; // ��������� �� ���������� ������� ����� p
		while(pPred->pNext!=p && pPred->pNext)
			pPred=pPred->pNext;
		if (pPred->pNext==0) return 0; // �������� p ��� � ������
		pPred->pNext=p->pNext;
		return p;
	}
	while(delFirst(pF)); // ������� ������
}
	
int main(int argc, char* argv[])
{
	List *pF=0; // ������ ����
	List *p;
	// ���� ������
	char Ch; // ���������� ��� ����� ������� ����������� �����
	do
	{
		p=(List *)malloc(sizeof(List)); // �������� ������ ��� �������
		printf("\nFIO: ");
		fflush(stdin); gets(p->sotr.fio);
		printf("Date: ");
		fflush(stdin); gets(p->sotr.date);
		printf("Dolg: ");
		fflush(stdin); gets(p->sotr.dolg);
		printf("Okl=");
		fflush(stdin); scanf("%lf", &p->sotr.okl);
		addFirst(pF, p); // ��������� ������� � ������ ������
		printf("For continue press Y or y else any key! ");
		Ch=getche();
	}
	while(Ch=='Y' || Ch=='y');
	// ����� �����
	for(List *pi=pF; pi; pi=pi->pNext) // �������� ������
		printf("\n%s %s %s oklad=%.2f", pi->sotr.fio, pi->sotr.date, 
pi->sotr.dolg, pi->sotr.okl);


	// ���������� ������
	for(List *pi=pF; pi->pNext; )
	{
		// ���� ����������� ������� � ������
		char *min=pi->sotr.fio;
		List *pmin=pi;
		for(List *pj=pi->pNext; pj; pj=pj->pNext)
			if (strcmp(pj->sotr.fio,min)<0) 
			{
				min=pj->sotr.fio;
				pmin=pj;
			}
		if (pi!=pmin) // ����������� ������� ������ ������, �� ����� ����� pi
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi=pi->pNext;
	}
		printf("\n\nSortirovka po FIO:");
	for(List *pi=pF; pi; pi=pi->pNext) // �������� ������
			printf("\n%s %s %s oklad=%.2f", pi->sotr.fio, pi->sotr.date, 
pi->sotr.dolg, pi->sotr.okl);

	printf("\nFor exit press any key ");
	getch();
	return 0;
}

