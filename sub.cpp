#include <string>
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

int sosanh(LUANVAN *a, LUANVAN *b);       
int sosanh(LUANVAN *a, LUANVAN *b)
{
	if (a->namthuchien>b->namthuchien)
	return 1;
}