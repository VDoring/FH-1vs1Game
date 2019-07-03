#include <stdio.h> //버전 4
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num();

	while (1) { // 1번재 While
		title();
		if (First_select == 1) { //1번. 게임시작
			while (1) { // 2번째 While
				choose_character();
				if (Character_select == 1) { //1번. Attacker 선택시..
					set_Attacker();
					break; //2번째 반복문 벗어남
				}
				if (Character_select == 2) { //2번. Defender 선택시..
					set_Defender();
					break; //2번째 반복문 벗어남
				}
				if (Character_select == 3) { //3번. Allrounder 선택시..
					set_Allrounder();
					break; //2번째 반복문 벗어남
				}
				else {
					puts("다시 입력하십시오"); //잘못된 값을 입력시
				}
			} //반복문 1 끝
			story();
			while (1) { // 3번째 While
				player_act();
				if (Attack_Number == 1) { // 1. 때리기 선택시
					player_AttackNum_1();
					endline_player();
				}
				if (Attack_Number == 2) { // 2. 할퀴기 선택시
					player_AttackNum_2();
					if (Scratch_Attack > 5) { //만약 랜덤숫자가 5보다 클시
						player_AttackNum_2_Critical();
					}
					endline_player();
				}
				if (Attack_Number == 3) { //차기 선택시 <추후 찬 부분 충격으로 인해 지속적인 데미지를 넣게끔 추가하기>
					player_AttackNum_3();
					endline_player();
				}
				if (Attack_Number == 4) { //베기 선택시
					player_AttackNum_4();
					if (Slash_Attack <= 2) { //만약 랜덤숫자가 2이하일시 공격실패함
						player_AttackNum_4_None();
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //만약 랜덤숫자가 3~6일시 공격 성공
						player_AttackNum_4_Normal();
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //만약 랜덤숫자가 7~9일시 강력한 공격 성공
						player_AttackNum_4_Critical();
					}
					endline_player();
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //결과계산 1.
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						knockdown_player();
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						knockdown_monster();
					}
					knockdown_result();
					break;
				}
				if (Turn % 2 == 0) { //(턴이 짝수일때)몬스터의 턴
					monster_act();
					if (Monster_Attack <= 1) { //만약 랜덤숫자가 1이하일때 공격실패함
						monster_Attack_None();
						endline_monster();
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //만약 랜덤숫자가 2~7일시 공격 성공
						monster_Attack_Normal();
						endline_monster();
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //만약 랜덤숫자가 8~9일시 강력한 공격 성공
						monster_Attack_Critical();
						endline_monster();
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //결과계산 1.
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						knockdown_player();
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						knockdown_monster();
					}
					knockdown_result();
					break;
				}
			}
		}
		if (First_select == 2) { //2번. 데이터초기화 시작
			reset_data();
		}
		if (First_select == 3) { //3번. 프로그램 종료
			printf("\n프로그램이 종료됩니다.\n");
			break; //1번째 반복문 벗어남
		}
	}
	printf("\n\n---사용해주셔서 감사합니다---\n\n");
	Sleep(2000);
}

/*
몬스터의 강력한 공격 계산식 수정하기
상태이상(독, 마비 등) 구현하기
*/