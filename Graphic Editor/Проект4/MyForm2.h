

#pragma once


namespace Проект4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolStripButton^  button1;
	private: System::Windows::Forms::ToolStripButton^  button2;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(0, 33);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(6, 12, 6, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1489, 1662);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm2::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(29, 29);
			this->button1->Text = L"Open";
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// button2
			// 
			this->button2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(29, 29);
			this->button2->Text = L"Save";
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(25, 25);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->button1, this->button2,
					this->toolStripButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Padding = System::Windows::Forms::Padding(0, 0, 2, 0);
			this->toolStrip1->Size = System::Drawing::Size(472, 32);
			this->toolStrip1->TabIndex = 4;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(29, 29);
			this->toolStripButton1->Text = L"toolStripButton1";
//			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm2::toolStripButton1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 50);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 313);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->pictureBox1);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Font = (gcnew System::Drawing::Font(L"Gabriola", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 12, 6, 12);
			this->Name = L"MyForm2";
			this->Text = L"Picture Editor";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Image^ img;
		Graphics^ g;
		Bitmap^ b;
		Bitmap^ bgr;
		PointF start_point;
		Pen^ p;
		String^ full_name_of_image;

		bool Draw;
		int brush_size;

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 Draw = false;
				 g = Graphics::FromImage(b);
				 pictureBox1->Image = b;
	}
	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 Draw = true;
				 brush_size = 7;
				 //pen
				 start_point = e->Location;
	}
	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (Draw == true){
					 g = Graphics::FromImage(b);
					 g->DrawLine(p, start_point, e->Location);
					 start_point = e->Location;
					 pictureBox1->Image = b;
					 delete g;
				 }
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ open_dialog = gcnew OpenFileDialog;
				 open_dialog->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG|All files (*.*)|*.*";
				 if (open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 delete b;
					 full_name_of_image = open_dialog->FileName;
					 b = gcnew Bitmap(Image::FromFile(open_dialog->FileName));
					 pictureBox1->Image = b;
				 }
				 delete open_dialog;

	}
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
				 p = gcnew Pen(Color::Black, 2);
				 p->StartCap = System::Drawing::Drawing2D::LineCap::Round;
				 p->EndCap = System::Drawing::Drawing2D::LineCap::Round;
				 bgr = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
				 b = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
				 b = gcnew Bitmap(Image::FromFile("mine.png"));
				 pictureBox1->Image = b;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 SaveFileDialog^ SaveFile = gcnew SaveFileDialog;
				 SaveFile->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
				 SaveFile->Title = "Save an Image File";
				 SaveFile->OverwritePrompt = true;
				 SaveFile->CheckPathExists = true;
				 SaveFile->ShowHelp = true;
				 b = gcnew Bitmap(pictureBox1->Image);


				 if (SaveFile->ShowDialog() == Windows::Forms::DialogResult::OK)
				 {
					 b->Save(SaveFile->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
				 }
	}

	};
};