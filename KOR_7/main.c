#include <stdio.h> //���� 5
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num(); //���� ����

	while (1) {
		title(); //����ȭ��
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
			}
			story(); //���� ���� �� ���丮
			while (1) {
				if (Character_select == 1) player_Attacker_visual();
				if (Character_select == 2) player_Defender_visual();
				if (Character_select == 3) player_Allrounder_visual();
				player_monster_visual(); //���ݹ�� ���� �� �ƽ�Ű��Ʈ

				player_act(); //���ݹ�� ����

				if (Attack_Number == 1) { // 1. �����ġ�� ���ý�..
					player_AttackNum_1(); // �⺻ ����
					player_AttackNum_1_randomnum(); // �����(1�� ���� �߰�����) ��������
					if (Bodyhit_Attack <= 10) player_AttackNum_1_Shock0();						   // 10�����϶� : 10
					if (Bodyhit_Attack >= 11 && Bodyhit_Attack <= 26) player_AttackNum_1_Shock1(); // 11�̻�, 26���� : 15
					if (Bodyhit_Attack >= 26 && Bodyhit_Attack <= 41) player_AttackNum_1_Shock2(); // 26�̻�, 41���� : 15
					if (Bodyhit_Attack >= 41 && Bodyhit_Attack <= 60) player_AttackNum_1_Shock3(); // 41�̻�, 60���� : 19
					if (Bodyhit_Attack >= 61 && Bodyhit_Attack <= 75) player_AttackNum_1_Shock4(); // 61�̻�, 75���� : 14
					if (Bodyhit_Attack >= 76 && Bodyhit_Attack <= 85) player_AttackNum_1_Shock5(); // 76�̻�, 85���� : 9
					if (Bodyhit_Attack >= 86 && Bodyhit_Attack <= 94) player_AttackNum_1_Shock6(); // 86�̻�, 94���� : 8
					if (Bodyhit_Attack >= 95) player_AttackNum_1_Shock7();						   // 95�̻� : 5
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}

				if (Attack_Number == 2) { // 2. ���������� ���ý�..
					player_Attacknum_2_randomcounts(); // ��������(��� �������� ����)
					Damage = 0; //��� �� �������� �ʱ�ȭ(�ʼ�)
					if (Scratch_Attack_counts == 0) { //���� �������ڰ� 0�϶�
						Scratch_counts = 1; //ȭ������ ����� ���� Ƚ�� : 1
						player_AttackNum_2_attackcount(); // ������ 1���� �Ѵٰ� �˸�
														  // (�������ڿ� ����Ƚ���� �ٸ� ������ �����Լ��� ��Ÿ�� �� �ִ� ���� ���� ���ڰ� 0�̱� ����.)
														  // (1���� ��Ÿ���°� �Ұ��ϹǷ� if���� �̿��Ͽ� ���� ����Ѵ�.)
						player_AttackNum_2_damage(); //���������� �������� �ִ� �Լ�.
					}
					if (Scratch_Attack_counts == 1) { //���� �������ڰ� 1�϶�
						Scratch_counts = 2; //ȭ������ ����� ���� Ƚ�� : 2
						player_AttackNum_2_attackcount(); //���� x2
						for(int i = 0; i < 2; i++) //for���� �̿��� �������� 2�� ����
							player_AttackNum_2_damage(); //���������� �������� �ִ� �Լ�.
					}
					if (Scratch_Attack_counts == 2) { //���� �������ڰ� 2�϶�
						Scratch_counts = 3; //ȭ������ ����� ���� Ƚ�� : 3
						player_AttackNum_2_attackcount(); //���� x3
						for (int i = 0; i < 3; i++) //for���� �̿��� �������� 3�� ����
							player_AttackNum_2_damage(); //���������� �������� �ִ� �Լ�.
					}
					if (Scratch_Attack_counts == 3) { //���� �������ڰ� 3�϶�
						Scratch_counts = 4; //ȭ������ ����� ���� Ƚ�� : 4
						player_AttackNum_2_attackcount(); //���� x4
						for (int i = 0; i < 4; i++) //for���� �̿��� �������� 4�� ����
							player_AttackNum_2_damage(); //���������� �������� �ִ� �Լ�.
					}
					if (Scratch_Attack_counts == 4) { //���� �������ڰ� 4�϶�
						Scratch_counts = 5; //ȭ������ ����� ���� Ƚ�� : 5
						player_AttackNum_2_attackcount(); //���� x5
						for (int i = 0; i < 5; i++) //for���� �̿��� �������� 5�� ����
							player_AttackNum_2_damage(); //���������� �������� �ִ� �Լ�.
					}
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}

				if (Attack_Number == 3) { //3. ����ű ���ý�..
					player_AttackNum_3(); //�⺻ ����
					player_AttackNum_3_randomnum(); // ����(3�� ���� �����̻�) ��������
					if (Upperkick_Attack > 25) {
						printf("�����̻� ���� ���� �Լ� ����� �߰��ϱ�!!!!");
					}
					endline_player();//���Ϳ��� ���� ������, ���� HP ���
				}

				if (Attack_Number == 4) { //4. ���� ���ý�..
					player_AttackNum_4(); //�⺻ ����
					player_AttackNum_4_randomnum(); // ũ��Ƽ��(4�� ���� �߰�����) ��������
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
		}
		if (First_select == 3) { //3��. ���α׷� ����
			program_exit();
			break;
		}
	}
}