#pragma once
#include <iostream>
#include<stdio.h>
#include<iomanip>
#include <fstream>
#include<string>
using namespace std;
#include<list>
#include"HoaDon.h"

void  ghifileVip(const char* filename, Tree& T);
bool kiemTraTonTaiFile(string FileName);
void inDanhSachKhachHang(list<string> ListCus);
list<string> ReadFile(string FileName);