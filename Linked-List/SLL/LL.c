#include "LL.h"

//노드 생성
Node *SLL_CreateNode(ElementType NewData)
{
	Node *NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData; // 데이터 저장
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화

	return NewNode; // 노드의 주소 값 반환
}

// 노드 소멸
void SLL_DestroyNode(Node *Node)
{
	free(Node);
}

// 노드 추가
void SLL_AppendNode(Node **Head, Node *NewNode)
{

	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	 if ((*Head)==NULL)
		*Head = NewNode;
	else
	{
		// 테일을 찾아  NewNode를 연결한다.
		Node *Tail = (*Head);
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
	}
}

// 노드 삽입
void SLL_InsertAfter(Node *Current, Node *NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
	if (Head == NULL)
		(*Head) = NewHead;
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// 노드 제거
void SLL_RemoveNode(Node **Head, Node *Remove)
{
	if (*Head == Remove)
		*Head = Remove->NextNode;
	else
	{
		Node *Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
			Current = Current->NextNode;
		if (Current!=NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// 노드 탐색
Node *SLL_GetNodeAt(Node *Head, int Locataion)
{
	Node *Current = Head;

	while (Current != NULL && (--Locataion) >= 0)
		Current = Current->NextNode;
	return Current;
}

// 노드 개수 세기
int SLL_GetNodeCount(Node *Head)
{
	int Count = 0;
	Node *Current = Head;

	while (Current!=NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}