#include <stdio.h>
int main()
{
	/* 선택지 */
	int First_select; //캐릭터를 정하는 변수
	int Second_select; //게임시작과 데이터초기화중 무엇을 선택할지 정하는 변수
	int Number_of_plays; //플레이한 휫수를 저장하는 변수.(게임 시작하기 전에 데이터를 초기화할껀지 말껀지에 대한 판단에 사용)
	int Continue_or_Reset; //캐릭터를 고르고 게임을 시작하기 전 계속할껀지 초기화할껀지 선택하는 변수

	/* 캐릭터와 플레이어 스탯 */
	int Attacker_HP = 130, Attacker_ATK = 120, Attacker_DEF = 50; //Attacker 기본스탯
	int Defender_HP = 200, Defender_ATK = 60, Defender_DRF = 100; //Depender 기본스탯
	int Allrounder_HP = 100, Allrounder_ATK = 100, Allrounder_DEF = 100; //Allrounder 기본스탯
	int Player_HP, Player_ATK, Player_DEF; //실 전투에서 사용하는 스탯(선택한 캐릭터의 능력치를 복사해 사용하는 변수)
	int LV, EXP; //플레이어 경험치

	/* 전투중 */
	int Attack_Num;

	printf("\n[MAIN] --Welcome to HDR 1vs1--\n\n\n"); //메인
	while (1) {
		while (1) {
			printf("<<게임시작은 1번, 데이터초기화는 2번, 종료는 3번을 입력해주세요.>>\n"); //메인선택지
			scanf("%d", &First_select);
			if (First_select != 0) break;
		}
		while (1) {
			if (First_select == 1) {//캐릭터 선택
				printf("\n\n\"캐릭터를 선택하십시오\"\n\n");
				printf(" [1]Attacker - 공격에 특화되어 있습니다.\n [2]Defender - 방어에 특화되어 있습니다.\n [3]Allrounder - 벨런스형입니다.\n\n"); //캐릭터 설명
				scanf("%d", &Second_select);

				if (Second_select == 1) {
					Player_HP = Attacker_HP;
					Player_ATK = Attacker_ATK;
					Player_DEF = Attacker_DEF;
					printf("셋팅성공");//-----------------------------------------------------------------------------이 이후로 교정하기(다른 변수를 써야하나?)
				}

				if (Second_select == 99) { //캐릭터선택을 취소하고 메인화면으로 돌아와야할때
					break;
				}
				if (Number_of_plays > 0) { //이미 전에 플레이했을경우
					printf("당신은 이미 %d플레이 하였습니다.\n플레이하던 데이터가 남아있어 이대로 진행하실 경우 당시의 능력치를 토대로 게임이 진행됩니다.\n", Number_of_plays);
					printf("<<계속하시려면 1번, 데이터초기화는 2번을 입력해주세요.>>\n");
					scanf("%d", &Continue_or_Reset);

					while (1) {
						if (Continue_or_Reset == 1) { //1번.계속하기
							printf("이전 데이터 그대로 게임을 진행합니다.\n\n");
							break;
						}
						if (Continue_or_Reset == 2) {
							Attacker_HP = 130, Attacker_ATK = 120, Attacker_DEF = 50;
							Defender_HP = 200, Defender_ATK = 60, Defender_DRF = 100;
							Allrounder_HP = 100, Allrounder_ATK = 100, Allrounder_DEF = 100;
							LV = 0, EXP = 0;
							printf(" [초기화가 완료되었습니다!] \n");
							break;
						}
						else printf("다시 입력해주세요.\n");
					}
				}

				printf("게임이 시작됩니다!\n");

				printf(" -STAGE 1 : 미지의 세계"); //게임시작. STAGE 1
				printf("\n\n[STORY]\n당신은 길을 가고 있었다.\n하지만 당신이 가는 이 길은 평소에 흉악한 몬스터들이 많이 나타나고, 하필 지금은 밤이라 더 많이 출몰한다.\n 그리고 어느세 당신은 뒤를 쫒고있던 몬스터를 보게 되는데..\n"); //STAGE 1 스토리


				printf("무엇을 할까?\n");
				printf("[1]때리기    [2]할퀴기    [3]차기    [4]베기]\n입력 -> ");
				scanf("%d", &Attack_Num);
			}
			if (First_select == 2) {
				Attacker_HP = 130, Attacker_ATK = 120, Attacker_DEF = 50;
				Defender_HP = 200, Defender_ATK = 60, Defender_DRF = 100;
				Allrounder_HP = 100, Allrounder_ATK = 100, Allrounder_DEF = 100;
				LV = 0, EXP = 0;
				printf(" [초기화가 완료되었습니다!] \n");
				break;
			}
			if (First_select == 3) {
				break;
			}
			else {
				printf("다시 입력해주세요.\n");
				break;
			}
		}
	}
	printf("-> 이용해 주셔서 감사합니다!\n\n");
	return 0;
}

/*
문제점 : 게임이 종료되지 않음. (3번 키를 눌러도)
*/