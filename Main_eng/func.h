/* 변하지 않는 변수들을 저장하는 공간(헤더) */
#ifndef __FUNC_H__
#define __FUNC_H__
#include <stdio.h>

/* 선택지 */
int First_select; //첫번째 선택. 시작, 초기화, 종료중 어떤것을 선택할지 정하는 변수
int Character_select; //두번째 선택. 어떤 캐릭터를 고를지 정하는 변수

/* 캐릭터/몬스터 스탯*/
int Attacker_HP, Attacker_ATK, Attacker_DEF; //Attacker 기본스탯
int Defender_HP, Defender_ATK, Defender_DEF; //Depender 기본스탯
int Allrounder_HP, Allrounder_ATK, Allrounder_DEF; //Allrounder 기본스탯
int Player_HP, Player_ATK, Player_DEF; //실 전투에서 사용하는 스탯(선택한 캐릭터의 능력치를 복사해 사용하는 변수)
int Monster1_HP, Monster1_ATK, Monster1_DEF; //실 전투에서 사용하는 라운드1 몬스터 스탯 

/* 전투중/게임시스템 */
int Attack_Number; // [때리기] [할퀴기] [차기] [베기]의 공격을 정하는 변수
int Damage; //계산한 데미지수를 담는 변수
int Turn; //턴이 얼마나 지나갔나를 알려주는 변수
int monster_Turn; //몬스터가 공격할 차례인지 알려주는 변수
int Scratch_Attack; //랜덤함수에 의한 플레이어 [할퀴기]의 공격성공률
int Scratch_random_number; // [할퀴기]선택시 크리티컬이 뜰지 말지를 정하기위한 랜덤함수를 넣은 변수
int Slash_Attack; //랜덤함수에 의한 플레이어 [베기]공격성공률
int Slash_Attack_random_number; // [베기]선택시 벤 부위(랜덤)에 따라 데미지를 달리하게 만들어주는 변수
int Monster_Attack; //랜덤함수에 의한 몬스터의 공격성공률
int Monster_Attack_random_number; //상대몬스터 턴일시 랜덤한 숫자에 따라 공격방식을 정할 수 있게 하는 변수


void random_num(); //난수생성구문
void title(); //메인타이틀(첫화면) 표시
void choose_character(); //1번. 캐릭터 선택
void reset_data(); //2번, 데이터 리셋
void set_Attacker(); //Attacker 스탯설정
void set_Defender(); //Defender 스탯설정
void set_Allrounder(); //Allrounder 스탯설정

void story(); //전추 시작 전 스토리
void player_act(); //플레이어 행동(공격) 선택
void monster_act(); //몬스터의 턴일때 공격을 준비하는 문구

void endline_player(); //플레이어 공격시 몬스터의 남은 HP등을 출력
void endline_monster(); //몬스터 공?시 플레이어의 남은 HP등을 출력

void player_AttackNum_1(); //플레이어가 1번 공격을 선택했을 때
void player_AttackNum_2(); //플레이어가 2번 공격을 선택했을 때
void player_AttackNum_2_Critical(); //2번 공격 크리티컬시
void player_AttackNum_3(); //플레이어가 3번 공격을 선택했을 때
void player_AttackNum_4(); //플레이어가 4번 공격을 선택했을 때
void player_AttackNum_4_None(); //4번 공격 실패했을 때
void player_AttackNum_4_Normal(); //4번 공격 성공했을 때
void player_AttackNum_4_Critical(); //4번 공격 크리티컬시

void monster_Attack_None(); //몬스터가 공격을 실패했을 때
void monster_Attack_Normal(); //몬스터가 공격을 성공했을 때
void monster_Attack_Critical(); //몬스터가 크리티컬을 성공했을 때


void knockdown_player(); //자신의 HP가 0 이하로 떨어졌을 때
void knockdown_monster(); //상대몬스터의 HP가 0 이하로 떨어졌을 ?
void knockdown_result_turn(); //총 결과 확인


#endif