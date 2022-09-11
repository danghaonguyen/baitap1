#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

/** Cau Truc NhanVien **/
typedef struct 
{
	int maNV;
	char* hoTen;
	int luong;
} NhanVien;

/** Cau truc cua mot Node cho list kieu NhanVien **/
typedef struct Node 
{
	NhanVien Info;		 // Info: Chua thong tin cua Nhan Vien
	Node* pNext;	 	// pNext: Con tro tro toi Node ke tiep
} Node;

/** Cau truc dinh nghia mot Danh sach lien ket kieu NVNode **/
typedef struct 
{
	Node* pHead;  	 // Con tro chi Node dau tien cua list
	Node* pTail; 	// Con tro chi Node cuoi cung cua list
} LinkedList;

//====================================================================================================//

/** ============================= Cac phuong thuc tren DSLK ========================================== **/

/** Tao mot NhanVien moi voi 3 tham so **/
NhanVien CreateNhanVien(int ms, char* hoten, int luong)
{
	NhanVien nv;	
	nv.maNV = ms;
	nv.hoTen = hoten;
	nv.luong = luong;		
	return nv;
}

//====================================================================================================//

/** Tao mot Node moi, voi thong tin la NhanVien (info) **/
Node* CreateNode(NhanVien info) 
{
	Node* node = new Node;	// Cap phat vung nho cho Node	
	node->Info = info;		// Gan thong tin cho Node
	node->pNext = NULL;		// Cho duoi cua node chi ve NULL	
	return node;
}

//====================================================================================================//

/** In node moi **/
void PrintNode(Node* p)
{
	printf("%5d %30s %10d\n", p->Info.maNV, p->Info.hoTen, p->Info.luong );
}

//====================================================================================================//

/** Tao mot DSLK moi **/
void CreateList(LinkedList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

//====================================================================================================//

/** Nhap node moi tu ban phim **/
Node* EnterNewNode()
{
	printf("Nhap Nhan vien moi\n");
	int ma, l;	
	char* ht; // Bien con tro kieu char de chua ten NhanVien
	ht = (char*)malloc(30* sizeof(char)); // Cap phat vung nho cho bien con tro	
	printf("Ma so: "); 
	scanf("%d", &ma);	
	printf("Ho ten: "); 
	fflush(stdin); 
	gets(ht);	
	printf("Luong: "); 
	scanf("%d", &l);
	NhanVien n = CreateNhanVien(ma,ht,l);	
	return CreateNode(n);		
}

//====================================================================================================//



int main()
{
	char* ht[] ={"Nguyen Van An", "Tran Thuy Ai", "Le Phuoc Loc", "Tran Thi Kim Ha", "Van Ngoc Tuong"};
	int ma[N] = {1,2,3,4,5};
	int l[N] = {1000, 1500, 2200, 1800, 1300};
	
	LinkedList myNhanViens;	 //Khai bao list
	CreateList(myNhanViens); //Khoi tao list
	NhanVien nvs;
	
	for (int i = 0; i <N ; i++)
	{
		nvs = CreateNhanVien(ma[i], ht[i], l[i]);
		Node* new_ele; //Khai bao node	
		new_ele = CreateNode(nvs);
		AddFirst(myNhanViens, new_ele); // Dua node vao dau list	
	}	
	PrintList(myNhanViens);
	
	Node *new_ele, *p;
	LinkedList resultList;
	
	return 0;	
}
