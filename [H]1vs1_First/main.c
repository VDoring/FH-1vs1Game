#include <stdio.h> //���� 4
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num();

	while (1) { // 1���� While
		title();
		if (First_select == 1) { //1��. ���ӽ���
			while (1) { // 2��° While
				choose_character();
				if (Character_select == 1) { //1��. Attacker ���ý�..
					set_Attacker();
					break; //2��° �ݺ��� ���
				}
				if (Character_select == 2) { //2��. Defender ���ý�..
					set_Defender();
					break; //2��° �ݺ��� ���
				}
				if (Character_select == 3) { //3��. Allrounder ���ý�..
					set_Allrounder();
					break; //2��° �ݺ��� ���
				}
				else {
					puts("�ٽ� �Է��Ͻʽÿ�"); //�߸��� ���� �Է½�
				}
			} //�ݺ��� 1 ��
			story();
			while (1) { // 3��° While
				player_act();
				if (Attack_Number == 1) { // 1. ������ ���ý�
					player_AttackNum_1();
					endline_player();
				}
				if (Attack_Number == 2) { // 2. ������ ���ý�
					player_AttackNum_2();
					if (Scratch_Attack > 5) { //���� �������ڰ� 5���� Ŭ��
						player_AttackNum_2_Critical();
					}
					endline_player();
				}
				if (Attack_Number == 3) { //���� ���ý� <���� �� �κ� ������� ���� �������� �������� �ְԲ� �߰��ϱ�>
					Sleep(700);
					printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
					Sleep(1000);
					puts("����� ��븦 á���ϴ�.");
					Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
					Damage -= Monster1_DEF / 2; //���������� ���� ���� ������ 2�Ѹ�ŭ ����
					Sleep(1000);
					printf("\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
					Monster1_HP -= Damage;
					Sleep(1500);
					printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
					Turn++;
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Attack_Number == 4) { //���� ���ý�
					Sleep(700);
					printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
					Sleep(1000);
					printf("����� ��븦 ");
					Slash_Point_random_number = rand(); //������ �������� �����
					Slash_Attack = (int)Slash_Point_random_number % 10; //�������ڸ� 0~9�� ����
					if (Slash_Attack <= 2) { //���� �������ڰ� 2�����Ͻ� ���ݽ�����
						printf("���� ���߽��ϴ�.");
						Sleep(1500);
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
						Turn++;
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //���� �������ڰ� 3~6�Ͻ� ���� ����
						printf("�������ϴ�.");
						Damage = Player_ATK / 2; //�÷��̾� ���ݷ� ������ 2
						Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
						Sleep(1000);
						printf("\n\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
						Monster1_HP -= Damage;
						Sleep(1500);
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
						Turn++;
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //���� �������ڰ� 7~9�Ͻ� ������ ���� ����
						printf("����� �������ϴ�.");
						Damage = Player_ATK; //������ �����̹Ƿ� �÷��̾� ���ݷ� �״�� �������� ��
						Damage -= Monster1_DEF / 3; //���������� ���� ���� ������ 3�Ѹ�ŭ ����
						Sleep(1000);
						printf("\n\n����� ��뿡�� %d�� �������� �������ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
						Monster1_HP -= Damage;
						Sleep(1500);
						printf("\n\n\n=��� ������ ���� HP : %d", Monster1_HP); //���� ��� ������ ä�� ���
						Turn++;
					}
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //������ 1.
					printf("\n\n\n\t\t��Ÿ�̾�! �������!");
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						Sleep(500);
						printf("\n\t\t���� : ����"); //���� �¸�!
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						Sleep(500);
						printf("\n\t\t���� : �÷��̾�"); //�÷��̾� �¸�!
					}
					Sleep(800);
					printf("\n\t\t����� �� �� : %d\n\n\n", Turn); //�� �� ���
					printf("\n\n==============================================================================\n\n");
					break;
				}
				if (Turn % 2 == 0) { //(���� ¦���϶�)������ ��
					Sleep(1200);
					printf("\n\n==================================[�� �� : %d]=================================\n\n", Turn);
					Sleep(1000);
					printf("��� ������ ���Դϴ�.\n");
					Monster_Attack_random_number = rand(); //������ �������� �����
					Monster_Attack = (int)Monster_Attack_random_number % 10; //�������ڸ� 0~9�� ����

					if (Monster_Attack <= 1) { //���� �������ڰ� 1�����϶� ���ݽ�����
						Sleep(1000);
						printf("\n���Ͱ� ������ �����߽��ϴ�.");
						Sleep(1500);
						printf("\n\n\n=������ Hp : %d", Player_HP); //���� �÷��̾��� ä�� ���
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //���� �������ڰ� 2~7�Ͻ� ���� ����
						Sleep(1000);
						printf("\n���Ͱ� ������ �߽��ϴ�.");
						Damage = Monster1_ATK / 3; //�������� ���� ���ݷ��� ������ 3
						Damage -= Player_DEF / 4; //���������� �÷��̾� ���� ������ 4�Ѹ�ŭ ����
						Player_HP -= Damage;
						Sleep(1000);
						printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
						Sleep(1500);
						printf("\n\n\n=������ Hp : %d", Player_HP); //���� �÷��̾��� ä�� ���
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //���� �������ڰ� 8~9�Ͻ� ������ ���� ����
						Sleep(1000);
						printf("\n���Ͱ� ������ ������ �߽��ϴ�!");
						Damage = Monster1_ATK; //������ �����̹Ƿ� ������ ���ݷ� �״�� ��
						Damage -= (Player_DEF / 2) + Damage / 4; // (Player_DEF / 2.5�� �����ҷ��� ��.  Release�������� ���� �����̰�. ���� �����Ϸ��� �ߴ� �ͺ��� ������ ����)
						Player_HP -= Damage;
						Sleep(1000);
						printf("\n\n����� %d��ŭ�� �������� �Ծ����ϴ�.", Damage); //�󸶸�ŭ �������� �������� ǥ��
						Sleep(1500);
						printf("\n\n\n=������ Hp : %d", Player_HP); //���� �÷��̾��� ä�� ���
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //������ 2.
					printf("\n\n\n\t\t��ٿ� �߻�! �������!");
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						Sleep(500);
						printf("\n\t\t���� : ����"); //���� �¸�!
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						Sleep(500);
						printf("\n\t\t���� : �÷��̾�"); //�÷��̾� �¸�!
					}
					Sleep(800);
					printf("\n\t\t����� �� �� : %d\n\n\n", Turn); //�� �� ���
					printf("\n\n==============================================================================\n\n");
					break;
				}
			}
		}
		if (First_select == 2) { //2��. �������ʱ�ȭ ����
			Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
			Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
			Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
			Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
			Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
			First_select = 0;
			Character_select = 0;

			printf("\n�ʱ�ȭ�� �Ϸ�Ǿ����ϴ�.\n\n\n");
		}
		if (First_select == 3) { //3��. ���α׷� ����
			printf("\n���α׷��� ����˴ϴ�.\n");
			break; //1��° �ݺ��� ���
		}
	}
	printf("\n\n---������ּż� �����մϴ�---\n\n");
	Sleep(2000);
}

/*
������ ������ ���� ���� �����ϱ�
�����̻�(��, ���� ��) �����ϱ�
*/