/* ���� ���� �� �Լ����� ��Ƴ��� �� */
/* �̰��� ���� ��������� include �������� */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

/* ��Ÿ �ٹ̱� */
int loop; //���� �����Ÿ��� �Ҷ� �ʿ��� ����

/* ������ */
int First_select; //ù��° ����. ����, �ʱ�ȭ, ������ ����� �������� ���ϴ� ����
int Character_select; //�ι�° ����. � ĳ���͸� ������ ���ϴ� ����

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
int Bodyhit_Attack; //�����Լ��� ���� �÷��̾� [�����ġ��]�� �߰� �������� ���ϱ� ���� �����Լ��� ���� ����
int Bodyhit_Attack_random_number; //[�����ġ��] ���ý� ������� ���� �߰��������� �󸶳� ���������� ���ϴ� ����
int Scratch_Attack_counts; //[����������] ������ ��� �Ҳ��� ���ϴ� ����
int Scratch_Attack_counts_random_number; //�����Լ��� ���� [����������]�� ��� �����ϰ� �Ұ��� ���ϴ� ����
int Scratch_counts; //[����������] ����� ��� ����ߴ��� ����Ҷ� ����ϴ� ����
int Scratch_Attack; //�����Լ��� ���� �÷��̾� [������]�� ���ݼ�����
int Scratch_Attack_random_number; // [������]���ý� ũ��Ƽ���� ���� ������ ���ϱ����� �����Լ��� ���� ����
int Slash_Attack; //�����Լ��� ���� �÷��̾� [����]���ݼ�����
int Slash_Attack_random_number; // [����]���ý� �� ����(����)�� ���� �������� �޸��ϰ� ������ִ� ����
int Monster_Attack; //�����Լ��� ���� ������ ���ݼ�����
int Monster_Attack_random_number; //������ ���Ͻ� ������ ���ڿ� ���� ���ݹ���� ���� �� �ְ� �ϴ� ����


gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void random_num() { //������ ���ڸ� ��Ÿ�����ϴ� ����(���� ����)
	srand((unsigned int)time(NULL));
}

void title() { //����Ÿ��Ʋ(ùȭ��) ǥ��
	int x = 44, y = 5;
	system("mode con cols=120 lines=35"); //**â ����ũ�� 120, ����ũ�� 40 ����
	gotoxy(x, y + 0); printf("______               ___  ___"); Sleep(70); //�� ���α��� 29
	gotoxy(x, y + 1); printf("| ___ \\              |  \\/  |"); Sleep(70);
	gotoxy(x, y + 2); printf("| |_/ / __   __ ___  | .  . |"); Sleep(70);
	gotoxy(x, y + 3); printf("|  __/  \\ \\ / // __| | |\\/| |"); Sleep(70);
	gotoxy(x, y + 4); printf("| |      \\ V / \\__ \\ | |  | |"); Sleep(70);
	gotoxy(x, y + 5); printf("\\_|       \\_/  |___/ \\_|  |_/"); Sleep(70);
	gotoxy(x, y + 8); printf("        [1] ���� ����"); Sleep(5);
	gotoxy(x, y + 10); printf("        [2] �ʱ�ȭ"); Sleep(5);
	gotoxy(x, y + 12); printf("        [3] ����"); Sleep(150);
	gotoxy(x, y + 15); printf("  Input  :  ");
	gotoxy(x + 13, y + 15); scanf("%d", &First_select);  //��ȣ �Է�
	if (First_select != 1 && First_select != 2 && First_select != 3) {
		gotoxy(x + 4, y + 18); printf("[�߸� �Է��Ѱ� �ƴұ�?]"); Sleep(700);
	}
}

void choose_character() { //ĳ���� ����
	int x = 15, y = 4;
	system("mode con cols=100 lines=25"); //**â ����ũ�� 120, ����ũ�� 40 ����
	gotoxy(x - 4, y); printf("===========================[ĳ���͸� �����Ͻʽÿ�]===========================\n"); Sleep(100); //ĳ���� ���� ����
	gotoxy(x + 1, y + 3);  printf(" [1] Attacker - ���ݿ� Ưȭ�Ǿ� ����."); Sleep(50);//ĳ���� ����
	gotoxy(x + 1, y + 5);  printf(" [2] Defender - �� Ưȭ�Ǿ� ����."); Sleep(50);//ĳ���� ����
	gotoxy(x + 1, y + 7);  printf(" [3] Allrounder - �������� �ɷ�."); Sleep(50);//ĳ���� ����
	gotoxy(x + 26, y + 10); printf("Input  :  ");
	gotoxy(x + 37, y + 10);  scanf("%d", &Character_select);
	if (Character_select != 1 && Character_select != 2 && Character_select != 3) {
		gotoxy(x + 22, y + 13); printf("[�װ� ���� ĳ���;�!]"); Sleep(700);
	}
}

void reset_data() { //2��. �ʱ�ȭ �����
	int x = 44, y = 5;
	Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
	Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
	Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
	Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
	First_select = 0;
	Character_select = 0;
	Turn = 1, monster_Turn = 0;
	gotoxy(x + 2, y + 18); printf("[�ʱ�ȭ�� �Ϸ�Ǿ����ϴ�.]"); Sleep(900);
}

void program_exit() { //3��, ���α׷� ���� �����
	int x = 44, y = 5;
	gotoxy(x + 2, y + 18);  printf("������..."); Sleep(100);
	gotoxy(x + 2, y + 20);  printf("[������ּż� �����մϴ�]"); Sleep(1500);
}

void set_Attacker() { //Attacker �ɷ�ġ ����
	int x = 15, y = 4;
	Player_HP = Attacker_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Attacker_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Attacker_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	gotoxy(x + 18, y + 13); printf("{ ����� ���� Attacker�Դϴ�..! }"); Sleep(1000);
}

void set_Defender() { //Defender �ɷ�ġ ����
	int x = 15, y = 4;
	Player_HP = Defender_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Defender_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Defender_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	gotoxy(x + 18, y + 13); printf("{ ����� ���� Defender�Դϴ�..! }"); Sleep(1000);
}

void set_Allrounder() { //Allrounder �ɷ�ġ ����
	int x = 15, y = 4;
	Player_HP = Allrounder_HP; //�� ������ ����� ������ ����ȭ
	Player_ATK = Allrounder_ATK; //�� ������ ����� ������ ����ȭ
	Player_DEF = Allrounder_DEF; //�� ������ ����� ������ ����ȭ
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //���� �����Ͱ� �������� �� �ֱ⶧���� �ʱ�ȭ
	Turn = 1; //�� �ʱ�ȭ
	gotoxy(x + 18, y + 13);  printf("{ ����� ���� Allrounder�Դϴ�..! }"); Sleep(1000);
}

void story() { //STAGE 1 ���丮
	int x = 47, y = 2;
	system("mode con cols=110 lines=37");
	gotoxy(x, y); printf("[ ���丮 ]");
	gotoxy(x - 15, y + 4); printf("�̷��� ������ ���� ��.");
	gotoxy(x - 15, y + 6); printf("��濡�� �������� ���͵�.");
	gotoxy(x - 15, y + 8); printf("����鵵 �ϳ��Ѿ� ����������..");
	gotoxy(x - 15, y + 12); printf("������ ���� ����");
	gotoxy(x - 15, y + 14); printf("���������� ������ �˳���");
	gotoxy(x - 15, y + 16); printf("�� ���Ͱ� ������ ������ ��û�Ͽ���");
	gotoxy(x - 15, y + 21); printf("���� ���Ͱ� ���Ѻ��� �տ��� ������ ������ ���۵Ǿ���");
	gotoxy(x - 15, y + 24); printf("...������ �ο��� ����");
	gotoxy(x + 2, y + 28); printf("\"����..!\"");
	system("mode con cols=120 lines=45");
}

void player_act() { //�÷��̾��� ��. �ൿ�� ���Ѵ�
	while (1) {
		int x = 47, y = 23;
		gotoxy(x - 43, y); printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"); Sleep(100);
		gotoxy(x + 4, y + 2); printf("== ������ �ұ�? ==");
		Sleep(200);
		gotoxy(x - 20, y + 6); printf("[1] �����ġ��        [2] ����������        [3] ����ű        [4] ����"); //��� �����Ұ��� ����
		scanf("%d", &Attack_Number); 
		if (Attack_Number >= 5 || Attack_Number <= 0) {
			printf("\n[�ٽ� �Է����ּ���]\n\n");
		}
		else break;
	}
}

void player_AttackNum_1() { // 1. ������ ���ý�..
	Sleep(700); printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn); Sleep(1000);
	printf("\n����� ��븦 ���Ƚ��ϴ�.");
	Damage = Player_ATK / 3; //�����ġ�� ���� ���ݷ�
	Damage -= Monster1_DEF / 3; //���� ���¿� ���� ���� ���� ����(����)
	Bodyhit_Attack_random_number = rand();
	Bodyhit_Attack = (int)Bodyhit_Attack_random_number % 8; //�������� 0~7
}

void player_AttackNum_1_Shock0() { //���� �뷱�� ��ġ �ʿ�
	printf("�����⸸ �� ��, ���� �ƹ��� ��ݵ� ������ ���߽��ϴ�.");
}

void player_AttackNum_1_Shock1() {
	Damage += Damage / 50;
	printf("���� ���Ǻο� �̾��� ����� �������ϴ�.");
}

void player_AttackNum_1_Shock2() {
	Damage += Damage / 45;
	printf("���� ���Ǻο� ���� ����� ������ �����߽��ϴ�.");
}

void player_AttackNum_1_Shock3() {
	Damage += Damage / 40;
	printf("���� ���Ǻο� ����� ������ �� ������ �ֽ��ϴ�.");
}

void player_AttackNum_1_Shock4() {
	Damage += Damage / 30;
	printf("���� ���忡 �����̳��� ����� �޾����� �����߽��ϴ�");
}

void player_AttackNum_1_Shock5() {
	Damage += Damage / 25;
	printf("���� ������� ����� �� ���뽺�����մϴ�.");
}

void player_AttackNum_1_Shock6() {
	Damage += Damage / 20;
	printf("���� ������ �︱���� ��ݿ� ���ܿ��ϰ� �ֽ��ϴ�.");
}

void player_AttackNum_1_Shock7() {
	Damage += Damage / 14;
	printf("������ ��ݿ� ���� ȥ�����մϴ�.");
}

void player_Attacknum_2_counts() {
	Scratch_Attack_counts_random_number = rand();
	Scratch_Attack_counts = (int)Scratch_Attack_counts_random_number % 5; //�������ڸ� 0~4�� ����
}

void player_AttackNum_2() { // 2. ������ ���ý�..
	Sleep(700);
	printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("����� ��븦 %d�� ���������ϴ�.", Scratch_counts); //���� ��� ���״��� ������ ������ �̻��ϰ� �۵���!!===============================================
	Damage = Player_ATK / 3; //�÷��̾� ���ݷ� ������ 3
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
}

void endline_player() { //�÷��̾� ���϶� ��Ȳ����
	Sleep(1000);
	printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
	Sleep(1500);
	Monster1_HP -= Damage; //������ ä�� - ������
	printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
	Sleep(1000);
	monster_Turn += 2;
	printf("\n\n==============================================================================\n\n");
}

void endline_monster() { //���� ���϶� ��Ȳ����
	Sleep(1500);
	printf("\n\n\n=������ Hp : %d", Player_HP); //���� �÷��̾��� ä�� ���
	Turn++; //�� ����
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}

void player_AttackNum_3() { //3. ���� ���ý�..
	Sleep(700);
	printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("����� ��븦 á���ϴ�.");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 2; //���������� ���� ���� ������ 2�Ѹ�ŭ ����
}

void  player_AttackNum_4() { //4. ���� ���ý�..
	Sleep(700);
	printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("����� ��븦 ");
	Slash_Attack_random_number = rand(); //������ �������� �����
	Slash_Attack = (int)Slash_Attack_random_number % 10; //�������ڸ� 0~9�� ����
}

void player_AttackNum_4_None() { //4. ���� ����
	printf("���� ���߽��ϴ�.\n");
	Damage = 0;
}

void player_AttackNum_4_Normal() { //4. ���� ����
	printf("�������ϴ�.\n");
	Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
}

void player_AttackNum_4_Critical() { //4. ������ ���� ����
	printf("����� �������ϴ�.\n");
	Damage = Player_ATK; //������ �����̹Ƿ� �÷��̾� ���ݷ� �״�� �������� ��
	Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
}

void monster_act() { //���� ��, ���Ͱ� �ൿ�� ����
	Sleep(1200);
	printf("\n\n==============================================================================\n\n");
	Sleep(1000);
	printf("��� ������ ���Դϴ�.\n");
	Monster_Attack_random_number = rand(); //������ �������� �����
	Monster_Attack = (int)Monster_Attack_random_number % 10; //�������ڸ� 0~9�� ����
}

void monster_Attack_None() { //���� ���� ����
	Sleep(1000);
	printf("\n���Ͱ� ������ �����߽��ϴ�.");
	Damage = 0;
}

void monster_Attack_Normal() { //���� ���� ����
	Sleep(1000);
	printf("\n���Ͱ� ������ �߽��ϴ�.");
	Damage = Monster1_ATK / 3; //�������� ���� ���ݷ��� ������ 3
	Damage -= Player_DEF / 4; //���������� �÷��̾� ���� ������ 4�Ѹ�ŭ ����
	Player_HP -= Damage; //�÷��̾� ä�� - ������
	Sleep(1000);
	printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
}

void monster_Attack_Critical() { //���� ������ ���� ����
	Sleep(1000);
	printf("\n���Ͱ� ������ ������ �߽��ϴ�!");
	Damage = Monster1_ATK; //������ �����̹Ƿ� ������ ���ݷ� �״�� ��
	Damage -= (Player_DEF / 2) + Damage / 4; // < (Player_DEF / 2.5�� �����ҷ��� ��.  Release�������� ���� �����̰�. ���� �����Ϸ��� �ߴ� �ͺ��� ������ ����) >
	Player_HP -= Damage; //�÷��̾� ä�� - ������
	Sleep(1000);
	printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
}

void knockdown_player() { //�÷��̾� HP�� 0 �����϶�. (�� �÷��̾ ����������)
	printf("\n\n\n\t\t��Ÿ�̾�! �������!"); //���� ����
	Sleep(500);
	printf("\n\t\t���� : ����"); //���� �¸�!
	Sleep(800);
}

void knockdown_monster() { //���� HP�� 0 �����϶�. (�� ���Ͱ� ����������)
	printf("\n\n\n\t\t��Ÿ�̾�! �������!"); //���� ����
	Sleep(500);
	printf("\n\t\t���� : �÷��̾�"); //�÷��̾� �¸�!
	Sleep(800);
}

void knockdown_result_turn() {
	printf("\n\t\t����� �� �� : %d\n\n\n", Turn); //�� �� ���
	printf("\n\n==============================================================================\n\n");
}


/*

������ ������ ���� ���� �����غ���
�����̻�(��, ���� ��) �����ϱ�
1�� �̻� �÷��̽� ���丮 ��ŵ�� �� �ִ� ��� �߰�

*/