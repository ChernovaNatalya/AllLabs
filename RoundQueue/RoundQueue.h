#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <MyQueue.h>
const int k = 30;

namespace RoundQueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ RoundQueue
	/// </summary>
	public ref class RoundQueue : public System::Windows::Forms::Form
	{
	public:
		RoundQueue(void)
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
		~RoundQueue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
	protected: Random^ rnd1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:  Graphics^ gr;
	protected: TQueue<int>* queue;
	protected: int add, clean = 0;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(561, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RoundQueue::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &RoundQueue::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(564, 101);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 42);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RoundQueue::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(121, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(77, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(122, 72);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(75, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Add";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Clean";
			// 
			// RoundQueue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 393);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"RoundQueue";
			this->Text = L"RoundQueue";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->gr = CreateGraphics();
			this->queue = new TQueue<int>(k);
			this->rnd1 = gcnew Random();
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		timer1->Enabled = true;
		string a = msclr::interop::marshal_as<std::string>(textBox1->Text);
		add = stoi(a, 0);
		string b = msclr::interop::marshal_as<std::string>(textBox1->Text);
		clean = stoi(b, 0);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Graphics^ gr = this->CreateGraphics();
		Pen^ MyPen = gcnew Pen(Color::Navy);
		MyPen->Width = 20;
		Pen^ MyPenW = gcnew Pen(SystemColors::Control);
		MyPenW->Width = 30;

		if ((!(queue->IsFull())) && (rnd1->Next() % 100 < add) && add) { 
			queue->Push(rnd1->Next());
		}
		if ((!(queue->IsEmpty())) && (rnd1->Next() % 100 < clean) && clean) { 
			queue->Pop(); 
		}

		gr->DrawArc(MyPenW, 150, 70, 230, 230, 0, 360);
		gr->DrawArc(MyPen, 150, 70, 230, 230, 360*((queue->GetStart()*1.0)/k), 360 * ((queue->GetCount()*1.0) / k));
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}
	};
}
