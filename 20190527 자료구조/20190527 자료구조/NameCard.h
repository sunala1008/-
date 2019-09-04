#ifndef _NAMECARD_H_
#define _NAMECARD_H_

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	// �̸�
	char name[NAME_LEN];

	// ��ȭ��ȣ
	char phone[PHONE_LEN];
} NameCard;

// �̸�, ��ȭ��ȣ ������� �ʱ�ȭ : ������ ����� ����
NameCard* Make_NameCard(char *name, char *phone);

// ����Լ� : ������ ��������� ���
void Show_NameCard(NameCard* pcard); // ??

// �̸��� �˻��ؼ� ������ 0, �ٸ��� 1
int Search_NameCard(NameCard* pcard, char * name);

// ��ȭ��ȣ ���� �Լ�
void Change_PhoneNum(NameCard* pcard, char * phone);

#endif // !_NAMECARD_H_


