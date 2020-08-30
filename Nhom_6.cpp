#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;
struct LuanVan
{
	string maluanvan;
	string tenluanvan;
	string hotensv;
	string hotengv;
	int namthuchien;
	int soluong;
	
};
typedef struct LuanVan LUANVAN;

void NhapLuanVan(fstream &FileOut ,LUANVAN &lv);
void NhapLuanVan(fstream &FileOut ,LUANVAN &lv)
{	
	cout << "\nNhap ma luan van: "; fflush(stdin);
	getline(cin, lv.maluanvan);
	FileOut << lv.maluanvan << "\t";
	cout << "Nhap ten luan van: ";
	getline(cin, lv.tenluanvan);
	FileOut << lv.tenluanvan << "\t";
	cout << "Nhap ho ten SV thuc hien: ";
	getline(cin, lv.hotensv);
	FileOut << lv.hotensv << "\t";
	cout << "Nhap ho ten GV huong dan: ";
	getline(cin, lv.hotengv);
	FileOut << lv.hotengv << "\t";
	cout << "Nhap nam thuc hien: ";
    cin >> lv.namthuchien;
    FileOut << lv.namthuchien << "\n";
	
}

void Write(fstream &FileOut, LUANVAN &lv);
void Write(fstream &FileOut, LUANVAN &lv)
{
	FileOut << lv.maluanvan <<"\t";
	FileOut << lv.tenluanvan <<"\t";
	FileOut << lv.hotensv << "\t";
	FileOut << lv.hotengv << "\t";
	FileOut << lv.namthuchien << "\n";
}

void XuatLuanVan(fstream &FileIn, LUANVAN lv);
void XuatLuanVan(fstream &FileIn, LUANVAN lv)
{	
	getline(FileIn, lv.maluanvan,'\t');
	cout << "\nMa luan van: " << lv.maluanvan;
	getline(FileIn, lv.tenluanvan,'\t');
	cout << "\nTen luan van: " << lv.tenluanvan;
	getline(FileIn, lv.hotensv,'\t');
	cout << "\nTen sinh vien thuc hien: " << lv.hotensv;
	getline(FileIn, lv.hotengv,'\t');
	cout << "\nGiang vien huong dan: " << lv.hotengv;
	FileIn >> lv.namthuchien;
	cout << "\nNam thuc hien: " << lv.namthuchien;
	FileIn.ignore();
}

void swap(LUANVAN *a, LUANVAN *b);
void swap(LUANVAN *a, LUANVAN *b)
{
    LUANVAN doi;
    doi=*a;
    *a=*b;
    *b=doi;
}

int sosanh(LUANVAN *a, LUANVAN *b);       
// int sosanh(LUANVAN *a, LUANVAN *b)
// {
// 	if (a->namthuchien>b->namthuchien)
// 	return 1;
// }

int main()
{
	fflush(stdin);
	char fileName[30];
	cout << "\n*******Tao ten File: ";
	cin.get(fileName, 30);			
	LUANVAN lv, *ds;
	int key;
	do{	
		cout << endl;
        cout<<"\t\t\t******************************************\n";
        cout<<"\t\t\t*__________________MENU__________________*\n";
        cout<<"\t\t\t*|     CHUONG TRINH QUAN LY LUAN VAN    |*\n";
        cout<<"\t\t\t*|      1. Nhap thong tin luan van      |*\n";
        cout<<"\t\t\t*|      2. Xuat danh sach luan van      |*\n";
        cout<<"\t\t\t*|      3. DS sau khi sap xep           |*\n";
        cout<<"\t\t\t*|      4. Them 1 luan van vao cuoi DS  |*\n";
        cout<<"\t\t\t*|      5. Tim va xoa luan van theo ten |*\n";
        cout<<"\t\t\t*|      0. Thoat                        |*\n";
        cout<<"\t\t\t*|______________________________________|*\n";
        cout<<"\t\t\t*________________________________________*\n";
        cout<<"\t\t\t******************************************\n";
        cout<<"\t\t\t**       Nhap lua chon cua ban!         **\n";
        cout<<"\nChon: ";
		cin>>key;
		switch(key)
		{
			case 1:
			{
				cout << "\nBan da chon chuc nang nhap thong tin!";
				cout << "\nNhap so luong luan van: ";
				cin >> lv.soluong;
				ds = new LUANVAN[lv.soluong];
				fstream FileOut;
				FileOut.open(fileName, ios::out);
				for(int i=0; i < lv.soluong; ++i)
				{
					cout << "\n*******Nhap thong tin luan van thu "<<i+1;
					NhapLuanVan(FileOut, *(ds+i));
					cout << "\n";
				}
				FileOut.close();
				cout << "\nBan da nhap thanh cong!" << endl;
				system("pause");
				break;
			}
			case 2:
			{	
				cout << "\nBan da chon chuc nang xuat thong tin!";
				fstream FileIn;
				FileIn.open(fileName, ios::in);
				cout << "\n*******Danh sach luan van da nhap: ";
				for(int i=0; i < lv.soluong; ++i)
				{
					cout << "\nThong tin luan van thu "<<i+1;
					XuatLuanVan(FileIn, *(ds+i));
					cout << "\n";
				}
				FileIn.close();
				system("pause");
				break;				
	   		}
	   		case 3:
	   		{	
	   			cout << "\nBan da chon chuc nang sap xep thong tin!";
				fstream fileOut;
				fileOut.open(fileName, ios::out);
				for (int i=0; i < lv.soluong-1; ++i)
				{
            		for (int j=i+1; j<lv.soluong; ++j)
					{
                		if (ds[i].namthuchien > ds[j].namthuchien) 
						swap(ds[i],ds[j]);
            		}
				}
				for(int i=0; i< lv.soluong; ++i)
    			{
    				Write(fileOut,ds[i]);
				}
				fileOut.close();
		
    			fstream fileIn;
				fileIn.open(fileName, ios::in);
				cout<<"\nDanh sach luan van sau khi sap xep: ";
				for(int i=0; i < lv.soluong; ++i)
				{
					cout << "\nThong tin luan van thu "<<i+1;
					XuatLuanVan(fileIn, *(ds+i));
					cout << "\n";
				}
				fileIn.close();
				system("pause");
				break;				
			}
			case 4:
			{
				cout <<"\nBan da chon chuc nang them thong tin!";
				cout <<"\n\n*******Them thong tin 1 luan van moi: \n";
				fstream FileAdd;
				ds = new LUANVAN[lv.soluong+1];
				lv.soluong++;
				FileAdd.open(fileName, ios::app);
				NhapLuanVan(FileAdd, *ds);
				fstream FileListAdd;
				FileListAdd.open(fileName, ios::in);
				FileAdd.close();
				cout << "\n********Danh sach luan van sau khi them moi: ";
				for(int i=0; i < lv.soluong; ++i)
				{
					cout << "\nThong tin luan van thu: " <<i+1;
					XuatLuanVan(FileListAdd, *(ds+i));
					cout << "\n";
				}
				FileListAdd.close();
				system("pause");
				break;				
			}
			case 5:
			{	
				cout<<"\nBan da chon chuc nang tim va xoa thong tin!";
				cout<<"\n==========Nhap ten luan van muon tim thong tin: \n";
				string Search; fflush(stdin);
				getline(cin,Search);
				fstream fSearch;
				for(int i = 0; i < lv.soluong; ++i)
				{
					if (ds[i].tenluanvan == Search)
					{
						XuatLuanVan( fSearch,*(ds+i));
					}
				}	
				fSearch.close();
				
				fflush(stdin);
				string delet;
				cout<<"\n==========Nhap ten luan van de xoa: ";
				getline(cin,delet);
				
				fstream fUpdateDelete;
				fUpdateDelete.open("update.txt", ios::out);
				for (int i = 0; i < lv.soluong; ++i)
				{
					if(ds[i].tenluanvan == delet)
					{
						lv.soluong--;
						for (int j = i; j < lv.soluong; ++j)
						{
							*(ds+j)=*(ds+j+1);
						}
					}
				}
				for(int i=0; i< lv.soluong; ++i)
			    {
			    	Write(fUpdateDelete,ds[i]);
				}
				fUpdateDelete.close();
				
				fstream fListDelete;
				fListDelete.open("update.txt", ios::in);
				cout<<"\n==========Danh sach sau khi xoa 1 luan van:";
				for(int i=0; i< lv.soluong; ++i)
				{
					cout<<"\nThong tin luan van thu "<<i+1;
					XuatLuanVan(fListDelete,*(ds+i));
					cout<<"\n";
				}
				fListDelete.close();
				delete []ds;
				system("pause");
				break;			
			}
			case 0:
			{
            	cout<<"\nBan da chon thoat chuong trinh!\n";
            	system("pause");
                break;
			}
			default:
			{
                cout<<"\nKhong co chuc nang nay!\n";
                system("pause");
                break;
			}
		}
	}while(key != 0);

	return 0;
}
