#pragma once

namespace Проект4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TextDialog
	/// </summary>
	public ref class TextDialog : public System::Windows::Forms::Form
	{
	public:
		TextDialog(void)
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
		~TextDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  textOkButton;
	protected:
	private: System::Windows::Forms::Button^  textCancelButton;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->textOkButton = (gcnew System::Windows::Forms::Button());
			this->textCancelButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textOkButton
			// 
			this->textOkButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->textOkButton->Location = System::Drawing::Point(12, 103);
			this->textOkButton->Name = L"textOkButton";
			this->textOkButton->Size = System::Drawing::Size(75, 23);
			this->textOkButton->TabIndex = 1;
			this->textOkButton->Text = L"Ok";
			this->textOkButton->UseVisualStyleBackColor = true;
			// 
			// textCancelButton
			// 
			this->textCancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->textCancelButton->Location = System::Drawing::Point(164, 103);
			this->textCancelButton->Name = L"textCancelButton";
			this->textCancelButton->Size = System::Drawing::Size(75, 23);
			this->textCancelButton->TabIndex = 2;
			this->textCancelButton->Text = L"Cancel";
			this->textCancelButton->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 75);
			this->textBox1->TabIndex = 0;
			// 
			// TextDialog
			// 
			this->AcceptButton = this->textOkButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->CancelButton = this->textCancelButton;
			this->ClientSize = System::Drawing::Size(254, 135);
			this->ControlBox = false;
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textCancelButton);
			this->Controls->Add(this->textOkButton);
			this->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TextDialog";
			this->Text = L"Create Text Element";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Property to access the text in the edit box
	public: property String^ TextString
	{
				String^ get() { return textBox1->Text; }
				void set(String^ text) { textBox1->Text = text; }
	}
			// Set the edit box font
	public: property System::Drawing::Font^ TextFont
	{
				void set(System::Drawing::Font^ font) { textBox1->Font = font; }
	}

	};
}
