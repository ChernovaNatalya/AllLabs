#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <MyStack.h>
//#include "..\All_labs\stacklib\MyStack.h"

namespace Calculator {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyCalculator
	/// </summary>
	public ref class MyCalculator : public System::Windows::Forms::Form
	{
	public:
		MyCalculator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyCalculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ answer;
	private: System::Windows::Forms::Button^ button1;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->answer = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter expression";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textBox1->Location = System::Drawing::Point(20, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(258, 26);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(23, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Postfix";
			// 
			// answer
			// 
			this->answer->AutoSize = true;
			this->answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->answer->Location = System::Drawing::Point(364, 54);
			this->answer->Name = L"answer";
			this->answer->Size = System::Drawing::Size(65, 20);
			this->answer->TabIndex = 3;
			this->answer->Text = L"Answer";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(284, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 27);
			this->button1->TabIndex = 4;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyCalculator::button1_Click);
			// 
			// MyCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(470, 209);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->answer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyCalculator";
			this->Text = L"MyCalculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	string infix;
	infix = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (infix.size() == 0) return;
	TCalculator Tcalc;
	try {
	Tcalc.SetExpression(infix);
	Tcalc.ToPostfix();
	label2->Text = msclr::interop::marshal_as<String^>(Tcalc.GetPostfix());
	answer->Text = Convert::ToString(Tcalc.CalculateAll());
	}
	catch (...) { 
		answer->Text = Convert::ToString("ERROR");
	}
}
};
}
