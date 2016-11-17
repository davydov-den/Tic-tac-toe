#pragma once
namespace OX 
{
#include "game.h"
#include "AI.h"
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Bitmap^ bmp; //полотно где рисуем
		static	array<Game^>^ game = gcnew array<Game^>(11);
		int countAction;
		int currentAction;
		int Level;
		int pause;
		bool IIStep;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	public:
		Form1(void)
		{
			InitializeComponent();
			countAction= 0;
			currentAction = 0;
			RefreshPicture();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1; 
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Обязательный метод для поддержки конструктора - не изменяйте
			 /// содержимое данного метода при помощи редактора кода.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
				 this->pictureBox1->Enabled = false;
				 this->pictureBox1->Location = System::Drawing::Point(13, 128);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(360, 360);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Игрок1(собирает ряд)", L"Игрок2(мешает собрать ряд)"});
				 this->comboBox1->Location = System::Drawing::Point(92, 10);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(154, 21);
				 this->comboBox1->TabIndex = 1;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(175, 45);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 37);
				 this->button1->TabIndex = 2;
				 this->button1->Text = L"Начать игру";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(175, 45);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 37);
				 this->button2->TabIndex = 3;
				 this->button2->Text = L"Закончить игру";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Visible = false;
				 this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(32, 19);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(35, 23);
				 this->button3->TabIndex = 4;
				 this->button3->Text = L"<-";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Visible = false;
				 this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(73, 19);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(35, 23);
				 this->button4->TabIndex = 5;
				 this->button4->Text = L"->";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Visible = false;
				 this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
				 // 
				 // button5
				 // 
				 this->button5->Enabled = false;
				 this->button5->Location = System::Drawing::Point(14, 48);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(121, 23);
				 this->button5->TabIndex = 6;
				 this->button5->Text = L"Вернуться к игре";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->button4);
				 this->groupBox1->Controls->Add(this->button5);
				 this->groupBox1->Controls->Add(this->button3);
				 this->groupBox1->Location = System::Drawing::Point(12, 40);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(141, 82);
				 this->groupBox1->TabIndex = 7;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Просмотр ходов";
				 this->groupBox1->Visible = false;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(26, 13);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(60, 13);
				 this->label1->TabIndex = 8;
				 this->label1->Text = L"Выберите:";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"1 уровень", L"2 уровень", L"3 уровень"});
				 this->comboBox2->Location = System::Drawing::Point(252, 10);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(121, 21);
				 this->comboBox2->TabIndex = 9;
				 this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(381, 500);
				 this->Controls->Add(this->comboBox2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->comboBox1);
				 this->Controls->Add(this->pictureBox1);
				 this->Name = L"Form1";
				 this->Text = L"Крестики-нолики";
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 button2->Visible = true;
				 comboBox1->Visible = false;
				 comboBox2->Visible = false;
				 button1->Visible = false;
				 pictureBox1->Enabled = true;
				 button3->Visible = true;
				 button4->Visible = true;
				 groupBox1->Visible = true;
				 Level = comboBox2->SelectedIndex;
				 label1->Visible  = false;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 stop();
			 }
	private: void stop()
			 {
				 button1->Visible = true;
				 comboBox1->Visible = true;
				 comboBox2->Visible = true;
				 button2->Visible = false;
				 pictureBox1->Enabled = false;
				 countAction = 0;
				 currentAction = 0;
				 button3->Visible = false;
				 button4->Visible = false;
				 groupBox1->Visible = false;
				 label1->Visible  = true;
				 RefreshPicture();
			 }
	private: void RefreshPicture()
			 {
				 bmp = gcnew Bitmap(pictureBox1->Width,pictureBox1->Height); //новое полотно
				 Graphics^ g = Graphics::FromImage(bmp);	
				 for(int i=0;i<2;i++)
				 {
					 g->DrawLine(gcnew Pen(Color::Black,3.0f),0,120*(i+1),360,120*(i+1));
					 g->DrawLine(gcnew Pen(Color::Black,3.0f),120*(i+1),0,120*(i+1),360);
				 }
				 if(countAction>0)
					 g = game[currentAction]->Draw(g);
				 pictureBox1->Image = bmp;
				 pictureBox1->Invalidate();

			 }
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
				 int x = e->X/120;
				 int y= e->Y/120;
				 IIStep = false;
				 int type;
				 if(currentAction == countAction-1 || countAction==0)
				 {
					 if(e->Button==System::Windows::Forms::MouseButtons::Right)
						 type = 0;
					 else
						 type = 1;
					 if(!newAction(x,y,type))
						 MessageBox::Show("Нельзя сюда поставить");
					 else
					 {
						 if(!CheckStop())
						 {
							 pause = 0;
							 pictureBox1->Enabled = false;
							 timer1->Enabled = true;				
						 }
					 }
				 }
				 else
					 MessageBox::Show("Необходимо вернуться к игре");

			 }
	private: bool CheckStop()
			 {
				 if(game[currentAction]->isFinish())
				 {
					 int win = game[currentAction]->WhoWin();
					 if(win ==-1)
						 MessageBox::Show("Победил Игрок2");
					 else
						 MessageBox::Show("Победил Игрок1");					
					 stop();
					 return true;
				 }
				 else
					 return false;
			 }
	private: bool newAction(int x,int y,int mode)
			 {
				 Game^ newAction = gcnew Game(3);
				 if(countAction>0)
					 newAction->Copy(game[countAction-1]);
				 if(newAction->action(Point(x,y),mode,IIStep))
				 {
					 game[countAction]=newAction;
					 countAction++;
					 currentAction = countAction-1;	 
					 RefreshPicture();				 
					 return true;
				 }
				 else
					 return false;
			 }
	private: void II()
			 {	 
				 IIStep = true;
				 int mode = Math::Abs(1-comboBox1->SelectedIndex);
				 bool success = false;
				 int *probabilityPlace  =game[currentAction]->GetListEmptyPlace();
				 int count = probabilityPlace[9];
				 int PosX=-1,PosY=-1,tmp;
				 Random^ rand = gcnew Random();
				 int type = rand->Next(2);
				 AI* m = new AI();
				 AI* m2 = new AI();
				 Game^ AIstep = gcnew Game(3);
				 Game^ AIstep2 = gcnew Game(3);
				 Moved* newMove;
				 Moved* newMove2;
				 switch (Level)
				 {
				 case 0:
					 tmp =  rand->Next(0,count);
					 PosX = probabilityPlace[tmp]/3;
					 PosY= probabilityPlace[tmp] - PosX*3;
					 newAction(PosX,PosY,type);
					 break;
				 case 1:
					 tmp = game[currentAction]->isOneStepToWin(1);
					 if(tmp>=0)
					 {
						 PosX = tmp/3;
						 PosY= tmp - PosX*3;
						 if(comboBox2->SelectedIndex!=0)
							 type = Math::Abs(1-mode);
						 else
							 type = mode;
						 newAction(PosX,PosY,type);
					 }
					 else
					 {
						 tmp = game[currentAction]->isOneStepToWin(0);
						 if(tmp >=0)
						 {
							 PosX = tmp/3;
							 PosY= tmp - PosX*3;
							 if(comboBox2->SelectedIndex!=0)
								 type = mode;
							 else
								 type = Math::Abs(1-mode);
							 newAction(PosX,PosY,type);
						 }
						 else
						 {
							 tmp =  rand->Next(0,count);
							 PosX = probabilityPlace[tmp]/3;
							 PosY= probabilityPlace[tmp] - PosX*3;
							 newAction(PosX,PosY,type);
							 while(game[currentAction]->isOneStepToWin(1) >=0 || game[currentAction]->isOneStepToWin(0)>=0)
							 {
								 countAction--;
								 currentAction = countAction-1;
								 probabilityPlace[tmp] = probabilityPlace[count-1];
								 count--;
								 tmp =  rand->Next(0,count);
								 PosX = probabilityPlace[tmp]/3;
								 PosY= probabilityPlace[tmp] - PosX*3;
								 newAction(PosX,PosY,type);
								 CheckStop();
							 }
						 }
					 }

					 break;
				 case 2:  
					 AIstep->Copy(game[currentAction]);
					 newMove= m->GetBestMove(AIstep,1);
					 AIstep2->Copy(game[currentAction]);
					 newMove2= m2->GetBestMove(AIstep2,0); 
					 if(newMove->Fitness>newMove2->Fitness) 
					 {
						 if(comboBox1->SelectedIndex==1)
							 newAction(newMove->X,newMove->Y,1);
						 else
							 newAction(newMove->X,newMove->Y,0);
					 }
					 else
					 {
						 if(comboBox1->SelectedIndex==1)
							 newAction(newMove2->X,newMove2->Y,0);
						 else
							 newAction(newMove2->X,newMove2->Y,1);
					 }
					 break;
				 default:
					 break;
				 }
				 IIStep = false;
				 CheckStop();

			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(currentAction>0)
				 {
					 currentAction--;				 
					 RefreshPicture();
				 }
				 if( currentAction != countAction-1)
					 button5->Enabled = true;
				 else
					 button5->Enabled = false;
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(currentAction<countAction-1)
				 {
					 currentAction++;
					 RefreshPicture();
				 }
				 if( currentAction != countAction-1)
					 button5->Enabled = true;
				 else
					 button5->Enabled = false;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 pause++;
				 if(pause==10)
				 {
					 pictureBox1->Enabled =true;
					 timer1->Enabled = false;
					 II();
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 comboBox1->SelectedIndex = 0;
				 comboBox2->SelectedIndex = 0;
			 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 currentAction = countAction-1;
				 button5->Enabled = false;
				 RefreshPicture();
			 }
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

