/* ���� ���� �� �Լ����� ��Ƴ��� �� */
/* �̰��� ���� ��������� include �������� */

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
int Monster1_HP = 3200, Monster1_ATK = 500, Monster1_DEF = 100; //�� �������� ����ϴ� ����1 ���� ���� 

/* ������/���ӽý��� */
int Attack_Number; // [������] [������] [����] [����]�� ������ ���ϴ� ����
int Damage; //����� ���������� ��� ����
int Turn = 1; //���� �󸶳� ���������� �˷��ִ� ����
int monster_Turn = 0; //���Ͱ� ������ �������� �˷��ִ� ����
int Scratch_Attack; //�����Լ��� ���� �÷��̾� [������]�� ���ݼ�����
int Scratch_random_number; // [������]���ý� ũ��Ƽ���� ���� ������ ���ϱ����� �����Լ��� ���� ����
int Slash_Attack; //�����Լ��� ���� �÷��̾� [����]���ݼ�����
int Slash_Attack_random_number; // [����]���ý� �� ����(����)�� ���� �������� �޸��ϰ� ������ִ� ����
int Monster_Attack; //�����Լ��� ���� ������ ���ݼ�����
int Monster_Attack_random_number; //������ ���Ͻ� ������ ���ڿ� ���� ���ݹ���� ���� �� �ְ� �ϴ� ����


void random_num() { //������ ���ڸ� ��Ÿ�����ϴ� ����(���� ����)
	srand((unsigned int)time(NULL));
}

void title() { //����Ÿ��Ʋ(ùȭ��) ǥ��
	puts("[MAIN] --Welcome to HDR 1vs1--"); //����ȭ��
	printf("<<[1]Game start, [2]Reset, [3] Exit>>\n: "); //���μ�����
	scanf("%d", &First_select); //��ȣ �Է�
}

void choose_character() { //ĳ���� ����
	printf("\n[Choose your characters]------------------\n"); //ĳ���� ���� ����
	Sleep(100);
	printf(" -[1]Attacker - Attack specialization.\n -[2]Defender - Defence specialization.\n -[3]Allrounder - Balanced.\n\n: "); //ĳ���� ����
	scanf("%d", &Character_select);
}

void reset_data() { //2��. �ʱ�ȭ �����
	Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
	Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
	Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
	Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
	First_select = 0;
	Character_select = 0;
	Turn = 1, monster_Turn = 0;
}

void set_Attacker() { //Attacker �ɷ�ġ ����
	Player_HP = Attacker_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Attacker_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Attacker_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	printf("\t -Completed \"Attacker\" status settings!-");
}

void set_Defender() { //Defender �ɷ�ġ ����
	Player_HP = Defender_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Defender_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Defender_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	printf("\t -Completed \"Defender\" status settings!-");
}

void set_Allrounder() { //Allrounder �ɷ�ġ ����
	Player_HP = Allrounder_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Allrounder_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Allrounder_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	printf("\t -Completed \"Allrounder\" status settings!-");
}

void story() { //STAGE 1 ���丮
	Sleep(2000);
	printf("\n\n__[STORY]__\n\nYou're walking down the street.\n");
	Sleep(1000);
	printf("But this road is dangerous. Even more because it's night.\n");
	Sleep(1000);
	printf("And you found the Monster..!\n\n");
}

void player_act() { //�÷��̾��� ��. �ൿ�� ���Ѵ�
	while (1) {
		Sleep(1100);
		printf("\n\t=Choose your ACT=");
		Sleep(200);
		printf("\n\n[1]Hit    [2]Scratch   [3]Kick    [4]Cut\n\n: "); //��� �����Ұ��� ����
		scanf("%d", &Attack_Number);
		if (Attack_Number >= 5 || Attack_Number <= 0) {
			printf("\n[Please input retry]\n\n");
		}
		else break;
	}
}

void player_AttackNum_1() { // 1. ������ ���ý�..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("you Hit opponent");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 2; //���������� ���� ���� ������ 2�Ѹ�ŭ ����
}

void player_AttackNum_2() { // 2. ������ ���ý�..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("you Scratch opponent");
	Damage = Player_ATK / 3; //�÷��̾� ���ݷ� ������ 3
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
	Scratch_random_number = rand(); //������ �������� �����
	Scratch_Attack = (int)Scratch_random_number % 10; // �������ڸ� 0~9�� ����  <���� ���� ũ��Ƽ�� ���κ��� �� �̻��� �� ����. ����>
}

void player_AttackNum_2_Critical() { // 2. ������ ũ��Ƽ��!
	printf("\n[Criical!]"); //ũ��Ƽ���� ���� �����Ѵ�
	Damage += Damage * 2; //���� ���� �������� ���ϱ� 2
}

void endline_player() { //�÷��̾� ���϶� ��Ȳ����
	Sleep(1000);
	printf("\nYou gave your opponent a \"%d\" damage.", Damage); //�󸶸�ŭ �������� �������� ǥ��
	Sleep(1500);
	Monster1_HP -= Damage; //������ ä�� - ������
	printf("\n\n\n=Remaining Monsters HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
	Sleep(1000);
	monster_Turn += 2;
	printf("\n\n==============================================================================\n\n");
}

void endline_monster() { //���� ���϶� ��Ȳ����
	Sleep(1500);
	printf("\n\n\n=Your Hp : %d", Player_HP); //���� �÷��̾��� ä�� ���
	Turn++; //�� ����
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}

void player_AttackNum_3() { //3. ���� ���ý�..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("You kick opponent.");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 2; //���������� ���� ���� ������ 2�Ѹ�ŭ ����
}

void  player_AttackNum_4() { //4. ���� ���ý�..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("You ");
	Slash_Attack_random_number = rand(); //������ �������� �����
	Slash_Attack = (int)Slash_Attack_random_number % 10; //�������ڸ� 0~9�� ����
}

void player_AttackNum_4_None() { //4. ���� ����
	printf("didn't cut your opponent.\n");
	Damage = 0;
}

void player_AttackNum_4_Normal() { //4. ���� ����
	printf("cut off your opponent.\n");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
}

void player_AttackNum_4_Critical() { //4. ������ ���� ����
	printf("cut your opponent hard!\n");
	Damage = Player_ATK; //������ �����̹Ƿ� �÷��̾� ���ݷ� �״�� �������� ��
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
}

void monster_act() { //���� ��, ���Ͱ� �ൿ�� ����
	Sleep(1200);
	printf("\n\n==============================================================================\n\n");
	Sleep(1000);
	printf("Monster's Turn.\n");
	Monster_Attack_random_number = rand(); //������ �������� �����
	Monster_Attack = (int)Monster_Attack_random_number % 10; //�������ڸ� 0~9�� ����
}

void monster_Attack_None() { //���� ���� ����
	Sleep(1000);
	printf("\nMonster failed to attack.");
	Damage = 0;
}

void monster_Attack_Normal() { //���� ���� ����
	Sleep(1000);
	printf("\nMonster attack.");
	Damage = Monster1_ATK / 3; //�������� ���� ���ݷ��� ������ 3
	Damage -= Player_DEF / 4; //���������� �÷��̾� ���� ������ 4�Ѹ�ŭ ����
	Player_HP -= Damage; //�÷��̾� ä�� - ������
	Sleep(1000);
	printf("\n\nYou wore a \"%d\" damage.", Damage); //�󸶸�ŭ �������� �������� ǥ��
}

void monster_Attack_Critical() { //���� ������ ���� ����
	Sleep(1000);
	printf("\nMonster Hard attack!");
	Damage = Monster1_ATK; //������ �����̹Ƿ� ������ ���ݷ� �״�� ��
	Damage -= (Player_DEF / 2) + Damage / 4; // < (Player_DEF / 2.5�� �����ҷ��� ��.  Release�������� ���� �����̰�. ���� �����Ϸ��� �ߴ� �ͺ��� ������ ����) >
	Player_HP -= Damage; //�÷��̾� ä�� - ������
	Sleep(1000);
	printf("\n\nYou wore a \"%d\" damage.", Damage); //�󸶸�ŭ �������� �������� ǥ��
}

void knockdown_player() { //�÷��̾� HP�� 0 �����϶�. (�� �÷��̾ ����������)
	printf("\n\n\n\t\t{Retire!}"); //���� ����
	Sleep(500);
	printf("\n\t\tWinner : Monster"); //���� �¸�!
	Sleep(800);
}

void knockdown_monster() { //���� HP�� 0 �����϶�. (�� ���Ͱ� ����������)
	printf("\n\n\n\t\t{Retire!}"); //���� ����
	Sleep(500);
	printf("\n\t\tWinner : Player"); //�÷��̾� �¸�!
	Sleep(800);
}

void knockdown_result_turn() {
	printf("\n\t\tTotal turn count : %d\n\n\n", Turn); //�� �� ���
	printf("\n\n==============================================================================\n\n");
}
