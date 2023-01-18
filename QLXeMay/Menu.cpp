#include"HoaDon.h"
#include"DocGhiVip.h"
HANDLE hOut;

void menuMain() {
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 3 << 10 | 1 << 4 | 11);
	cout << ("\t\t     #   #   #   #   #  # #      #       \n");
	cout << ("\t\t     #   # #   # ##  #  #   #   # #      \n");
	cout << ("\t\t     ##### #   # # # #  #    # #####     \n");
	cout << ("\t\t     #   # #   # #  ##  #   #  #   #     \n");
	cout << ("\t\t     #   #   #   #   #  # #    #   #     \n");
	cout << "\n";
	SetConsoleTextAttribute(hOut,2);
	cout << "============ CHUONG TRINH QUAN LY HOA DON CUA HANG XE MAY ============" << "\n\n";
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t============MENU MAIN===========\n";
	SetConsoleTextAttribute(hOut, 6);
	cout << "\t\t1.Thanh toan." << endl;
	cout << "\t\t2.Danh sach khach hang VIP." << endl;
	cout << "\t\t3.Thoat." << endl;
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t=================================\n";
	SetConsoleTextAttribute(hOut,2);
	cout << "============================= END ====================================" << "\n\n";
}

void menuVip()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\n\n";
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t==========MENU VIP========\n\n";
	SetConsoleTextAttribute(hOut, 6);
	cout << "\t\t\t1. Xem danh sach khach VIP." << endl;
	cout << "\t\t\t2. Quay ve menu chinh" << endl << endl;
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t===========================\n";
	cout << "\n\n";
	
}

void menuPay()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n";
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t============MENU PAY============\n\n";
	SetConsoleTextAttribute(hOut, 6);
	cout << "\t\t\t1. Tao hoa don." << endl;
	cout << "\t\t\t2. Quay ve Menu Chinh." << endl << endl;
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t================================\n";
	cout << "\n\n";
}

void menuBill()
{
	cout << "\n\n";
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t=================MENU BILL==================\n\n";
	SetConsoleTextAttribute(hOut, 6);
	cout << "\t\t\t1. Xem hoa don." << endl;
	cout << "\t\t\t2. Doc hoa don." << endl;
	cout << "\t\t\t3. Them hoa don." << endl;
	cout << "\t\t\t4. Tim kiem hoa don theo ma khach hang." << endl;
	cout << "\t\t\t5. Xoa hoa don theo theo ma khach hang." << endl;
	cout << "\t\t\t6. Luu du lieu." << endl;
	cout << "\t\t\t7. Quay ve Muc Thanh Toan." << endl;
	cout << "\t\t\t8. Quay ve Menu Chinh." << endl << endl;
	SetConsoleTextAttribute(hOut, 4);
	cout << "\t\t\t============================================\n";
	cout << "\n\n";
}


void Menu()
{
	Tree T;
	HOADON x;
	T = NULL;
	cout << endl;
	cout << endl;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* f = "Ds.txt";
	const char* v = "vip.txt";
	int flag;


MenuMain: {
	menuMain();
	SetConsoleTextAttribute(hOut, 5);
	cout << "* Nhap So De Thao Tac: ";
	cin >> flag;
	}
		if (flag == 1)
		{
			int flag1;
			system("cls");
MenuPay: {
	menuPay();
	SetConsoleTextAttribute(hOut, 5);
	cout << "* Nhap So De Thao Tac: ";
	cin >> flag1;
}
		if (flag1 == 1)
		{
			system("cls");
			int flag2;
MenuBill: {
	menuBill();
	SetConsoleTextAttribute(hOut, 5);
	cout << "* Nhap So De Thao Tac: ";
	cin >> flag2;
}

		if (flag2 == 1)
		{
			SetConsoleTextAttribute(hOut, 7);
			system("cls");
			cout << endl;
			cout << "==================================================================DANH SACH HOA DON==============================================================" << endl;
			cout << endl;
			cout << setw(10) << "MaKH" << setw(15) << "TenKH" << setw(15) << "DiaChi" << setw(15) << "SDT" << setw(15) << "MaXe" << setw(15) << "TenXe" << setw(15) << "DonGia" << setw(15) << "SoLuong" << setw(15) << "ThanhTien" << endl;
			cout << "=================================================================================================================================================" << endl;
			LNR(T);
			system("pause");
			system("cls");
			goto MenuBill;
		}
		else if (flag2 == 2)
		{
			SetConsoleTextAttribute(hOut, 2);
			system("cls");
			cin.ignore();
			docfile(f, T);
			cout << "----Du Lieu Da Duoc Doc Len-----" << endl;
			system("pause");
			system("cls");
			goto MenuBill;
		}
		else if (flag2 == 3)
		{
			SetConsoleTextAttribute(hOut, 7);
			system("cls");
			cin.ignore();
			createTree(T);
			system("cls");
			goto MenuBill;
		}
		else if (flag2 == 4)
		{
			SetConsoleTextAttribute(hOut, 7);
			system("cls");
			char maKH[50];
			cin.ignore();
			cout << "* Nhap Ma Khach Hang can tim: ";
			gets_s(maKH);
			Tree P = searchHD(T, maKH);

			if (P != NULL)
			{
				int flag4;
			MenuSua: {
				system("cls");
				SetConsoleTextAttribute(hOut, 6);
				cout << "----------Tim Thay Hoa Don: " << maKH << "--------" << endl;
				cout << "1. Hien thi thong tin Hoa Don " << endl;
				cout << "2. Sua thong tin Hoa Don " << endl;
				cout << "3. Quay lai muc Bill " << endl;
				SetConsoleTextAttribute(hOut, 5);
				cout << "* Nhap So De Thao Tac: ";
				cin >> flag4;
				}
			if (flag4 == 1)
			{
				SetConsoleTextAttribute(hOut, 7);
				system("cls");
				cout << endl;
				cout << setw(10) << "MaKH" << setw(15) << "TenKH" << setw(15) << "DiaChi" << setw(15) << "SDT" << setw(15) << "MaXe" << setw(15) << "TenXe" << setw(15) << "DonGia" << setw(15) << "SoLuong" << setw(15) << "ThanhTien" << endl;
				cout << "=================================================================================================================================================" << endl;
				LNR(P);
				system("pause");
				goto MenuSua;
			}
			else if (flag4 == 2)
			{
				SetConsoleTextAttribute(hOut, 7);
				system("cls");
				cout << "* Nhap Thong Tin Can Sua" << endl;
				cin.ignore();
				suaHD(P);
				goto MenuSua;
			}
			else if (flag4 == 3)
			{
				system("cls");
				goto MenuBill;
			}
			}
			else
			{
				cout << "Khong Ton Tai Hoa Don Nay" << endl;
			}
			goto MenuBill;

		}
		else if (flag2 == 5)
		{
			system("cls");
			char maKH[50];
			cin.ignore();
			cout << "* Nhap Ma Khach Hang can tim: ";
			gets_s(maKH);
			Tree P = searchHD(T, maKH);
			if (P != NULL)
			{
				int flag5;
				system("cls");
				cout << endl;
				cout << setw(10) << "MaKH" << setw(15) << "TenKH" << setw(15) << "DiaChi" << setw(15) << "SDT" << setw(15) << "MaXe" << setw(15) << "TenXe" << setw(15) << "DonGia" << setw(15) << "SoLuong" << setw(15) << "ThanhTien" << endl;
				cout << "=================================================================================================================================================" << endl;
				LNR(P);
				SetConsoleTextAttribute(hOut, 6);
				cout << "----------------------------------------------------" << endl;
				cout << "1. Xoa Hoa Don " << maKH << endl;
				cout << "2. Huy Bo! va Quay lai Menu Chinh" << endl;
				cout << "----------------------------------------------------" << endl;
				SetConsoleTextAttribute(hOut, 5);
				cout << "Nhap So De Thao Tac: ";
				cin >> flag5;
				if (flag5 == 1)
				{
					SetConsoleTextAttribute(hOut, 7);
					system("cls");
					cin.ignore();
					int del = 1;
					while (del)
					{
						if (P != NULL)
						{
							cout << "---Xoa Thanh Cong---" << endl;
							del = delHD(T, P->key.MaHoaDon);
						}
						else
						{
							cout << "---Khong Co Du Lieu---" << endl;
							del = 0;
						}
						system("Pause");
						goto MenuBill;
					}
				}
				if (flag5 == 2)
				{
					system("cls");
					goto MenuBill;
				}
			}
			else
			{
				cout << "---- Khong Ton Tai Ma Sinh Vien Nay----" << endl;
			}
			goto MenuBill;

		}
		else if (flag2 == 6)
		{
			SetConsoleTextAttribute(hOut, 2);
			system("cls");
			ghifile(f, T);
			ghifileVip(v, T);
			cout << "----Da Luu Du Lieu-----" << endl;
			system("pause");
			system("cls");
			goto MenuBill;
		}
		else if (flag2 == 7)
		{
			system("cls");
			goto MenuPay;
		}
		else if (flag2 == 8)
		{
			system("cls");
			goto MenuMain;
		}
		}
		else if (flag1 == 2)
		{
			system("cls");
			goto MenuMain;
		}
		}
		if (flag == 2)
		{
			int flag3;
			system("cls");

		MenuVip: {
			menuVip();
			SetConsoleTextAttribute(hOut, 5);
			cout << "* Nhap So De Thao Tac: ";
			cin >> flag3;
			}

		if (flag3 == 1)
		{
			system("cls");
			SetConsoleTextAttribute(hOut, 2);
			cout << "==============DANH SACH KHACH HANG THAN THIET==============" << endl << endl;
			SetConsoleTextAttribute(hOut, 11);
			inDanhSachKhachHang(ReadFile("vip.txt"));
			SetConsoleTextAttribute(hOut, 2);
			cout << "============================================================" << endl << endl;
			SetConsoleTextAttribute(hOut, 7);
			system("pause");

			system("cls");
			goto MenuVip;

		}
		else if (flag3 == 2)
		{
			system("cls");
			goto MenuMain;
		}

		if (flag == 3)
		{
			return;
		}
	}

}