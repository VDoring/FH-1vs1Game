#include <stdio.h> //���� 5
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
			}
			story(); //���� ���� �� ���丮
			while (1) {
				player_act(); //���ݹ�� ����

				if (Attack_Number == 1) { // 1. ������ ���ý�..
					player_AttackNum_1(); // 1�� ����
					if (Bodyhit_Attack == 0) player_AttackNum_1_Shock0();
					if (Bodyhit_Attack == 1) player_AttackNum_1_Shock1();
					if (Bodyhit_Attack == 2) player_AttackNum_1_Shock2();
					if (Bodyhit_Attack == 3) player_AttackNum_1_Shock3();
					if (Bodyhit_Attack == 4) player_AttackNum_1_Shock4();
					if (Bodyhit_Attack == 5) player_AttackNum_1_Shock5();
					if (Bodyhit_Attack == 6) player_AttackNum_1_Shock6();
					if (Bodyhit_Attack == 7) player_AttackNum_1_Shock7();
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}

				if (Attack_Number == 2) { // 2. ������ ���ý�..
					player_Attacknum_2_randomcounts(); //��������
					Damage = 0; //��� �� �������� �ʱ�ȭ(�ʼ�)
					if (Scratch_Attack_counts == 0) { //���� �������ڰ� 0�϶�
						Scratch_counts = 1;
						player_AttackNum_2_attackcount(); //������ 1���� �Ѵٰ� �˸�(�������ڿ� ����Ƚ���� �ٸ� ������ �����Լ��� ��Ÿ�� �� �ִ� ���� ���� ���ڰ� 0�̱� ����. 1���� ��Ÿ���°� �Ұ��ϹǷ� if���� �̿��Ͽ� ���� ����Ѵ�)
						player_AttackNum_2_damage(); //���������� �������� �ִ� ��
					}
					if (Scratch_Attack_counts == 1) {
						Scratch_counts = 2;
						player_AttackNum_2_attackcount(); //������ 2���� ��
						for(int i = 0; i < 2; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 2) {
						Scratch_counts = 3;
						player_AttackNum_2_attackcount(); //������ 3�� ��
						for (int i = 0; i < 3; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 3) {
						Scratch_counts = 4;
						player_AttackNum_2_attackcount(); //������ 4�� ��
						for (int i = 0; i < 4; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 4) {
						Scratch_counts = 5;
						player_AttackNum_2_attackcount(); //������ 5�� ��
						for (int i = 0; i < 5; i++)
							player_AttackNum_2_damage();
					}
					endline_player(); //���Ϳ��� ���� ������, ���� HP ���
				}

				if (Attack_Number == 3) { //3. ���� ���ý�..   <���� �� �κ� ������� ���� �������� �������� �ְԲ� �߰��ϱ�>
					player_AttackNum_3(); //3�� �⺻ ����
					player_AttackNum_3_randomnum(); // ����(�����̻�) �����Ұ��� �����ϴ� ��������
					if (Upperkick_Attack > 25) {
						printf("�����̻� ���� ���� �Լ� ����� �߰��ϱ�!!!!");
					}
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
		}
		if (First_select == 3) { //3��. ���α׷� ����
			program_exit();
			break;
		}
	}
}