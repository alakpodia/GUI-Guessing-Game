//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

bool isNumberEntered = false;
int guessNumber;
int attemptsCounter = 0;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TitleLabel->Text = "Please Enter a Number: ";
	CounterLabel->Text = "0";
	HelperLabel->Text= "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{
	if(!isNumberEntered){
		guessNumber = NumbersEdit->Text.ToInt();
		isNumberEntered = true;
		TitleLabel->Text = "Now Guess the Number!!!";
		NumbersEdit->Text = "";
	}else{
		int secondUsersNumber = NumbersEdit->Text.ToInt();
		if (secondUsersNumber== guessNumber) {
			HelperLabel->Text = "You Won!! CONGRATULATIONS!!";
			ConfirmButton->Enabled = false;
			return;
		}else if(secondUsersNumber > guessNumber)
			HelperLabel->Text = "Number too big";
		else
			HelperLabel->Text = "Number too small";

			CounterLabel->Text = ++attemptsCounter;
			NumbersEdit->Text = "";
    }

}
//---------------------------------------------------------------------------
