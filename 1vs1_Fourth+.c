#include <stdio.h> //���� 2
#include <stdlib.h>
#include <time.h>

int main()
{
	/* ������ */
	int First_select; //ù��° ����. ����, �ʱ�ȭ, ������ ����� �������� ���ϴ� ����
	int Character_select; //�ι�° ����. � ĳ���͸� ���� ���ϴ� ����

	/* ĳ����/���� ����*/
	int Attacker_HP = 130, Attacker_ATK = 120, Attacker_DEF = 50; //Attacker �⺻����
	int Defender_HP = 200, Defender_ATK = 60, Defender_DEF = 100; //Depender �⺻����
	int Allrounder_HP = 100, Allrounder_ATK = 100, Allrounder_DEF = 100; //Allrounder �⺻����
	int Player_HP, Player_ATK, Player_DEF; //�� �������� ����ϴ� ����(������ ĳ������ �ɷ�ġ�� ������ ����ϴ� ����)
	int Monster1_HP = 200, Monster1_ATK = 80, Monster1_DEF = 60; //�� �������� ����ϴ� ����1 ���� ���� 

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

	srand((unsigned int)time(NULL)); //������ ���ڸ� ��Ÿ�����ϴ� ����


	puts("[MAIN] --Welcome to HDR 1vs1--");
	while (1) {
		printf("<<���ӽ����� 1��, �������ʱ�ȭ�� 2��, ����� 3���� �Է����ּ���.>>\n"); //���μ�����
		scanf("%d", &First_select);
		if (First_select == 1) { //1��. ���ӽ���
			while (1) { //�ݺ��� 1 ����
				printf("\n[ĳ���͸� �����Ͻʽÿ�]------------------\n"); //ĳ���� ����
				printf(" -[1]Attacker - ���ݿ� Ưȭ�Ǿ� �ֽ��ϴ�.\n -[2]Defender - �� Ưȭ�Ǿ� �ֽ��ϴ�.\n -[3]Allrounder - ���������Դϴ�.\n\n"); //ĳ���� ����
				scanf("%d", &Character_select);
				if (Character_select == 1) { //1��. Attacker ���ý�..
					Player_HP = Attacker_HP;
					Player_ATK = Attacker_ATK;
					Player_DEF = Attacker_DEF;
					printf("\t -Attacker ������ �Ϸ�Ǿ����ϴ�!-");
				}
				if (Character_select == 2) { //2��. Defender ���ý�..
					Player_HP = Defender_HP;
					Player_ATK = Defender_ATK;
					Player_DEF = Defender_DEF;
					printf("\t -Defender ������ �Ϸ�Ǿ����ϴ�!-");
				}
				if (Character_select == 3) { //3��. Allrounder ���ý�..
					Player_HP = Allrounder_HP;
					Player_ATK = Allrounder_DEF;
					Player_DEF = Allrounder_DEF;
					printf("\t -Allrounder ������ �Ϸ�Ǿ����ϴ�!-");
				}
				else {
					puts("�ٽ� �Է��Ͻʽÿ�"); //�߸��� ���� �Է½� �ٽ� �Է¸޼���
					Character_select = 0; //�ʱ�ȭ
				} //�ݺ��� 1 ��
				printf("\n\n__[STORY]__\n\n����� ���� ���� �־���.\n������ ����� ���� �� ���� ��ҿ� ����� ���͵��� ���� ��Ÿ����, ���� ������ ���̶� �� ���� ����Ѵ�.\n�׸��� ����� ����� �ڸ� �i���ִ� ���͸� ���� �Ǵµ�..\n\n"); //STAGE 1 ���丮
				while (1) { //�ݺ��� 2 ����
					printf("\n\t=����� ������ �ұ�?=");
					printf("\n\n[1]������    [2]������    [3]����    [4]����\n\n�Է� -> "); //����Ÿ�� ����
					scanf("%d", &Attack_Number);
					if (Attack_Number == 1) { //������
						printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
						puts("����� ��븦 ���Ƚ��ϴ�.");
						Damage = Player_ATK / 2;
						Damage -= Monster1_DEF / 3;
						printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage);
						Monster1_HP -= Damage;
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
						Turn++;
						printf("\n\n==============================================================================\n\n");
					}
					if (Attack_Number == 2) { //������
						printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
						puts("����� ��븦 ���������ϴ�.");
						Damage = Player_ATK / 4;
						Damage -= Monster1_DEF / 3;
						Monster1_HP -= Damage;
						Scratch_random_number = rand(); //ũ��Ƽ�� ���
						Scratch_Attack = (int)Scratch_random_number % 10; // 0~9���� �������� ����
						if (Scratch_Attack > 7) { //���� 7���� Ŭ��
							Damage += Damage * 2;
							Monster1_HP -= Damage;
							printf("\n[ũ��Ƽ��!]"); //ũ��Ƽ���� ���� ����
						}
						printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage);
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
						Turn++;
						printf("\n\n==============================================================================\n\n");
					}
					if (Attack_Number == 3) { //����
						printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
						puts("����� ��븦 á���ϴ�.");
						Damage = Player_ATK / 2;
						Damage -= Monster1_DEF / 3;
						printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage);
						Monster1_HP -= Damage;
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
						Turn++;
						printf("\n\n==============================================================================\n\n");
					}
					if (Attack_Number == 4) { //����
						printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
						printf("����� ��븦 ");
						Slash_Point_random_number = rand(); //����
						Slash_Attack = (int)Slash_Point_random_number % 10;
						if (Slash_Attack <= 2) { //2���� ���ݽ���
							printf("���� ���߽��ϴ�.");
							printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
							Turn++;
						}
						if (Slash_Attack >= 3 && Slash_Attack <= 5) { //3~5 ���ݼ���
							printf("�������ϴ�.");
							Damage = Player_ATK / 3;
							Damage -= Monster1_DEF / 3;
							printf("\n\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage);
							Monster1_HP -= Damage;
							printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
							Turn++;
						}
						if (Slash_Attack >= 6 && Slash_Attack <= 9) { //6~8 ���Ѱ��ݼ���
							printf("����� �������ϴ�.");
							Damage = Player_ATK;
							Damage -= Monster1_DEF / 3;
							printf("\n\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage);
							Monster1_HP -= Damage;
							printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP);
							Turn++;
						}
						printf("\n\n==============================================================================\n\n");
					}
					if (Player_HP <= 0 || Monster1_HP <= 0) { //1�� ������
						printf("\n\n\n\t\t��Ÿ�̾�! �������!");
						if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
							printf("\n\t\t���� : ����"); //���� ����
						}
						if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
							printf("\n\t\t���� : �÷��̾�"); //���� �÷��̾�
						}
						printf("\n\t\t����� �� �� : %d\n\n\n", Turn); //�� �� ���
						break;
					}
					if (Turn % 2 == 0) { //(���� ¦���϶�)���� ���� ��
						printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
						printf("��� ������ ���Դϴ�.\n");
						Monster_Attack_random_number = rand();
						Monster_Attack = (int)Monster_Attack_random_number % 10;

						if (Monster_Attack <= 1) {
							printf("\n���Ͱ� ������ �����߽��ϴ�.");
							printf("\n\n\n=������ Hp : %d", Player_HP);
							Turn++;
							printf("\n\n==============================================================================\n\n");
						}
						if (Monster_Attack >= 2 && Monster_Attack <= 7) {
							printf("\n���Ͱ� ������ �߽��ϴ�.");
							Damage = Monster1_ATK / 2;
							Damage -= Player_DEF / 3;
							Player_HP -= Damage;
							printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage);
							printf("\n\n\n=������ Hp : %d", Player_HP);
							Turn++;
							printf("\n\n==============================================================================\n\n");
						}
						if (Monster_Attack >= 8 && Monster_Attack <= 9) {
							printf("\n���Ͱ� ������ ������ �߽��ϴ�!");
							Damage = Monster1_ATK;
							Damage -= Player_DEF / 3;
							Player_HP -= Damage;
							printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage);
							printf("\n\n\n=������ Hp : %d", Player_HP);
							Turn++;
							printf("\n\n==============================================================================\n\n");
						}
					}
					if (Player_HP <= 0 || Monster1_HP <= 0) {
						printf("\n\n\n\t\t��ٿ� �߻�! �������!");
						if (Player_HP <= 0) {
							printf("\n\t\t���� : ����");
						}
						if (Monster1_HP <= 0) {
							printf("\n\t\t���� : �÷��̾�");
						}
						printf("\n\t\t����� �� �� : %d\n\n\n", Turn);
						break;
					}
				}
			}
		}
		if (First_select == 2) {
			Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
			Monster1_HP = 200, Monster1_ATK = 80, Monster1_DEF = 60;
			printf("�ʱ�ȭ�� �Ϸ�Ǿ����ϴ�");
		}
		if (First_select == 3) {
			printf("���α׷��� �����մϴ�.");
		}
	}
	printf("\n\n---������ּż� �����մϴ�---\n\n");
}

/*

�ʱ�ȭ �����ϱ�

���� �����ϱ�

�����̻�(��, ���� ��) �����ϱ�

*/