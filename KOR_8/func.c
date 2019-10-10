/* 계산식 등이 들어간 함수들을 모아놓는 곳 */
/* 이곳은 자작 헤더파일을 include 하지않음 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

/* 기타 꾸미기 */
int loop; //별을 깜빡거리게 할때 필요한 변수

/* 선택지 */
int First_select; //첫번째 선택. 시작, 초기화, 종료중 어떤것을 선택할지 정하는 변수
int Character_select; //두번째 선택. 어떤 캐릭터를 고를지 정하는 변수

/* 캐릭터/몬스터 스탯*/
int Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100; //Attacker 기본스탯
int Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200; //Depender 기본스탯
int Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150; //Allrounder 기본스탯
int Player_HP, Player_ATK, Player_DEF; //실 전투에서 사용하는 스탯(선택한 캐릭터의 능력치를 복사해 사용하는 변수)
int Monster1_HP = 3200, Monster1_ATK = 500, Monster1_DEF = 100; //실 전투에서 사용하는 라운드1 몬스터 스탯 

/* 전투중/게임시스템 */
int Attack_Number; // [때리기] [할퀴기] [차기] [베기]의 공격을 정하는 변수
int Damage; //계산한 데미지수를 담는 변수
int Turn = 1; //턴이 얼마나 지나갔나를 알려주는 변수
int monster_Turn = 0; //몬스터가 공격할 차례인지 알려주는 변수
int Bodyhit_Attack; //랜덤함수에 의한 플레이어 [몸통박치기]의 추가 데미지를 정하기 위한 랜덤함수를 넣은 변수
int Bodyhit_Attack_random_number; //[몸통박치기] 선택시 충격으로 인한 추가데미지를 얼마나 받을건지를 정하는 변수
int Scratch_Attack_counts; //[연속할퀴기] 공격을 몇번 할껀지 정하는 변수
int Scratch_Attack_counts_random_number; //랜덤함수에 의한 [연속할퀴기]를 몇번 공격하게 할건지 정하는 변수
int Scratch_counts; //[연속할퀴기] 기술을 몇번 사용했는지 출력할때 사용하는 변수
int Scratch_Attack; //랜덤함수에 의한 플레이어 [할퀴기]의 공격성공률
int Scratch_Attack_random_number; // [할퀴기]선택시 크리티컬이 뜰지 말지를 정하기위한 랜덤함수를 넣은 변수
int Upperkick_Attack_random_number; //[어퍼킥]의 기절 (상태이상)의 확률을 정하는 변수
int Upperkick_Attack; //랜덤함수에 의한 기절 상태이상을 할지 안할지 결정하는 변수
int Slash_Attack; //랜덤함수에 의한 플레이어 [베기]공격성공률
int Slash_Attack_random_number; // [베기]선택시 벤 부위(랜덤)에 따라 데미지를 달리하게 만들어주는 변수
int Monster_Attack; //랜덤함수에 의한 몬스터의 공격성공률
int Monster_Attack_random_number; //상대몬스터 턴일시 랜덤한 숫자에 따라 공격방식을 정할 수 있게 하는 변수


gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void random_num() { //랜덤한 숫자를 나타나게하는 구문(난수 생성)
	srand((unsigned int)time(NULL));
}

void title() { //메인타이틀(첫화면) 표시
	int x = 44, y = 5;
	system("mode con cols=120 lines=35"); //**창 가로크기 120, 세로크기 40 설정
	gotoxy(x, y + 0); printf("______               ___  ___"); Sleep(70); //총 가로길이 29
	gotoxy(x, y + 1); printf("| ___ \\              |  \\/  |"); Sleep(70);
	gotoxy(x, y + 2); printf("| |_/ / __   __ ___  | .  . |"); Sleep(70);
	gotoxy(x, y + 3); printf("|  __/  \\ \\ / // __| | |\\/| |"); Sleep(70);
	gotoxy(x, y + 4); printf("| |      \\ V / \\__ \\ | |  | |"); Sleep(70);
	gotoxy(x, y + 5); printf("\\_|       \\_/  |___/ \\_|  |_/"); Sleep(70);
	gotoxy(x, y + 8); printf("        [1] 게임 시작"); Sleep(5);
	gotoxy(x, y + 10); printf("        [2] 초기화"); Sleep(5);
	gotoxy(x, y + 12); printf("        [3] 종료"); Sleep(150);
	gotoxy(x, y + 15); printf("  Input  :  ");
	gotoxy(x + 13, y + 15); scanf("%d", &First_select);  //번호 입력
	if (First_select != 1 && First_select != 2 && First_select != 3) {
		gotoxy(x + 4, y + 18); printf("[잘못 입력한건 아닐까?]"); Sleep(700);
	}
}

void choose_character() { //캐릭터 선택
	int x = 15, y = 4;
	system("mode con cols=100 lines=25"); //**창 가로크기 120, 세로크기 40 설정
	gotoxy(x - 4, y); printf("===========================[캐릭터를 선택하십시오]===========================\n"); Sleep(100); //캐릭터 선택 문구
	gotoxy(x + 1, y + 3);  printf(" [1] Attacker - 공격에 특화되어 있음."); Sleep(50);//캐릭터 설명
	gotoxy(x + 1, y + 5);  printf(" [2] Defender - 방어에 특화되어 있음."); Sleep(50);//캐릭터 설명
	gotoxy(x + 1, y + 7);  printf(" [3] Allrounder - 균형잡힌 능력."); Sleep(50);//캐릭터 설명
	gotoxy(x + 26, y + 10); printf("Input  :  ");
	gotoxy(x + 37, y + 10);  scanf("%d", &Character_select);
	if (Character_select != 1 && Character_select != 2 && Character_select != 3) {
		gotoxy(x + 22, y + 13); printf("[그건 없는 캐릭터야!]"); Sleep(700);
	}
}

void reset_data() { //2번. 초기화 실행시
	int x = 44, y = 5;
	Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
	Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
	Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
	Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
	First_select = 0;
	Character_select = 0;
	Turn = 1, monster_Turn = 0;
	gotoxy(x + 2, y + 18); printf("[초기화가 완료되었습니다.]"); Sleep(900);
}

void program_exit() { //3번, 프로그램 종료 실행시
	int x = 44, y = 5;
	gotoxy(x + 2, y + 18);  printf("종료중..."); Sleep(100);
	gotoxy(x + 2, y + 20);  printf("[사용해주셔서 감사합니다]"); Sleep(1500);
}

void set_Attacker() { //Attacker 능력치 설정
	int x = 15, y = 4;
	Player_HP = Attacker_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Attacker_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Attacker_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	gotoxy(x + 18, y + 13); printf("{ 당신은 이제 Attacker입니다..! }"); Sleep(1000);
}

void set_Defender() { //Defender 능력치 설정
	int x = 15, y = 4;
	Player_HP = Defender_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Defender_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Defender_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	gotoxy(x + 18, y + 13); printf("{ 당신은 이제 Defender입니다..! }"); Sleep(1000);
}

void set_Allrounder() { //Allrounder 능력치 설정
	int x = 15, y = 4;
	Player_HP = Allrounder_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Allrounder_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Allrounder_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	gotoxy(x + 18, y + 13);  printf("{ 당신은 이제 Allrounder입니다..! }"); Sleep(1000);
}

void story() { //STAGE 1 스토리
	int x = 47, y = 2;
	system("mode con cols=110 lines=37");
	gotoxy(x, y); printf("[ 스토리 ]");
	gotoxy(x - 15, y + 4); printf("미로의 함정에 빠진 나.");
	gotoxy(x - 15, y + 6); printf("사방에서 몰려오는 몬스터들.");
	gotoxy(x - 15, y + 8); printf("동료들도 하나둘씩 쓰러져가고..");
	gotoxy(x - 15, y + 12); printf("위기라고 느낀 순간");
	gotoxy(x - 15, y + 14); printf("최종보스의 위엄을 뽐내며");
	gotoxy(x - 15, y + 16); printf("한 몬스터가 나에게 결투를 신청하였다");
	gotoxy(x - 15, y + 21); printf("부하 몬스터가 지켜보는 앞에서 최후의 결투가 시작되었다");
	gotoxy(x - 15, y + 24); printf("...최후의 싸움을 위해");
	gotoxy(x + 2, y + 28); printf("\"간다..!\"");
	system("mode con cols=170 lines=57");
}

void player_Attacker_visual() {
	int x = 0, y = 0; system("cls");
	/*
	gotoxy(x, y); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 1); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxldk00OxxkOXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 2); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWK0x:,'..''.....oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 3); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo;,,,'...';ldolOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 4); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o:,,''...,okOxdONMMN0XMMMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 5); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o:,'....;loxxkdclkOxl:o0WMMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 6); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo:;;;:lc:cooollc::cc::::lkNMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 7); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMWOc;;;:odddocc:;;clllc:;;;;;;:dXMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 8); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMW0c,,:odxxxdl:;;:llccc:;::;;',oXMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 9); printf("MMMMMMMMMMMMMMMMMMMMMMMMMWX0xc,;llccool:,,'',,,;;:cc;,;:coOXWMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 10); printf("MMMMWWMMMMMMMMMMMMMMMMMMMXdcc;,:ccldxxoc:,.'','',;;;:lxxdocxNMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 11); printf("MMMWNXKKXNWWMMWWMMMMMMMNKkool;;;:clloll:;,,,,,',,;:;:cclol:ckNMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 12); printf("MMMMWNX0kddxkOkdxOKKKkxdodoc;',;;;;,,,;:;,,,'',;cl:;:odc'',,;dXMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 13); printf("MMMMMMMWNKkd:,'.',;::;;:c:;,'.,:,',,'',,,''',:lxKKo:ldl;'',;;ckNMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 14); printf("MMMMMMMMMMMWKx:.....',,:ooo:,',;;;;;:;;,,,;cxOXWNkooolcll:;::ckNMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 15); printf("MMMMMMMMMMMNOdl:,'.',,';dO0o:col:loxxdo:,;oKWWX0xlcccloddodxOKNMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 16); printf("MMMMMMMMMMMMWWNX0OOKXXkc;::c:ldc:k0KNKkc;coOKkloxkkxollckNWMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 17); printf("MMMMMMMMMMMMMMMMMMMMNOdc::c:;::,lOOk0Oxc;;ckXK0KNWMMN0dcxNWXNMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 18); printf("MMMMMMMMMMMMMMMMMMWKxc:::lc;:loclddkKKkl;,,oXWX0kxxxOOxoxOklo0NMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 19); printf("MMMMMMMMMMMMMMMMMMNkl::ll:;cdxxocldxOkxol:,;kNWMWXOd:,',,;,;:cxXWMMMMMMMMMMMMMMM");
	gotoxy(x, y + 20); printf("MMMMMMMMMMMMMMMMW0o:;;cc;;cdxdccllolldxddo::ccokKXNNXx,....';clx0NMMMMMMMMMMMMMM");
	gotoxy(x, y + 21); printf("MMMMMMMMMMMMMMMNOl;;::,,;:cc;'':c;:llxOOOkl::;cl:;:lol,',;::cloddkXWMMMMMMMMMMMM");
	gotoxy(x, y + 22); printf("MMMMMMMMMMMMMMMKdol:;'';::;,'';:ccloodkkkko:::dXKd;..''',:clooodxdx0NMMMMMMMMMMM");
	gotoxy(x, y + 23); printf("MMMMMMMMMMMMMMWOool;.,:::;,,,;::lodddlc:::c:;cckWWKd;''''';:clllodk0NWMMMWMMMMMM");
	gotoxy(x, y + 24); printf("MMMMMMMMMMMMMMXo::;,,:c:;;;:cccclddxkl,;c:,'';:lKWNNOl;,''..',:clodkKXWMWXNMMMMM");
	gotoxy(x, y + 25); printf("MMMMMMMMMMMMMM0c;;;;;;;;ckOdllccoxkKNd,;c:;;,,:okXKO0XKOkd;...,:clloxkOKNX0XMMMM");
	gotoxy(x, y + 26); printf("MMMMMMMMMMMMMM0c,;;;;,;;oXNkddxOK0KWXd;;:;;:;;:cokO0kkO0KKd,',,;clodddxkXNOONMMM");
	gotoxy(x, y + 27); printf("MMMMMMMMMMMMMWO:,,,,;;:dKWWNNWWMWWWXkocc::;;;;;::odkKKkddol:;;;:clddxxdkXWKx0WMM");
	gotoxy(x, y + 28); printf("MMMMMMMMMMMMMNx::;;:coONMMMMMMMMMMWNXXKOkd:;;:ccccodKWNKkddolcclllodxxxx0X0xxKWM");
	gotoxy(x, y + 29); printf("MMMMMMMMMMWWNOolccld0NMMMMMMMMMMMMMMMMMMMNklccloolooOWMWNKOxxxdoooodxxxxxkkkxONM");
	gotoxy(x, y + 30); printf("MMMMMMMMMWKkxdoold0WMMMMMMMMMMMMMMMMMMMMMMWN0OxdddookXMMMWNKOOOkxxddxxxkkxkkkkXM");
	gotoxy(x, y + 31); printf("MMMMMMMMWKkxxddddxKMMMMMMMMMMMMMMMMMMMMMMMMMMMNKkddddONWMMMWWNK000OOkkkOOkkkkOXM");
	gotoxy(x, y + 32); printf("MMMMMMMMN0kxxxxxk0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOxkkxOKXWMMMMWNXKKKK0O0000O0KNM");
	gotoxy(x, y + 33); printf("MMMMMMMWXOkkkk0KKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0OOOkkOOKNMMMMMMWNNXXKKXNXXXNWM");
	gotoxy(x, y + 34); printf("MMMMMMMNK0OOOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0O00OOO0KNWMMMMMMMMWWNNNNNNNWMM");
	gotoxy(x, y + 35); printf("MMMMMMWX00KKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXKKK00XWMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 36); printf("MMMMMMMWNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKXKKXWMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 37); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNWMMMMMMMMMMMMMMMMMMMMMMM");
	gotoxy(x, y + 38); printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	*/

	gotoxy(x, y); printf("      .,;;;;;;;::::::cccccccccccccclllllllllllcllllllllllllllllllclcllcccccccc:::;;::");
	gotoxy(x, y + 1); printf("      .,;;;;;;;;;:::::cccllllcllclllllolllllllcllllllllllllllcllcllcllcccccccc::c;;::");
	gotoxy(x, y + 2); printf("      .,cccccccccllloddl:cc;,;lddddol;;,;lddddloxdddddddddddddddddoododdooooooloo::ll");
	gotoxy(x, y + 3); printf("      .;lllllloddddddxxo:'.':dxdxko,. .':dkkkdodxxxxxxxxxxxxxxxxxxxxxxxxddddddddd::oo");
	gotoxy(x, y + 4); printf("      .;cllooooodoooodddxc...:l:;:,.':ldkOOkkxodkkkxxxxkxxxxxxxxxxxxxxxxxxxddddddc:od");
	gotoxy(x, y + 5); printf("      .:olllcccllooddoc::;'.. .''.'';:;',codkxoxkxxxdxkxxxkkxxxxxxxxxxxxxxxxdddddccdd");
	gotoxy(x, y + 6); printf("    .',;'.......'cddl;.... ...''''...','',,;:c:;;cc'.,;,cddoddoooooooodooddddddddlcod");
	gotoxy(x, y + 7); printf("    .. .        'ldl;'...  .:;....,;,,,..........;.    ':c:loooooooooooooooooooooc:od");
	gotoxy(x, y + 8); printf("       ....',,',:looooooc.  .. ...,lo:'...      ',. .,oxkxxkxxxkkkxxkxxxxxxxxxdooc:lo");
	gotoxy(x, y + 9); printf("         .....''''''',,,,'.......,cdxc...    ...',,;oxxxxxxdxxxxxxxxddxddxdddd:'....,");
	gotoxy(x, y + 10); printf("               ..............',;:odkd,..   ...',;:odddooooooooooooooooooolllll:......");
	gotoxy(x, y + 11); printf("  ......'',;;;;::::cc:c:,,,..';lloxko'   ..,;;;;;;cdxxxxxxddxxddddddddddoooooo:......");
	gotoxy(x, y + 12); printf("llooddxkOOOOOO000000K0Oxlcc'.''';oxdd,  ,dOO0OOOkkkO0OO0OOOOOOOOOOOOOOOOOkkkkkdoooodd");
	gotoxy(x, y + 13); printf("0KKKKKKKKKKXXXXXXXXXOxk0xl:.......,:ol..xXXXXXXXXXXXXXXXXXXXXKKXXKKKKKKKKKKKKKK000000");
	gotoxy(x, y + 14); printf("KKXXXXXXXX0dooodxOO0kllc:;'''''..  .,o;cKXXXKK0O00OOOkkxdddddx0XXXXXXXKKKKKKKKKKKKK00");
	gotoxy(x, y + 15); printf("KKXXXXXXKOo:;;,,,,;cc;,:::;''',''..,ld;'cllcccc:coddollc:clccokKXXXXXXXXKKKKKKKKKKK00");
	gotoxy(x, y + 16); printf("KKKKKKKOo::;,'...',;ccccclcc:;,''',:c,''......''';:ccokOxdolcoOXXXXXXKKKKKKKKK0000000");
	gotoxy(x, y + 17); printf("0000000Oko:;,...;lo:;:;;,'.....':ldo:;oddool:'.....  ,OXXXK0OOKKKKKKKK000000000000OOO");
	gotoxy(x, y + 18); printf("OOO00Od:;,''....'',,,,,.....',;codxxdxO0KKKXX0dl;....:k0KXXKKKKKKKKKK000000KK00000000");
}

void player_Defender_visual() {
	int x = 0, y = 0; system("cls");
	gotoxy(x, y); printf("디펜더 아스키아트");
}

void player_Allrounder_visual() {
	int x = 0, y = 0; system("cls");
	gotoxy(x, y); printf("올라운더 아스키아트");
}

void player_monster_visual() {
	int x = 0, y = 0;
	gotoxy(x + 85, y); printf("몬스터 아스키아트");
}

void player_act() { //플레이어의 턴. 행동을 취한다
	while (1) {

		int x = 47, y = 0;
		gotoxy(x - 43, y+19); printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"); Sleep(100);
		gotoxy(x + 30, y + 21); printf("== 무엇을 할까? =="); Sleep(200);
		gotoxy(x + 3, y + 24); printf("[1] 몸통박치기        [2] 연속할퀴기        [3] 어퍼킥        [4] 참격"); //어떻게 공격할건지 선택
		gotoxy(x + 38, y + 27); printf(": ");
		gotoxy(x + 39, y + 27); scanf("%d", &Attack_Number);
		if (Attack_Number >= 5 || Attack_Number <= 0) {
			printf("\n[다시 입력해주세요]\n\n");
		}
		else break;
	}
}

void player_AttackNum_1() { // 1. 때리기 선택시..
	system("cls"); Sleep(400);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn); Sleep(1000);
	printf("\n당신은 상대를 때렸습니다.");
	Damage = Player_ATK / 3; //몸통박치기 고정 공격력
	Damage -= Monster1_DEF / 3; //몬스터 방어력에 따른 고정 피해 감소(방어력)
}

void player_AttackNum_1_randomnum() {
	Bodyhit_Attack_random_number = rand();
	Bodyhit_Attack = (int)Bodyhit_Attack_random_number % 101; //랜덤숫자 0~100
}

void player_AttackNum_1_Shock0() { //추후 밸런스 패치 필요
	printf("아프기만 할 뿐, 상대는 아무런 충격도 느끼지 못했습니다.");
}

void player_AttackNum_1_Shock1() {
	Damage += Damage / 30;
	printf("상대는 겉피부에 미약한 충격을 느꼈습니다.");
}

void player_AttackNum_1_Shock2() {
	Damage += Damage / 25;
	printf("상대는 겉피부에 약한 충격이 왔음을 인지했습니다.");
}

void player_AttackNum_1_Shock3() {
	Damage += Damage / 20;
	printf("상대는 겉피부에 충격이 감도는 걸 느끼고 있습니다.");
}

void player_AttackNum_1_Shock4() {
	Damage += Damage / 15;
	printf("상대는 내장에 조금이나마 충격을 받았음을 인지했습니다");
}

void player_AttackNum_1_Shock5() {
	Damage += Damage / 10;
	printf("상대는 내장까지 충격이 가 고통스러워합니다.");
}

void player_AttackNum_1_Shock6() {
	Damage += Damage / 5;
	printf("상대는 전신이 울릴만한 충격에 힘겨워하고 있습니다.");
}

void player_AttackNum_1_Shock7() {
	Damage += Damage / 2;
	printf("강력한 충격에 상대는 혼란해합니다.");
}

void player_Attacknum_2_randomcounts() {
	Scratch_Attack_counts_random_number = rand();
	Scratch_Attack_counts = (int)Scratch_Attack_counts_random_number % 5; //랜덤숫자를 0~4로 만듬
}

void player_AttackNum_2_attackcount() { // 2. 할퀴기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("당신은 상대를 %d번 할퀴었습니다.", Scratch_counts);
}

void player_AttackNum_2_damage() {
	Damage += Player_ATK / 3; //플레이어 공격력 나누기 3
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void player_AttackNum_3() { //3. 차기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("\n당신은 어퍼킥을 떄렸습니다.");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
}

void player_AttackNum_3_randomnum() {
	Upperkick_Attack_random_number = rand();
	Upperkick_Attack = (int)Upperkick_Attack_random_number % 30; //랜덤숫자를 0~29로 만듬
}

void player_AttackNum_3_Faint() {
	printf("기절기절기절"); //기절 상태이상 관련 기능 추가
}

void player_AttackNum_4() { //4. 베기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("당신은 상대를 ");
}

void player_AttackNum_4_randomnum() {
	Slash_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Slash_Attack = (int)Slash_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void player_AttackNum_4_None() { //4. 베기 실패
	printf("베지 못했습니다.\n");
	Damage = 0;
}

void player_AttackNum_4_Normal() { //4. 베기 성공
	printf("베었습니다.\n");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void player_AttackNum_4_Critical() { //4. 강력한 베기 성공
	printf("제대로 베었습니다.\n");
	Damage = Player_ATK; //강력한 공격이므로 플레이어 공격력 그대로 데미지가 들어감
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void endline_player() { //플레이어 턴일때 상황정리
	Sleep(1000);
	printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
	Sleep(1500);
	Monster1_HP -= Damage; //몬스터의 채력 - 데미지
	printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
	Sleep(1000);
	monster_Turn += 2;
	printf("\n\n==============================================================================\n\n");
}

void endline_monster() { //몬스터 턴일때 상황정리
	Sleep(1500);
	printf("\n\n\n=딩신의 Hp : %d", Player_HP); //남은 플레이어의 채력 출력
	Turn++; //턴 증가
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}

void monster_act() { //몬스터 턴, 몬스터가 행동을 취함
	Sleep(1200);
	printf("\n\n==============================================================================\n\n");
	Sleep(1000);
	printf("상대 몬스터의 턴입니다.\n");
	Monster_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Monster_Attack = (int)Monster_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void monster_Attack_None() { //몬스터 공격 실패
	Sleep(1000);
	printf("\n몬스터가 공격을 실패했습니다.");
	Damage = 0;
}

void monster_Attack_Normal() { //몬스터 공격 성공
	Sleep(1000);
	printf("\n몬스터가 공격을 했습니다.");
	Damage = Monster1_ATK / 3; //데미지는 몬스터 공격력의 나누기 3
	Damage -= Player_DEF / 4; //데미지에서 플레이어 방어력 나누기 4한만큼 빼기
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void monster_Attack_Critical() { //몬스터 강력한 공격 성공
	Sleep(1000);
	printf("\n몬스터가 강력한 공격을 했습니다!");
	Damage = Monster1_ATK; //강력한 공격이므로 몬스터의 공격력 그대로 들어감
	Damage -= (Player_DEF / 2) + Damage / 4; // < (Player_DEF / 2.5로 구현할려고 함.  Release버전으로 맞춘 상태이고. 원래 구현하려고 했던 것보다 데미지 적음) >
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void knockdown_player() { //플레이어 HP가 0 이하일때. (즉 플레이어가 쓰러졌을때)
	printf("\n\n\n\t\t리타이어! 여기까지!"); //전투 종료
	Sleep(500);
	printf("\n\t\t승자 : 몬스터"); //몬스터 승리!
	Sleep(800);
}

void knockdown_monster() { //몬스터 HP가 0 이하일때. (즉 몬스터가 쓰러졌을때)
	printf("\n\n\n\t\t리타이어! 여기까지!"); //전투 종료
	Sleep(500);
	printf("\n\t\t승자 : 플레이어"); //플레이어 승리!
	Sleep(800);
}

void knockdown_result_turn() {
	printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn); //턴 수 출력
	printf("\n\n==============================================================================\n\n");
}


/*

몬스터의 강력한 공격 계산식 수정해보기
상태이상(독, 마비 등) 구현하기
1번 이상 플레이시 스토리 스킵할 수 있는 기능 추가

*/