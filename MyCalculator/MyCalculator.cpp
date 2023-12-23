//#include "..\All_labs\stacklib\MyStack.h"

#include "MyCalculator.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calculator::MyCalculator form;
	Application::Run(% form);
}