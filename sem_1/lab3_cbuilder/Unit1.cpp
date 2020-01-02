//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include "Unit1.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;

int factorial(int num) {
     int i = 0, factorial = 1;
     for( i = 1; i <= num; i++) {
       factorial *= i;
     }
     return factorial;
 }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Clear();
Memo1->Lines->Add("Лабораторная работа 3");
Edit1->Text = 0.1;
Edit2->Text = 1.0;
Edit3->Text = 0.1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Memo1->Clear();
Memo1->Lines->Add("Лабораторная работа 3");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

// Считывание и объявление переменных

double a, b, h, n, x, y, s = 0, e;
 e = 2,71828;
int i, k;
a = StrToFloat(Edit1->Text);
b = StrToFloat(Edit2->Text);
h = StrToFloat(Edit3->Text);
n = StrToFloat(Edit4->Text);

//Вычисление значений

for( x = a; x < b; x +=h) {
  y = (1 + 2 * x * x) * std::pow(2.718281, x * x);
   for( k = 0; k <= n; k++) {
       s +=  (2*k + 1)/factorial(k)* std::pow(x, 2 * k);


     }
      Memo1 -> Lines -> Add("При х = " + FloatToStr(x) + ": S = " +
                           FloatToStr(s) + ", Y = " +  FloatToStr(y));
      s = 0;
      y = 0;
}
  }



//---------------------------------------------------------------------------
