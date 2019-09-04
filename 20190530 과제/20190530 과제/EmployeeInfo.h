#ifndef _EMPLOYEE_INFO_H_
#define _EMPLOYEE_INFO_H_

#define NAME_LEN 20

#define TRUE 1
#define FALSE 0

typedef struct _employee
{
	char Name[NAME_LEN];  // ��� �̸�
	int EmlpoyeeNum;     // ��� ��ȣ

	//Node* Name[NAME_LEN];  // ��� �̸�
	//Node* EmlpoyeeNum;     // ��� ��ȣ
}Employee;

typedef Employee* LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;

	int numOfData;
} CList;

typedef CList List;

// �ʱ�ȭ
void ListInit(List* plist);

Employee* EInfo(char* name, int num);

// ����Ʈ�� ��� ���� �߰� => ������ �߰��ϴ� �������
void EInfoInsert(List* plist, LData data);

// ù ��° ������� Ȯ��
int EFirst(List* plist, LData* data);

// ���� ������� �̵�
int ENext(List* plist, LData* data);

// �Էµ� ��� ���� ���
void Show_Employee(Employee* pemp);

// �˻� �� �̸��� ������. ������ 0, �ٸ��� 1
int Serch_Overtime_Employee_Name(Employee* pemp, char* name);

// Ư�� ����� �˻�, ���
void Serch_Next(List* plist, LData* data, int num);

// ����Ʈ�� ����� ��� ��
int ECount(List* plist);

#endif // !_EMPLOYEE_INFO_H_
