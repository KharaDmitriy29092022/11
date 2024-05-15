#include "stdafx.h"

namespace SecondsCalculator {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class MainForm : public System::Windows::Forms::Form {
    public:
        MainForm(void) {
            InitializeComponent();
        }

    protected:
        ~MainForm() {
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ txtN;
    private: System::Windows::Forms::Button^ btnCalculate;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->txtN = (gcnew System::Windows::Forms::TextBox());
            this->btnCalculate = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(42, 52);
            this->label1->Text = L"Enter the number of seconds from the beginning of the day:";
            // 
            // txtN
            // 
            this->txtN->Location = System::Drawing::Point(90, 49);
            this->txtN->Name = L"txtN";
            this->txtN->Size = System::Drawing::Size(100, 20);
            this->txtN->Text = L"";
            // 
            // btnCalculate
            // 
            this->btnCalculate->Location = System::Drawing::Point(90, 80);
...
        }

#pragma endregion

        System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
            int N = Convert::ToInt32(txtN->Text);

            int secondsFromLastHour = N % 3600;  // Вирахувати кількість секунд з початку останньої години

            String^ outputPath = "output.txt";
            StreamWriter^ writer = gcnew StreamWriter(outputPath);
            writer->WriteLine("Seconds from the last hour: " + secondsFromLastHour);
            writer->Close();

            MessageBox::Show("Seconds from the last hour have been saved to output.txt", "Result");
        }
    };

    [STAThread]
    void Main(array<System::String^>^ args) {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);

        SecondsCalculator::MainForm form;
        Application::Run(%form);
    }
}

