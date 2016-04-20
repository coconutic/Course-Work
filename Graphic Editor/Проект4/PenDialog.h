#pragma once
#pragma region 

namespace Проект4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PenDialog
	/// </summary>
	public ref class PenDialog : public System::Windows::Forms::Form
	{
	public:
		PenDialog(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PenDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  penWidthGroupBox;
	protected:
	private: System::Windows::Forms::RadioButton^  penWidthButton6;
	private: System::Windows::Forms::RadioButton^  penWidthButton5;
	private: System::Windows::Forms::RadioButton^  penWidthButton4;
	private: System::Windows::Forms::RadioButton^  penWidthButton3;
	private: System::Windows::Forms::RadioButton^  penWidthButton2;
	private: System::Windows::Forms::RadioButton^  penWidthButton1;
	private: System::Windows::Forms::Button^  penWidthOk;
	private: System::Windows::Forms::Button^  penWidthCancel;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->penWidthGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->penWidthButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->penWidthOk = (gcnew System::Windows::Forms::Button());
			this->penWidthCancel = (gcnew System::Windows::Forms::Button());
			this->penWidthGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// penWidthGroupBox
			// 
			this->penWidthGroupBox->Controls->Add(this->penWidthButton6);
			this->penWidthGroupBox->Controls->Add(this->penWidthButton5);
			this->penWidthGroupBox->Controls->Add(this->penWidthButton4);
			this->penWidthGroupBox->Controls->Add(this->penWidthButton3);
			this->penWidthGroupBox->Controls->Add(this->penWidthButton2);
			this->penWidthGroupBox->Controls->Add(this->penWidthButton1);
			this->penWidthGroupBox->Location = System::Drawing::Point(12, 21);
			this->penWidthGroupBox->Name = L"penWidthGroupBox";
			this->penWidthGroupBox->Size = System::Drawing::Size(260, 184);
			this->penWidthGroupBox->TabIndex = 0;
			this->penWidthGroupBox->TabStop = false;
			this->penWidthGroupBox->Text = L"Select Pen Width";
			// 
			// penWidthButton6
			// 
			this->penWidthButton6->AutoSize = true;
			this->penWidthButton6->Location = System::Drawing::Point(169, 143);
			this->penWidthButton6->Name = L"penWidthButton6";
			this->penWidthButton6->Size = System::Drawing::Size(84, 17);
			this->penWidthButton6->TabIndex = 5;
			this->penWidthButton6->TabStop = true;
			this->penWidthButton6->Text = L"Pen Width 6";
			this->penWidthButton6->UseVisualStyleBackColor = true;
			// 
			// penWidthButton5
			// 
			this->penWidthButton5->AutoSize = true;
			this->penWidthButton5->Location = System::Drawing::Point(169, 92);
			this->penWidthButton5->Name = L"penWidthButton5";
			this->penWidthButton5->Size = System::Drawing::Size(84, 17);
			this->penWidthButton5->TabIndex = 4;
			this->penWidthButton5->TabStop = true;
			this->penWidthButton5->Text = L"Pen Width 5";
			this->penWidthButton5->UseVisualStyleBackColor = true;
			// 
			// penWidthButton4
			// 
			this->penWidthButton4->AutoSize = true;
			this->penWidthButton4->Location = System::Drawing::Point(169, 40);
			this->penWidthButton4->Name = L"penWidthButton4";
			this->penWidthButton4->Size = System::Drawing::Size(84, 17);
			this->penWidthButton4->TabIndex = 3;
			this->penWidthButton4->TabStop = true;
			this->penWidthButton4->Text = L"Pen Width 4";
			this->penWidthButton4->UseVisualStyleBackColor = true;
			// 
			// penWidthButton3
			// 
			this->penWidthButton3->AutoSize = true;
			this->penWidthButton3->Location = System::Drawing::Point(18, 143);
			this->penWidthButton3->Name = L"penWidthButton3";
			this->penWidthButton3->Size = System::Drawing::Size(84, 17);
			this->penWidthButton3->TabIndex = 2;
			this->penWidthButton3->TabStop = true;
			this->penWidthButton3->Text = L"Pen Width 3";
			this->penWidthButton3->UseVisualStyleBackColor = true;
			// 
			// penWidthButton2
			// 
			this->penWidthButton2->AutoSize = true;
			this->penWidthButton2->Location = System::Drawing::Point(18, 92);
			this->penWidthButton2->Name = L"penWidthButton2";
			this->penWidthButton2->Size = System::Drawing::Size(84, 17);
			this->penWidthButton2->TabIndex = 1;
			this->penWidthButton2->TabStop = true;
			this->penWidthButton2->Text = L"Pen Width 2";
			this->penWidthButton2->UseVisualStyleBackColor = true;
			// 
			// penWidthButton1
			// 
			this->penWidthButton1->AutoSize = true;
			this->penWidthButton1->Location = System::Drawing::Point(18, 40);
			this->penWidthButton1->Name = L"penWidthButton1";
			this->penWidthButton1->Size = System::Drawing::Size(84, 17);
			this->penWidthButton1->TabIndex = 0;
			this->penWidthButton1->TabStop = true;
			this->penWidthButton1->Text = L"Pen Width 1";
			this->penWidthButton1->UseVisualStyleBackColor = true;
			// 
			// penWidthOk
			// 
			this->penWidthOk->Location = System::Drawing::Point(30, 227);
			this->penWidthOk->Name = L"penWidthOk";
			this->penWidthOk->Size = System::Drawing::Size(75, 23);
			this->penWidthOk->TabIndex = 1;
			this->penWidthOk->Text = L"Ok";
			this->penWidthOk->UseVisualStyleBackColor = true;
			this->penWidthOk->Click += gcnew System::EventHandler(this, &PenDialog::penWidthOk_Click);
			// 
			// penWidthCancel
			// 
			this->penWidthCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->penWidthCancel->Location = System::Drawing::Point(181, 227);
			this->penWidthCancel->Name = L"penWidthCancel";
			this->penWidthCancel->Size = System::Drawing::Size(75, 23);
			this->penWidthCancel->TabIndex = 2;
			this->penWidthCancel->Text = L"Cancel";
			this->penWidthCancel->UseVisualStyleBackColor = true;
			// 
			// PenDialog
			// 
			this->AcceptButton = this->penWidthOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->CancelButton = this->penWidthCancel;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->ControlBox = false;
			this->Controls->Add(this->penWidthCancel);
			this->Controls->Add(this->penWidthOk);
			this->Controls->Add(this->penWidthGroupBox);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PenDialog";
			this->Text = L"Set Pen Width";
			this->penWidthGroupBox->ResumeLayout(false);
			this->penWidthGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	property float PenWidth
	{
		float get()
		{
			if (penWidthButton1->Checked)
				
				return 1.0f;
			if (penWidthButton2->Checked)
				return 2.0f;
			if (penWidthButton3->Checked)
				return 3.0f;
			if (penWidthButton4->Checked)
				return 4.0f;
			if (penWidthButton5->Checked)
				return 5.0f;
			return 6.0f;
		}
	}

private: System::Void penWidthOk_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
};
}
