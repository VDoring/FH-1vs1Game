#include <stdio.h> //버전 4 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num(); //난수 생성

	while (1) {
		title(); //시작화면이 나타난다
		if (First_select == 1) { //1번. 게임시작 선택시..
			while (1) {
				choose_character(); //캐릭터 선택
				if (Character_select == 1) { //1번. Attacker 선택시..
					set_Attacker(); //Attacker 능력치 설정
					break;
				}
				if (Character_select == 2) { //2번. Defender 선택시..
					set_Defender(); //Defender 능력치 설정
					break;
				}
				if (Character_select == 3) { //3번. Allrounder 선택시..
					set_Allrounder(); //Allrounder 능력치 설정
					break;
				}
				else {
					printf("\n[Please input retry]\n\n");//다른걸 입력시
				}
			}

			story(); //게임 시작 전 스토리

			while (1) {
				player_act(); //공격방식 선택
				if (Attack_Number == 1) { // 1. 때리기 선택시..
					player_AttackNum_1(); // 1번 공격
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}
				if (Attack_Number == 2) { // 2. 할퀴기 선택시..
					player_AttackNum_2(); //2번 공격
					if (Scratch_Attack > 5) { //랜덤숫자가 5보다 클시
						player_AttackNum_2_Critical(); //크리티컬
					}
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}
				if (Attack_Number == 3) { //3. 차기 선택시..   <추후 찬 부분 충격으로 인해 지속적인 데미지를 넣게끔 추가하기>
					player_AttackNum_3(); //3번 공격
					endline_player();//몬스터에게 입힌 데미지, 남은 HP 출력
				}
				if (Attack_Number == 4) { //4. 베기 선택시..
					player_AttackNum_4(); //4번 공격
					if (Slash_Attack <= 2) { //랜덤숫자가 2 이하일시
						player_AttackNum_4_None(); //공격 실패
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //랜덤숫자가 3~6일시
						player_AttackNum_4_Normal(); //공격 성공
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //랜덤숫자가 7~9일시
						player_AttackNum_4_Critical(); //강력한 공격 성공
					}
					endline_player();//몬스터에게 입힌 데미지, 남은 HP 출력
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { // [1]결과계산
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						knockdown_player(); //몬스터 승리 문구 출력
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						knockdown_monster(); //플레이어 승리 문구 출력
					}
					knockdown_result_turn(); //총 진행된 턴수 출력
					break;
				}
				if (monster_Turn % 2 == 0) { //(턴이 짝수일때)몬스터의 턴
					monster_act(); //몬스터 턴 문구 출력, 랜덤숫자 생성
					if (Monster_Attack <= 1) { // 랜덤숫자가 1이하일때
						monster_Attack_None(); // 공격 실패
						endline_monster(); // 플레이어에게 입힌 데미지, 남은 HP 출력
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //랜덤숫자가 2~7일시 공격 성공
						monster_Attack_Normal(); //공격 성공
						endline_monster();//플레이어에게 입힌 데미지, 남은 HP 출력
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //랜덤숫자가 8~9일시 강력한 공격 성공
						monster_Attack_Critical(); //강력한 공격 성공
						endline_monster();//플레이어에게 입힌 데미지, 남은 HP 출력
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { // [1]결과계산
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						knockdown_player(); //몬스터 승리 문구 출력
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						knockdown_monster(); //플레이어 승리 문구 출력
					}
					knockdown_result_turn(); //총 진행된 턴수 출력
					break;
				}
			}
		}
		if (First_select == 2) { //2번. 데이터초기화 시작
			reset_data(); //초기화
			printf("\nReset success.\n\n\n");
		}
		if (First_select == 3) { //3번. 프로그램 종료
			printf("\nProgram exiting...\n");
			break;
		}
		else {
			printf("\n[Please input retry]\n\n"); //첫 메뉴에서 잘못 입력시
		}
	}
	printf("\n\n---Thank you for use this program!---\n\n");
	Sleep(2000); //문구도 못보고 바로 종료되는걸 방지
}


/*

몬스터의 강력한 공격 계산식 수정해보기
상태이상(독, 마비 등) 구현하기

*/