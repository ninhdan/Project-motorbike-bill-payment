#include"HoaDon.h"

int compare(HOADON x, HOADON y)
{
	return strcmp(x.MaHoaDon, y.MaHoaDon);
}

double tinhTien(HOADON x)
{
	return x.SoLuong * x.DonGia;
}

HOADON nhapHoaDon()
{
	HOADON x;
	cout << "* Nhap So Hoa Don (Q De Quay Lai): ";
	gets_s(x.MaHoaDon);
	if (strcmp(x.MaHoaDon, "q") == 0 || strcmp(x.MaHoaDon, "Q") == 0)
	{
		return x;
	}
	cout << "* Nhap Ten Khach Hang: ";
	gets_s(x.HoTen);
	cout << "* Nhap Dia Chi: ";
	gets_s(x.DiaChi);
	cout << "* Nhap So Dien Thoai: ";
	gets_s(x.SDT);
	cout << "* Nhap Ma Xe: ";
	gets_s(x.MaXe);
	cout << "* Nhap Ten Xe: ";
	gets_s(x.TenXe);
	cout << "* Nhap So Luong: "; cin >> x.SoLuong;
	cout << "* Nhap Don Gia: "; cin >> x.DonGia;
	while (getchar() != '\n');

	return x;
}

void xuatHoaDon(HOADON x)
{
	if (tinhTien(x) >= 100)
	{
		cout << setw(10) << x.MaHoaDon << setw(15) << x.HoTen << setw(15) << x.DiaChi << setw(15) << x.SDT << setw(15) << x.MaXe << setw(15) << x.TenXe << setw(15) << x.DonGia << setw(15) << x.SoLuong << setw(15) << tinhTien(x) << setw(15) << " VIP" << endl;
	}
	else
		cout << setw(10) << x.MaHoaDon << setw(15) << x.HoTen << setw(15) << x.DiaChi << setw(15) << x.SDT << setw(15) << x.MaXe << setw(15) << x.TenXe << setw(15) << x.DonGia << setw(15) << x.SoLuong << setw(15) << tinhTien(x) << endl;
}

int insertNode(Tree& T, HOADON x)
{
	if (T != NULL) {
		if (compare(T->key, x) == 0)
			return -1;
		if (compare(T->key, x) > 0)
			return insertNode(T->Left, x);
		else if (compare(T->key, x) < 0)
			return insertNode(T->Right, x);
	}
	T = (Node*)malloc(sizeof(Node));
	if (T == NULL)
		return 0;
	T->key = x;
	T->Left = T->Right = NULL;
	return 1;
}

void createTree(Tree& T)
{
	HOADON x;
	while (1) {
		cout << "\t-------Nhap Hoa Don--------" << endl << endl;
		x = nhapHoaDon();
		if (strcmp(x.MaHoaDon, "q") == 0 || strcmp(x.MaHoaDon, "Q") == 0)
			break;
		int check = insertNode(T, x);
		if (check == -1)
			cout << "---Ma Sinh Vien Da Co---\n" << endl;
		else if (check == 0)
			cout << "---Bo Nho Day---\n" << endl;
		else cout << "---Them Thanh Cong---\n\n";
	}
}

void LNR(Tree T)
{

	if (T != NULL)
	{
		LNR(T->Left);
		xuatHoaDon(T->key);
		LNR(T->Right);
	}
}
Tree searchHD(Tree T, char MaHD[])
{
	Node* P = T;
	if (T != NULL)
	{
		if (strcmp(T->key.MaHoaDon, MaHD) == 0)
		{
			return P;
		}
		else if (strcmp(T->key.MaHoaDon, MaHD) > 0)
		{
			return searchHD(T->Left, MaHD);
		}
		else
			return searchHD(T->Right, MaHD);
	}
	else
		return NULL;
}

Tree suaHD(Tree P)
{
	cout << "Sua Ten Khach Hang(Q De Quay Lai): ";
	cin.getline(P->key.HoTen, 50);
	if (strcmp(P->key.HoTen, "q") == 0 || strcmp(P->key.HoTen, "Q") == 0)
	{
		return P;
	}
	cout << "Sua SDT: ";
	cin >> P->key.SDT;
	while (getchar() != '\n');
	return P;
}
int delHD(Tree& T, char MaHD[]) {
	if (T == NULL)
		return 0;
	else if (strcmp(T->key.MaHoaDon, MaHD) > 0)
		return delHD(T->Left, MaHD);
	else if (strcmp(T->key.MaHoaDon, MaHD) < 0)
		return delHD(T->Right, MaHD);
	else
	{
		Node* P = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		else
		{
			Node* S = T, * Q = S->Left;
			while (Q->Right != NULL) {
				S = Q;
				Q = Q->Right;
			}
			P->key = Q->key;
			S->Right = Q->Left;
			delete Q;
		}
	}
	return 1;
}

void docfile(const char* filename, Tree& T) {
	HOADON x;
	FILE* f = fopen(filename, "rb");
	if (f != NULL)
	{
		while (!feof(f))
		{

			fscanf(f, "%s\n", &x.MaHoaDon);
			fscanf(f, "%s\n", &x.HoTen);
			fscanf(f, "%s\n", &x.DiaChi);
			fscanf(f, "%s\n", &x.SDT);
			fscanf(f, "%s\n", &x.MaXe);
			fscanf(f, "%s\n", &x.TenXe);
			fscanf(f, "%d\n", &x.SoLuong);
			fscanf(f, "%d\n", &x.DonGia);
			double tt = tinhTien(x);
			fscanf(f, "%lf\n\n", &tt);
			insertNode(T, x);
		}
		fclose(f);
	}
	else
	{
		cout << "!!--Thong Bao: Danh Sach Hoa Don Dang Rong, Xin Vui Long Nhap Hoa Don--!!" << "\n\n";
		createTree(T);
	}
}

void  ghifile(const char* filename, Tree& T)
{
	if (T != NULL)
	{
		FILE* f = fopen(filename, "ab");

		fprintf(f, "%s\n", T->key.MaHoaDon);
		fprintf(f, "%s\n", T->key.HoTen);
		fprintf(f, "%s\n", T->key.DiaChi);
		fprintf(f, "%s\n", T->key.SDT);
		fprintf(f, "%s\n", T->key.MaXe);
		fprintf(f, "%s\n", T->key.TenXe);
		fprintf(f, "%d\n", T->key.SoLuong);
		fprintf(f, "%d\n", T->key.DonGia);
		fprintf(f, "%lf\n\n", tinhTien(T->key));

		ghifile(filename, T->Left);
		ghifile(filename, T->Right);
		fclose(f);
	}
}




