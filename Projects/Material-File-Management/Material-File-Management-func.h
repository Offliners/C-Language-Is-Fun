#define FILEDATA "Data/materialList.txt"
#define FILE_TXT1 "Output/sortID.txt"
#define FILE_TXT2 "Output/sortObjectType.txt"
#define FILE_TXT3 "Output/sortMaterial.txt"
#define FILE_TXT4 "Output/sortVolumn.txt"
#define FILE_TXT5 "Output/sortWeight.txt"
#define NUM_OF_OBJECT_TYPE 4
#define NUM_OF_MATERIAL_TYPE 3
#define NUM_OF_ERROR_TYPE 5
#define PI 3.1415926
#define MAXSIZE 100

enum object_type {OBJECT_UNKNOWN,BALL,CUBE,PYRAMID,CYLINDER};
enum material_type {MATERIAL_UNKNOWN,IRON,ALUMINUM,LEAD};
enum sort_method {NONE,SORT_BY_ID,SORT_BY_OBJECT,SORT_BY_MATERIAL,SORT_BY_VOLUMN,SORT_BY_WEIGHT};
enum data_operation {EXIT,SHOW,APPEND,UPDATE,DELETE};
enum error_type {NORMAL,ERR_OBJECT,ERR_MATERIAL,ERR_PARA1,ERR_PARA2};

typedef enum object_type Otype;
typedef enum material_type Mtype;
typedef enum data_operation Data_OP;
typedef enum sort_method S_Method;
typedef enum error_type Err_type;

struct object
{
	int id;
	Otype otype;
	Mtype mtype;
	float para1;
	float para2;
	Err_type etype;
};

typedef struct object objdata;

void mainMenu();
void operationMenu();
void sortMenu();
void openFileandShowData();
void dataOperation();
void sortOperation();
void writeFile();
int readData(objdata obj[],FILE *fp);
Otype strToObjectType(char str[]);
Mtype strToMaterialType(char str[]);
double Volumn(objdata obj);
double Weight(objdata obj);
void printData(objdata data[],int size);
void appendData(objdata obj[],int *size);
void updateData(objdata obj[],int size,int id);
void deleteData(objdata obj[],int *size,int id);
void checkData(objdata *obj);
int Compare(objdata obj1,objdata obj2,S_Method method);
void sortData(objdata obj[],int size,S_Method method);
void Swap(objdata *obj1,objdata *obj2);
void writeDatatoSingleFile(objdata obj[],int size,FILE* fp);
int searchData(objdata obj[],int size,int id);