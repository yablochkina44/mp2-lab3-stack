#include "MyForm.h"
//#include "../mp2-lab3-stack/TStack.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CalcForm::MyForm form;
	Application::Run(% form);
}

