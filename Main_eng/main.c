#include <stdio.h> //���� 4 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num(); //���� ����

	while (1) {
		title(); //����ȭ���� ��Ÿ����
		if (First_select == 1) { //1��. ���ӽ��� ���ý�..
			while (1) {
				choose_character(); //ĳ���� ����
				if (Character_select == 1) { //1��. Attacker ���ý�..
					set_Attacker(); //Attacker �ɷ�ġ ����
					break;
				}
				if (Character_select == 2) { //2��. Defender ���ý�..
					set_Defender(); //Defender �ɷ�ġ ����
					break;
				}
				if (Character_select == 3) { //3��. Allrounder ���ý�..
					set_Allrounder(); //Allrounder �ɷ�ġ ����
					break;
				}
				else {
					printf("\n[Please input retry]\n\n");//�ٸ��� �Է½�
				}
			}

			story(); //���� ���� �� ���丮

			while (1) {
				player_act(); //���ݹ�� ����
				if (Attack_Number == 1) { // 1. ������ ���ý�..
					player_AttackNum_1(); // 1�� ����
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}
				if (Attack_Number == 2) { // 2. ������ ���ý�..
					player_AttackNum_2(); //2�� ����
					if (Scratch_Attack > 5) { //�������ڰ� 5���� Ŭ��
						player_AttackNum_2_Critical(); //ũ��Ƽ��
					}
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}
				if (Attack_Number == 3) { //3. ���� ���ý�..   <���� �� �κ� ������� ���� �������� �������� �ְԲ� �߰��ϱ�>
					player_AttackNum_3(); //3�� ����
					endline_player();//���Ϳ��� ���� ������, ���� HP ���
				}
				if (Attack_Number == 4) { //4. ���� ���ý�..
					player_AttackNum_4(); //4�� ����
					if (Slash_Attack <= 2) { //�������ڰ� 2 �����Ͻ�
						player_AttackNum_4_None(); //���� ����
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //�������ڰ� 3~6�Ͻ�
						player_AttackNum_4_Normal(); //���� ����
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //�������ڰ� 7~9�Ͻ�
						player_AttackNum_4_Critical(); //������ ���� ����
					}
					endline_player();//���Ϳ��� ���� ������, ���� HP ���
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { // [1]������
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						knockdown_player(); //���� �¸� ���� ���
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						knockdown_monster(); //�÷��̾� �¸� ���� ���
					}
					knockdown_result_turn(); //�� ����� �ϼ� ���
					break;
				}
				if (monster_Turn % 2 == 0) { //(���� ¦���϶�)������ ��
					monster_act(); //���� �� ���� ���, �������� ����
					if (Monster_Attack <= 1) { // �������ڰ� 1�����϶�
						monster_Attack_None(); // ���� ����
						endline_monster(); // �÷��̾�� ���� ������, ���� HP ���
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //�������ڰ� 2~7�Ͻ� ���� ����
						monster_Attack_Normal(); //���� ����
						endline_monster();//�÷��̾�� ���� ������, ���� HP ���
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //�������ڰ� 8~9�Ͻ� ������ ���� ����
						monster_Attack_Critical(); //������ ���� ����
						endline_monster();//�÷��̾�� ���� ������, ���� HP ���
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { // [1]������
					if (Player_HP <= 0) { //�÷��̾� ä���� 0 �����Ͻ�
						knockdown_player(); //���� �¸� ���� ���
					}
					if (Monster1_HP <= 0) { //���� ä���� 0 �����Ͻ�
						knockdown_monster(); //�÷��̾� �¸� ���� ���
					}
					knockdown_result_turn(); //�� ����� �ϼ� ���
					break;
				}
			}
		}
		if (First_select == 2) { //2��. �������ʱ�ȭ ����
			reset_data(); //�ʱ�ȭ
			printf("\nReset success.\n\n\n");
		}
		if (First_select == 3) { //3��. ���α׷� ����
			printf("\nProgram exiting...\n");
			break;
		}
		else {
			printf("\n[Please input retry]\n\n"); //ù �޴����� �߸� �Է½�
		}
	}
	printf("\n\n---Thank you for use this program!---\n\n");
	Sleep(2000); //������ ������ �ٷ� ����Ǵ°� ����
}


/*

������ ������ ���� ���� �����غ���
�����̻�(��, ���� ��) �����ϱ�

*/