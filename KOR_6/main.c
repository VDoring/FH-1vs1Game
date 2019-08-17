#include <stdio.h> //버전 5
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
			}
			story(); //게임 시작 전 스토리
			while (1) {
				player_act(); //공격방식 선택

				if (Attack_Number == 1) { // 1. 때리기 선택시..
					player_AttackNum_1(); // 1번 공격
					if (Bodyhit_Attack == 0) player_AttackNum_1_Shock0();
					if (Bodyhit_Attack == 1) player_AttackNum_1_Shock1();
					if (Bodyhit_Attack == 2) player_AttackNum_1_Shock2();
					if (Bodyhit_Attack == 3) player_AttackNum_1_Shock3();
					if (Bodyhit_Attack == 4) player_AttackNum_1_Shock4();
					if (Bodyhit_Attack == 5) player_AttackNum_1_Shock5();
					if (Bodyhit_Attack == 6) player_AttackNum_1_Shock6();
					if (Bodyhit_Attack == 7) player_AttackNum_1_Shock7();
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}

				if (Attack_Number == 2) { // 2. 할퀴기 선택시..
					player_Attacknum_2_randomcounts(); //랜덤숫자
					Damage = 0; //계산 전 데미지값 초기화(필수)
					if (Scratch_Attack_counts == 0) { //만약 랜덤숫자가 0일때
						Scratch_counts = 1;
						player_AttackNum_2_attackcount(); //공격을 1번만 한다고 알림(랜덤숫자와 공격횟수가 다른 이유는 랜덤함수가 나타낼 수 있는 가장 낮은 숫자가 0이기 때문. 1부터 나타내는건 불가하므로 if문을 이용하여 따로 사용한다)
						player_AttackNum_2_damage(); //실질적으로 데미지를 넣는 곳
					}
					if (Scratch_Attack_counts == 1) {
						Scratch_counts = 2;
						player_AttackNum_2_attackcount(); //공격을 2번만 함
						for(int i = 0; i < 2; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 2) {
						Scratch_counts = 3;
						player_AttackNum_2_attackcount(); //공격을 3번 함
						for (int i = 0; i < 3; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 3) {
						Scratch_counts = 4;
						player_AttackNum_2_attackcount(); //공격을 4번 함
						for (int i = 0; i < 4; i++)
							player_AttackNum_2_damage();
					}
					if (Scratch_Attack_counts == 4) {
						Scratch_counts = 5;
						player_AttackNum_2_attackcount(); //공격을 5번 함
						for (int i = 0; i < 5; i++)
							player_AttackNum_2_damage();
					}
					endline_player(); //몬스터에게 입힌 데미지, 남은 HP 출력
				}

				if (Attack_Number == 3) { //3. 차기 선택시..   <추후 찬 부분 충격으로 인해 지속적인 데미지를 넣게끔 추가하기>
					player_AttackNum_3(); //3번 기본 공격
					player_AttackNum_3_randomnum(); // 기절(상태이상) 적용할건지 결정하는 랜덤숫자
					if (Upperkick_Attack > 25) {
						printf("상태이상 기절 관련 함수 만들어 추가하기!!!!");
					}
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
		}
		if (First_select == 3) { //3번. 프로그램 종료
			program_exit();
			break;
		}
	}
}