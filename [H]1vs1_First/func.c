/* �Ϻ� ������ �� �Լ����� ��Ƴ��� �� */
/* ���⿡�� ��������� include �������� */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

/* ������ */
int First_select; //ù��° ����. ����, �ʱ�ȭ, ������ ����� �������� ���ϴ� ����
int Character_select; //�ι�° ����. � ĳ���͸� ���� ���ϴ� ����

/* ĳ����/���� ����*/
int Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100; //Attacker �⺻����
int Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200; //Depender �⺻����
int Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150; //Allrounder �⺻����
int Player_HP, Player_ATK, Player_DEF; //�� �������� ����ϴ� ����(������ ĳ������ �ɷ�ġ�� ������ ����ϴ� ����)
int Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //�� �������� ����ϴ� ����1 ���� ���� 

/* ������/���ӽý��� */
int Attack_Number; // [������] [������] [����] [����]�� ������ ���ϴ� ����
int Damage; //����� ���������� ��� ����
int Turn = 1; //���� �󸶳� ���������� �˷��ִ� ����
int Scratch_Attack; //�����Լ��� ���� �÷��̾� [������]�� ���ݼ�����
int Scratch_random_number; // [������]���ý� ũ��Ƽ���� ���� ������ ���ϱ����� �����Լ��� ���� ����
int Slash_Attack; //�����Լ��� ���� �÷��̾� [����]���ݼ�����
int Slash_Point_random_number; // [����]���ý� �� ����(����)�� ���� �������� �޸��ϰ� ������ִ� ����
int Monster_Attack; //�����Լ��� ���� ������ ���ݼ�����
int Monster_Attack_random_number; //������ ���Ͻ� ������ ���ڿ� ���� ���ݹ���� ���� �� �ְ� �ϴ� ����


void random_num() {
	srand((unsigned int)time(NULL)); //������ ���ڸ� ��Ÿ�����ϴ� ����
}

void title() { //����Ÿ��Ʋ(ùȭ��) ǥ��
	puts("[MAIN] --Welcome to HDR 1vs1--"); //����ȭ��
	printf("<<���ӽ����� 1��, �������ʱ�ȭ�� 2��, ����� 3���� �Է����ּ���.>>\n"); //���μ�����
	scanf("%d", &First_select);
}

void choose_character() { //ĳ���� ����
	printf("\n[ĳ���͸� �����Ͻʽÿ�]------------------\n"); //ĳ���� ����
	Sleep(100);
	printf(" -[1]Attacker - ���ݿ� Ưȭ�Ǿ� �ֽ��ϴ�.\n -[2]Defender - �� Ưȭ�Ǿ� �ֽ��ϴ�.\n -[3]Allrounder - ���������Դϴ�.\n\n"); //ĳ���� ����
	scanf("%d", &Character_select);
}

void set_Attacker() {
	Player_HP = Attacker_HP;
	Player_ATK = Attacker_ATK;
	Player_DEF = Attacker_DEF;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1;
	printf("\t -Attacker ������ �Ϸ�Ǿ����ϴ�!-");
}

void set_Defender() {
	Player_HP = Defender_HP;
	Player_ATK = Defender_ATK;
	Player_DEF = Defender_DEF;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1;
	printf("\t -Defender ������ �Ϸ�Ǿ����ϴ�!-");
}

void set_Allrounder() {
	Player_HP = Allrounder_HP;
	Player_ATK = Allrounder_ATK;
	Player_DEF = Allrounder_DEF;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1;
	printf("\t -Allrounder ������ �Ϸ�Ǿ����ϴ�!-");
}

void story() {
	Sleep(2000);
	printf("\n\n__[STORY]__\n\n����� ���� ���� �־���.\n"); //STAGE 1 ���丮
	Sleep(1000);
	printf("������ ����� ���� �� ���� ��ҿ� ����� ���͵��� ���� ��Ÿ����, ���� ������ ���̶� �� ���� ����Ѵ�.\n");
	Sleep(1000);
	printf("�׸��� ����� ����� �ڸ� �i���ִ� ���͸� ���� �Ǵµ�..\n\n");
}

void player_act() {
	Sleep(1100);
	printf("\n\t=����� ������ �ұ�?="); //�÷��̾��� ��!
	Sleep(200);
	printf("\n\n[1]������    [2]������    [3]����    [4]����\n\n�Է� -> "); //��� �����Ұ��� ����
	scanf("%d", &Attack_Number);
}

void player_AttackNum_1() {
	Sleep(700);
	printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("����� ��븦 ���Ƚ��ϴ�.");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 2; //���������� ���� ���� ������ 2�Ѹ�ŭ ����
}

void player_AttackNum_2() {
	Sleep(700);
	printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("����� ��븦 ���������ϴ�.");
	Damage = Player_ATK / 3; //�÷��̾� ���ݷ� ������ 3
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
	Monster1_HP -= Damage;
	Scratch_random_number = rand(); //������ �������� �����
	Scratch_Attack = (int)Scratch_random_number % 10; // �������ڸ� 0~9�� ���� <���� ���� ũ��Ƽ�� ���κ��� �� �̻��� �� ����. ����>
}

void player_AttackNum_2_Critical() {
	printf("\n[ũ��Ƽ��!]"); //ũ��Ƽ���� ���� �����Ѵ�
	Damage += Damage * 2; //���� ���� �������� ���ϱ� 2
	Monster1_HP -= Damage;
	Sleep(1000);
}

void endline_player() {
	Sleep(1000);
	printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
	Monster1_HP -= Damage;
	Sleep(1500);
	printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
	Turn++;
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}