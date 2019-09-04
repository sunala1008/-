#ifndef _NAMECARD_H_
#define _NAMECARD_H_

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	// 이름
	char name[NAME_LEN];

	// 전화번호
	char phone[PHONE_LEN];
} NameCard;

// 이름, 전화번호 멤버변수 초기화 : 명함을 만들기 위해
NameCard* Make_NameCard(char *name, char *phone);

// 출력함수 : 명함의 멤버변수를 출력
void Show_NameCard(NameCard* pcard); // ??

// 이름을 검색해서 같으면 0, 다르면 1
int Search_NameCard(NameCard* pcard, char * name);

// 전화번호 변경 함수
void Change_PhoneNum(NameCard* pcard, char * phone);

#endif // !_NAMECARD_H_


