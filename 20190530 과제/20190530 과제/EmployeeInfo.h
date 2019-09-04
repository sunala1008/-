#ifndef _EMPLOYEE_INFO_H_
#define _EMPLOYEE_INFO_H_

#define NAME_LEN 20

#define TRUE 1
#define FALSE 0

typedef struct _employee
{
	char Name[NAME_LEN];  // 사원 이름
	int EmlpoyeeNum;     // 사원 번호

	//Node* Name[NAME_LEN];  // 사원 이름
	//Node* EmlpoyeeNum;     // 사원 번호
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

// 초기화
void ListInit(List* plist);

Employee* EInfo(char* name, int num);

// 리스트에 사원 정보 추가 => 꼬리에 추가하는 방식으로
void EInfoInsert(List* plist, LData data);

// 첫 번째 사원인지 확인
int EFirst(List* plist, LData* data);

// 다음 사원으로 이동
int ENext(List* plist, LData* data);

// 입력된 사원 정보 출력
void Show_Employee(Employee* pemp);

// 검색 중 이름이 같은지. 같으면 0, 다르면 1
int Serch_Overtime_Employee_Name(Employee* pemp, char* name);

// 특근 출근자 검색, 출력
void Serch_Next(List* plist, LData* data, int num);

// 리스트에 저장된 사원 수
int ECount(List* plist);

#endif // !_EMPLOYEE_INFO_H_
