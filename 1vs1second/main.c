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
					player_AttackNum_3();
					endline_player();
				}
				if (Attack_Number == 4) { //���� ���ý�
					player_AttackNum_4();
					if (Slash_Attack <= 2) { //���� �������ڰ� 2�����Ͻ� ���ݽ�����
						player_AttackNum_4_None();
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //���� �������ڰ� 3~6�Ͻ� ���� ����
						player_AttackNum_4_Normal();
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //���� �������ڰ� 7~9�Ͻ� ������ ���� ����
						player_AttackNum_4_Critical();
					}
					endline_player();
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //������ 1.
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						knockdown_player();
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						knockdown_monster();
					}
					knockdown_result();
					break;
				}
				if (Turn % 2 == 0) { //(���� ¦���϶�)������ ��
					monster_act();
					if (Monster_Attack <= 1) { //���� �������ڰ� 1�����϶� ���ݽ�����
						monster_Attack_None();
						endline_monster();
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //���� �������ڰ� 2~7�Ͻ� ���� ����
						monster_Attack_Normal();
						endline_monster();
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //���� �������ڰ� 8~9�Ͻ� ������ ���� ����
						monster_Attack_Critical();
						endline_monster();
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //������ 1.
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						knockdown_player();
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						knockdown_monster();
					}
					knockdown_result();
					break;
				}
			}
		}
		if (First_select == 2) { //2��. �������ʱ�ȭ ����
			reset_data();
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