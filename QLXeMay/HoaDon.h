#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#include <windows.h>
#include<iomanip>

class HOADON {
public:
	char MaHoaDon[50];
	char HoTen[50];
	char DiaChi[50];
	char MaXe[50];
	char TenXe[50];
	char SDT[20];
	int SoLuong;
	int DonGia;
};

class Node
{
public:
	HOADON key;
	Node* Left, * Right;
};

typedef Node* Tree;

int compare(HOADON x, HOADON y);
HOADON nhapHoaDon();
void xuatHoaDon(HOADON x);
double tinhTien(HOADON x);
int insertNode(Tree& T, HOADON x);
void createTree(Tree& T);
void LNR(Tree T);
Tree searchHD(Tree T, char MaKH[]);
Tree suaHD(Tree P);
int delHD(Tree& T, char MaKH[]);
void  ghifile(const char* filename, Tree& T);
void docfile(const char* filename, Tree& T);