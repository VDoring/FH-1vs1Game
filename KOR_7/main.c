#include <stdio.h> //버전 5
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num(); //난수 생성

	while (1) {
		title(); //메인화면
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
			}
			story(); //게임 시작 전 스토리
			while (1) {
				if (Character_select == 1) player_Attacker_visual();
				if (Character_select == 2) player_Defender_visual();
				if (Character_select == 3) player_Allrounder_visual();
				player_monster_visual(); //공격방식 선택 전 아스키아트

				player_act(); //공격방식 선택

				if (Attack_Number == 1) { // 1. 몸통박치기 선택시..
					player_AttackNum_1(); // 기본 공격
					player_AttackNum_1_randomnum(); // 충격파(1번 고유 추가공격) 랜덤변수
					if (Bodyhit_Attack <= 10) player_AttackNum_1_Shock0();						   // 10이하일때 : 10
					if (Bodyhit_Attack >= 11 && Bodyhit_Attack <= 26) player_AttackNum_1_Shock1(); // 11이상, 26이하 : 15
					if (Bodyhit_Attack >= 26 && Bodyhit_Attack <= 41) player_AttackNum_1_Shock2(); // 26이상, 41이하 : 15
					if (Bodyhit_Attack >= 41 && Bodyhit_Attack <= 60) player_AttackNum_1_Shock3(); // 41이상, 60이하 : 19
					if (Bodyhit_Attack >= 61 && Bodyhit_Attack <= 75) player_AttackNum_1_Shock4(); // 61이상, 75이하 : 14
					if (Bodyhit_Attack >= 76 && Bodyhit_Attack <= 85) player_AttackNum_1_Shock5(); // 76이상, 85이하 : 9
					if (Bodyhit_Attack >= 86 && Bodyhit_Attack <= 94) player_AttackNum_1_Shock6(); // 86이상, 94이하 : 8
					if (Bodyhit_Attack >= 95) player_AttackNum_1_Shock7();						   // 95이상 : 5
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}

				if (Attack_Number == 2) { // 2. 연속할퀴기 선택시..
					player_Attacknum_2_randomcounts(); // 랜덤변수(몇번 공격할지 결정)
					Damage = 0; //계산 전 데미지값 초기화(필수)
					if (Scratch_Attack_counts == 0) { //만약 랜덤숫자가 0일때
						Scratch_counts = 1; //화면으로 출력할 공격 횟수 : 1
						player_AttackNum_2_attackcount(); // 공격을 1번만 한다고 알림
														  // (랜덤숫자와 공격횟수가 다른 이유는 랜덤함수가 나타낼 수 있는 가장 낮은 숫자가 0이기 때문.)
														  // (1부터 나타내는건 불가하므로 if문을 이용하여 따로 사용한다.)
						player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 함수.
					}
					if (Scratch_Attack_counts == 1) { //만약 랜덤숫자가 1일때
						Scratch_counts = 2; //화면으로 출력할 공격 횟수 : 2
						player_AttackNum_2_attackcount(); //공격 x2
						for(int i = 0; i < 2; i++) //for문을 이용해 데미지를 2번 넣음
							player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 함수.
					}
					if (Scratch_Attack_counts == 2) { //만약 랜덤숫자가 2일때
						Scratch_counts = 3; //화면으로 출력할 공격 횟수 : 3
						player_AttackNum_2_attackcount(); //공격 x3
						for (int i = 0; i < 3; i++) //for문을 이용해 데미지를 3번 넣음
							player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 함수.
					}
					if (Scratch_Attack_counts == 3) { //만약 랜덤숫자가 3일때
						Scratch_counts = 4; //화면으로 출력할 공격 횟수 : 4
						player_AttackNum_2_attackcount(); //공격 x4
						for (int i = 0; i < 4; i++) //for문을 이용해 데미지를 4번 넣음
							player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 함수.
					}
					if (Scratch_Attack_counts == 4) { //만약 랜덤숫자가 4일때
						Scratch_counts = 5; //화면으로 출력할 공격 횟수 : 5
						player_AttackNum_2_attackcount(); //공격 x5
						for (int i = 0; i < 5; i++) //for문을 이용해 데미지를 5번 넣음
							player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 함수.
					}
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}

				if (Attack_Number == 3) { //3. 어퍼킥 선택시..
					player_AttackNum_3(); //기본 공격
					player_AttackNum_3_randomnum(); // 기절(3번 고유 상태이상) 랜덤변수
					if (Upperkick_Attack > 25) {
						printf("상태이상 기절 관련 함수 만들어 추가하기!!!!");
					}
					endline_player();//몬스터에게 입힌 데미지, 남은 HP 출력
				}

				if (Attack_Number == 4) { //4. 참격 선택시..
					player_AttackNum_4(); //기본 공격
					player_AttackNum_4_randomnum(); // 크리티컬(4번 고유 추가공격) 랜덤변수
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
		}
		if (First_select == 3) { //3번. 프로그램 종료
			program_exit();
			break;
		}
	}
}