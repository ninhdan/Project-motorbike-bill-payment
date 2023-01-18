#include"DocGhiVip.h"

bool kiemTraTonTaiFile(string FileName)
{
	fstream p;
	p.open(FileName, ios::in);
	if (p.fail())
		return false;
	else
		return true;
	p.close();
}

void inDanhSachKhachHang(list<string> ListCus)
{
	
	int dem = 0;
	for (list<string>::iterator i = ListCus.begin(); i != ListCus.end(); i++)
	{
		cout <<"                        "<< * i << "                  "<< endl;
		if (*i != "")
		{
			dem++;
		}
	}
	cout << "        CUA HANG XE MAY HONDA CO " << dem << " KHACH HANG THAN THIET!" << endl;
	cout<< "                        XIN CHUC MUNG !!!" <<endl<<endl;
	
}

list<string> ReadFile(string FileName)
{
	list<string> listStr;
	fstream fst;
	if (kiemTraTonTaiFile(FileName))
	{
		fst.open(FileName, ios::in);
		do
		{
			string s = "";
			getline(fst, s);
			listStr.push_back(s);
		} while (!fst.eof());
		fst.close();
	}
	else
	{
		cout << "\t +. File khong ton tai.\n \t +. Hay chon file khac. \n";
		system("pause");
	}
	return listStr;
}

void  ghifileVip(const char* filename, Tree& T)
{
	if (T != NULL)
	{
		FILE* f = fopen(filename, "ab");

		if (tinhTien(T->key) >= 100) {
			fprintf(f, "%s-%s\n", T->key.HoTen, T->key.SDT);
		}
		ghifileVip(filename, T->Left);
		ghifileVip(filename, T->Right);
		fclose(f);
	}
}




