/* ������ �ʴ� �������� �����ϴ� ����(���) */
#ifndef __FUNC_H__
#define __FUNC_H__
#include <stdio.h>

/* ������ */
int First_select; //ù��° ����. ����, �ʱ�ȭ, ������ ����� �������� ���ϴ� ����
int Character_select; //�ι�° ����. � ĳ���͸� ���� ���ϴ� ����

/* ĳ����/���� ����*/
int Attacker_HP, Attacker_ATK, Attacker_DEF; //Attacker �⺻����
int Defender_HP, Defender_ATK, Defender_DEF; //Depender �⺻����
int Allrounder_HP, Allrounder_ATK, Allrounder_DEF; //Allrounder �⺻����
int Player_HP, Player_ATK, Player_DEF; //�� �������� ����ϴ� ����(������ ĳ������ �ɷ�ġ�� ������ ����ϴ� ����)
int Monster1_HP, Monster1_ATK, Monster1_DEF; //�� �������� ����ϴ� ����1 ���� ���� 

/* ������/���ӽý��� */
int Attack_Number; // [������] [������] [����] [����]�� ������ ���ϴ� ����
int Damage; //����� ���������� ��� ����
int Turn; //���� �󸶳� ���������� �˷��ִ� ����
int Scratch_Attack; //�����Լ��� ���� �÷��̾� [������]�� ���ݼ�����
int Scratch_random_number; // [������]���ý� ũ��Ƽ���� ���� ������ ���ϱ����� �����Լ��� ���� ����
int Slash_Attack; //�����Լ��� ���� �÷��̾� [����]���ݼ�����
int Slash_Point_random_number; // [����]���ý� �� ����(����)�� ���� �������� �޸��ϰ� ������ִ� ����
int Monster_Attack; //�����Լ��� ���� ������ ���ݼ�����
int Monster_Attack_random_number; //������ ���Ͻ� ������ ���ڿ� ���� ���ݹ���� ���� �� �ְ� �ϴ� ����


void random_num(); //������������
void title(); //����Ÿ��Ʋ(ùȭ��) ǥ��
void choose_character(); //ĳ���� ����
void set_Attacker(); //Attacker ���ȼ���
void set_Defender(); //Defender ���ȼ���
void set_Allrounder(); //Allrounder ���ȼ���

void story(); //���� ���� �� ���丮
void player_act(); //�÷��̾� �ൿ(����) ����

void endline_player(); //�÷��̾� ���ݽ� ���� ���� HP���� ���
void endline_monster(); //
void player_AttackNum_1(); //�÷��̾ 1�� ������ �������� ��
void player_AttackNum_2(); //�÷��̾ 2�� ������ �������� ��
void player_AttackNum_2_Critical(); //2�� ���� ũ��Ƽ�ý�




#endif