#include "Elements.h"
#include "PenDialog.h"
#include <cliext/vector>
#include "Sketch.h"
#include "TextDialog.h"
#include "MyForm1.h"
#include "MyForm2.h"


#pragma once


namespace Ïðîåêò4 {

    using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace cliext;
	using namespace MyForm;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::IO;


	enum class ElementType { LINE, RECTANGLE, CIRCLE, CURVE, TEXT };
	enum class Mode { Normal, Move };
	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) : elementType(ElementType::LINE), /*ñolor(Color::Black),*/ drawing(false)
			, firstPoint(0), tempElement(nullptr), sketch(gcnew Sketch()),
			highlightedElement(nullptr), mode(Mode::Normal), penDialog(gcnew PenDialog())
			, penWidth(1.0f), textDialog(gcnew TextDialog())
			, saved(false), formatter(gcnew BinaryFormatter())
			, sketchFilePath(nullptr), aboutDialog(gcnew MyForm1()), tr(gcnew MyForm2())
		{
			InitializeComponent();
			//
			SetElementTypeButtonsState();
			SetColorButtonsState();
			lineStyleComboBox->SelectedIndex = 0;
			textFont = Font;
			
			//
		}
		//óñòàíîâêà ñîñòîÿíèÿ êíîïîê ýëåìåíòîâ
		void SetElementTypeButtonsState(void){
			toolStripButton1->Checked = elementType == ElementType::LINE;
			toolStripButton2->Checked = elementType == ElementType::RECTANGLE;
			toolStripButton3->Checked = elementType == ElementType::CIRCLE;
			toolStripButton4->Checked = elementType == ElementType::CURVE;
			}
		//óñòàíîâêà ñîñòîÿíèÿ êíîïîê öâåòà
		void SetColorButtonsState(void){
			toolStripButton5->Checked = color == Color::Black;
			toolStripButton6->Checked = color == Color::Red;
			toolStripButton7->Checked = color == Color::Green;
			toolStripButton8->Checked = color == Color::Blue;
			}
		ElementType elementType;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  sendToBackContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  moveContextMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  contextSeparator;

	private: System::Windows::Forms::ToolStripMenuItem^  lineContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangleContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  circleContextMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  curveContextMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
	private: System::Windows::Forms::ToolStripMenuItem^  blackContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenContextMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueContextMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton9;
	private: System::Windows::Forms::ComboBox^  lineStyleComboBox;
	private: System::Windows::Forms::ToolStripMenuItem^  textToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton10;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton11;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Drawing::Printing::PrintDocument^  printDocument;
	private: System::Windows::Forms::PrintDialog^  printDialog;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripButton^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripButton^  toolStripButton12;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton13;


	public:

	public:
		Color color;
	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  printToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elementToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  curveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blackToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  ñîçäàòüToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  goodToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  ïå÷àòüToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton8;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Òðåáóåòñÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà - íå èçìåíÿéòå
		/// ñîäåðæèìîå äàííîãî ìåòîäà ïðè ïîìîùè ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->curveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->ñîçäàòüToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->goodToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ïå÷àòüToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton11 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton12 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->sendToBackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->lineContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->curveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->blackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineStyleComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->printDocument = (gcnew System::Drawing::Printing::PrintDocument());
			this->printDialog = (gcnew System::Windows::Forms::PrintDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->contextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Constantia", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ôàéëToolStripMenuItem,
					this->elementToolStripMenuItem, this->colorToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(10, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(1130, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->createToolStripMenuItem,
					this->printToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(40, 19);
			this->ôàéëToolStripMenuItem->Text = L"&File";
			// 
			// createToolStripMenuItem
			// 
			this->createToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->createToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"createToolStripMenuItem.Image")));
			this->createToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->createToolStripMenuItem->Name = L"createToolStripMenuItem";
			this->createToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->createToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->createToolStripMenuItem->Text = L"&New";
			this->createToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::createToolStripMenuItem_Click);
			// 
			// printToolStripMenuItem
			// 
			this->printToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->printToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"printToolStripMenuItem.Image")));
			this->printToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
			this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->printToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->printToolStripMenuItem->Text = L"&Print";
			this->printToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïå÷àòüToolStripButton_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->exitToolStripMenuItem->Text = L"Ex&it";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// elementToolStripMenuItem
			// 
			this->elementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->lineToolStripMenuItem,
					this->rectangleToolStripMenuItem, this->circleToolStripMenuItem, this->curveToolStripMenuItem, this->textToolStripMenuItem
			});
			this->elementToolStripMenuItem->Name = L"elementToolStripMenuItem";
			this->elementToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::L));
			this->elementToolStripMenuItem->Size = System::Drawing::Size(67, 19);
			this->elementToolStripMenuItem->Text = L"&Element";
			this->elementToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &MyForm::elementToolStripMenuItem_DropDownOpening);
			// 
			// lineToolStripMenuItem
			// 
			this->lineToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lineToolStripMenuItem->Checked = true;
			this->lineToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
			this->lineToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::L));
			this->lineToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->lineToolStripMenuItem->Text = L"&Line";
			this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// rectangleToolStripMenuItem
			// 
			this->rectangleToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
			this->rectangleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::R));
			this->rectangleToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->rectangleToolStripMenuItem->Text = L"&Rectangle";
			this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->circleToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->circleToolStripMenuItem->Text = L"&Circle";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// curveToolStripMenuItem
			// 
			this->curveToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->curveToolStripMenuItem->Name = L"curveToolStripMenuItem";
			this->curveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::C));
			this->curveToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->curveToolStripMenuItem->Text = L"&Curve";
			this->curveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::curveToolStripMenuItem_Click);
			// 
			// textToolStripMenuItem
			// 
			this->textToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textToolStripMenuItem->Name = L"textToolStripMenuItem";
			this->textToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::T));
			this->textToolStripMenuItem->Size = System::Drawing::Size(209, 22);
			this->textToolStripMenuItem->Text = L"&Text";
			this->textToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::textToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->blackToolStripMenuItem,
					this->redToolStripMenuItem, this->greenToolStripMenuItem, this->blueToolStripMenuItem
			});
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			this->colorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->colorToolStripMenuItem->Size = System::Drawing::Size(50, 19);
			this->colorToolStripMenuItem->Text = L"&Color";
			this->colorToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &MyForm::colorToolStripMenuItem_DropDownOpening);
			// 
			// blackToolStripMenuItem
			// 
			this->blackToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->blackToolStripMenuItem->Checked = true;
			this->blackToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->blackToolStripMenuItem->Name = L"blackToolStripMenuItem";
			this->blackToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->blackToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->blackToolStripMenuItem->Text = L"&Black";
			this->blackToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blackToolStripMenuItem_Click);
			// 
			// redToolStripMenuItem
			// 
			this->redToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->redToolStripMenuItem->Name = L"redToolStripMenuItem";
			this->redToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->redToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->redToolStripMenuItem->Text = L"&Red";
			this->redToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::redToolStripMenuItem_Click);
			// 
			// greenToolStripMenuItem
			// 
			this->greenToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->greenToolStripMenuItem->Name = L"greenToolStripMenuItem";
			this->greenToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::G));
			this->greenToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->greenToolStripMenuItem->Text = L"&Green";
			this->greenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::greenToolStripMenuItem_Click);
			// 
			// blueToolStripMenuItem
			// 
			this->blueToolStripMenuItem->BackColor = System::Drawing::SystemColors::ControlDark;
			this->blueToolStripMenuItem->Name = L"blueToolStripMenuItem";
			this->blueToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::B));
			this->blueToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->blueToolStripMenuItem->Text = L"&Blue";
			this->blueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::blueToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem1 });
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(54, 19);
			this->aboutToolStripMenuItem->Text = L"&About";
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->aboutToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem1.Image")));
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(109, 22);
			this->aboutToolStripMenuItem1->Text = L"About";
			this->aboutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(15, 15);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(20) {
				this->ñîçäàòüToolStripButton,
					this->goodToolStripButton, this->ïå÷àòüToolStripButton, this->toolStripSeparator6, this->toolStripButton4, this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton10, this->toolStripSeparator7, this->toolStripButton5, this->toolStripButton6,
					this->toolStripButton7, this->toolStripButton8, this->button1, this->toolStripSeparator8, this->toolStripButton9, this->toolStripButton11,
					this->toolStripButton12, this->toolStripButton13
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 27);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Padding = System::Windows::Forms::Padding(0, 0, 2, 0);
			this->toolStrip1->Size = System::Drawing::Size(1130, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// ñîçäàòüToolStripButton
			// 
			this->ñîçäàòüToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ñîçäàòüToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ñîçäàòüToolStripButton.Image")));
			this->ñîçäàòüToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ñîçäàòüToolStripButton->Name = L"ñîçäàòüToolStripButton";
			this->ñîçäàòüToolStripButton->Size = System::Drawing::Size(23, 22);
			this->ñîçäàòüToolStripButton->Text = L"&Create";
			this->ñîçäàòüToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::createToolStripMenuItem_Click);
			// 
			// goodToolStripButton
			// 
			this->goodToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->goodToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goodToolStripButton.Image")));
			this->goodToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->goodToolStripButton->Name = L"goodToolStripButton";
			this->goodToolStripButton->Size = System::Drawing::Size(23, 22);
			this->goodToolStripButton->Text = L"&Good thing";
			this->goodToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::goodToolStripMenuItem_Click);
			// 
			// ïå÷àòüToolStripButton
			// 
			this->ïå÷àòüToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ïå÷àòüToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ïå÷àòüToolStripButton.Image")));
			this->ïå÷àòüToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ïå÷àòüToolStripButton->Name = L"ïå÷àòüToolStripButton";
			this->ïå÷àòüToolStripButton->Size = System::Drawing::Size(23, 22);
			this->ïå÷àòüToolStripButton->Text = L"&Print";
			this->ïå÷àòüToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::ïå÷àòüToolStripButton_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->AccessibleRole = System::Windows::Forms::AccessibleRole::Alert;
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"Curve";
			this->toolStripButton4->ToolTipText = L"Draw Curve";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MyForm::curveToolStripMenuItem_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Line";
			this->toolStripButton1->ToolTipText = L"Draw Line";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::lineToolStripMenuItem_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"Rectangle";
			this->toolStripButton2->ToolTipText = L"Draw Rectangle";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MyForm::rectangleToolStripMenuItem_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::White;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"Round";
			this->toolStripButton3->ToolTipText = L"Draw Circle";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MyForm::circleToolStripMenuItem_Click);
			// 
			// toolStripButton10
			// 
			this->toolStripButton10->AccessibleRole = System::Windows::Forms::AccessibleRole::Caret;
			this->toolStripButton10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton10.Image")));
			this->toolStripButton10->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton10->Name = L"toolStripButton10";
			this->toolStripButton10->Size = System::Drawing::Size(23, 22);
			this->toolStripButton10->Text = L"Text";
			this->toolStripButton10->Click += gcnew System::EventHandler(this, &MyForm::textToolStripMenuItem_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(23, 22);
			this->toolStripButton5->Text = L"Black";
			this->toolStripButton5->ToolTipText = L"Black color";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &MyForm::blackToolStripMenuItem_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(23, 22);
			this->toolStripButton6->Text = L"Red";
			this->toolStripButton6->ToolTipText = L"Red color";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &MyForm::redToolStripMenuItem_Click);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton7.Image")));
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(23, 22);
			this->toolStripButton7->Text = L"Green";
			this->toolStripButton7->ToolTipText = L"Green color";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &MyForm::greenToolStripMenuItem_Click);
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton8.Image")));
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(23, 22);
			this->toolStripButton8->Text = L"Blue";
			this->toolStripButton8->ToolTipText = L"Blue color";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &MyForm::blueToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(23, 22);
			this->button1->Text = L"Change color";
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton9
			// 
			this->toolStripButton9->BackColor = System::Drawing::SystemColors::ControlDark;
			this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton9.Image")));
			this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton9->Name = L"toolStripButton9";
			this->toolStripButton9->Size = System::Drawing::Size(23, 22);
			this->toolStripButton9->Text = L"penWidthButton";
			this->toolStripButton9->ToolTipText = L"Change Pen Width";
			this->toolStripButton9->Click += gcnew System::EventHandler(this, &MyForm::penWidthButton9_Click);
			// 
			// toolStripButton11
			// 
			this->toolStripButton11->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton11.Image")));
			this->toolStripButton11->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton11->Name = L"toolStripButton11";
			this->toolStripButton11->Size = System::Drawing::Size(23, 22);
			this->toolStripButton11->Text = L"Font";
			this->toolStripButton11->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton11_Click);
			// 
			// toolStripButton12
			// 
			this->toolStripButton12->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton12.Image")));
			this->toolStripButton12->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton12->Name = L"toolStripButton12";
			this->toolStripButton12->Size = System::Drawing::Size(23, 22);
			this->toolStripButton12->Text = L"toolStripButton12";
			this->toolStripButton12->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton12_Click);
			// 
			// toolStripButton13
			// 
			this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton13.Image")));
			this->toolStripButton13->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton13->Name = L"toolStripButton13";
			this->toolStripButton13->Size = System::Drawing::Size(23, 22);
			this->toolStripButton13->Text = L"toolStripButton13";
			this->toolStripButton13->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton13_Click);
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->ImeMode = System::Windows::Forms::ImeMode::On;
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {
				this->sendToBackContextMenuItem,
					this->deleteContextMenuItem, this->moveContextMenuItem, this->contextSeparator, this->lineContextMenuItem, this->rectangleContextMenuItem,
					this->circleContextMenuItem, this->curveContextMenuItem, this->toolStripSeparator9, this->blackContextMenuItem, this->redContextMenuItem,
					this->greenContextMenuItem, this->blueContextMenuItem
			});
			this->contextMenuStrip->Name = L"contextMenuStrip";
			this->contextMenuStrip->Size = System::Drawing::Size(143, 258);
			this->contextMenuStrip->UseWaitCursor = true;
			this->contextMenuStrip->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::contextMenuStrip_Opening);
			this->contextMenuStrip->Click += gcnew System::EventHandler(this, &MyForm::contextMenuStrip_Click);
			// 
			// sendToBackContextMenuItem
			// 
			this->sendToBackContextMenuItem->Name = L"sendToBackContextMenuItem";
			this->sendToBackContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->sendToBackContextMenuItem->Text = L"Send to back";
			this->sendToBackContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sendToBackContextMenuItem_Click);
			// 
			// deleteContextMenuItem
			// 
			this->deleteContextMenuItem->Name = L"deleteContextMenuItem";
			this->deleteContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->deleteContextMenuItem->Text = L"Delete";
			this->deleteContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteContextMenuItem_Click);
			// 
			// moveContextMenuItem
			// 
			this->moveContextMenuItem->Name = L"moveContextMenuItem";
			this->moveContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->moveContextMenuItem->Text = L"Move";
			this->moveContextMenuItem->Click += gcnew System::EventHandler(this, &MyForm::moveContextMenuItem_Click);
			// 
			// contextSeparator
			// 
			this->contextSeparator->Name = L"contextSeparator";
			this->contextSeparator->Size = System::Drawing::Size(139, 6);
			// 
			// lineContextMenuItem
			// 
			this->lineContextMenuItem->Name = L"lineContextMenuItem";
			this->lineContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->lineContextMenuItem->Text = L"Line";
			// 
			// rectangleContextMenuItem
			// 
			this->rectangleContextMenuItem->Name = L"rectangleContextMenuItem";
			this->rectangleContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->rectangleContextMenuItem->Text = L"Rectangle";
			// 
			// circleContextMenuItem
			// 
			this->circleContextMenuItem->Name = L"circleContextMenuItem";
			this->circleContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->circleContextMenuItem->Text = L"Circle";
			// 
			// curveContextMenuItem
			// 
			this->curveContextMenuItem->Name = L"curveContextMenuItem";
			this->curveContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->curveContextMenuItem->Text = L"Curve";
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(139, 6);
			// 
			// blackContextMenuItem
			// 
			this->blackContextMenuItem->Name = L"blackContextMenuItem";
			this->blackContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->blackContextMenuItem->Text = L"Black";
			// 
			// redContextMenuItem
			// 
			this->redContextMenuItem->Name = L"redContextMenuItem";
			this->redContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->redContextMenuItem->Text = L"Red";
			// 
			// greenContextMenuItem
			// 
			this->greenContextMenuItem->Name = L"greenContextMenuItem";
			this->greenContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->greenContextMenuItem->Text = L"Green";
			// 
			// blueContextMenuItem
			// 
			this->blueContextMenuItem->Name = L"blueContextMenuItem";
			this->blueContextMenuItem->Size = System::Drawing::Size(142, 22);
			this->blueContextMenuItem->Text = L"Blue";
			// 
			// lineStyleComboBox
			// 
			this->lineStyleComboBox->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lineStyleComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->lineStyleComboBox->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lineStyleComboBox->FormattingEnabled = true;
			this->lineStyleComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Solied lines", L"Dashed lines", L"Dotted lines",
					L"Dash-dotted lines", L"Dash-dot-dotted lines"
			});
			this->lineStyleComboBox->Location = System::Drawing::Point(461, 27);
			this->lineStyleComboBox->Margin = System::Windows::Forms::Padding(5);
			this->lineStyleComboBox->Name = L"lineStyleComboBox";
			this->lineStyleComboBox->Size = System::Drawing::Size(119, 23);
			this->lineStyleComboBox->TabIndex = 2;
			this->lineStyleComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lineStyleComboBox_SelectedIndexChanged);
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->Filter = L" \"Òåêñòîâûå ôàéëû (*.ske)|*.ske|Âñå ôàéëû (*.*)|*.*\"";
			this->saveFileDialog->FilterIndex = 2;
			this->saveFileDialog->InitialDirectory = L"G:\\ïðîåêòû";
			this->saveFileDialog->Title = L"mimi";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"sketch";
			this->openFileDialog->Filter = L" \"Òåêñòîâûå ôàéëû (*.ske)|*.ske|Âñå ôàéëû (*.*)|*.*\"";
			this->openFileDialog->FilterIndex = 2;
			this->openFileDialog->InitialDirectory = L"G:\\ïðîåêòû";
			this->openFileDialog->Title = L"mimi";
			// 
			// printDocument
			// 
			this->printDocument->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MyForm::printDocument_PrintPage);
			// 
			// printDialog
			// 
			this->printDialog->Document = this->printDocument;
			this->printDialog->UseEXDialog = true;
			// 
			// colorDialog1
			// 
			this->colorDialog1->ShowHelp = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1130, 504);
			this->ContextMenuStrip = this->contextMenuStrip;
			this->Controls->Add(this->lineStyleComboBox);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"MyForm";
			this->Text = L"Graphic Editor by Katte";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 elementType = ElementType::LINE;
				 SetElementTypeButtonsState();
	}
	private: System::Void rectangleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 elementType = ElementType::RECTANGLE;
				 SetElementTypeButtonsState();
	}
	private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 elementType = ElementType::CIRCLE;
				 SetElementTypeButtonsState();
	}
			 
	private: System::Void curveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 elementType = ElementType::CURVE;
				 SetElementTypeButtonsState();
	}
			 
	private: System::Void blackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 color = Color::Black;
				 SetColorButtonsState();
	}
	private: System::Void redToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 color = Color::Red;
				 SetColorButtonsState();
	}
	private: System::Void greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 color = Color::Green;
	}
	private: System::Void blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 color = Color::Blue;
				 SetColorButtonsState();
	}
	private: System::Void elementToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
				 lineToolStripMenuItem->Checked = elementType == ElementType::LINE;
				 rectangleToolStripMenuItem->Checked = elementType == ElementType::RECTANGLE;
				 circleToolStripMenuItem->Checked = elementType == ElementType::CIRCLE;
				 curveToolStripMenuItem->Checked = elementType == ElementType::CURVE;
	}
	private: System::Void colorToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
				 blackToolStripMenuItem->Checked = color == Color::Black;
				 redToolStripMenuItem->Checked = color == Color::Red;
				 greenToolStripMenuItem->Checked = color == Color::Green;
				 blueToolStripMenuItem->Checked = color == Color::Blue;
	}
	public:
		bool drawing;
		Point firstPoint;
		Element^ tempElement;
		Sketch^ sketch;
		Color highlighted;
		Element^ highlightedElement;
		bool saved;
		Mode mode;
		Image^ img;
		Graphics^ g;
		Bitmap^ b;
		Bitmap^ bgr;
		PointF start_point;
		Pen^ p;
		String^ full_name_of_image;

		bool Draw;
		int brush_size;
	    

	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			firstPoint = e->Location;
			if (mode == Mode::Normal)
			{
				if (elementType == ElementType::TEXT)
				{
					textDialog->TextString = L"";        // Reset the text box string  
					textDialog->TextFont = textFont;     // Set the font for the edit box
					if (textDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						tempElement = gcnew TextElement(color, firstPoint,
							textDialog->TextString, textFont);
						sketch += tempElement;
						sketch->saved = false;             // Sketch has changed so mark it not saved
						Invalidate(tempElement->bound);    // The text element region
						tempElement = nullptr;
						Update();
					}
					drawing = false;
				}
				else
				{
					drawing = true;
				}
			}
		}
	}


private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (drawing)
	{
		if (tempElement)
			Invalidate(tempElement->bound);               // Invalidate old element area
		switch (elementType)
		{
		case ElementType::LINE:
			tempElement = gcnew Line(color, firstPoint, e->Location, penWidth, lineStyle);
			break;
		case ElementType::RECTANGLE:
			tempElement = gcnew Rectangl(color, firstPoint, e->Location, penWidth, lineStyle);
			break;
		case ElementType::CIRCLE:
			tempElement = gcnew Circle(color, firstPoint, e->Location, penWidth, lineStyle);
			break;
		case ElementType::CURVE:
			if (tempElement)
				safe_cast<Curve^>(tempElement)->Add(e->Location);
			else
				tempElement = gcnew Curve(color, firstPoint, e->Location, penWidth, lineStyle);
			break;
		}
		Invalidate(tempElement->bound);                 // Invalidate new element area
		Update();                                       // Repaint
	}
	else if (mode == Mode::Normal)
	{
		// Find the element under the cursor - if any
		Element^ element(sketch->HitElement(e->Location));
		if (highlightedElement == element)        // If the old is same as the new
			return;                                // there's nothing to do

		// Reset any existing highlighted element
		if (highlightedElement)
		{
			Invalidate(highlightedElement->bound);  // Invalidate element area
			highlightedElement->highlighted = false;
			highlightedElement = nullptr;
		}
		// Find and set new highlighted element, if any
		highlightedElement = element;
		if (highlightedElement)
		{
			highlightedElement->highlighted = true;
			Invalidate(highlightedElement->bound);  // Invalidate element area
		}
		Update();                                 // Send a paint message
	}
	else if (mode == Mode::Move && e->Button == System::Windows::Forms::MouseButtons::Left)
	{  // Move the highlighted element
		if (highlightedElement)
		{
			Invalidate(highlightedElement->bound);    // Region before move
			highlightedElement->Move(e->X - firstPoint.X, e->Y - firstPoint.Y);
			firstPoint = e->Location;
			Invalidate(highlightedElement->bound);     // Region after move
			Update();
		}
	}
}
private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (!drawing)
	{
		mode = Mode::Normal;
		return;
	}
	if (tempElement)
	{
		sketch += tempElement;
		sketch->saved = false;
		tempElement = nullptr;
		Invalidate();
	}
	drawing = false;
	
}
		 
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ g = e->Graphics;
				 sketch->Draw(g);
				 if (tempElement != nullptr)
				 {
					 tempElement->Draw(g);
				 }
	}


private: System::Void contextMenuStrip_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 contextMenuStrip->Items->Clear();    // Remove existing items
			 if (highlightedElement)
			 {
				 contextMenuStrip->Items->Add(moveContextMenuItem);
				 contextMenuStrip->Items->Add(deleteContextMenuItem);
				 contextMenuStrip->Items->Add(sendToBackContextMenuItem);
			 }
			 else
			 {
				 contextMenuStrip->Items->Add(lineContextMenuItem);
				 contextMenuStrip->Items->Add(rectangleContextMenuItem);
				 contextMenuStrip->Items->Add(circleContextMenuItem);
				 contextMenuStrip->Items->Add(curveContextMenuItem);
				 contextMenuStrip->Items->Add(contextSeparator);
				 contextMenuStrip->Items->Add(blackContextMenuItem);
				 contextMenuStrip->Items->Add(redContextMenuItem);
				 contextMenuStrip->Items->Add(greenToolStripMenuItem);
				 contextMenuStrip->Items->Add(blueContextMenuItem);
				 				 // Set checks for the menu items
				 lineContextMenuItem->Checked = elementType == ElementType::LINE;
				 rectangleContextMenuItem->Checked = elementType == ElementType::RECTANGLE;
				 circleContextMenuItem->Checked = elementType == ElementType::CIRCLE;
				 curveContextMenuItem->Checked = elementType == ElementType::CURVE;
				 blackContextMenuItem->Checked = color == Color::Black;
				 redContextMenuItem->Checked = color == Color::Red;
				 greenContextMenuItem->Checked = color == Color::Green;
				 blueContextMenuItem->Checked = color == Color::Blue;
			 }
}
		 
private: System::Void sendToBackContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (highlightedElement)
			 {
				 sketch->saved = false;
				 sketch -= highlightedElement;               // Delete the highlighted element
				 sketch->push_front(highlightedElement);     // then add it back to the beginning
				 highlightedElement->highlighted = false;
				 Invalidate(highlightedElement->bound);
				 highlightedElement = nullptr;
				 Update();
			 }
}

private: System::Void deleteContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (highlightedElement)
			 {	 
				 sketch->saved = false;
				 sketch -= highlightedElement;              // Delete the highlighted element
				 Invalidate(highlightedElement->bound);
				 highlightedElement = nullptr;
				 Update();
			 }
}

private: System::Void moveContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 mode = Mode::Move;
}

private: System::Void contextMenuStrip_Click(System::Object^  sender, System::EventArgs^  e) {
}

public:
	PenDialog^ penDialog;
	MyForm1^ aboutDialog;
	MyForm2^ tr;
public:
	float penWidth;

private: System::Void penWidthButton9_Click(System::Object^  sender, System::EventArgs^  e) {
			penDialog->ShowDialog();
		    penWidth = penDialog->PenWidth;      // Get the pen width
			 
}

public:
	System::Drawing::Drawing2D::DashStyle lineStyle;

private: System::Void lineStyleComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (lineStyleComboBox->SelectedIndex)
			 {
			 case 1:
				 lineStyle = DashStyle::Dash;
				 break;
			 case 2:
				 lineStyle = DashStyle::Dot;
				 break;
			 case 3:
				 lineStyle = DashStyle::DashDot;
				 break;
			 case 4:
				 lineStyle = DashStyle::DashDotDot;
				 break;
			 default:
				 lineStyle = DashStyle::Solid;
				 break;
			 }
}

private: System::Void textToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 elementType = ElementType::TEXT;
			 SetElementTypeButtonsState();
}

public:
	System::Drawing::Font^ textFont;

private: System::Void toolStripButton11_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 textFont = fontDialog1->Font;
			 }
}

public:
	TextDialog^ textDialog;

private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 {
				 Stream^ stream;
				 if (!sketch->saved)
				 {
					 String^ message = L"The current sketch is not saved.\nSave the current sketch?";
					 String^ caption = L"Sketch Not Saved";
					 MessageBoxButtons buttons = MessageBoxButtons::YesNo;

					 // Displays the MessageBox to warn about unsaved sketch
					 if (MessageBox::Show(this, message, caption, buttons) ==
						 System::Windows::Forms::DialogResult::Yes)
					 {
						 SaveSketch();
					 }
				 }

				 // Now open a new sketch
				 if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 stream = openFileDialog->OpenFile();
					 if (stream != nullptr)
					 {
						 stream->Close();
						 sketch->saved = true;
						 sketchFilePath = openFileDialog->FileName;
						 Invalidate();
					 }
				 }
			 }
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	tr->ShowDialog();
//			 SaveSketch();
}
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveSketchAs();
}

		 void SaveSketch(void)
		 {
			 if (sketch->saved)
				 return;                // Nothing to do because the sketch was not modified

			 if (sketchFilePath == nullptr)
			 {
				 // File has not yet been saved before, so show the save dialog
				 SaveSketchAs();
			 }
			 else
			 {
				 // File has been saved before, so just save it using the same name
				 Stream^ stream = File::OpenWrite(sketchFilePath);
				 formatter->Serialize(stream, sketch);
				 stream->Close();
			 }
		 }

		 void SaveSketchAs(void)
		 {
			 if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 Stream^ stream = File::Open(saveFileDialog->FileName, FileMode::Create);
				 if (stream != nullptr)
				 {
					
					 formatter->Serialize(stream, sketch);
					 stream->Close();
					 sketchFilePath = saveFileDialog->FileName;
					 sketch->saved = true;
				 }
				 else
				 {
					 MessageBox::Show(L"Failed to create sketch file stream!");
				 }
			 }
		 }

public:

	String^ sketchFilePath;
	BinaryFormatter^ formatter;

	void SaveSketchCheck(void)
	{
		if (!sketch->saved)
		{
			String^ message = L"The current sketch is not saved.\nSave the current sketch?";
			String^ caption = L"Sketch Not Saved";
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;

			// Displays the MessageBox to warn about unsaved sketch
			if (MessageBox::Show(this, message, caption, buttons) ==
				System::Windows::Forms::DialogResult::Yes)
			{
				SaveSketch();
			}
		}
	}

private: System::Void createToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveSketchCheck();
			 sketch = gcnew Sketch();
			 sketchFilePath = nullptr;
			 Invalidate();
			 Update();
}

private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 SaveSketchCheck();
}
	
private: System::Void printDocument_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
			 sketch->Draw(e->Graphics);
}

private: System::Void ïå÷àòüToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 printDocument->Print();

}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 {
				 if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 color = colorDialog1->Color;
					 SetColorButtonsState();
				 }
			 }
}
		 
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}

private: System::Void aboutToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 aboutDialog->ShowDialog();
}

private: System::Void goodToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	tr->ShowDialog();
}


private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 p = gcnew Pen(Color::Black, 2);
			 p->StartCap = System::Drawing::Drawing2D::LineCap::Round;
			 p->EndCap = System::Drawing::Drawing2D::LineCap::Round;//			 bgr = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			 //b = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			 b = gcnew Bitmap(Image::FromFile("mine.png"));
			 //pictureBox1->Image = b;
}
private: System::Void toolStripButton12_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ open_dialog = gcnew OpenFileDialog;
			 open_dialog->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG|All files (*.*)|*.*";
			 if (open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 delete b;
				 full_name_of_image = open_dialog->FileName;
				 b = gcnew Bitmap(Image::FromFile(open_dialog->FileName));
//				 pictureBox1->Image = b;
			 }
			 delete open_dialog;
}
private: System::Void toolStripButton13_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ SaveFile = gcnew SaveFileDialog;
			 SaveFile->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
			 SaveFile->Title = "Save an Image File";
			 SaveFile->OverwritePrompt = true;
			 SaveFile->CheckPathExists = true;
			 SaveFile->ShowHelp = true;
//			 b = gcnew Bitmap(pictureBox1->Image);


			 if (SaveFile->ShowDialog() == Windows::Forms::DialogResult::OK)
			 {
				 b->Save(SaveFile->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
			 }
			  
}
};
};

